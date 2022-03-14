import java.util.Scanner;

class StartUp
{
    public static void main(String[] args)
    {
        String text = "Text test";
        PrintName(text);
    }

    public static void PrintName(String s)
    {
        System.out.println(s);
    }

    public int testMethod(int x) { return x; }

    public void testMethod(int i, int j) { }

    private static void PrintIntroduction()
    {
        System.out.println("BMI calculator");
    }

    private static double GetBMI(Scanner scanner)
    {
        System.out.prinln("Enter weight");
        double weight = Double.parseDouble(scanner.nextLine());

        System.out.prinln("Enter weight");
        double height = Double.parseDouble(scanner.nextLine());
    }

    private static double BmiFor(double weight, double height)
    {

    }

    private static String GetStatus(double bmi)
    {
        if()
        {
            return "underweight";
        }
        else if()
        {
            return "normal";
        }
        else if()
        {
            return "overweight";
        }
        else
        {
            return "obese";
        }
    }
}
