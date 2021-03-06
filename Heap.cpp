#include<iostream>
#include <ctime>
#include "Heap.h"
using namespace std;

void heapify(int arr[], int n, int root)
{
    int largest = root;
    int l = 2*root + 1;
    int r = 2*root + 2;

    if (l < n && arr[l] > arr[largest])
        largest = l;

    if (r < n && arr[r] > arr[largest])
        largest = r;

    if (largest != root)
    {
        swap(arr[root], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (int i=n-1; i>=0; i--)
    {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

double Heap (int a[], int counter){
    clock_t time = clock();
    heapSort(a, counter);
    return (double)(clock() - time)/CLOCKS_PER_SEC;
}