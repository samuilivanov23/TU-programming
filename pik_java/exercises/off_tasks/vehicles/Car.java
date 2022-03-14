public class Car extends Vehicle implements IsLandVehicle
{
    private int horsePower;

    public Car() { super(); };

    public Car( int maxSpeed, String model, double price, int horsePower )
    {
        super( maxSpeed, model, price );
        this.horsePower = horsePower;
    }

    @Override
    public void EnterLand()
    {
        System.out.println( "Entering land" );
    }

    @Override
    public double CheckPromo()
    {
        return ( super.getPrice() - super.getPrice() * 0.20) ;
    }
}