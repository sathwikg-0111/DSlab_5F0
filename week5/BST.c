#include <stdio.h>
#include <stdlib.h>

// Define BST Node
struct node {
    int key;
    struct node *left, *right;
};

// Create a new node
struct node* newnode(int item) {
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}

// Inorder traversal
void inorder(struct node* root) {
    if (root == NULL)
        return;
    inorder(root->left);
    printf("%d ", root->key);
    inorder(root->right);
}

// Insert a node into BST
struct node* insert(struct node* node, int key) {
    if (node == NULL)
        return newnode(key);
    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    return node;
}

// Search for a node
struct node* search(struct node* root, int key) {
    if (root == NULL || root->key == key)
        return root;
    if (key < root->key)
        return search(root->left, key);
    else
        return search(root->right, key);
}

// Find minimum value node (used in delete)
struct node* minvaluenode(struct node* node) {
    struct node* current = node;
    while (current && current->left != NULL)
        current = current->left;
    return current;
}

// Delete a node
struct node* deletenode(struct node* root, int key) {
    if (root == NULL)
        return root;

    if (key < root->key)
        root->left = deletenode(root->left, key);
    else if (key > root->key)
        root->right = deletenode(root->right, key);
    else {
        // Node with only one child or no child
        if (root->left == NULL) {
            struct node* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            struct node* temp = root->left;
            free(root);
            return temp;
        }
        // Node with two children
        struct node* temp = minvaluenode(root->right);
        root->key = temp->key;
        root->right = deletenode(root->right, temp->key);
    }
    return root;
}

// Driver code
int main() {
    struct node* root = NULL;
    int choice, val;
    struct node* ptr;

    while (1) {
        printf("\n******** BINARY SEARCH TREE MENU ********\n");
        printf("1. Inorder traversal\n");
        printf("2. Insert\n");
        printf("3. Search\n");
        printf("4. Find minimum value\n");
        printf("5. Delete\n");
        printf("6. Exit\n");
        printf("Enter option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Inorder Traversal: ");
                inorder(root);
                printf("\n");
                break;
            case 2:
                printf("Insert a new node value: ");
                scanf("%d", &val);
                root = insert(root, val);
                break;
            case 3:
                printf("Enter key element to search: ");
                scanf("%d", &val);
                ptr = search(root, val);
                if (ptr != NULL)
                    printf("Element %d found in the tree.\n", val);
                else
                    printf("Element %d not found in the tree.\n", val);
                break;
            case 4:
                ptr = minvaluenode(root);
                if (ptr)
                    printf("Smallest value in the tree is: %d\n", ptr->key);
                else
                    printf("Tree is empty.\n");
                break;
            case 5:
                printf("Enter the element to be deleted: ");
                scanf("%d", &val);
                root = deletenode(root, val);
                break;
            case 6:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

