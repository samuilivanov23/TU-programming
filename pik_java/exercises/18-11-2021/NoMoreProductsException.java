class NoMoreProductsException extends Exception 
{
    @Override
    public String getMessage()
    {
        return "No more products left!";
    }
}