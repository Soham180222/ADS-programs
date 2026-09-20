#include <stdio.h>

int getMax(int a[], int n)
{
    int max, i;

    max = a[0];

    for (i = 1; i < n; i++)
    {
        if (a[i] > max)
            max = a[i];
    }

    return max;
}

void countingSort(int a[], int n, int exp)
{
    int output[100];
    int count[10] = {0};
    int i;

    for (i = 0; i < n; i++)
        count[(a[i] / exp) % 10]++;

    for (i = 1; i < 10; i++)
        count[i] = count[i] + count[i - 1];

    for (i = n - 1; i >= 0; i--)
    {
        output[count[(a[i] / exp) % 10] - 1] = a[i];
        count[(a[i] / exp) % 10]--;
    }

    for (i = 0; i < n; i++)
        a[i] = output[i];
}

void radixSort(int a[], int n)
{
    int max, exp;

    max = getMax(a, n);

    exp = 1;

    while (max / exp > 0)
    {
        countingSort(a, n, exp);
        exp = exp * 10;
    }
}

int main()
{
    int a[100], n, i;

    printf("Enter n: ");
    scanf("%d", &n);

    printf("Enter elements: ");

    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    radixSort(a, n);

    printf("Sorted array: ");

    for (i = 0; i < n; i++)
        printf("%d ", a[i]);

    return 0;
}
