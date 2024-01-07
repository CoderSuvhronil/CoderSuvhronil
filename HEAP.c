#include<stdio.h>
#include<math.h>
#include<stdlib.h>

void insertHeap(int *,int,int);//Base Address, SIZE of HEAP, Element to be inserted
void deleteRootOfHeap(int *,int);

int main()
{
	int i,n,m;
	
	printf("How many elements: ");
	scanf("%d",&n);
	
    int a[n];
    
	printf("Enter %d elements: ",n);
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	printf("The elements in the array are: ");
	for(i=0;i<n;i++)
		printf("%4d",a[i]);
	//Creation of Heap
	for(i=1;i<n;i++)
		insertHeap(a,i,a[i]);
		//Base address of array, size of heap, element to be inserted
	printf("\nThe elements in the heap are: ");
	for(i=0;i<n;i++)
		printf("%4d",a[i]);
	printf("\n");
	
	system("pause");
	
	for(i=0;i<n-1;i++)
	{
		m=a[0];
		deleteRootOfHeap(a,n-i);
		a[n-i-1]=m;
	}
	printf("\nThe sorted array is: ");
	for(i=0;i<n;i++)
		printf("%4d",a[i]);
	return 0;
}

void insertHeap(int *a,int n,int x)
{
	int ptr=n,par;
	while(ptr>0)
	{
		par=floor((ptr-1)/2);
		if(x<=a[par])
		{
			a[ptr]=x;
			return;
		}
		a[ptr]=a[par];
		ptr=par;
	}
	a[0]=x;
}

void deleteRootOfHeap(int *a,int k)
{
	int y,p,l,r;
	y=a[k-1];
	p=0;
	l=2*p+1;
	r=2*p+2;
	k--;
	while(r<=k-1)
	{
		if(y>=a[l] && y>=a[r])
		{
			a[p]=y;
			return;
		}
		if(a[l]>a[r])
		{
			a[p]=a[l];
			p=l;
		}
		else
		{
			a[p]=a[r];
			p=r;
		}
		l=2*p+1;
		r=l+1;
	}
	if(l==k-1 && y<a[l])
	{
		a[p]=a[l];
		a[l]=y;
	}
	else
		a[p]=y;
}
