#include <ctime>
#include <utility>
#include "Quick.h"
using namespace std;

void quickSort (int arr[], int low, int high){
    int i = low;
    int j = high;
    int x = arr[(low + high) / 2];
    do{
        while (arr[i] < x){i++;}
        while (arr[j] > x){j--;}
        if(i <= j){
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    } while (i <= j);
    if(low < j){quickSort(arr, low, j);}
    if(high > i){ quickSort(arr, i, high);}
}

double Quick (int a[], int count){
    clock_t time = clock();
    quickSort(a, 0, count-1);
    return (double)(clock() - time)/CLOCKS_PER_SEC;
}