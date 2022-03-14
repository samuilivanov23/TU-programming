import java.util.ArrayList;
import java.util.Collections;

class Test
{
    public static void main( String args[] )
    {
        ArrayList<Question> questions = new ArrayList<Question>();
        Shuffle( questions );
        PerformTest( questions );
    }

    public static void PerformTest( ArrayList<Question> questions )
    {
        questions.add( new IntegerQuestion( 10, "What is the product of 5 and 2?" ) );
        questions.add( new IntegerQuestion( 15, "What is the product of 5 and 3?" ) );
        questions.add( new IntegerQuestion( 20, "What is the product of 5 and 4?" ) );
        questions.add( new IntegerQuestion( 25, "What is the product of 5 and 5?" ) );
        questions.add( new IntegerQuestion( 30, "What is the product of 5 and 6?" ) );

        questions.add( new OpenQuestion( "Vihren", "Which is the tallest peak in Pirin mountain?" ) );
        questions.add( new OpenQuestion( "Vihren", "Which is the tallest peak in Pirin mountain?" ) );
        questions.add( new OpenQuestion( "Vihren", "Which is the tallest peak in Pirin mountain?" ) );
        questions.add( new OpenQuestion( "Vihren", "Which is the tallest peak in Pirin mountain?" ) );
        questions.add( new OpenQuestion( "Vihren", "Which is the tallest peak in Pirin mountain?" ) );

        System.out.println( ( ( IntegerQuestion ) questions.get( 0 ) ).CheckQuestion( 10 ) );
        System.out.println( ( ( IntegerQuestion ) questions.get( 0 ) ).CheckQuestion( 20 ) );
        System.out.println( ( ( IntegerQuestion ) questions.get( 1 ) ).CheckQuestion( 15 ) );
        System.out.println( ( ( IntegerQuestion ) questions.get( 1 ) ).CheckQuestion( 20 ) );

        System.out.println( ( ( OpenQuestion ) questions.get( questions.size() -1 ) ).CheckQuestion( "Vihren" ) );
        System.out.println( ( ( OpenQuestion ) questions.get( questions.size() -1 ) ).CheckQuestion( "Kamenitsa" ) );
        System.out.println( ( ( OpenQuestion ) questions.get( questions.size() -1 ) ).CheckQuestion( "Todorka" ) );
    }

    public static void Shuffle( ArrayList<Question> questions )
    {
        Collections.shuffle( questions );
    }
}