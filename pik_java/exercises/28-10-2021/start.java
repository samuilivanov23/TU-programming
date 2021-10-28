import java.util.Scanner;

class StartUp
{
    public static void main(String[] args)
    {
        Scanner scanner = new Scanner(System.in);
        CreateEvent createEvent = new CreateEvent();

        System.out.print("Enter competition type: ");
        String competitionType = scanner.nextLine();
        Competition competition = null;

        try
        {
            competition = createEvent.GetEvent(competitionType);
        }
        catch (EventException e)
        {
            System.out.println(e.getMessage());
            System.exit(1);
        }

        Participant[] participants = new Participant[2];
        for(int i = 0; i < participants.length; i++)
        {
            participants[i] = new Participant();
            participants[i].id = scanner.nextInt();
            scanner.nextLine();
            participants[i].name = scanner.nextLine();
            participants[i].age = scanner.nextInt();
            participants[i].betForWin = scanner.nextDouble();
            participants[i].chanceToWin = scanner.nextDouble();
        }

        try
        {
            createEvent.FillSchedule(competition, participants);
        }
        catch (EmptySetException e)
        {
            System.out.println(e.getMessage());
            System.exit(1);
        }

        System.out.println("Enter id to recalculate chanceToWin coefficient: ");
        int id = scanner.nextInt();
        createEvent.Bets(competition, id, 10.0);
    }
}