#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int number;
    struct TreeNode* left;
    struct TreeNode* right;
};

struct TreeNode* inserir(struct TreeNode **node, int number) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));

    if (newNode == NULL) {
        printf("Memory not allocated.\n");
        exit(0);
    } else {
        newNode->number = number;
        
        if (*node == NULL) {
            *node = newNode;
            return *node;
        } else {
            if (number < (*node)->number) {
                if ((*node)->left == NULL)
                    (*node)->left = newNode;
                else
                    inserir(&(*node)->left, number);
            }
            else if (number > (*node)->number) {
                if ((*node)->right == NULL)
                    (*node)->right = newNode;
                else
                    inserir(&(*node)->right, number);
            }
            else{
                printf("Duplicated Key not inserting.\n");
            }
        }
        return NULL;
    }
}

void printTree(void (*fun)(struct TreeNode **), struct TreeNode **node) {
    fun(node);
    printf("NULL\n");
}

void inOrder(struct TreeNode **node) {
    if (*node != NULL) {
        inOrder(&(*node)->left);
        printf("%i -> ", (*node)->number);
        inOrder(&(*node)->right);
    }
}

void preOrder(struct TreeNode **node) {
    if (*node != NULL) {
        printf("%i -> ", (*node)->number);
        preOrder(&(*node)->left);
        preOrder(&(*node)->right);
    }
}

void postOrder(struct TreeNode **node) {
    if (*node != NULL) {
        postOrder(&(*node)->left);
        postOrder(&(*node)->right);
        printf("%i -> ", (*node)->number);
    }
}

struct TreeNode* searchKey(struct TreeNode **node, int number) {
    if (*node == NULL || number == (*node)->number) return *node;
    else
        if (number < (*node)->number)
            return searchKey(&(*node)->left, number);
        else
            return searchKey(&(*node)->right, number);
}

struct TreeNode* getMax(struct TreeNode **node) {
    struct TreeNode* max = *node;
    while (max->right != NULL)
        max = max->right;
    return max;
}

struct TreeNode* getMin(struct TreeNode **node) {
    struct TreeNode* min = *node;
    while (min->left != NULL)
        min = min->left;
    return min;
}

struct TreeNode* getMinParent(struct TreeNode **node) {
    struct TreeNode* min = *node;
    while (min->left != NULL && min->left->left != NULL)
        min = min->left;
    return min;
}

struct TreeNode* deleteNode(struct TreeNode **root, int number) {
    if (*root == NULL)
        return *root;
    
    if (number < (*root)->number) {
        (*root)->left = deleteNode(&(*root)->left, number);
        return *root;
    } else if (number > (*root)->number) {
        (*root)->right = deleteNode(&(*root)->right, number);
        return *root;
    }

    if ((*root)->left == NULL) {
        struct TreeNode* temp = (*root)->right;
        free((*root));
        return temp;
    } else if ((*root)->right == NULL) {
        struct TreeNode* temp = (*root)->left;
        free((*root));
        return temp;
    }

    struct TreeNode* succParent = *root;
    struct TreeNode* succ = (*root)->right;
    while (succ->left != NULL) {
        succParent = succ;
        succ = succ->left;
    }

    (*root)->number = succ->number;

    if (succParent->left == succ) succParent->left = succ->right;
    else succParent->right = succ->right;
    free(succ);
    return *root;
}

int main() {
    struct TreeNode* root = NULL;
    inserir(&root, 12);
    inserir(&root, 5);
    inserir(&root, 13);
    inserir(&root, 2);
    inserir(&root, 8);
    inserir(&root, 17);
    inserir(&root, 15);
    printTree(inOrder, &root);
    printTree(preOrder, &root);
    printTree(postOrder, &root);

    struct TreeNode* foundNode = searchKey(&root, 70);
    printf("Found node: %p\n", foundNode);

    struct TreeNode* minNode = getMin(&root);
    printf("Min node: %i\n", minNode->number);

    struct TreeNode* maxNode = getMax(&root);
    printf("Max node: %i\n", maxNode->number);

    deleteNode(&root, 5);
    printTree(preOrder, &root);

    return 0;
}