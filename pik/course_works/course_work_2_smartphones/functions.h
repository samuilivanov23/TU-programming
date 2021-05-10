typedef struct Smartphone_Struct Smartphone;
struct Smartphone_Struct {
  char nomenclature_number[12];
  char model[20];
  double price;
  unsigned int quantity;
};

typedef struct Node_Struct Node;
struct Node_Struct {
  Smartphone smartphone;
  Node *next;
};

Node *NewItem();
void FreeList( Node *head );
void PrintList( Node *head );
void AddQuantity( Node *head );
Node *BuySmartphone( Node *head );
char *RemoveTrailingNL( char *string );
void PrintData( Smartphone smartphone );
void PrintSpecificSmartphone( Node *head );
Node *AddSmartphoneToShop( Node *head, Node *new );
void SaveDataToFile( Node *head, char *file_path );
Node *InitializeList( Node *head, char *file_path );
Node *RemoveSmartphone( Node *head, char *nomenclature_number );
