class Product 
{
    private int inventoryNumber;
    private double price;
    private int quantity;
    private Provider provider;

    public Product( int inventoryNumber, double price, int quantity, Provider provider )
    {
        this.setInventoryNumber( inventoryNumber );
        this.setPrice( price );
        this.setQuantity( quantity );
        this.setProvider( provider );
    }

    public int getInventoryNumber() { return this.inventoryNumber; }
    public void setInventoryNumber( String inventoryNumber ) { this.inventoryNumber = inventoryNumber; }

    public double getPrice() { return this.price; }
    public void setPrice( String price ) { this.price = price; }

    public int getQuantity() { return this.quantity; }
    public void setQuantity( String quantity ) { this.quantity = quantity; }

    public int getProvider() { return this.provider; }
    public void setProvider( Provider provider ) { this.provider = new Provider( provider.name, provider.phoneNumber ); }

    public abstract double GetPromotionalPrice();

    public abstract boolean SellProduct( int pieceCount ) throws NoMoreProductsException;
}