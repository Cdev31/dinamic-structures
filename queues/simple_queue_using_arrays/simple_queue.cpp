#include <iostream>

using namespace std;

struct Queue {
    int front, rear, capacity;
    int* queue;

    Queue( int size ): front(0), rear(-1), capacity(size), queue( new int[size]){};

    ~Queue(){ delete[] queue; }

    void queueEnqueue( int data ){
        if( rear == capacity -1 ){
            cout << "\nQueue is full\n";
            return;
        }
        queue[++rear] = data;
    }
};