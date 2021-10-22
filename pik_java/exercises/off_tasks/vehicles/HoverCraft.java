public class HoverCraft extends Vehicle implements IsSeaVehicle
{
    private int passangersCount;

    public HoverCraft() { super(); };

    public HoverCraft( int maxSpeed, String model, double price, int passangersCount )
    {
        super( maxSpeed, model, price );
        this.passangersCount = passangersCount;
    }
    
    @Override
    public void EnterSea()
    {
        System.out.println( "Entering sea" );
    }

    @Override
    public double CheckPromo()
    {
        return ( super.getPrice() - super.getPrice() * 0.03 );
    }
}