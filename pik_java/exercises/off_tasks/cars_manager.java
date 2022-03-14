import java.util.Arrays;

class StartUp
{
	public static void main( String args[] )
	{
		Car cars[] = {
			new Car( "opel", "zafira", "grey", 90, "petrol", "manual", 1999 ),
			new Car( "opel", "kadett", "lightblue", 60, "petrol", "manual", 1994 ),
			new Car( "bmw", "X3", "black", 160, "diesel", "automatic", 2006 ),
			new Car( "audi", "A3", "black", 120, "diesel", "manual", 2006 )
		};

		Car resultCars[] = new Car[4];
		//resultCars = FilterBrands( cars, 'o' );
		//resultCars = SortedCars( cars, 0 );
		resultCars = RemoveCommonCars( cars );
		PrintCars( resultCars );
	}

	public static Car[] FilterBrands( Car cars[], char brand_symbol )
	{
		Car filteredCars[] = new Car[cars.length];
		int i = 0;
		for( Car car: cars )
		{
			if( car.getBrand().charAt(0) == brand_symbol )
			{
				filteredCars[i] = car;
				i++;
			}
		}

		return filteredCars;
	}

	//0 -> ascending 1 -> descending 
	public static Car[] SortedCars( Car cars[], int sortingOrder )
	{
		for(int i = 0; i < ( cars.length - 1 ); i++)
		{
			for( int j = ( i + 1 ) ; j < cars.length; j++ )
			{
				System.out.println( cars[i].getBrand().compareTo( cars[j].getBrand() ) > 0 );

				if (sortingOrder == 0)
				{
					if( cars[i].getBrand().compareTo( cars[j].getBrand() ) > 0 )
					{
						Car tempCar = cars[i];
						cars[i] = cars[j];
						cars[j] = tempCar;
					}
				}
				else
				{
					if( cars[i].getBrand().compareTo( cars[j].getBrand() ) < 0 )
					{
						Car tempCar = cars[i];
						cars[i] = cars[j];
						cars[j] = tempCar;
					}
				}
				
			}
		}

		return cars;
	}

	public static Car[] RemoveCommonCars( Car cars[] )
	{
		Car resultCars[] = new Car[cars.length];
		int occurrences[] = new int[cars.length];
		int index = 0;

		for(int i = 0; i < ( cars.length - 1 ); i++)
		{
			for( int j = ( i + 1 ); j < cars.length; j++ )
			{
				if(cars[i].getBrand() == cars[j].getBrand())
				{
					occurrences[i]++;
					occurrences[j]++;
					break;
				}	
			}
		}

		for( int i = 0; i < occurrences.length; i++ )
		{
			if( occurrences[i] < 1 )
			{
				resultCars[i] = cars[i];
			}
		}

		return resultCars;
	}

	public static void PrintCars(Car cars[])
	{
		for(Car car: cars)
		{
			try
			{
				System.out.println(car.getBrand());
			}
			catch(Exception e)
			{
				System.out.println("Empty slot");
			}
		}
	}
}

class Car
{
	private String brand;
	private String model;
	private String color;
	private int horsePower;
	private String engineType;
	private String gearBoxType;
	private int manufactureYear;

	public Car(){};

	public Car(String brand, 
				String model, 
				String color, 
				int horsePower, 
				String engineType, 
				String gearBoxType, 
				int manufactureYear)
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
	public void setHorsePower( int horsePower ) { this.horsePower = horsePower; }

	public String getEngineType() { return this.engineType; }
	public void setEngineType( String engineType ) { this.engineType = engineType; }

	public String getGearBoxType() { return this.gearBoxType; }
	public void setGearBoxType( String gearBoxType ) { this.gearBoxType = gearBoxType; }
	
	public int getManufactureYear() { return this.manufactureYear; }
	public void setManufactureYear( int manufactureYear ) { this.manufactureYear = manufactureYear; }

}