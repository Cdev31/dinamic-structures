#include <iostream>

using namespace std;

struct Node{
    int data;
    Node* next;

    Node( int _data ): data( _data ), next( nullptr){}
};

class MinUnorderedPriorityQueue{
    Node* head = nullptr;
    Node* tail = nullptr;

    public:
    bool isEmpty(){
        return head == nullptr;
    }
    
    void enqueue( int data ){

        Node* newNode = new Node( data );

        if( head == nullptr ) tail = newNode;

        newNode->next = head;
        head = newNode;
    }

    void dequeue(){
        
        Node* currentNode = head;
        Node* minValue = head;
        Node* previus;

        while ( currentNode->next != nullptr ){
            if( minValue->data > currentNode->next->data ){
                minValue = currentNode->next;
                previus = currentNode;
            }
            currentNode = currentNode->next;
        }

        if( minValue->data > tail->data ){
            tail = minValue;
            delete minValue->next;
            return;
        }
    
        if ( minValue == head ){
            head = minValue->next;
            delete minValue;
            return;
        }

        previus->next = minValue->next;
        delete minValue;
    }

    void peek(){}

    void print(){

        if( isEmpty()){
            cout << "Empty list" << endl;
            return;
        }

        Node* currentNode = head;

        while( currentNode->next != nullptr){
            cout << currentNode->data << " ";
            currentNode = currentNode->next;
        }
        cout << currentNode->data << endl;
    }

    void deleteAll(){}
};

class DescendingUnorderedPriorityQueue{};

int main(int argc, char const *argv[])
{
    MinUnorderedPriorityQueue firstQueue = MinUnorderedPriorityQueue();

    cout << "Enqueue " << endl;
    firstQueue.enqueue(2);
    firstQueue.enqueue(3);
    firstQueue.enqueue(4);
    firstQueue.enqueue(1);
    firstQueue.enqueue(9);
    firstQueue.enqueue(8);

    firstQueue.print();

    cout << "Dequeue min value" << endl;

    firstQueue.dequeue();
    firstQueue.dequeue();

    firstQueue.print();
    return 0;
}
