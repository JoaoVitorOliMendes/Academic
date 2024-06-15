#include <cstddef>
#include <stdio.h>
#include <stdlib.h>

struct LinkNode {
    int number;
    struct LinkNode* next;
    struct LinkNode* prev;
};

void insert(struct LinkNode **node, int number) {
    struct LinkNode* newNode = (struct LinkNode*)malloc(sizeof(struct LinkNode));

    if (newNode == NULL) {
        printf("Memory not allocated.\n");
        exit(0);
    } else {
        newNode->number = number;
        newNode->next = NULL;
        
        //Head of List
        if (*node == NULL) {
            *node = newNode;
            return;
        } else {
            newNode->prev = *node;
        }
        
        //Point last node to new node
        struct LinkNode* current = *node;
        while (current->next != NULL) {
            current = current->next;
        }
        
        current->next = newNode;
    }
}

struct LinkNode* getNodeByVal(struct LinkNode **node, int number) {
    struct LinkNode* current = *node;

    while (current->next != NULL) {
        if (current->number == number)
            return current;
        current = current->next;
    }
    return NULL;
}

int removeNodeByVal(struct LinkNode **node, int number) {
    struct LinkNode* current = *node;

    while (current->next != NULL) {
        if (current->number == number){
            current->prev->next = current->next;
            current->next->prev = current->prev;
            free(current);
            current = NULL;
            return 1;
        }
        current = current->next;
    }
    return -1;
}

void printList(struct LinkNode* node) {
    struct LinkNode* current = node;
    while (current != NULL) {
        printf("%d -> ", current->number);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    struct LinkNode* head = NULL;
    insert(&head, 10);
    insert(&head, 20);
    insert(&head, 30);
    insert(&head, 40);

    printf("Linked List: \n");
    printList(head);

    struct Node* found = getNodeByVal(&head, 30);

    printf("Find address: %p, val: %i\n", &found, found->number);

    int removal = removeNodeByVal(&head, 0);

    printf("Node removal: %i\n", removal);
    printf("Linked List: \n");
    printList(head);

    return 0;
}