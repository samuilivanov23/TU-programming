public class EventException extends Exception
{
    @Override
    public String getMessage()
    {
        return "Invalid event type! Enter one of these: FootballCompetition, HorseCompetition, Formula1Competition";
    }
}