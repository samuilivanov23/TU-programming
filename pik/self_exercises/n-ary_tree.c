#include <stdio.h>
#include <stdlib.h>

//The structure for Node entity
typedef struct Node_Struct Node;
struct Node_Struct 
{
  int data;
  unsigned int number_children;
  Node **childs;
};

int TraverseTree(Node *root); 
int isPrinted(int printed_nums[], int num, unsigned int length);

int main()
{
  int number_nodes = 3; //from task description/picture
  //printf("%ld\n", sizeof(Node**));
  Node **tree = (Node**)malloc(sizeof(Node) * number_nodes);

  //root
  tree[0] = (Node*)malloc(sizeof(Node));
  tree[0]->data = 1;
  tree[0]->number_children = 2;
  tree[0]->childs = (Node**)malloc(sizeof(Node)*2); // using 2 (number of childs) for testing purposes only;
   
  //allocate memory for children
  tree[0]->childs[0] = (Node*)malloc(sizeof(Node));
  tree[0]->childs[1] = (Node*)malloc(sizeof(Node));

  //first child
  tree[0]->childs[0]->data = 2;
  tree[0]->childs[0]->number_children = 3;
  tree[0]->childs[0]->childs = (Node **)malloc(sizeof(Node)*3);
  
  tree[0]->childs[0]->childs[0] = (Node *)malloc(sizeof(Node));
  tree[0]->childs[0]->childs[1] = (Node *)malloc(sizeof(Node));
  tree[0]->childs[0]->childs[2] = (Node *)malloc(sizeof(Node));
  
  tree[0]->childs[0]->childs[0]->data = 4;
  tree[0]->childs[0]->childs[0]->number_children = 0;
  tree[0]->childs[0]->childs[0]->childs = NULL;

  tree[0]->childs[0]->childs[1]->data = 5;
  tree[0]->childs[0]->childs[1]->number_children = 0;
  tree[0]->childs[0]->childs[1]->childs = NULL;

  tree[0]->childs[0]->childs[2]->data = 6;
  tree[0]->childs[0]->childs[2]->number_children = 0;
  tree[0]->childs[0]->childs[2]->childs = NULL;
 
  //second child  
  tree[0]->childs[1]->data = 3;
  tree[0]->childs[1]->number_children = 2;
  tree[0]->childs[1]->childs = (Node **)malloc(sizeof(Node)*2);
  
  tree[0]->childs[1]->childs[0] = (Node *)malloc(sizeof(Node));
  tree[0]->childs[1]->childs[1] = (Node *)malloc(sizeof(Node));

  tree[0]->childs[1]->childs[0]->data = 7;
  tree[0]->childs[1]->childs[0]->number_children = 0;
  tree[0]->childs[1]->childs[0]->childs = NULL;

  tree[0]->childs[1]->childs[1]->data = 8;
  tree[0]->childs[1]->childs[1]->number_children = 0;
  tree[0]->childs[1]->childs[1]->childs = NULL;


  TraverseTree(tree[0]);

  //Node *current_node = tree[0];
  //while(current_node->childs != NULL)
  //{
  //  printf("%d\n", current_node->data);
  //  int i = 0;
  //  while(current_node->childs[i] != NULL)
  //  {
  //    printf("%d\n", current_node->childs[i]->data);
  //    i++;
  //  }
    
  // current_node = current_node->childs[0];
  //}

  free(tree[0]->childs[0]->childs[0]);
  free(tree[0]->childs[0]->childs[1]);
  free(tree[0]->childs[0]->childs[2]);
  free(tree[0]->childs[0]->childs);

  free(tree[0]->childs[1]->childs[0]);
  free(tree[0]->childs[1]->childs[1]);
  free(tree[0]->childs[1]->childs);

  free(tree[0]->childs[0]);
  free(tree[0]->childs[1]);
  free(tree[0]->childs);
  free(tree[0]);
  free(tree);
  return 0;
}

int TraverseTree(Node *root)
{
  if(root->number_children <= 0)
  {
    printf("%d\n", root->data);
    return 0;
  }

  for (int i = 0; i < root->number_children; i++)
  {
    if(i == 0)
    {
      printf("%d\n", root->data);
    }
    TraverseTree(root->childs[i]);
  }
}
