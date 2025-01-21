#include <iostream>

using namespace std;

struct Node{
    int data;
    Node* next;

    Node( int _data ): data( _data ), next( nullptr ){}
};

class SimpleQueue{
    Node* head = nullptr;

    public:

    bool isEmpty(){
        return head == nullptr;
    }

    void enqueue( int data ){
        
        Node* newNode = new Node( data );

        if( head == nullptr ){
            newNode->next = head;
            head = newNode;
            return;
        }

        Node* currentNode = head;

        while( currentNode->next != nullptr ){
            currentNode = currentNode->next;
        }

        currentNode->next = newNode;
    }

    void dequeue(){
        if( isEmpty() ){
            cout << "Error: Empty queue" << endl;
            return;
        }
        Node* firstNode = head;
        head = firstNode->next;

        delete firstNode;
    }

    void peek(){
        cout << "First element: " << head->data << endl;
    }

    void printQueue(){
        Node* currentNode = head;

        while( currentNode->next != nullptr ){
            cout << currentNode->data << " ";
            currentNode = currentNode->next;
        }

        cout << currentNode->data << "\n";
    }


};


int main(int argc, char const *argv[])
{
    SimpleQueue queue = SimpleQueue();

    queue.enqueue(2);
    queue.enqueue(4);
    queue.enqueue(5);
    queue.enqueue(6);

    queue.printQueue();
    queue.peek();

    queue.dequeue();

    queue.printQueue();

    return 0;
}
