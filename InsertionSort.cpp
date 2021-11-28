#include<iostream>
#include <fstream>
#include <time.h>
using namespace std;
int b[1000000];

bool load(int count){
    ifstream sourceFile("SortedDESC.txt");
    if(!sourceFile.is_open()){
        return false;
    } else {
        for (int i = 0; i < count; i++) {
            sourceFile >> b[i];
        }
        sourceFile.close();
        cout << "Loaded\n";
        return true;
    }
}

int main2 ()
{
    int counter = 1000000;
    load(counter);
    clock_t time = clock();

    for(int k=1; k<counter; k++)
    {
        int temp = b[k];
        int j= k-1;
        while(j>=0 && temp <= b[j])
        {
            b[j+1] = b[j];
            j = j-1;
        }
        b[j+1] = temp;
    }
    cout <<"Sorted in " << (double)(clock() - time)/CLOCKS_PER_SEC;

    return 0;
}