import java.util.Scanner;

class StartUp
{
	public static void main(String args[])
	{
		Scanner scanner = new Scanner(System.in);
		PrintIntroduction();

		System.out.println("Enter id: ");
		int id = Integer.parseInt(scanner.nextLine());

		double bmi = GetBMI(scanner);
		String status = GetStatus(bmi);
		ReportStatus(bmi, id, status);
	}

	private static void PrintIntroduction()
	{
		System.out.println("Program calculating body mass index.");
	}

	private static double GetBMI(Scanner scanner)
	{
		System.out.println("Enter height [inches]: ");
		double height = Double.parseDouble(scanner.nextLine());

		System.out.println("Enter your weight [lbs]: ");
		double weight = Double.parseDouble(scanner.nextLine());

		return BmiFor(weight, height);
	}

	private static double BmiFor(double weight, double height)
	{
		return (weight * 703) / (height * height);
	}

	private static String GetStatus(double bmi)
	{
		if(bmi <= 18.5)
		{
			return "underweight";
		}
		else if (bmi > 18.5 && bmi <= 25) 
		{
			return "normal";
		}
		else if (bmi > 25 && bmi <= 30) 
		{
			return "overweight";
		}
		else 
		{
			return "obese";
		}
	}

	private static void ReportStatus(double bmi, int id, String status)
	{
		System.out.println("id: " + id + " with bmi: " + (Math.round(bmi*100.0)/100.0) + " is: " + status);	
	}
}