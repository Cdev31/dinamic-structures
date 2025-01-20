#include <iostream>

using namespace std;

class SimpleQueue{

    private:
       int front;
       int rear;
       int size;
       int* array;

    public: 
       SimpleQueue( int capacity ): size( capacity ), array( new int[size] ),
                                    front( -1 ), rear( -1 ){}
    
       ~SimpleQueue(){
        delete[] array;
       }

       //methods
       bool isFull() const {
         return ( rear + 1 ) % size == front;
       }

       bool isEmpty() const {
         return front == -1;
       }

       void enqueue( int value ){
          
          if( isFull() ){
            cout << "Queue is full" << "\n";
            return;
          }

          if( isEmpty() ){
            front = 0;
          }

          rear = ( rear + 1 ) % size;
          array[rear] = value;
       }

       void dequeue(){
         
         if( isEmpty()){
            cout << "Queue is empty" << "\n";
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

       void peek() {
        if( isEmpty() ){
            cout << "Error: Queue is empty" << "\n";
            return;
        }
        cout << array[front] << "\n";
       }

       void printQueue(){
         
         for( int index = 0; size > index; index++ ){
            if( array[index] == 0 ) break;
            cout << array[index] << " ";
         }
         cout << "\n";

       }



};

int main(int argc, char const *argv[])
{
    SimpleQueue queue = SimpleQueue(20);

    queue.enqueue(2);
    queue.enqueue(4);
    queue.enqueue(5);
    queue.enqueue(1);
    queue.enqueue(6);
    queue.enqueue(8);
    queue.enqueue(9);

    queue.printQueue();

    queue.dequeue();
    queue.dequeue();
    queue.dequeue();

    queue.printQueue();

    return 0;
}
