public class Ship extends Vehicle implements IsSeaVehicle
{
    private int deadWeight;

    public Ship() { super(); };

    public Ship( int maxSpeed, String model, double price, int deadWeight )
    {
        super( maxSpeed, model, price );
        this.deadWeight = deadWeight;
    }

    @Override
    public void EnterSea()
    {
        System.out.println( "Entering sea" );
    }

    @Override
    public double CheckPromo()
    {
        return (super.getPrice() - super.getPrice() * 0.003 );
    }
}