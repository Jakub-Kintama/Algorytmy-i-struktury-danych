#include<iostream>
#include <fstream>
#include <time.h>
using namespace std;
int a[1000000];

bool load(int count){
    ifstream sourceFile("SortedASC.txt");
    if(!sourceFile.is_open()){
        return false;
    } else {
        for (int i = 0; i < count; i++) {
            sourceFile >> a[i];
        }
        sourceFile.close();
        cout << "Loaded\n";
        return true;
    }
}

void swap(int* a1, int* b)
{
    int t = *a1;
    *a1 = *b;
    *b = t;
}

int partition (int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = (low - 1);
    for (int j = low; j <= high- 1; j++)
    {
        if (arr[j] <= pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pivot = partition(arr, low, high);
        quickSort(arr, low, pivot - 1);
        quickSort(arr, pivot + 1, high);
    }
}

int main (){
    int count = 1000000;
    load(count);
    clock_t time = clock();

    quickSort(a, 0, count-1);
    cout <<"Sorted in " << (double)(clock() - time)/CLOCKS_PER_SEC;

    return 0;
}