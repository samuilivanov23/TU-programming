import java.util.Scanner;
import java.util.ArrayList;

class StartUp
{
    public static void main( String args[] )
    {
        Scanner scanner = new Scanner( System.in );
        ArrayList<User> users = new ArrayList<User>();
        String command = "";

        // 1 -> REGISTRATION
        // 2 -> LOGIN
        // 3 -> EXIT
        do
        {
            System.out.println( "Enter command: " );
            command = scanner.nextLine();
            command = command.toLowerCase();

            switch( command )
            {
                case "registration":
                    System.out.print("Enter username: ");
                    String username = scanner.nextLine();

                    System.out.print("Enter phone number: ");
                    String phoneNumber = scanner.nextLine();

                    String password, passwordAgain;
                    
                    do
                    {
                        System.out.print("Enter password: ");
                        password = scanner.nextLine();

                        System.out.print("Enter password again: ");
                        passwordAgain = scanner.nextLine();

                        if( !password.equals( passwordAgain ) )
                        {
                            System.out.println( "Passwords must match!" );
                            continue;
                        }
                        else
                        {
                            PasswordValidator passwordValidator = new PasswordValidator();

                            if( !passwordValidator.isPasswordValid( password ) )
                            {
                                System.out.println("Not a valid password! Must contain only a-z A-Z and be at least 11 chars!");
                            }
                        }
                    }
                    while( !password.equals( passwordAgain ) );

                    try
                    {
                        User user = new User( username, password, phoneNumber );
                        boolean userExists = false;
                        for( User currentUser: users )
                        {
                            System.out.println(currentUser.getUsername());
                            System.out.println(user.getUsername());

                            if( currentUser.getUsername().equals( user.getUsername() ) )
                            {
                                userExists = true;
                                break;
                            }
                        }

                        if( !userExists )
                        {
                            users.add( user );
                        }
                        else
                        {
                            System.out.println( "This user already exists." );
                        }
                    }
                    catch( WrongPhoneNumberException | WrongUserException e)
                    {
                        System.out.println(e.getMessage());
                    }

                    break;
                case "login":
                    System.out.print("Enter username: ");
                    username = scanner.nextLine();


                    System.out.print("Enter password: ");
                    password = scanner.nextLine();

                    boolean successfullLogin = false;
                    for( User currentUser: users )
                    {
                        if( currentUser.getUsername().equals( username ) && currentUser.getPassword().equals( password ) )
                        {
                            successfullLogin = true;
                            break;
                        }
                    }

                    if( successfullLogin )
                    {
                        System.out.println( "Successfull login!" );
                    }
                    else
                    {
                        System.out.println( "Error while trying to login! Wrong username or password!" );
                    }

                    break;
            }
        }
        while( !command.equalsIgnoreCase("EXIT") );
    }
}