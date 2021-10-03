#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LEN 30

struct Student
{
  unsigned int faculty_number;
  char name[LEN];
  float avg_mark;
};


struct Student InputStudent();
void PrintStudent(struct Student student);
struct Student InputStudentFromCSV(File *file_stream); 

int main()
{
  struct Student student1 = InputStudent();
  
  PrintStudent(student1);
  
  return 0;
}

struct Student InputStudent()
{
  struct Student student;

  printf("faculty number: ");
  scanf("%u", &student.faculty_number);

  getchar();
  printf("student's name: ");
  fgets(student.name, LEN, stdin);
  
  if(strlen(student.name) < LEN - 1)
  {
    student.name[strlen(student.name) - 1] = '\0';
  }

  printf("average mark: ");
  scanf("%f", &student.avg_mark);

  return student;
}

void PrintStudent(struct Student student)
{
  printf("[%u, %s, %g]\n", student.faculty_number, student.name, student.avg_mark);
}


struct Student InputStudentFromCSV(File *file_stream)
{
  
} 

