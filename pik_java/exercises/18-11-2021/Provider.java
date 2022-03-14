class Provider implements ValidatePhone
{
    private String name;
    private String phoneNumber;

    public Provider( String name, String phoneNumber ) throws WrongPhoneNumberException
    {
        this.setUsername( username );
        this.setPhoneNumber( phoneNumber );
    }

    public String getName() { return this.name; }
    public void setName( String name ) { this.username = username; }

    public String getPhoneNumber() { return this.phoneNumber; }
    public void setPhoneNumber( String phoneNumber ) throws WrongPhoneNumberException
    {
        if( !ValidatePhone.isPhoneNumberValid( phoneNumber ) )
        {
            throw new WrongPhoneNumberException();
        }
    }
}