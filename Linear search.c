#include <stdio.h>

int main() 
{
    int size, i, key, flag = 0;
    int arr[size];

    printf("Enter the number of elements in the array: ");
    scanf("%d", &size);

    printf("Enter %d elements:\n", size);
    for(i = 0; i < size; i++) 
	{
        scanf("%d", &arr[i]);
    }

    printf("Enter the element to search: ");
    scanf("%d", &key);

    for(i = 0; i < size; i++) 
	{
        if(arr[i] == key) 
		{
            printf("Element found at position %d.\n", i + 1);
            flag = 1;
            break;
        }
    }

    if(flag == 0) 
	{
        printf("Element not found in the array.\n");
    }

    return 0;
}

