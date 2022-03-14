public abstract class Vehicle
{
    private int maxSpeed;
    private String model;
    private double price;

    public Vehicle(){};

    public Vehicle(int maxSpeed, String model, double price)
    {
        this.maxSpeed = maxSpeed;
        this.model = model;
        this.price = price;
    }

    public int getMaxSpeed() { return this.maxSpeed; };
    public void setMaxSpeed( int maxSpeed ) { this.maxSpeed = maxSpeed; };

    public String getModel() { return this.model; };
    public void setModel( String model ) { this.model = model; };

    public double getPrice() { return this.price; };
    public void setPrice( double price ) { this.price = price; };

    public abstract double CheckPromo();
}