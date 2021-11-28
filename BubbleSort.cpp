#include<iostream>
#include <fstream>
#include <time.h>
using namespace std;
int a[1000000];

bool load1(int count){
    ifstream sourceFile("SortedDESC.txt");
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

int main1 (){
    int count = 1000000;
    load1(count);
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
    cout <<"Sorted in " << (double)(clock() - time)/CLOCKS_PER_SEC;

    return 0;
}