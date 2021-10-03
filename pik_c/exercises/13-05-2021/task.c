#include <stdio.h>
#include <stdlib.h>

typedef struct Employee Employee;
struct Employee
{
    char name[30];
    double salary;
    char gender;
};

typedef struct Node Node;
struct Node
{
    Employee employee;
    struct Node *next;
};

Node *NewItem();
Node *CreateList();
Node *HigherThanMax( Node *head );
Node *DeleteEmployee( Node *head );
double FemaleSalarySum( Node *head );
void FreeList( Node *head, Node *head2 );
void WriteToFile( Node *head, char fname[] );

int main()
{
    Node *head = NULL;
    head = CreateList();
    WriteToFile( head, "employees" );

    printf( "Sum of female salaries: %lf\n", FemaleSalarySum( head ) );

    Node *new_head = NULL;
    new_head = HigherThanMax( head );
    head = DeleteEmployee( head );

    FreeList( head, new_head );
    return 0;
}

Node *NewItem(){
    Node *result = NULL;
    result = ( Node* )malloc( sizeof( Node ) );
    Employee employee;

    printf( "Enter employee name: ");
    scanf( "%s", employee.name );
    printf( "Enter employee salary: " );
    scanf( "%lf", &employee.salary );
    getc( stdin );
    printf( "Enter employee gender: " );
    scanf( "%c", &employee.gender );

    result->employee = employee;
    result->next = NULL;

    return result;
}

Node *CreateList(){
    int employees_count;
    printf( "Enter employees count: " );
    scanf( "%d", &employees_count );

    Node *head = NULL;
    Node *last = NULL;

    for( int i = 0; i < employees_count; i++ )
    {
        if( head == NULL )
        {
            head = NewItem();
            last = head;
        }
        else
        {
            last->next = NewItem();
            last = last->next;
        }
    }

    return head;
}

void WriteToFile( Node *head, char fname[] )
{
    Node *current = head;
    FILE *file_stream;

    if( ( file_stream = fopen( fname, "wb" ) ) == NULL )
    {
        printf( "Error when opening file!" );
        exit( 1 );
    }

    while( current != NULL )
    {
        fwrite( &current->employee, sizeof( Employee ), 1, file_stream );
        current = current->next;
    }

    fclose( file_stream );
}

double FemaleSalarySum( Node *head )
{
    Node *current = head;
    double salary_sum = 0;

    while( current != NULL )
    {
        if( current->employee.gender == 'f' && current->employee.name[0] > 'M' )
        {
            salary_sum += current->employee.salary;
        }
        current = current->next;        
    }

    return salary_sum;
}

Node *HigherThanMax( Node *head )
{
    Node *current = head;
    double max_salary = current->employee.salary;
    current = current->next;

    while( current != NULL )
    {
        if( current->employee.salary > max_salary )
        {
            max_salary += current->employee.salary;
        }
        current = current->next;        
    }

    Node *new_head = NULL, *item = NULL;
    current = head;
    
    while( current != NULL )
    {
        if( current->employee.salary > max_salary / 2 )
        {
            item = ( Node * )malloc( sizeof( Node ) );
            item->employee = current->employee;
            item->next = new_head; 
            new_head = item;
        }
        current = current->next;        
    }

    return new_head;
}

Node *DeleteEmployee( Node *head )
{
    while ( head && head->employee.name[0] == 'A' )
    {   
        head = head->next;
        free( head );
    }

    Node* current;
    for( current = head; current != NULL; current = current->next )
    {
        while( current->next != NULL && current->employee.name[0] == 'A' )
        {
            Node *temp = current->next;
            current->next = temp->next;
            free( temp );
        }
    }

    free( current );

    return head;
}

void FreeList( Node *head, Node *head2 )
{
    Node *current = head;
    while( head != NULL )
    {
        head = head->next;
        free( current );
        current = head;
    }

    current = head2;
    while( head2 != NULL )
    {
        head2 = head2->next;
        free( current );
        current = head2;
    }
}