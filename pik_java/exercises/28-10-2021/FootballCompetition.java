public class FootballCompetition implements Competition
{
    private int fastestGoal;
    Participant[] schedule;

    @Override
    public Participant[] GetSchedule()
    {
        return this.schedule;
    }
}