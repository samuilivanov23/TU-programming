#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct name {
    char *first_name;
    char *middle_name;
    char *last_name;
};

struct student {
    struct name name;
    char specialty[30];
    double grade;
    int age;
    char gender[10];
};

void InputStudent(struct student students[], int number);
void ShowInfo(struct student students[], int number);
void ShowExcellentScore(struct student students[], int number);
void CheckGrades(struct student students[], int number);

int main(){
    int number;
    printf("Enter number of students: ");
    scanf("%d", &number);

    struct student *students = malloc(sizeof(struct student) * number);

    InputStudent(students, number);
    ShowInfo(students, number);
    printf("\n\n");
    ShowExcellentScore(students, number);
    printf("\n\n");
    CheckGrades(students, number);

    for(int i = 0; i < number; i++)
    {
        free(students[i].name.first_name);
        free(students[i].name.middle_name);
        free(students[i].name.last_name);
    }

    free(students);
    return 0;
}

void InputStudent(struct student students[], int number)
{
    for(int i = 0; i < number; i++)
    {
        printf("Enter first name: ");
        students[i].name.first_name = malloc(sizeof(struct name) * 30);
        scanf("%s", students[i].name.first_name);

        printf("Enter middle name: ");
        students[i].name.middle_name = malloc(sizeof(struct name) * 30);
        scanf("%s", students[i].name.middle_name);

        printf("Enter last name: ");
        students[i].name.last_name = malloc(sizeof(struct name) * 30);
        scanf("%s", students[i].name.last_name);

        printf("Enter student specialty: ");
        scanf("%s", students[i].specialty);

        printf("Enter student grades: ");
        scanf("%lf", &students[i].grade);

        printf("Enter student age: ");
        scanf("%d", &students[i].age);

        printf("Enter student gender: ");
        scanf("%s", students[i].gender);
    }
}

void ShowInfo(struct student students[], int number)
{
    for(int i = 0; i < number; i++)
    {
        if(students[i].grade < 4.5)
        {
            printf("Student info: \n");
            printf("First name: %s, Middle name: %s, Last name: %s, Specialty: %s, Grade: %lf, Age: %d, Gender: %s", students[i].name.first_name, 
                                                                                                                     students[i].name.first_name, 
                                                                                                                     students[i].name.first_name, 
                                                                                                                     students[i].specialty, 
                                                                                                                     students[i].grade, 
                                                                                                                     students[i].age, 
                                                                                                                     students[i].gender);
            printf("\n");
        }
    }
}

void ShowExcellentScore(struct student students[], int number)
{
    for(int i = 0; i < number; i++)
    {
        if(students[i].grade >= 5.5 && students[i].age < 22)
        {
            printf("Excellent Student info: \n");
            printf("First name: %s, Middle name: %s, Last name: %s, Specialty: %s, Grade: %lf, Age: %d, Gender: %s", students[i].name.first_name, 
                                                                                                                     students[i].name.first_name, 
                                                                                                                     students[i].name.first_name, 
                                                                                                                     students[i].specialty, 
                                                                                                                     students[i].grade, 
                                                                                                                     students[i].age, 
                                                                                                                     students[i].gender);
            printf("\n");
        }
    }
}

void CheckGrades(struct student students[], int number)
{
    double male_grades = 0;
    double female_grades = 0;
    int males = 0;
    int females = 0;

    for(int i = 0; i < number; i++)
    {
        if(!strcmp("male", students[i].gender))
        {
            males++;
            male_grades += students[i].grade;
        }
        else if(!strcmp("female", students[i].gender))
        {
            females++;
            female_grades += students[i].grade;
        }
    }

    male_grades /= males;
    female_grades /= females;

    if( male_grades > female_grades )
    {
        printf("Males have a higher average grade (%lf)\n", male_grades);
    }

    else if( male_grades < female_grades )
    {
        printf("Females have a higher average grade (%lf)\n", female_grades);
    }

    else
    {
        printf("Both genders have the same average grade\n");
    }
}