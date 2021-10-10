import java.util.Arrays;

class StartUp
{
	public static void main( String args[] )
	{

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

	public Car[] FilterBrands(Car cars[], char brand_symbol)
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
	public Car[] SortedCars( Car cars[], int sortingOrder )
	{
		for(int i = 0; i < ( cars.length - 1 ); i++)
		{
			for( int j = 0; j < cars.length; j++ )
			{
				if (sortingOrder == 0)
				{
					if( cars[i].brand.compareTo( cars[j].brand ) > 0 )
					{
						//Car tempCar = cars[i];
						//cars[i] = cars[j];
						//cars[j] = tempCar;
						SwapCars( cars[i], cars[j] );
					}
				}
				else
				{
					if( cars[i].brand.compareTo( cars[j].brand ) < 0 )
					{
						//Car tempCar = cars[i];
						//cars[i] = cars[j];
						//cars[j] = tempCar;
						SwapCars( cars[i], cars[j] );
					}
				}
				
			}
		}

		return cars;
	}

	public Car[] RemoveCommonCars( Car cars[] )
	{
		Car resultCars[] = new Car[cars.length];
		int count;
		int index = 0;

		for(int i = 0; i < ( cars.length - 1 ); i++)
		{
			count = 0;
			for( int j = ( i + 1 ); j < cars.length; j++ )
			{
				if(cars[i] == cars[j])
				{
					count++;
					break;
				}	
			}

			if( count == 1 )
			{
				resultCars[index] = cars[i];
				index++;
			}
		}

		return resultCars;
	}

	private void SwapCars(Car car1, Car car2)
	{
		Car tempCar = car1;
		car1 = car2;
		car2 = tempCar;
	}
}