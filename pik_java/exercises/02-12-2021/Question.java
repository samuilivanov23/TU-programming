class Question
{
    private String question;

    public Question( String question )
    {
        this.question = question;
    }

    public String getQuestion() { return this.question; }
    public void setQuestion( String question ) { this.question = question; }

    public void AskQuestion()
    {
        System.out.println( this.question );
    }
}