#include <stdio.h>

int binarySearch(int a[], int low, int high, int key)
{
    if (low > high)
        return -1;

    int mid = (low + high) / 2;

    if (a[mid] == key)
        return mid;
    else if (a[mid] < key)
        return binarySearch(a, mid + 1, high, key);
    else
        return binarySearch(a, low, mid - 1, key);
}

int main()
{
    int a[] = {10, 20, 30, 40, 50, 60, 70};
    int n = 7, key = 50;

    int pos = binarySearch(a, 0, n - 1, key);

    if (pos != -1)
        printf("Element found at position %d", pos + 1);
    else
        printf("Element not found");

    return 0;
}
