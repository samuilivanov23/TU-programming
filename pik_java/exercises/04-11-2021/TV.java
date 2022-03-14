public class TV extends Stock implements ElectricalAppliance
{
    private String manufacturer;
    private String model;
    private double power;

    public TV() { super(); }

    public TV( int id, double price, String manufacturer, String model, double power ) throws PriceException, PowerException
    {
        super(id, price);
        this.setManufacturer( manufacturer );
        this.setModel( model );
        this.setPower( power );
    }

    public String getManufacturer() { return this.manufacturer; };
    public void setManufacturer( String manufacturer ) { this.manufacturer = manufacturer; };

    public String getModel() { return this.model; };
    public void setModel( String model ) { this.model = model; };

    public double getPower() { return this.power; };
    public void setPower( double power ) throws PowerException
    {
        if( power <= 0 )
        {
            throw new PowerException();
        }
        else
        {
            this.power = power;
        }
    };

    public double CheckPromo()
    {
        return this.getPrice() - (this.getPrice() * 0.09);
    }

    public double CalculateEnergyConsumption(int period)
    {
        return this.power * period;
    }
}