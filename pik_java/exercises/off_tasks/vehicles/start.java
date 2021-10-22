class StartUp
{
    public static void main( String args[] )
    {
        Car car = new Car( 400, "test model1", 3000000, 1600 );
        HoverCraft hoverCraft = new HoverCraft( 140, "test model2", 80000, 7);
        Ship ship = new Ship( 200, "test model3", 100000, 6000 );

        car.EnterLand();
        System.out.println( "car promo: " + car.CheckPromo() );

        hoverCraft.EnterSea();
        System.out.println( "hovercraft promo: " + hoverCraft.CheckPromo() );

        ship.EnterSea();
        System.out.println( "ship promo: " + ship.CheckPromo() );
    }
}