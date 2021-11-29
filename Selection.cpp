#include <ctime>
#include "Selection.h"
using namespace std;

int findSmallest(int myArray[],int i, int counter)
{
    int ele_small,position,j;
    ele_small = myArray[i];
    position = i;
    for(j=i+1;j< counter;j++)
    {
        if(myArray[j]<ele_small)
        {
            ele_small = myArray[j];
            position=j;
        }
    }
    return position;
}

double Selection (int a[], int counter){
    clock_t time = clock();
    int pos,temp;
    for(int i=0;i<counter;i++)
    {
        pos = findSmallest (a,i,counter);
        temp = a[i];
        a[i]=a[pos];
        a[pos] = temp;
    }
    return (double)(clock() - time)/CLOCKS_PER_SEC;
}