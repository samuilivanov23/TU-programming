class WrongPhoneNumberException extends Exception
{
    @Override
    public String getMessage()
    {
        return "Invalid Phone Number! Should only contain digits!";
    }
}