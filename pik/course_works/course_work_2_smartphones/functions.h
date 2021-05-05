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

Node *InitializeList( Node *head, char *file_path );
Node *NewItem();
Node *AddSmartphoneToShop( Node *head, Node *new );
Node *BuySmartphone( Node *head );
void AddQuantity( Node *head );
Node *RemoveSmartphone( Node *head, char *nomenclature_number );
void PrintList( Node *head );
void PrintData( Smartphone smartphone );
void PrintSpecificSmartphone( Node *head );
void SaveDataToFile( Node *head, char *file_path );
void FreeList( Node *head );
char *RemoveTrailingNL( char *string );
