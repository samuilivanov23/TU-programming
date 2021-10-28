public class HorseCompetition implements Competition
{
    private String breed;
    Participant[] schedule;

    @Override
    public Participant[] GetSchedule()
    {
        return this.schedule;
    }
}