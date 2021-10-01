import java.util.Scanner;

class StartUp{
  public static void main(String args[]){
    Scanner sc = new Scanner(System.in);

    System.out.println( "Enter your name: " );
    String name = sc.nextLine();

    System.out.println( "Enter your age: " );
    String age = sc.nextLine();
    
    System.out.println( "Enter your gender: " );
    String gender = sc.nextLine();
    
    System.out.println( "Enter some other info: " );
    String other_info = sc.nextLine();
    
    String[] biography = { name, age, gender, other_info };

    int count = 1;
    for( String item: biography )
    {

      System.out.println( count + ": " + item );
      count++;
    }
  }
}
