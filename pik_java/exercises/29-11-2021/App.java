import java.util.ArrayList;

class App
{
    public static void main( String args[] )
    {
        PresentStore presentStore = new PresentStore();

        presentStore.products.add( new Product( 15.99, "naitisov", 1, 99 ) );
        presentStore.products.add( new Product( 17.99, "sezgo", 2, 100 ) );
        presentStore.products.add( new Product( 19.99, "bedov", 3, 100 ) );

        presentStore.devApi.add( new Product( 15.99, "naitisov", 1, 99 ) );
        presentStore.devApi.add( new Product( 17.99, "sezgo", 2, 100 ) );
        presentStore.devApi.add( new Product( 19.99, "bedov", 3, 100 ) );

        ArrayList<GetProductsTo> products = presentStore.GetLowerPriceProducts( 19.99 );
        ArrayList<DeliveryAPI> devApi = presentStore.GetAllProviderProducts( 100 );

        for( GetProductsTo product : products )
        {
            System.out.println( product.getPrice() + " : " + product.getType() );
        }

        for( DeliveryAPI product : devApi )
        {
            System.out.println( product.getNumber( product.getIdOfProvider() ) + " : " + product.getType( product.getIdOfProvider() ) + " : " + product.getIdOfProvider() );
        }
    }
}