public class Formula1Competition implements Competition
{
    private double winnersTime;
    Participant[] schedule;

    @Override
    public Participant[] GetSchedule()
    {
        return this.schedule;
    }
}