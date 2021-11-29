#include <iostream>
#include <fstream>
#include "Bubble.h"
#include "Merge.h"
#include "Quick.h"
#include "Selection.h"
#include "Insertion.h"
#include "Heap.h"
using namespace std;
int a[1000000];
int loadTimes = 0;

void printTimes(string S, double R, double A, double D) {
    cout << S << ":\n" << " Random - " << R << "\n Ascending - " << A << "\n Descending - " << D << endl;
}

bool load(int count, string fileName){
    ifstream sourceFile(fileName);
    if(!sourceFile.is_open()){
        cout << "Cant load file\n";
        return false;
    } else {
        for (int i = 0; i < count; i++) {
            sourceFile >> a[i];
        }
        sourceFile.close();
        cout << "Loaded " << ++loadTimes << "/18" << endl;
        return true;
    }
}

int main() {
    string ran = "Unsorted.txt";
    string asc = "SortedASC.txt";
    string des = "SortedDESC.txt";
    int count = 1000000;

    if(!load(count, ran)){
        return 1;
    }
    double QuickR = Quick(a, count);
    if(!load(count, asc)){
        return 1;
    }
    double QuickA = Quick(a, count);
    if(!load(count, des)){
        return 1;
    }
    double QuickD = Quick(a, count);

    if(!load(count, ran)){
        return 1;
    }
    double HeapR = Heap(a, count);
    if(!load(count, asc)){
        return 1;
    }
    double HeapA = Heap(a, count);
    if(!load(count, des)){
        return 1;
    }
    double HeapD = Heap(a, count);

    if(!load(count, ran)){
        return 1;
    }
    double MergeR = Merge(a, count);
    if(!load(count, asc)){
        return 1;
    }
    double MergeA = Merge(a, count);
    if(!load(count, des)){
        return 1;
    }
    double MergeD = Merge(a, count);

    if(!load(count, ran)){
        return 1;
    }
    double InsertionR = Insertion(a, count);
    if(!load(count, asc)){
        return 1;
    }
    double InsertionA = Insertion(a, count);
    if(!load(count, des)){
        return 1;
    }
    double InsertionD = Insertion(a, count);

    if(!load(count, ran)){
        return 1;
    }
    double SelectionR = Selection(a, count);
    if(!load(count, asc)){
        return 1;
    }
    double SelectionA = Selection(a, count);
    if(!load(count, des)){
        return 1;
    }
    double SelectionD = Selection(a, count);

    if(!load(count, ran)){
        return 1;
    }
    double bubbleR = Bubble(a, count);
    if(!load(count, asc)){
        return 1;
    }
    double bubbleA = Bubble(a, count);
    if(!load(count, des)){
        return 1;
    }
    double bubbleD = Bubble(a, count);

    printTimes("QuickSort", QuickR, QuickA, QuickD);
    printTimes("HeapSort", HeapR, HeapA, HeapD);
    printTimes("MergeSort", MergeR, MergeA, MergeD);
    printTimes("InsertionSort", InsertionR, InsertionA, InsertionD);
    printTimes("SelectionSort", SelectionR, SelectionA, SelectionD);
    printTimes("BubbleSort", bubbleR, bubbleA, bubbleD);
    
    return 0;
}