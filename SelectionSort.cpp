#include<iostream>
#include<fstream>
using namespace std;
int d[1000000];

bool load3(int count){
    ifstream sourceFile("Unsorted.txt");
    if(!sourceFile.is_open()){
        return false;
    } else {
        for (int i = 0; i < count; i++) {
            sourceFile >> d[i];
        }
        sourceFile.close();
        cout << "Loaded\n";
        return true;
    }
}

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

int main ()
{
    int counter = 1000000;
    load3(counter);
    clock_t time = clock();

    int pos,temp;
    for(int i=0;i<counter;i++)
    {
        pos = findSmallest (d,i,counter);
        temp = d[i];
        d[i]=d[pos];
        d[pos] = temp;
    }
    cout <<"Sorted in " << (double)(clock() - time)/CLOCKS_PER_SEC;

    return 0;
}