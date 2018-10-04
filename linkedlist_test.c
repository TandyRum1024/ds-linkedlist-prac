#include "LinkedList.h"
#include <stdio.h>
#include <stddef.h>

int main (void)
{
    int i = 0, count = 0;
    Node* list = NULL;
    Node* current = NULL;
    Node* newNode = NULL;


    for (i=0; i<5; i++)
    {
        newNode = createNode(i);
        appendNode(&list, newNode);
    }

    newNode = createNode(-1);
    makeNodeHead(&list, newNode);

    newNode = createNode(-2);
    makeNodeHead(&list, newNode);

    // dump
    count = nodeCount(list);
    for (i=0; i<count; i++)
    {
        current = findNodeIdx(list, i);
        printf("LNK[%d] - %d\n", i, current->val);
    }

    // Shove
    printf("\nRUSH B PLZ AAAAAAAAAAAAAAAAAAAAAAA [2]\n\n");
    current = findNodeIdx(list, 2);
    newNode = createNode(3000);

    pushNodeAt(current, newNode);

    // dump
    count = nodeCount(list);
    for (i=0; i<count; i++)
    {
        current = findNodeIdx(list, i);
        printf("LNK[%d] - %d\n", i, current->val);
    }

    // dealloc
    printf("\neveryone died\n");

    for (i=0; i<count; i++)
    {
        current = findNodeIdx(list, i);
        if (current)
        {
            removeNode(&list, current);
            destroyNode(current);
        }
    }

    return 0;
}