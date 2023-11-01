#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5

int a[MAX_SIZE];
int front = -1;
int rear = -1;

void add(int x) 
{
    if (rear == MAX_SIZE - 1) 
	{
        printf("Queue is full. Cannot add %d\n");
    } 
	else 
	{
        if(front==-1)
          front=rear=0;
        else
		  rear++;
		a[rear]=x;
    }
}

void del() 
{
    if (front == -1) 
	{
        printf("Queue is empty. Cannot delete.\n");
    } 
	else 
	{
        printf("Deleted Element=%d\n", a[front]);
        if (front == rear) 
		{
            front = -1;
            rear = -1;
        } 
		else 
		{
            front++;
        }
    }
}

void display() 
{
    if (front == -1) 
	{
        printf("Queue is empty.\n");
    } 
	else 
	{
		int i;
        printf("Queue elements: ");
        for (i = front; i <= rear; i++) 
		{
            printf("%d ", a[i]);
        }
        printf("\n");
    }
}

void menu()
{
	printf("\t\t Program on Queue\n");
	printf("\t\t  1.addition\n");
	printf("\t\t  2.deletion\n");
	printf("\t\t  3.display\n");
	printf("\t\t  4.Exit\n");
	printf("\nEnter Your Choice");
}

int main() 
{
    int ch,m;
    rear=-1;
    
    for( ; ; )   //infinite loop
    {
    	menu();
    	scanf("%d",&ch);   //accept choice
    	
    	switch(ch)
    	{
    		case 1:
    			printf("Enter Number to add");
    			scanf("%d",&m);
    			
    			add(m);
    			break;
    			
    		case 2:
			    del();
				break;
				
			case 3:
			    display();
				break;
				
			case 4:
			    exit(0);   //Exit from the program
				
			default:
			    printf("Invalid choice");
				break;		
		}
    }
    return 0;
}

