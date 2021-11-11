class WrongUserException extends Exception
{
    @Override
    public String getMessage()
    {
        return "Invalid user! Should contain only a-z 0-9 - _ and between 3-15 chars!";
    }
}