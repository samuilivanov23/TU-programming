class IntegerQuestion extends Question
{
    public int correctAnswer;

    public IntegerQuestion( int correctAnswer, String question )
    {
        super( question );
        this.correctAnswer = correctAnswer;
    }

    public boolean CheckQuestion( int answer )
    {
        if ( correctAnswer == answer ) { return true; }
        else { return false; }
    }
}