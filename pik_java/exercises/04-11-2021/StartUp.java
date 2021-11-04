import java.util.Scanner;

public class StartUp
{
    public static void main( String args[] )
    {
        Scanner scanner = new Scanner(System.in);
        double bookPrice, tvPrice, tvPower;

        System.out.println("Enter book price: ");
        bookPrice = scanner.nextDouble();

        System.out.println("Enter TV price: ");
        tvPrice = scanner.nextDouble();

        System.out.println("Enter TV power: ");
        tvPower = scanner.nextDouble();

        try
        {
            Book book = new Book(1, bookPrice, "Mark Wolynn", "It didn't start with you");
            System.out.println("book promo price: " + book.CheckPromo());
        }
        catch( PriceException e )
        {
            System.out.println( e.getMessage() );
        }
        
        try
        {
            TV tv = new TV(1, tvPrice, "Samsung", "testmodel", tvPower);
            System.out.println("tv promo price: " + tv.CheckPromo());
            System.out.println("tv energy consumption for 1 hour: " + tv.CalculateEnergyConsumption(3) + " kWh");
        }
        catch( PriceException | PowerException e )
        {
            System.out.println( e.getMessage() );
        }
    }
}