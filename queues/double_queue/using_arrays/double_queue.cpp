#include <iostream>

using namespace std;

class Deque{
    int front;
    int rear;
    int size;
    int* array;

    public:
    Deque( int _size ): front(-1), rear(-1), size(_size), array( new int[_size] ){}

    ~Deque(){
        delete[] array;
    }

    public:
    bool isFull(){
        return ( rear + 1 ) == size;
    }

    bool isEmpty(){
        return front == -1;
    }

    void enqueueFront( int data ){

        if( isFull() ){
            cout << "Error: queue is full" << endl;
            return;
        }

        if( isEmpty() ){
            front = 0;
        }

        
        rear = ( rear + 1 ) % size;
        array[rear] = data;

    }

    void enqueueEnd( int data ){

         if( isFull() ){
            cout << "Error: queue is full" << endl;
            return;
        }

        if( isEmpty() ){
            front = 0;
            return;
        }

        for( int i = 0; i < size; i++ ){
            if( array[i] == 0 ){
                array[i] = data;
                rear++;
                break;
            }
        }
    }

    void dequeueEnd(){

        if( isEmpty() ){
            cout << "Error: queue is empty" << endl;
            return;
        }

        for( int i =0; i < size; i++ ){
            if( (i + 1) == size ){
                array[i] = 0;
            }
            else if( array[i + 1] == 0 ){
                array[i] = 0;
            }
        }
        rear--;
    }

    void dequeueFront(){
         
        if( isEmpty() ){
            cout << "Error: queue is empty" << endl;
            return;
        }

        if( front == rear ){
            front = rear = -1;
         }

         else {
            int next = front + 1;
            for( int i = 0; i <= rear; i++){
                array[i] = array[next];
                if( i == rear){
                    array[rear] = 0;
                    rear = i -1;
                }
                next++;
            }
         }

    }

    void peek(){
        cout << "First element: " << array[front] << endl;
    }

    void printAsc(){

        for( int i =0; i < size; i++ ){
            if( array[i] == 0 ) break;
            cout << array[i] << " ";
        }
        cout << endl;
    }

    void printDesc(){

        for( int i = rear; 0 <= i; i-- ){
            cout << array[i] << " ";
        }
        cout << endl;
    }
};

int main(int argc, char const *argv[])
{
    Deque queue = Deque(20);

    cout << "Enqueue front" << endl;
    queue.enqueueFront(2);
    queue.enqueueFront(3);
    queue.enqueueFront(4);
    queue.enqueueFront(1);

    queue.printAsc();
    queue.printDesc();

    cout << "Enqueue end" << endl;

    queue.enqueueEnd(5);
    queue.enqueueEnd(8);
    queue.enqueueEnd(9);

    queue.printAsc();

    cout << "Dequeue front" << endl;

    queue.dequeueFront();

    queue.peek();
    queue.printAsc();

    cout << "Dequeue end" << endl;

    queue.dequeueEnd();
    queue.dequeueEnd();

    queue.printAsc();
    queue.printDesc();

    return 0;
}
