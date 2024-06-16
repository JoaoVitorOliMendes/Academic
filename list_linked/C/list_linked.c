#include <stdio.h>
#include <stdlib.h>

struct LinkNode {
    int number;
    struct LinkNode* next;
    struct LinkNode* prev;
};

void insertToNode(struct LinkNode **node, int number) {
    struct LinkNode* newNode = (struct LinkNode*)malloc(sizeof(struct LinkNode));

    if (newNode == NULL) {
        printf("Memory not allocated.\n");
        exit(0);
    } else {
        newNode->number = number;
        
        //Head of List
        if (*node == NULL) {
            *node = newNode;
            newNode->next = NULL;
            return;
        } else {
            printf("%p, %d\n", *node, (*node)->number);
            newNode->prev = *node;
            newNode->next = (*node)->next;
            if ((*node)->next != NULL) {
                newNode->next->prev = newNode;
            }
            newNode->prev->next = newNode;
        }
    }
}

void insertAtEnd(struct LinkNode **node, int number) {
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

void linkLastNode(struct LinkNode **node) {
    //Point last node to new node
    struct LinkNode* current = *node;
    while (current->next != NULL) {
        current = current->next;
    }
    
    current->next = *node;
}

//Floyd’s Cycle Finding
int detectLoop(struct LinkNode **node) {
    if(*node==NULL) return 0;
    //Point to head
    struct LinkNode* head = *node;
    while (head->prev != NULL) {
        head = head->prev;
    }
    if (head->next==NULL) return 0;

    struct LinkNode *slowPointer = head, *fastPointer = head;
    while (slowPointer != NULL && fastPointer != NULL && fastPointer->next != NULL) {
        slowPointer = slowPointer->next;
        fastPointer = fastPointer->next->next;
        if (slowPointer == fastPointer)
            return 1;
    }

    return 0;
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

void printList(struct LinkNode **node) {
    if (detectLoop(node)==1) {
        printf("There is a loop\n");
        return;
    }
    struct LinkNode* current = *node;
    while (current != NULL) {
        printf("%d -> ", current->number);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    struct LinkNode* head = NULL;
    insertToNode(&head, 10);
    insertToNode(&head, 20);
    insertToNode(&head, 30);
    insertAtEnd(&head, 40);

    printf("Linked List: \n");
    printList(&head);

    struct LinkNode* found = getNodeByVal(&head, 30);
    // linkLastNode(&found);
    // printf("Linked List: \n");
    // printList(&head);

    printf("Find address: %p, val: %i\n", &found, found->number);

    int removal = removeNodeByVal(&head, 0);

    printf("Node removal: %i\n", removal);
    printf("Linked List: \n");
    printList(&head);

    return 0;
}