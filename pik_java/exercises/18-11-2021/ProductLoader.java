import java.io.*;

class ProductLoader implements ImportData
{
    Object[] ImportDataFromFile()
    {
        numberOfRows = GetNumberOfRows();
        Product[] products = new Product[numberOfRows];
        List<Book> books = new List<Book>();
        List<Electronics> electronics = new List<Electronics>();
        BufferedReader buffer = null;

        try
        {
            String currentLine;
            buffer = new BufferedReader( new FileReader( "salesproducts.txt" ) );
            while( ( currentLine = buffer.readLine() ) != null )
            {
                String[] args = currentLine.split("#");
                if( args[0].equals( "1" ) )
                {
                    
                    Electronics currentElectronics = new Electronics(args[6], args[7], args[3], args[4], args[5], new Provider( args[1], args[2] ) );
                    electronics.add();
                }

                if( args[0].equals( "2" ) )
                {
                    Book currentBook = new Book(args[6], args[7], args[3], args[4], args[5], new Provider( args[1], args[2] ) );
                    books.add();
                }
            }

            int i = 0;
            for( Electronics tmpElectronics : electronics )
            {
                products[i] = tmpElectronics;
                i++;
            }
            for( Book tmpBook : books )
            {
                products[i] = tmpBook;
                i++;
            }

            return products;
        }
        catch( IOException e )
        {
            e.printStackTrace();
        }
        finally
        {
            try
            {
                if( buffer != null ) buffer.close();
            }
            catch( IOException e )
            {
                e.printStackTrace();
            }
        }

        return numberOfRows;  
    } 
    }

    private int GetNumberOfRows() throws IOException
    {
        int numberOfRows = 0;
        BufferedReader buffer = null;

        try
        {
            String currentLine;
            buffer = new BufferedReader( new FileReader( "salesproducts.txt" ) );
            while( ( currentLine = buffer.readLine() ) != null )
            {
                numberOfRows++;
            }
        }
        catch( IOException e )
        {
            e.printStackTrace();
        }
        finally
        {
            try
            {
                if( buffer != null ) buffer.close();
            }
            catch( IOException e )
            {
                e.printStackTrace();
            }
        }

        return numberOfRows;  
    } 
}