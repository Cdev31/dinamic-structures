#include <iostream>

using namespace std;

struct Node{
    int data;
    Node* next;
    Node* previus;

    Node( int _data ): data( _data ), next( nullptr ), previus( nullptr ){}
};

class CircularDoubleLinkedList{
    
    Node* head = nullptr;
    Node* tail = nullptr;

    public:
    //insert methods
    void insertAtBeginnig( int data ){
        Node* newNode = new Node( data );
        
        if( head == nullptr){
            head = tail = newNode;
            head->next = head;
            head->previus = head;
            return;
        }

        newNode->next = head;
        head->previus = newNode;
        head = newNode;
        head->previus = tail;
        tail->next = head;
    }

    void insertAtEnd( int data ){

        Node* newNode = new Node( data );
        
        if( head == nullptr){
            head = tail = newNode;
            head->next = head;
            head->previus = head;
            return;
        }

        tail->next = newNode;
        newNode->previus = tail;
        tail = newNode;
        tail->next = head;
        head->previus = tail;
    }

    void insertAtPosition( int data, int position ){

        Node* currentNode = head;
        Node* newNode = new Node( data );

        int counter = 1;
        while( currentNode->next != head ){
            if( counter == position) break;;
            currentNode = currentNode->next;
            counter++;
        }

        newNode->next = currentNode;
        newNode->previus = currentNode->previus;
        currentNode->previus->next = newNode;
        currentNode->previus = newNode;
    }

    void printAsc(){
        Node* currentNode = head;

        while( currentNode->next != head){
            cout << currentNode->data << " ";
            currentNode = currentNode->next;
        }
        cout << currentNode->data << "\n";
    }

    void printDesc(){
        Node* currentNode = tail;

        while( currentNode != head){
            cout << currentNode->data << " ";
            currentNode = currentNode->previus;
        }
        cout << currentNode->data << "\n";
    }
};



int main(int argc, char const *argv[])
{
    CircularDoubleLinkedList firstList = CircularDoubleLinkedList();

    //Insertar al final

    firstList.insertAtEnd(9);
    firstList.insertAtEnd(11);
    firstList.insertAtEnd(12);

    firstList.printAsc();

    //Insertar al inicio
    firstList.insertAtBeginnig(2);
    firstList.insertAtBeginnig(3);
    firstList.insertAtBeginnig(8);
    firstList.insertAtBeginnig(1);
    firstList.insertAtBeginnig(9);
    firstList.insertAtBeginnig(6);
    
    firstList.printAsc();

    //Insertar posicion

    firstList.insertAtPosition( 13, 4);
    firstList.insertAtPosition( 14, 4);

    firstList.printAsc();
    firstList.printDesc();

    return 0;
}
