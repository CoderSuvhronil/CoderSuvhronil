#include <stdio.h>

int interpolationSearch(int arr[], int n, int x) {
    int low = 0, high = n - 1;

    while (low <= high && x >= arr[low] && x <= arr[high]) {
        if (low == high) {
            if (arr[low] == x) return low;
            return -1;
        }

        int pos = low + (((double)(high - low) / (arr[high] - arr[low])) * (x - arr[low]));

        if (arr[pos] == x) return pos;

        if (arr[pos] < x) low = pos + 1;
        else high = pos - 1;
    }

    return -1;
}

int main() {
    int n, x,i;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter the elements of the sorted array:\n");
    for (i = 0; i < n; ++i) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the element to search: ");
    scanf("%d", &x);

    int index = interpolationSearch(arr, n, x);
    if (index != -1) {
        printf("Element found at index %d\n", index);
    } else {
        printf("Element not found\n");
    }

    return 0;
}

