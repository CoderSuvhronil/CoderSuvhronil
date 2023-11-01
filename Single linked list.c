#include <stdio.h>
#include <stdlib.h>

struct linklist{
	int n;
	struct linklist *next;
};
typedef struct linklist node;

node *head = NULL;

//Create function
void create()
{
	int x;
	char ch;
	node *h,*t;

	do
	{
		printf("Enter the Value: ");
		scanf("%d",&x);

		t =(node *)malloc(sizeof(node));
		t->n = x;
		t->next = '\0';

		if(head =='\0')
		{
			head = t;
			h = t;
		}
		else
		{
			h->next = t;
			h = t;
		}
		printf("Do You Want to Continue ?");
		fflush(stdin);
		ch = getchar();
	}
	while(ch == 'Y' || ch == 'y');
}

//Displaying the List
void display()
{
	node *h;
	h = head;
	if(head =='\0')
	{
		printf("Empty Node");
		return;
	}
	while(h!='\0')
	{
		printf("%5d",h->n);
		h = h->next;
	}
}

//Search function
node* search(int x)
{
	node *h;
	h = head;

	if(head == '\0')
	{
		printf("Empty Node, Can't search");
		return;
	}
	else
	{
		while(h!= '\0')
		{
			if(h->n == x)
			   return h;
			h = h->next;
		}
		return h;
	}
}

//Counting the Number of Nodes
int count()
{
	node *h;
	int n = 0;
	h = head;
	if(head == '\0')
	{
		printf("Empty Node, Can't Count");
		return;
	}
	while(h!='\0')
	{
		n++;
		h = h->next;
	}
	return n;
}

//Deleting by value
void delbyValue(int x)
{
	node *h,*y;
	y = search(x);

	if(y =='\0')
	{
		printf("The Number is not found.");
	}
	else
	{
		h = head;
		while(h->next!=y)
		{
			h = h->next;
		}
		h->next = y->next;
	}
	free(y);
}

//Delete by Position
void delbyPosition(int x)
{
	node *h1,*h2;
	int i, n = count();

	if(x<1 || x>n)
	{
		printf("Input OUT of Range.");
		return;
	}
	if(x==1)
	{
		head = head->next;
	}
	else
	{
		h1 = head;
		h2 = head->next;

		for(i = 1;i <= x;i++)
		{
			h1 = h2;
			h2 = h2->next;
		}
		h1->next = h2->next;
		free(h2);
	}
}

//Inserting by position
void insertbyPosition(int x,int y)
{
	node *h1,*h2,*h;
	int i, n;
	n = count();

	if(y<1 || y>n+1)
	{
		printf("Input OUT of range");
		return;
	}
	h = (node *)malloc(sizeof(node));
	h->n = x;
	if(x == 1)
	{
		h->next = head;
		head = h;
	}
	else
	{
		h1 = head;
		h2 = head->next;

		for(i = 1;i <=y-2;i++)
		{
			h1 = h2;
			h2 = h2->next;
		}
		h->next = h2;
		h1->next = h;
	}
}

//Adding Before
void addBefore(int x, int y)
{
	node *t,*p,*h;
	p = search(x);
	if(p == '\0')
	{
		printf("Value Not Found");
		return;
	}
	t = (node *)malloc(sizeof(node));
	t->n = y;
	if(head == p)
	{
		t->next = head;
		head = t;
	}
	else
	{
		h = head;
		while(h->next == p)
		{
			h = h->next;
		}
		h->next = t;
		t->next = p;
	}
}

//Adding After
void addAfter(int x, int y)
{
	node *t,*p;
	p = search(x);
	if(p=='\0')
	{
		printf("Value Not Found.");
		return;
	}
	t = (node *)malloc(sizeof(node));
	t->n = y;
	t->next = p->next;
	p->next = t;
}

//Reversing the List
void reverse()
{
	node *h1,*h2,*h3;
	if(head =='\0' || head->next =='\0')
	{
		printf("There is no node or only one node.");
		return;
	}
	h1 = head;
	h2 = h1->next;
	h3=h2->next;
	h1->next = '\0';

	while(h2!= '\0')
	{
		h2->next = h1;
		h1 = h2;
		h2 = h3;
		if(h3!='\0')
			h3 = h3->next;
	}
	head = h1;
}

void menu()
{
	printf("\n");
	printf("\t\t\t PROGRAM ON LINKLIST: \n");
	printf("\t\t\t   1.Create.\n");
	printf("\t\t\t   2.Display.\n");
	printf("\t\t\t   3.Search.\n");
	printf("\t\t\t   4.Count.\n");
	printf("\t\t\t   5.Delete by Value.\n");
	printf("\t\t\t   6.Delete by Position.\n");
	printf("\t\t\t   7.Insert by Position.\n");
	printf("\t\t\t   8.Add Before.\n");
	printf("\t\t\t   9.Add After.\n");
	printf("\t\t\t   10.Reverse.\n");
	printf("\t\t\t   11.Exit.\n");

	printf("\t\t\t   Enter your Choice Please! : ");
}

int main()
{
	int ch,x,y,b,z,u,v,w,e,f,g,h;
	node *a;

	while(4)
	{
		menu();
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				create();
				break;

			case 2:
				display();
				break;

			case 3:
				printf("Enter the Element to be Searched: ");
				scanf("%d",&y);

				a = search(y);

				if(a =='\0')
				   printf("NOT found");
				else
				   printf("FOUND at address %u",a);
				break;

			case 4:
				b = count();
				printf("The Node number is %d",b);
				break;

			case 5:
				printf("Enter the value to be DELETED: ");
				scanf("%d",&x);

				delbyValue(x);
				break;

			case 6:
			    printf("Enter the position to be DELETED: ");
				scanf("%d",&z);

				delbyPosition(z);
				break;

			case 7:
			    printf("Enter the value to be INSERTED and POSITION: ");
				scanf("%d%d",&u,&v);

				insertbyPosition(u,w);
				break;

			case 8:
				printf("Enter the INSERTION position value and ADD VALUE: ");
				scanf("%d%d",&e,&f);

				addBefore(e,f);
				break;

			case 9:
				printf("Enter the INSERTION position value and ADD VALUE: ");
				scanf("%d%d",&g,&h);

				addAfter(g,h);
				break;

			case 10:
				reverse();
				break;

			case 11:
				exit(4);
				break;

			default:
				printf("Sorry!!Invalid Choice!");
		}
	}
	return 0;
}

