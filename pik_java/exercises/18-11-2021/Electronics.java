class Electronics extends Product
{
    private String manufacturer;
    private String model;

    public Electronics( String manufacturer, String model, int inventoryNumber, double price, int quantity, Provider provider )
    {
        super( inventoryNumber, price, quantity, provider );
        this.setManufacturer( manufacturer );
        this.setModel( model );
    }

    public String getManufacturer() { return this.manufacturer; }
    public void setManufacturer( String manufacturer ) { this.manufacturer = manufacturer; }

    public String getModel() { return this.model; }
    public void setModel( String model ) { this.model = model; }

    public abstract double GetPromotionalPrice()
    {
        return this.getPrice() - this.getPrice()*0.1;
    }

    public abstract boolean SellProduct( int pieceCount ) throws NoMoreProductsException
    {
        if( this.getQuantity() - pieceCount )
        {
            throw new NoMoreProductsException(); 
        }

        this.setQuantity( this.getQuantity() - pieceCount );
    }
}