#include "estruturas.h"

char* tokens[] = {"Program", "FieldDecl", "VarDecl", "MethodDecl", "MethodHeader", "MethodParams", "ParamDecl",
                  "MethodBody", "StringArray", "Block", "DoWhile", "If", "Print", "Return", "While", "Assign", "Call",
                  "ParseArgs", "Or", "And", "Eq", "Neq", "Lt", "Gt", "Leq", "Geq", "Add", "Sub", "Mul", "Div", "Mod", "Not", "Minus",
                  "Plus", "Length", "Bool", "BoolLit", "Double", "DecLit", "Id", "Int", "RealLit", "StrLit", "Void","Null"};


/*Create Node*/
Node* createNode(NodeType node_type, char* token, Node* son, Node* brother){
  Node* node = malloc(sizeof(Node));
  node->node_type = node_type;
  if (token != NULL) {
    node->token = strdup(token);
  } else {
    node->token = NULL;
  }
  node->son = son;
  node->brother = brother;
  return node;
}

void insertSon(Node* n, Node* son )
{
  if(!is_null(n))
  {
    if(n->son == NULL)
    {
      n->son = son;
    }
    else{
      insertSon(n->son,son);
    }
  }
}
/*Delete Node*/
void deleteNode(Node* this) {
  if (this == NULL) {
    return;
  }

  deleteNode(this->son);
  deleteNode(this->brother);

  free(this->token);
  if (this->son != NULL) {
    free(this->son);
  }
  if (this->brother != NULL) {
    free(this->brother);
  }
}

/*Insert brother*/
void insertBrother(Node* this, Node* brother) {
  if (this != NULL) {
    while (this->brother != NULL) {
      this = this->brother;
    }
    this->brother = brother;
  }
}

//check node to make block
int checkBlock(Node* this) {
  int n_brothers = 0;
  Node* temp = this;
  while (temp != NULL) {
    if(temp->node_type != type_Null){
      n_brothers++;
    }
    temp = temp->brother;
  }
  return n_brothers;
}

int is_null(Node* n)
{
  if(n->node_type!=type_Null)
  {
    return 0;
  }
  else
  {
    return 1;
  }
}


/*Print tree*/
void printList(Node* root, int high) {
  int i;
  if(root != NULL){
    /*All the terminals with multiple values*/
    if(root->node_type == type_Id || root->node_type == type_BoolLit || root->node_type == type_RealLit || root->node_type == type_StrLit || root->node_type == type_DecLit){

      for(i=0; i < high; i++){
        printf(".");
      }
      printf("%s(%s)\n",getNode_type(root->node_type), root->token);
    }else{
      if(root->node_type!=type_Null){
      for(i=0; i < high; i++){
          printf(".");
      }
      printf("%s\n",getNode_type(root->node_type) );
    }}

    /*As it is a son, prints 2 more (.)*/
    printList(root->son, high + 2);
    printList(root->brother, high);
  }
}


/*Get Node Type*/
char* getNode_type(NodeType node_type){
  return tokens[node_type];
}

void free_tree(Node* root)
{
  if(root == NULL)
  {
    return;
  }
  free_tree(root->son);
  free_tree(root->brother);

  free(root->token);
  if(root->son != NULL)
  {
    free(root->son);
  }
  if(root->brother)
  {
    free(root->brother);
  }
}
