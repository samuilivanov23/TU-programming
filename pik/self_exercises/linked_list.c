#include <stdio.h>
#include <stdlib.h>

// The structure for a single Node
typedef struct Node_Struct Node; 
struct Node_Struct{
  int index;
  int data;
  Node *next;
  Node *previous;
};

void PrintList(Node *head);

int main(){
  Node *head = NULL;
  Node *second = NULL;
  Node *third = NULL;
  
  printf("Size of Node: %ld\n", sizeof(Node));

  head = (Node*)malloc(sizeof(Node));
  second = (Node*)malloc(sizeof(Node));
  third = (Node*)malloc(sizeof(Node));
  
  //Initialize the head. Set the head to point to the second Node. Set the previous Node to NULL.
  head->index = 0;
  head->data = 15;
  head->previous = NULL;
  head->next = second;
  
  //Initialize the second Node. Set it to point to the third Node. Set the previous Node to point to the head.
  second->index = 1;
  second->data = 20;
  second->previous = head;
  second->next = third;
  
  //Initialize the third Node. Set it to point to NULL because its the last Node in the list. Set the previous node to point to the second.
  third->index = 2;
  third->data = 25;
  third->previous = second;
  third->next = NULL;
  
  PrintList(head); 
  
  free(head);
  free(second);
  free(third);
  return 0;
}

void PrintList(Node *head){
  while(head!=NULL){
    printf("%d: %d\n", head->index, head->data);
    head = head->next;
  }
}
