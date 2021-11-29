#include <ctime>
#include "Insertion.h"
using namespace std;

double Insertion (int a[], int counter){
    clock_t time = clock();

    for(int k=1; k<counter; k++){
        int temp = a[k];
        int j = k-1;
        while(j>=0 && temp <= a[j]){
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = temp;
    }
    return (double)(clock() - time)/CLOCKS_PER_SEC;
}