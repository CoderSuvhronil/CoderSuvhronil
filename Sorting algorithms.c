#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//Input function
void input(int a[], int n)
{
	int i;
	printf("Enter %d Elements:\n",n);
	for(i = 0;i < n;i++)
	{
		scanf("%d",&a[i]);
	}
}

// Function to perform Bubble Sort
void bubbleSort(int a[], int n)
{
	int i,j,temp;
	
	for(i = 0;i < n - 1;i++)
	{
		for(j = 0;j < n - i;j++)
		{
			if(a[j] > a[j + 1])
			{
				temp = a[j];
				a[j] = a[j+1];
				a[j+1] = temp;
			}
		}
	}
}

// Function to perform Selection Sort
void selectionSort(int arr[], int n) {
    int i, j, min_idx, temp;
    for (i = 0; i < n - 1; i++) {
        min_idx = i;
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx])
                min_idx = j;
        }
        // Swap the found minimum element with the first element
        temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
    }
}

// Function to perform Insertion Sort
void insertionSort(int arr[], int n) 
{
    int i, key, j;
    for (i = 1; i < n; i++) 
	{
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) 
		{
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

// Function to display array elements
void display(int arr[], int n) 
{
	int i;
    printf("\nArray elements: ");
    for (i = 0; i < n; i++) 
	{
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() 
{
    int choice, n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];

    input(arr, n);
    display(arr, n);

    printf("\nChoose Sorting Technique:\n");
    printf("1. Bubble Sort\n");
    printf("2. Selection Sort\n");
    printf("3. Insertion Sort\n");
    printf("\nEnter your choice: ");
    scanf("%d", &choice);

    switch (choice) 
	{
        case 1:
            bubbleSort(arr, n);
            printf("\nArray sorted using Bubble Sort: ");
            break;
        case 2:
            selectionSort(arr, n);
            printf("\nArray sorted using Selection Sort: ");
            break;
        case 3:
            insertionSort(arr, n);
            printf("\nArray sorted using Insertion Sort: ");
            break;
        default:
            printf("Invalid choice");
            return 1;
    }

    display(arr, n);

    return 0;
}
