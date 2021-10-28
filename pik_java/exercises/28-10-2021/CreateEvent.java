public class CreateEvent
{
    private String typeOfEvent;

    public Competition GetEvent(String competitionType) throws EventException
    {
        typeOfEvent = competitionType;
        if (typeOfEvent.equals("FootballCompetition"))
        {
            return new FootballCompetition();
        }
        else if (typeOfEvent.equals("HorseCompetition"))
        {
            return new HorseCompetition();
        }
        else if (typeOfEvent.equals("Formula1Competition"))
        {
            return new Formula1Competition();
        }
        else
        {
            throw new EventException();
        }
    }

    public void FillSchedule(Competition ob, Participant[] schedule) throws EmptySetException
    {
        if(schedule == null || schedule.length == 0)
        {
            throw new EmptySetException();
        }

        switch(this.typeOfEvent)
        {
            case "FootballCompetition" : ((FootballCompetition) ob).schedule = schedule; break;
            case "HorseCompetition"    : ((HorseCompetition) ob).schedule = schedule; break;
            case "Formula1Competition" : ((Formula1Competition) ob).schedule = schedule; break;
        }
    }

    public static void Bets(Competition ob, int id, double bet)
    {
        Participant[] participants = ob.GetSchedule();
        
        for(Participant participant: participants)
        {
            if(participant.id == id)
            {
                System.out.println("initial chanceToWin: " + participant.chanceToWin);

                double coefficient = (participant.betForWin + bet) / participant.betForWin;
                participant.chanceToWin -= coefficient;
                if(participant.chanceToWin < 1.1) participant.chanceToWin = 1.1;
                
                System.out.println("result chanceToWin: " + participant.chanceToWin);
            }
        }
    }
}