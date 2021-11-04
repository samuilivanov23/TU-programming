public class Book extends Stock 
{
    private String authorName;
    private String title;

    public Book() { super(); }

    public Book( int id, double price, String authorName, String title ) throws PriceException
    {
        super(id, price);
        this.setAuthorName( authorName );
        this.setTitle( title );
    }

    public String getAuthorName() { return this.authorName; };
    public void setAuthorName( String authorName ) { this.authorName = authorName; };

    public String getTitle() { return this.title; };
    public void setTitle( String title ) { this.title = title; };

    public double CheckPromo()
    {
        return this.getPrice() - (this.getPrice() * 0.15);
    }
}