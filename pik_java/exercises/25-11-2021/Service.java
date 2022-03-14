import java.util.ArrayList;
import java.io.IOException;
import java.lang.ClassNotFoundException;
import java.io.FileOutputStream;
import java.io.FileInputStream;
import java.io.ObjectOutputStream;
import java.io.ObjectInputStream;

class Service 
{
    public ArrayList<Device> devices = new ArrayList<Device>();
    public ArrayList<BrokenDevice> brokenDevices = new ArrayList<BrokenDevice>();

    public void PrintList()
    {
        System.out.println("These are the healthy devices");
        for( Device device : devices )
        {
            System.out.println( device.getBrand() + " - " + device.getModel() + " - " + device.getPrice() );
        }

        System.out.println("These are the broken devices");
        for( BrokenDevice brokenDevice : brokenDevices )
        {
            System.out.println( brokenDevice.getBrand() + " - " + brokenDevice.getModel() + " - " + brokenDevice.getPrice() );
        }
    }

    public void AddDevice( Device device )
    {
        devices.add( device );
    }

    public void AcceptBrokenDeviceRequest( Device device, String symptoms, int recoveryDueDays )
    {
        System.out.println( "Accepting broken device request for: " + device.getBrand() + " - " + device.getModel() + " - " + device.getPrice() );

        BrokenDevice brokenDevice = new BrokenDevice( device.getBrand(), device.getModel(), device.getPrice(), symptoms, recoveryDueDays );
        devices.remove( devices.indexOf( device ) );
        brokenDevices.add( brokenDevice );
    }

    public void TransferRecoveredDevice( BrokenDevice brokenDevice )
    {
        System.out.println( "Tranfering broken device to the list of healthy ones: " + brokenDevice.getBrand() + " - " + brokenDevice.getModel() + " - " + brokenDevice.getPrice() );

        Device device = new Device( brokenDevice.getBrand(), brokenDevice.getModel(), brokenDevice.getPrice() );
        brokenDevices.remove( brokenDevices.indexOf( brokenDevice ) );
        devices.add(device);
    }

    public void PrintDevicesWithSymptoms( String symptoms )
    {
        System.out.println("These are the broken devices with such symptoms: " + symptoms );
        for( BrokenDevice brokenDevice : brokenDevices )
        {
            if( brokenDevice.getSymptoms().equalsIgnoreCase( symptoms ) )
            {
                System.out.println( brokenDevice.getBrand() + " - " + brokenDevice.getModel() + " - " + brokenDevice.getPrice() + " - " + brokenDevice.getSymptoms() + " - " + brokenDevice.getRecoveryDueDays() );
            }
        }
    }

    public void CalculateTotalPrice()
    {
        double totalPrice = 0;

        for( Device device : devices )
        {
            totalPrice += device.getPrice();
        }

        for( BrokenDevice brokenDevice : brokenDevices )
        {
            totalPrice += brokenDevice.getPrice();
        }
        
        System.out.println( "TOTAL price of all devices: " + totalPrice );
    }

    public void CalculateRevoceryIncome()
    {
        double recoveryIncome = 0;

        for( BrokenDevice brokenDevice : brokenDevices )
        {
            recoveryIncome += brokenDevice.getPrice() * brokenDevice.getRecoveryDueDays();
        }

        System.out.println( "Total broken device recovery income: " + recoveryIncome );
    }

    public void SaveToFile()
    {
        for( Device device : devices )
        {
            try( ObjectOutputStream out = new ObjectOutputStream( new FileOutputStream( "healthy_devices.txt" ) ) )
            {
                out.writeObject( device );
                out.flush();
                out.close();
            }
            catch( IOException exception )
            {
                System.out.println( "Serialization error: " + exception.getMessage() );
                return;
            }
        }

        for( Device brokenDevice : brokenDevices )
        {
            try( ObjectOutputStream out = new ObjectOutputStream( new FileOutputStream( "broken_devices.txt" ) ) )
            {
                out.writeObject( brokenDevice );
                out.flush();
                out.close();
            }
            catch( IOException exception )
            {
                System.out.println( "Serialization error: " + exception.getMessage() );
                return;
            }
        }
    }
}