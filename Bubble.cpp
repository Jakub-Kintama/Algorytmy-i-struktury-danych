#include <ctime>
#include "Bubble.h"
using namespace std;

int Bubble (int a[], int count){
    clock_t time = clock();
    int i, j,temp;
    for(i = 0; i < count; i++) {
        for(j = i+1; j < count; j++)
        {
            if(a[j] < a[i]) {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
    return (double)(clock() - time)/CLOCKS_PER_SEC;
}