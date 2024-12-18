#include <iostream>

using namespace std;

struct Queue {
    int front, rear, capacity;
    int* queue;

    Queue( int size ): front(0), rear(-1), capacity( size ), queue( new int[size] ){}

    ~Queue(){ delete[] queue; }
};

bool isFull( const Queue& queue){
    return ( queue.rear - queue.front + 1) == queue.capacity;
}

bool isEmpty( const Queue& queue ){
    return queue.front > queue.rear;
}

void enqueue( Queue& queue, int value ){
    if( isFull(queue)){
        cout << "is full\n";
        return ;
    }
    queue.queue[++queue.rear] = value;
}

int dequeue( Queue& queue ){
    if( isEmpty( queue) ){
        cout << "is empty\n";
        return -1;
    }
    int value = queue.queue[queue.front];
    queue.front++;
    return value;
}

void showQueue( Queue& queue ){
    for( int i = queue.front; i <= queue.rear; i++ ){
        cout << queue.queue[i] << " ";
    }
    cout << "\n";
}


int main(){

    Queue queue = Queue(8);

    enqueue( queue, 10);
    enqueue( queue, 18);
    enqueue( queue, 23);
    enqueue( queue, 4);
    enqueue( queue, 2);

    showQueue( queue);

    dequeue( queue );

    showQueue( queue );

}

