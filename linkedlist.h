#ifndef LINKDED
#define LINKDED

typedef int TYPE;

typedef struct LNKLST_NODE
{
    TYPE val;
    struct Node* next;
}Node;

// predecl
Node* createNode (TYPE val);
void destroyNode (Node* node);
void appendNode (Node** head, Node* newNode);
void pushNodeAt (Node* current, Node* newNode);
void makeNodeHead (Node** head, Node* newHead);
void removeNode (Node** head, Node* target);
Node* findNodeIdx (Node* Head, int idx);
int nodeCount (Node* Head);

#endif