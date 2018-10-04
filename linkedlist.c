#include <stdio.h>
#include <stddef.h>
#include "LinkedList.h"

Node* createNode (TYPE val)
{
    Node* newNode = (Node*) malloc(sizeof(Node));

    newNode->val = val;
    newNode->next = NULL;

    return newNode;
}

void destroyNode (Node* node)
{
    free(node);
}

void appendNode (Node** head, Node* newNode)
{
    if (*head == NULL)
        *head = newNode;
    else
    {
        Node* tail = *head;

        while (tail->next != NULL)
            tail = tail->next;
        
        tail->next = newNode;
    }
}

void pushNodeAt (Node* current, Node* newNode)
{
    newNode->next = current->next;
    current->next = newNode;
}

void makeNodeHead (Node** head, Node* newHead)
{
    if (head == NULL)
        *head = newHead;
    else
    {
        newHead->next = *head;
        *head = newHead;
    }
}

void removeNode (Node** head, Node* target)
{
    if (*head == target)
        *head = target->next;
    else
    {
        Node* current = *head;

        while (current != NULL && current->next != target)
            current = current->next;
        
        if (current != NULL)
            current->next = target->next;
    }
}

Node* findNodeIdx (Node* head, int idx)
{
    Node* current = head;

    while (current != NULL && idx--)
        current = current->next;

    return current;
}

int nodeCount (Node* Head)
{
    int idx = 0;
    Node* current = Head;

    while (current != NULL)
        current = current->next, idx++;

    return idx;
}