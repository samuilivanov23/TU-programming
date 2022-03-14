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

void InitializeNode(Node **node, int index, int data, Node *previous, Node *next);
void PrintList(Node *head);
void FindItem(Node *head, int index, Node **result_node);

int main(){
  int num_nodes;
  printf("Enter number of nodes: ");
  scanf("%d", &num_nodes);
  Node **nodes = (Node**)malloc(sizeof(Node)*num_nodes);
  
  int i=0;
  while(i < num_nodes){
    int data;
    printf("Input data for node: ");
    scanf("%d", &data);
    nodes[i] = (Node*)malloc(sizeof(Node));
    InitializeNode(&nodes[i], i, data, NULL, NULL);
    i++;
  }

  i = 0;
  while(i < num_nodes){
    printf("%d node: %d\n", i, nodes[i]->data);
    i++;
  }


  i = 0;
  while(i < num_nodes){
    free(nodes[i]);
    i++;
  }
  free(nodes);

  // //Create and initialize nodes
  // Node *head =   (Node*)malloc(sizeof(Node));
  // Node *second = (Node*)malloc(sizeof(Node));
  // Node *third =  (Node*)malloc(sizeof(Node));
  // InitializeNode(&head, 0, 15, NULL, second);
  // InitializeNode(&second, 1, 20, head, third);
  // InitializeNode(&third, 2, 25, second, NULL);
  
  // //Print the list
  // PrintList(head);

  // //Find the Node by associated whith the given index
  // Node *result_node = NULL;
  // FindItem(head, 2, &result_node);

  // if(!(result_node == NULL)){
  //   printf("result_node data: %d\n", result_node->data);
  // }
  // else{
  //   printf("Item not found\n");
  // }

  // //Free the allocated memory and exit the program
  // free(head);
  // free(second);
  // free(third);
  return 0;
}

void InitializeNode(Node **node, int index, int data, Node *previous, Node *next){
  (*node)->index = index;
  (*node)->data = data;
  (*node)->previous = previous;
  (*node)->next = next;
}

void PrintList(Node *head){
  while(head != NULL){
    printf("%d: %d\n", head->index, head->data);
    head = head->next;
  }
}

void FindItem(Node *head, int index, Node **result){ 
  while(head != NULL){
    printf("head: %p\n", head);
    if(head->index == index){
      printf("index: %d\n", head->index);
      (*result) = head;
      printf("head_data: %d\n", head->data);
      printf("result_data: %d\n", (*result)->data);
    }
    head = head->next;
  }
}














