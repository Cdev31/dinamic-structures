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

    //Delete methods
    void deleteAtBeginning(){
        
        Node* firstNode = head;
        head = firstNode->next;
        tail->next = head;

        delete firstNode;
    }

    void deleteAtEnd(){

        Node* currentNode = head;

        while( currentNode->next != tail ){
            currentNode = currentNode->next;
        }

        Node* temporalNode = currentNode->next;

        currentNode->next = head;
        tail = currentNode;

        delete temporalNode;
    }

    void deleteAtPosition( int position ){

        if( position == 0 || position == 1 ){
            cout << "Invalid position" << endl;
            return;
        }
        
        Node* currentNode = head;

        int counter = 1;
        while( currentNode->next != head ){
            if( counter == ( position -1 ) ) break;
            currentNode = currentNode->next;
            counter++;
        }

        Node* temporalNode = currentNode->next;

        currentNode->next = currentNode->next->next;

        delete temporalNode;

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
    firstList.insertAtBeginning(9);
    firstList.insertAtBeginning(4);
    firstList.insertAtBeginning(1);

    firstList.print();

    //inserciones en posicion
    firstList.insertAtPosition(34, 4);

    firstList.print();

    //eliminacion inicio
    firstList.deleteAtBeginning();

    firstList.print();

    //eliminacion al final

    firstList.deleteAtEnd();

    firstList.print();

    //eliminacion posicion

    firstList.deleteAtPosition(3);

    firstList.print();

    return 0;
}

