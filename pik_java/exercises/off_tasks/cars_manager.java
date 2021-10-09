class StartUp
{
	public static void main( String args[] )
	{

	}
}

public class Car
{
	private String brand;
	private String model;
	private String color;
	private int horsePower;
	private String engineType;
	private String gearBoxType;
	private Int manufactureYear;

	public Car(){};

	public Car(String brand, 
				String model, 
				String color, 
				int horsePower, 
				String engineType, 
				String gearBoxType, 
				String manufactureYear)
	{
		this.setBrand(brand);
		this.setModel(model);
		this.setColor(color);
		this.setHorsePower(horsePower);
		this.setEngineType(engineType);
		this.setGearBoxType(gearBoxType);
		this.setManufactureYear(manufactureYear);
	}

	public String getBrand() { return this.brand; }
	public void setBrand( String brand ) { this.brand = brand; }

	public String getMode() { return this.model; }
	public void setModel( String model ) { this.model = model; }

	public String getColor() { return this.color; }
	public void setColor( String color ) { this.color = color; }

	public int getHosrePower() { return this.horsePower; }
	public void setHorsePower( String horsePower ) { this.horsePower = horsePower; }

	public String getEngineType() { return this.engineType; }
	public void setEngineType( String engineType ) { this.engineType = engineType; }

	public String getGearBoxType() { return this.gearBoxType; }
	public void setGearBoxType( String gearBoxType ) { this.gearBoxType = gearBoxType; }
	
	public String getManufactureYear() { return this.manufactureYear; }
	public void setManufactureYear( String gearBoxType ) { this.manufactureYear = manufactureYear; }

}