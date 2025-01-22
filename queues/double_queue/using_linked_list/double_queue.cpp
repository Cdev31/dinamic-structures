#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
    Node* previus;

    Node( int _data ): data( _data ), next( nullptr ), previus( nullptr){}
};

class Deque{

    Node* head = nullptr;
    Node* tail = nullptr;

    public:

    void enqueueFront( int data ){

        Node* newNode = new Node( data );
        newNode->next = head;

        if( head == nullptr ) tail = newNode;
        if( head != nullptr  ) head->previus = newNode;
        
        head = newNode;
        
    }

    void enqueueEnd( int data ){

        Node* newNode = new Node( data );

        if( head == nullptr ){
            enqueueFront(data);
            return;
        }
        tail->next = newNode;
        newNode->previus = tail;
        tail = newNode;
    }

    void dequeueFront(){

        if( head == nullptr ){
            cout << "Error: Queue is empty" << endl;
            return;
        }

        Node* firstNode = head;

        head = firstNode->next;

        delete firstNode;
    }

    void dequeueEnd(){

        if( head == nullptr ){
            cout << "Error: Queue is empty" << endl;
            return;
        }

        Node* lastNode = tail;

        
        tail = lastNode->previus;
        tail->next = nullptr;

        delete lastNode;
    }

    void peek(){
        cout << head->data << endl;
        return;
    }

    void printAsc(){
        
        Node* firstNode = head;

        while( firstNode->next != nullptr ){
            cout << firstNode->data << " ";
            firstNode = firstNode->next;
        }
        cout << firstNode->data << endl;
    }

    void printDesc(){
        Node* lastNode = tail;

        while( lastNode->previus != nullptr ){
            cout << lastNode->data << " ";
            lastNode = lastNode->previus;
        }
        cout << endl;
    }
};

int main(int argc, char const *argv[])
{
    Deque queue = Deque();

    cout << "Enqueue end: " << endl;
    queue.enqueueEnd(3);
    queue.enqueueEnd(4);
    queue.enqueueEnd(1);
    queue.enqueueEnd(2);

    queue.peek();
    queue.printAsc();

    cout << "Enqueue front: " << endl;

    queue.enqueueFront(5);
    queue.enqueueFront(9);
    queue.enqueueFront(8);
    queue.enqueueFront(7);

    queue.printAsc();

    cout << "Dequeue front: " << endl;

    queue.dequeueFront();

    queue.printAsc();

    cout << "Dequeue end: " << endl;

    queue.dequeueEnd();
    queue.dequeueEnd();

    queue.printAsc();
    queue.printDesc();

    return 0;
}
