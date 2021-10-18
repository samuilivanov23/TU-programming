class StartUp
{
    public static void main( String args[] )
    {
        Rectangle rectangle = new Rectangle();
        Triangle triangle = new Triangle();

        System.out.println( "Rectangle area: " + rectangle.CalculateArea( 10 ,5 ) );
        System.out.println( "Triangle area: " + triangle.CalculateArea( 10 ,5 ) );
    }
}