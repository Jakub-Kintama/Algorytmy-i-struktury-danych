#include <ctime>
#include "Merge.h"
using namespace std;
int t[1000000];

void merge(int *arr, int low, int high, int mid)
{
    int i, j, k;
    i = low;
    k = low;
    j = mid + 1;
    while (i <= mid && j <= high) {
        if (arr[i] < arr[j]) {
            t[k] = arr[i];
            k++;
            i++;
        }
        else {
            t[k] = arr[j];
            k++;
            j++;
        }
    }

    while (i <= mid) {
        t[k] = arr[i];
        k++;
        i++;
    }
    while (j <= high) {
        t[k] = arr[j];
        k++;
        j++;
    }
    for (i = low; i < k; i++) {
        arr[i] = t[i];
    }
}

void merge_sort(int *arr, int low, int high)
{
    int mid;
    if (low < high){
        mid=(low+high)/2;
        merge_sort(arr,low,mid);
        merge_sort(arr,mid+1,high);
        merge(arr,low,high,mid);
    }
}

double Merge(int a[], int counter)
{
    clock_t time = clock();
    merge_sort(a, 0, counter - 1);
    return (double)(clock() - time)/CLOCKS_PER_SEC;
}