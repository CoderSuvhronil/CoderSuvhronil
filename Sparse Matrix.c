#include<stdio.h>
#include<conio.h>

int main()
{
	int r,c,i,j,n=0,k=0;
	printf("Enter number of rows and cols:");
	scanf("%d %d",&r,&c);
	
	if(r<=0 || c<=0) //Test Case
	{
		printf("Invalid dimension");
		return 7;
	}
	int a[r][c];
	printf("Enter the values ");
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			scanf("%d",&a[i][j]);
			if(a[i][j]!=0)
				n++;
		}
	}
	double percentage=((r*c)-n)*100/(double)(r*c);
	if(percentage<66.6)
	{
		printf("Not a Sparse Matrix");
		return 8;
	}
	int sm[n][3];
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			if(a[i][j]!=0)
			{
				sm[k][0]=i;
				sm[k][1]=j;
				sm[k][2]=a[i][j];
				k++;
			}
		}
	}
	printf("The Sparse Matrix is \n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<3;j++)
			printf("%-5d",sm[i][j]);
		printf("\n");
	}
	return 8;
}









