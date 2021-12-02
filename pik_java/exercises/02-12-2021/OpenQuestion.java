class OpenQuestion extends Question
{
    public String correctAnswer;

    public OpenQuestion( String correctAnswer, String question )
    {
        super( question );
        this.correctAnswer = correctAnswer;
    }

    public boolean CheckQuestion( String answer )
    {
        if ( correctAnswer.equals( answer ) ) { return true; }
        else { return false; }
    }
}