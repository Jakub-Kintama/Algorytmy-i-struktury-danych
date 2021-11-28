#include <iostream>
#include <fstream>
#include <time.h>
using namespace std;
int c[1000000];
int t[500000];

bool load2(int count){
    ifstream sourceFile("SortedDESC.txt");
    if(!sourceFile.is_open()){
        return false;
    } else {
        for (int i = 0; i < count; i++) {
            sourceFile >> c[i];
        }
        sourceFile.close();
        cout << "Loaded\n";
        return true;
    }
}

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

int main3()
{
    int counter = 1000000;
    load2(counter);
    clock_t time = clock();

    merge_sort(c, 0, counter - 1);
    cout <<"Sorted in " << (double)(clock() - time)/CLOCKS_PER_SEC;

    return 0;
}