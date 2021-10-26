#include <stdio.h>
#include <math.h>
#include <time.h>
void Merge(int a[], int low, int mid, int high)
{
    // We have low to mid and mid+1 to high already sorted.
    int i, j, k, temp[high - low + 1];
    i = low;     //index of first element in first half
    k = 0;       //index of temporary array temp
    j = mid + 1; //index of first element in second half
    // Merge the two parts into temp[].
    while (i <= mid && j <= high)
    {
        if (a[i] < a[j])
        {
            temp[k] = a[i];
            k++;
            i++;
        }
        else
        {
            temp[k] = a[j];
            k++;
            j++;
        }
    }
    // Insert all the remaining values from i to mid into temp[].
    while (i <= mid)
    {
        temp[k] = a[i];
        k++;
        i++;
    }
    // Insert all the remaining values from j to high into temp[].
    while (j <= high)
    {
        temp[k] = a[j];
        k++;
        j++;
    }
    // Assign sorted data stored in temp[] to a[].
    for (i = low; i <= high; i++)
    {
        a[i] = temp[i - low];
    }
}
// A function to split array into two parts.
void MergeSort(int a[], int low, int high)
{
    int mid;
    if (low < high) //array is having more than one element
    {
        mid = (low + high) / 2;
        // Split the data into two half.
        MergeSort(a, low, mid); //applying mergesort on first half
        MergeSort(a, mid + 1, high);
        // Merge them to get sorted output
        Merge(a, low, mid, high);
    }
}
void main()
{
    int n, a[100], k;
    clock_t st, et;
    double ts;
    printf("\n Enter How many Numbers: ");
    scanf("%d", &n);
    printf("\nThe Random Numbers are:\n");
    for (k = 1; k <= n; k++)
    {
        //genereates random number between 50 and 100
        a[k] = rand() % (100 - 50 + 1) + 50;
        printf("%d\t", a[k]);
    }
    st = clock();
    for (k = 1; k < 10000; k++)
        MergeSort(a, 1, n);
    et = clock(); //approximate processor time that is consumed
    ts = (float)(et - st) / CLOCKS_PER_SEC;
    ts = ts / 10000;
    printf("\nSorted Numbers are: \n ");
    for (k = 1; k <= n; k++)
        printf("%d\t", a[k]);
    printf("\nThe time taken is %e sec\n", ts);
}
