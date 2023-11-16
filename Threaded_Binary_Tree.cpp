#include<stdio.h>
#include<stdlib.h>
typedef struct Node
{
	struct Node *lc;
	int lthread;
	int info;
	int rthread;
	struct Node *rc;
}node;

node *root='\0';

// Insert a Node in Binary Threaded Tree
void insert(int x)
{
	node *ptr = root;
	node *par = '\0';
	
	while (ptr != '\0')
	{
		if (x == (ptr->info))
		{
			printf("\nDuplicate Value\n");
			return;
		}
		
		par = ptr;
		
		if (x < ptr->info)
		{
			if (ptr -> lthread == 0)
				ptr = ptr -> lc;
			else
				break;
		}
		else
		{
			if (ptr->rthread == 0)
				ptr = ptr -> rc;
			else
				break;
		}
	}
	node *tmp = (node *)malloc(sizeof(node));
	tmp -> info = x;
	tmp -> lthread = 1;
	tmp -> rthread = 1;
	if (par == '\0')
	{
		root = tmp;
		tmp -> lc = '\0';
		tmp -> rc = '\0';
	}
	else if (x < (par -> info))
	{
		tmp -> lc = par -> lc;
		tmp -> rc = par;
		par -> lthread = 0;
		par -> lc = tmp;
	}
	else
	{
		tmp -> lc = par;
		tmp -> rc = par -> rc;
		par -> rthread = 0;
		par -> rc = tmp;
	}
}

//In-Order successor
node *inorderSuccessor(node *ptr)
{
	if (ptr -> rthread == 1)
		return ptr->rc;
	ptr = ptr -> rc;
	while (ptr -> lthread == 0)
		ptr = ptr -> lc;
	return ptr;
}
void inorder()
{
	if (root == '\0')
		printf("Tree is empty");

	// Reach Left most node
	node *ptr = root;
	while (ptr -> lthread == 0)
		ptr = ptr -> lc;

	// Print successors one by one
	while (ptr != '\0')
	{
		printf("%d ",ptr -> info);
		ptr = inorderSuccessor(ptr);
	}
}


void menu()
{
	printf("\t\t\t1.Insert\n");
    printf("\t\t\t2.In-order Traversal\n");
	printf("\t\t\t3.Quit\n");
	printf("\nEnter your choice : ");

}
int main()
{
	int ch,p;
	while(1)
	{
		menu();
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("Enter the value to insert ");
				scanf("%d",&p);
				insert(p);
				break;
			case 2:
				printf("The in-order traversal :");
				inorder();
				printf("\n");
				break;
			case 3:
				exit(0);
		}
	}
	return 0;
}
