#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;

    Node( int _data ): data( _data ), next(nullptr){} 
}; 

class LinkedList{

    Node* head = nullptr;
    Node* tail = nullptr;

    public:
    int size(){
        Node* currentNode = head;

        int counter = 0;
        while( currentNode->next != nullptr ){
            currentNode= currentNode->next;
            counter++;
        }
        return counter;
    }
   //metodos de insercion
    void insertAtEnd( int data ){

        Node* newNode = new Node( data );
        Node* currentNode = head;

        if( head == nullptr ){
            newNode->next = head;
            head = newNode;
            return;
        }

        while( currentNode->next != nullptr ){
            currentNode = currentNode->next;
        }

        currentNode->next = newNode;

    }

    void insertAtBeginning( int data ){
        
        Node* newNode = new Node( data );
        newNode->next = head;
        head = newNode;

    }

    void insertAtPosition( int data, int position ){

        if( position == 0 || position == 1 ){
            cout << "Invalid position" << "\n";
            return;
        }

        Node* newNode = new Node( data );
        Node* currentNode = head;

        int counter = 0;
        while( currentNode->next != nullptr ){
            if( counter == ( position -1 )) break;
            counter++;
        }
        newNode->next = currentNode->next;
        currentNode->next = newNode;
    }



    void print(){
        
        if( head == nullptr ){
            cout << "Empty list" << "\n";
            return;
        }

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
    LinkedList firstList = LinkedList();
    LinkedList secondList = LinkedList();
    LinkedList threthList = LinkedList();

    //insertar al inicio
    firstList.insertAtBeginning(3);
    firstList.insertAtBeginning(5);
    firstList.insertAtBeginning(7);
    firstList.insertAtBeginning(3);
    firstList.insertAtBeginning(8);

    //primera impresion para insertar en el inicio
    firstList.print();

    //insertar al final
    secondList.insertAtEnd(4);
    secondList.insertAtEnd(8);
    secondList.insertAtBeginning(5);

    //segunda impresion para insertar al final
    secondList.print();

    //insertar en una posicion
    threthList.insertAtPosition(2,1);

    threthList.print();

 
    return 0;
}
