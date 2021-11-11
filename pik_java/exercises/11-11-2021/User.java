class User implements ValidatePhone
{
    private String username;
    private String password;
    private String phoneNumber;

    public User( String username, String password, String phoneNumber ) throws WrongPhoneNumberException, WrongUserException
    {
        this.setUsername( username );
        this.setPassword( password );
        this.setPhoneNumber( phoneNumber );
    }

    public String getUsername() { return this.username; }
    public void setUsername( String username ) throws WrongUserException
    {
        UsernameValidator usernameValidator = new UsernameValidator();
        if( !usernameValidator.isUsernameValid( username ) )
        {
            throw new WrongUserException();
        }
        this.username = username;
    }

    public String getPassword() { return this.password; }
    public void setPassword( String password ) { this.password = password; }

    public String getPhoneNumber() { return this.phoneNumber; }
    public void setPhoneNumber( String phoneNumber ) throws WrongPhoneNumberException
    {
        if( !ValidatePhone.isPhoneNumberValid( phoneNumber ) )
        {
            throw new WrongPhoneNumberException();
        }
    }

}