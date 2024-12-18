#include <iostream>

using namespace std;

struct DoubleEndedQueue{
    int front;
    int rear;
    int capacity;
    int *queue;

    DoubleEndedQueue( int size ): front(0), rear(-1), capacity( size), queue( new int[size]){}

    ~DoubleEndedQueue(){ delete[] queue; }


    bool isEmpty(){
        return front > rear;
    }

    bool isFull(){
        return ( rear - front + 1 ) == capacity;
    }

    void enqueueFront( int data ){
        if( isFull() ){
            cout << "Is full\n";
            return;
        }

        if( front == -1 ){
            front =0;
            rear = 1;
        }
        else if( front == 0){
            front = capacity -1;
        }
        else {
            front--;
        }

        queue[front] = data;

    }
};