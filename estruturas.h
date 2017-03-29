#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*Enumeration of the NodeTypes*/
typedef enum {type_Program, type_FieldDecl,  type_VarDecl, type_MethodDecl, type_MethodHeader, type_MethodParams, type_ParamDecl,
              type_MethodBody, type_StringArray, type_Block, type_DoWhile, type_If, type_Print, type_Return, type_While, type_Assign, type_Call,
              type_ParseArgs, type_Or, type_And, type_Eq, type_Neq, type_Lt, type_Gt, type_Leq, type_Geq, type_Add, type_Sub, type_Mul, type_Div, type_Mod, type_Not, type_Minus,
              type_Plus, type_Length, type_Bool, type_BoolLit, type_Double, type_DecLit, type_Id, type_Int, type_RealLit, type_StrLit, type_Void, type_Null, type_Error } NodeType;


/*This is not a tree, it's more like a list of lists*/
/*Node*/
typedef struct node Node;
struct node {
    NodeType node_type;
    char* token;
    Node* son;
    Node* brother;
};


Node* createNode(NodeType node_type, char* token, Node* son, Node* brother);
void deleteNode(Node* this);
void insertBrother(Node* this, Node* brother);
void printList(Node* root, int high);
char* getNode_type(NodeType node_type);
int checkBlock(Node* this);
void insertSon(Node* n, Node* son );
int is_null(Node* n);
void insertSon(Node* n, Node* son );
