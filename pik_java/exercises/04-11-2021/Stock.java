public abstract class Stock
{
    private int id;
    private double price;

    public Stock(){};

    public Stock( int id, double price ) throws PriceException
    {
        this.setId( id );
        this.setPrice( price );
    }

    public int getId() { return this.id; };
    public void setId( int id ) { this.id = id; };

    public double getPrice() { return this.price; };
    public void setPrice( double price ) throws PriceException 
    { 
        if( price < 0 )
        {
            throw new PriceException();
        }
        else
        {
            this.price = price;
        }
    };

    public abstract double CheckPromo();
}