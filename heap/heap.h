//
//  heap.h
//  heap
//
//  Created by zhangalice on 6/27/21.
//

#ifndef heap_h
#define heap_h

#include <stdio.h>

#include <iostream>
using namespace std;

template<typename T>
class Heap{
private:
    int capacity;
    int length;
    T* heap;

public:
    
    Heap(int capacity){
        this->capacity = capacity;
        length = 0;
        heap = new T[capacity];
    }

    //return type is ostream &
    // output is stream, put element in output stream
    friend ostream &operator << (ostream &output, const Heap &p){
        for(int i=0; i<p.length; i++){
            output << p.heap[i] << ' ';
        }
        return output;
    }

    int left(int i){
        return i * 2 + 1;
    }

    int right(int i){
        return i * 2 + 2;
    }

    int parent(int i){
        return (i - 1) / 2;
    }

    void buildHeap(){
        for(int i = (length/2 - 1); i >=0; i--){
            heapifyDown(i);
        }
    }

    void heapifyDown(int i){
        int l = left(i);
        int r = right(i);
        int maxIndex = i;
        if(l < length && (heap[l] > heap[i])){
            maxIndex = l;
        }

        //for all T, overload the > operator
        if(r < length && (heap[r] > heap[maxIndex])){
            maxIndex = r;
        }

        if(i != maxIndex){
            swap(i, maxIndex);
            heapifyDown(maxIndex);
        }
    }

    void swap(int i, int maxIndex){
       T temp = heap[i];
        heap[i] = heap[maxIndex];
        heap[maxIndex] = temp;
    }

    void insert(int newValue){
        length++;
        heap[length-1] = newValue;
        heapifyUp(length-1);
    }

    void heapifyUp(int i){
        int p = parent(i);
        if(p >=0 && heap[i] > heap[p]){
            swap(i, p);
            heapifyUp(p);
        }
    }

    bool isEmpty(){
        return length == 0;
    }

    int pop(){
        swap(0, length-1);
        T temp = heap[length-1];
        length--;
        if(length == 0){
            return temp;
        }
        heapifyDown(0);
        return temp;
    }

    T* sort(){
        T* array = new T[length];
        //T array[length];
        for(int i=0; i<length;i++){
            array[i] = pop();
        }
        return array;
    }
    
    ~Heap(){
        delete [] heap;
    }
};

#endif /* heap_h */

