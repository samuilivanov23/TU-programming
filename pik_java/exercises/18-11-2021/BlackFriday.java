class BlackFriday
{
    public Electronics[] electronics;
    public Book[] books;

    public static void ProcessSales()
    {
        ProductLoader productLoader = new ProductLoader();
        Product[] products = productLoader.ImportDataFromFile();
    }
}