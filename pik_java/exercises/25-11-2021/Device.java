class Device 
{
    private String brand;
    private String model;
    private double price;

    public Device( String brand, String model, double price )
    {
        this.setBrand(brand);
        this.setModel(model);
        this.setPrice(price);
    }

    public String getBrand() { return this.brand; }
    public void setBrand( String brand ) { this.brand = brand; }

    public String getModel() { return this.brand; }
    public void setModel( String model ) { this.model = model; }

    public double getPrice() { return this.price; }
    public void setPrice( double price ) { this.price = price; }
}