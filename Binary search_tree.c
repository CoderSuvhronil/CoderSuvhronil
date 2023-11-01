#include <stdio.h>
#include <stdlib.h>

// Structure for a node in the BST
struct Node 
{
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* createNode(int value) 
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a node into the BST
struct Node* insert(struct Node* root, int value) 
{
    if (root == NULL) 
	{
        return createNode(value);
    }

    if (value < root->data) 
	{
        root->left = insert(root->left, value);
    } 
	else if (value > root->data) 
	{
        root->right = insert(root->right, value);
    }

    return root;
}

// Function to search for a value in the BST
struct Node* search(struct Node* root, int value) 
{
    if (root == NULL || root->data == value) 
	{
        return root;
    }

    if (value < root->data) 
	{
        return search(root->left, value);
    } 
	else 
	{
        return search(root->right, value);
    }
}

// Function to find the minimum value node in the BST
struct Node* findMin(struct Node* root) 
{
    while (root->left != NULL) 
	{
        root = root->left;
    }
    return root;
}

// Function to delete a node with a given value from the BST
struct Node* deleteNode(struct Node* root, int value) 
{
    if (root == NULL) 
	{
        return root;
    }

    if (value < root->data) 
	{
        root->left = deleteNode(root->left, value);
    } 
	else if (value > root->data) 
	{
        root->right = deleteNode(root->right, value);
    } 
	else 
	{
        // Node with only one child or no child
        if (root->left == NULL) 
		{
            struct Node* temp = root->right;
            free(root);
            return temp;
        } 
		else if (root->right == NULL) 
		{
            struct Node* temp = root->left;
            free(root);
            return temp;
        }

        // Node with two children, get the inorder successor (smallest in the right subtree)
        struct Node* temp = findMin(root->right);

        // Copy the inorder successor's data to this node
        root->data = temp->data;

        // Delete the inorder successor
        root->right = deleteNode(root->right, temp->data);
    }

    return root;
}

// Function for in-order traversal (LNR)
void inorderTraversal(struct Node* root) 
{
    if (root != NULL) 
	{
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

// Function for pre-order traversal (NLR)
void preorderTraversal(struct Node* root) 
{
    if (root != NULL) 
	{
        printf("%d ", root->data);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}

// Function for post-order traversal (LRN)
void postorderTraversal(struct Node* root) 
{
    if (root != NULL) 
	{
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        printf("%d ", root->data);
    }
}

int main() 
{
    struct Node* root = NULL;
    int choice, value;

    while (1) 
	{
        printf("\nBinary Search Tree Operations:\n");
        printf("1. Insert\n");
        printf("2. Search\n");
        printf("3. Delete\n");
        printf("4. In-order Traversal\n");
        printf("5. Pre-order Traversal\n");
        printf("6. Post-order Traversal\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) 
		{
            case 1:
                printf("Enter the value to insert: ");
                scanf("%d", &value);
                root = insert(root, value);
                break;
            case 2:
                printf("Enter the value to search: ");
                scanf("%d", &value);
                if (search(root, value) != NULL) 
				{
                    printf("Value %d found in the tree.\n", value);
                } 
				else 
				{
                    printf("Value %d not found in the tree.\n", value);
                }
                break;
            case 3:
                printf("Enter the value to delete: ");
                scanf("%d", &value);
                root = deleteNode(root, value);
                break;
            case 4:
                printf("In-order Traversal: ");
                inorderTraversal(root);
                printf("\n");
                break;
            case 5:
                printf("Pre-order Traversal: ");
                preorderTraversal(root);
                printf("\n");
                break;
            case 6:
                printf("Post-order Traversal: ");
                postorderTraversal(root);
                printf("\n");
                break;
            case 7:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}
