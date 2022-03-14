class Product implements GetProductsTo, DeliveryAPI
{
    private double price;
    private String type;
    private int number;
    private int idOfProvider;

    public Product(){};

    public Product( double price, String type, int number, int idOfProvider )
    {
        this.price = price;
        this.type = type;
        this.number = number;
        this.idOfProvider = idOfProvider;
    }

    public double getPrice() { return this.price; }
    public void setPrice( double price ) { this.price = price; }

    public String getType() { return this.type; }
    public void setType( String type ) { this.type = type; }

    public String getType( int idOfProvider )
    {
        if( this.getIdOfProvider() == idOfProvider )
        {
            return this.type;
        }

        return null;
    }

    public int getNumber() { return this.number; }
    public void setNumber( int number ) { this.number = number; }

    public int getNumber( int idOfProvider )
    {
        if( this.getIdOfProvider() == idOfProvider )
        {
            return this.number;
        }

        return -1;
    }

    public int getIdOfProvider() { return this.idOfProvider; }
    public void setIdOfProvider( int idOfProvider ) { this.idOfProvider = idOfProvider; }
}