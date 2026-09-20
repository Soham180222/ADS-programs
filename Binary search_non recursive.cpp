#include <stdio.h>

int binarySearch(int a[], int n, int key)
{
    int low = 0, high = n - 1, mid;

    while (low <= high)
    {
        mid = (low + high) / 2;

        if (a[mid] == key)
            return mid;
        else if (a[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return -1;
}

int main()
{
    int a[] = {10, 20, 30, 40, 50, 60, 70};
    int n = 7, key = 40;

    int pos = binarySearch(a, n, key);

    if (pos != -1)
        printf("Element found at position %d", pos + 1);
    else
        printf("Element not found");

    return 0;
}
