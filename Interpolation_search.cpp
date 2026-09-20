#include <stdio.h>

int interpolation(int a[], int x, int low, int high)
{
    int pos;

    while (low <= high && x >= a[low] && x <= a[high])
    {
        if (low == high)
        {
            if (a[low] == x)
                return low;
            return -1;
        }

        pos = low + ((x - a[low]) * (high - low)) /
                     (a[high] - a[low]);

        if (a[pos] == x)
            return pos;
        else if (x < a[pos])
            high = pos - 1;
        else
            low = pos + 1;
    }

    return -1;
}

int main()
{
    int a[100], n, x, i, k;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter sorted array elements:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    printf("Enter element to search: ");
    scanf("%d", &x);

    k = interpolation(a, x, 0, n - 1);

    if (k != -1)
        printf("%d is found at location %d\n", x, k + 1);
    else
        printf("%d is not found\n", x);

    return 0;
}
