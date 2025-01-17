#include <iostream>

using namespace std;

struct Node{
    int data;
    Node* next;

    Node( int _data ): data( _data ), next( nullptr ){}
};

class CircularLinkedList{

    Node* head = nullptr;
    Node* tail = nullptr;

    public:
    //Insert methods
    void insertAtBeginning( int data ){

        Node* newNode = new Node( data );

        if( head == nullptr ) {
            tail = newNode;
            head = newNode;
            head->next = head;
            return;
        }

        newNode->next = head;
        head = newNode;
        tail->next = head;

    }

    void insertAtEnd( int data ){

        Node* newNode = new Node( data );

        if( head == nullptr ){
            tail = newNode;
            head = newNode;
            head->next = head;
            return;
        }

        tail->next = newNode;
        tail = newNode;
        tail->next = head;

    }

    void insertAtPosition( int data, int position ){

        if( position == 1 || position == 0){
            cout << "Invalid position" << "\n";
            return;
        }

        Node* newNode = new Node( data );
        Node* currentNode = head;

        int counter = 1;
        while( true ){
            if( counter == ( position -1) ) break;
            currentNode = currentNode->next;
            counter++;
        }
        newNode->next = currentNode->next;
        currentNode->next = newNode; 
    }

    void print(){
        Node* currentNode = head;

        while( currentNode->next != head ){
            cout << currentNode->data << " ";
            currentNode = currentNode->next;
        }
        cout << currentNode->data <<"\n";
    }

};

int main(int argc, char const *argv[])
{
    CircularLinkedList firstList = CircularLinkedList();

    firstList.insertAtEnd(2);

    firstList.print();

    //inserciones adelante
    firstList.insertAtBeginning(3);
    firstList.insertAtBeginning(6);
    firstList.insertAtBeginning(8);
    firstList.insertAtEnd(7);
    firstList.insertAtBeginning(2);

    firstList.print();

    //inserciones en posicion
    firstList.insertAtPosition(34, 4);

    firstList.print();

    return 0;
}

