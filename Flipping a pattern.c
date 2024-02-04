#include<stdio.h>
#include<conio.h>

int main()
{
	int i, j, k, p, rows;
	
	printf("Enter Number of Rows: ");
	scanf("%d",&rows);
	
	for(i = rows; i >= 1; i--)
	{
		for(j = rows; j > i; j--)
		{
			printf("%5d",j);
		}
		for(k = 1; k <= (2*i-1); k++)
		{
			printf("%5d", i);
		}
		for(p = i + 1; p <= rows; p++)
		{
			printf("%5d",p);
		}
		printf("\n");
	}
	//Flipping the pattern
	
	for(i = 2; i <= rows; i++)
	{
		for(j = rows; j > i; j--)
		{
			printf("%5d",j);
		}
		for(k = 1; k <= (2*i-1); k++)
		{
			printf("%5d", i);
		}
		for(p = i+1; p <= rows; p++)
		{
			printf("%5d",p);
		}
		printf("\n");
	}
	return 0;
}
