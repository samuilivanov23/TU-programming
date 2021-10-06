import java.util.Scanner;

class StartUp
{
	public static void main(String args[])
	{
		Scanner scanner = new Scanner(System.in);
		PrintIntroduction();
		double bmi = GetBMI(scanner);

		System.out.println(GetStatus(bmi));
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
}