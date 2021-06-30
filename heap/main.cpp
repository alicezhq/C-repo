//
//  main.cpp
//  heap
//
//  Created by zhangalice on 6/25/21.
//


#include <stdio.h>
#include <iostream>
#include "heap.h"
using namespace std;

int main(int argc, const char * argv[]) {
    Heap<int> heap(10);

    heap.insert(9);
    cout << heap << endl;
    
    heap.insert(8);
    cout << heap << endl;
    heap.insert(20);
    cout << heap << endl;
    heap.insert(99);
    cout << heap << endl;
    cout << heap.pop() << endl;
    cout << heap << endl;
    cout << heap.isEmpty() << endl;
    heap.buildHeap();
    heap.sort();

    cout << heap << endl;

    return 0;
}


