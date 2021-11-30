import java.util.ArrayList;

class PresentStore
{
    public ArrayList<GetProductsTo> products;
    public ArrayList<DeliveryAPI> devApi;

    public PresentStore()
    {
        products = new ArrayList<GetProductsTo>();
        devApi = new ArrayList<DeliveryAPI>();
    }

    public PresentStore( ArrayList<GetProductsTo> products, ArrayList<DeliveryAPI> devApi )
    {
        this.products = products;
        this.devApi = devApi;
    }

    public ArrayList<GetProductsTo> GetLowerPriceProducts( double maxPresentPrice )
    {
        ArrayList<GetProductsTo> resultList = new ArrayList<GetProductsTo>();

        for( GetProductsTo product : products )
        {
            if( product.getPrice() < maxPresentPrice )
            {
                resultList.add(product);
            }
        }

        return resultList;
    }

    public ArrayList<DeliveryAPI> GetAllProviderProducts( int IdOfProvider )
    {
        ArrayList<DeliveryAPI> resultList = new ArrayList<DeliveryAPI>();

        for( DeliveryAPI product : devApi )
        {
            if( product.getIdOfProvider() == IdOfProvider )
            {
                resultList.add(product);
            }
        }

        return resultList;
    }
}