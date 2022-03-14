import java.util.Scanner;

class StartUp
{
	public static void main( String args[] )
	{
        Person person1 = new Person();
        Person person2 = new Person( "Samuil Ivanov", "01" );

        person1.setName( "Adam Nagaitis" );
        System.out.println( person1.getName() );
        System.out.println( person2.getName() );

        Student student1 = new Student( "Samuil Ivanov", "01", "121220011" );
        student1.PrintFnum();
        student1.SayHello(); //works this way also but the line below is the right way to call static method
        Student.SayHello(); //static method

        Teacher teacher1 = new Teacher();
        teacher1.setName("Name1");
        teacher1.subject.setName("subject1");

        Teacher teacher2 = new Teacher();
        teacher2.setName("Name2");
        teacher2.subject.setName("subject2");

        Teacher teacher3 = new Teacher();
        teacher3.setName("Name3");
        teacher3.subject.setName("subject3");

        Teacher teacher4 = new Teacher();
        teacher4.setName("Name4");
        teacher4.subject.setName("subject4");

        Teacher teacher5 = new Teacher();
        teacher5.setName("Name5");
        teacher5.subject.setName("subject5");

        Teacher teachers[] = {teacher1, teacher2, teacher3, teacher4, teacher5};

        for(Teacher teacher: teachers)
        {
            System.out.println(teacher.getName());
            System.out.println(teacher.subject.getName());
            System.out.println("------------------------------");
        }
	}
}

class Person
{
    private String name;
    private String age;

    public Person()
    {
        this.name = " ";
        this.age = " ";
    }

    public Person( String name, String age )
    {
        this.name = name;
        this.age = age;
    }

    public String getName() { return this.name; };
    public void setName( String name ) { this.name = name; };

    public String getAge() { return this.age; };
    public void setAge( String age ) { this.age = age; };
}

class Student extends Person
{
    private String fNum;

    public Student()
    {
        super();
        this.fNum = " ";
    }

    public Student( String name, String age, String fNum )
    {
        super( name, age );
        this.fNum = fNum;
    }

    public String getFnum() { return this.fNum; };
    public void setFnum( String fNum ) { this.fNum = fNum; };

    public static void SayHello()
    {
        System.out.println( "Hello" );
    }
    
    public void PrintFnum()
    {
        System.out.println( this.fNum );
    }
}

class Subject
{
    private String name;

    public Subject()
    {
        super();
        this.name = " ";
    }

    public Subject(String name)
    {
        this.name = name;
    }

    public String getName() { return this.name; };
    public void setName( String name ) { this.name = name; };
}

class Teacher extends Person
{
    Subject subject;

    public Teacher()
    {
        this.subject = new Subject();
    }

    public Teacher(String name, String age, Subject subject)
    {
        super(name, age);
        this.subject = new Subject();
        this.subject.setName(subject.getName());
    }
}