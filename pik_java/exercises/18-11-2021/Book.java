class Book extends Product
{
    private String author;
    private String title;

    public Electronics( String author, String model, int inventoryNumber, double price, int quantity, Provider provider )
    {
        super( inventoryNumber, price, quantity, provider );
        this.setAuthor( author );
        this.setTitle( title );
    }

    public String getAuthor() { return this.author; }
    public void setAuthor( String author ) { this.author = author; }

    public String getTitle() { return this.title; }
    public void setTitle( String title ) { this.title = title; }

    public abstract double GetPromotionalPrice()
    {
        return this.getPrice() - this.getPrice()*0.5;
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