#include <iostream>

using namespace std;

struct Node{
    int data;
    Node* next;
    Node* previus;

    Node( int _data ): data( _data ), next( nullptr ), previus( nullptr ){}

};


class DoubleLinkedList{

    Node* head = nullptr;
    Node* tail = nullptr;

    public: 
    // Insert methods
    void insertAtbeginning( int data ){

        Node* newNode = new Node( data );
        newNode->next = head;

        if( head == nullptr ) tail = newNode;
        if( head != nullptr ) head->previus = newNode;
        
        head = newNode;

    }

    void insertAtEnd( int data ){
        
        Node* newNode = new Node( data );
        Node* currentNode = tail;

        if( head == nullptr ) {
            head = newNode;
            tail = newNode;
            return;
        }

        newNode->previus = tail;
        tail->next = newNode;
        tail = newNode;
    }

    void insertAtPosition( int data, int position ){

        if( position == 0 || position == 1 ){
            cout << "Position invalid" << "\n";
            return;
        }

        Node* newNode = new Node( data );
        Node* currentNode = head;

        int counter = 1;
        while(true){
            if( counter == ( position -1 )) break;
            currentNode = currentNode->next;
            counter++;
        }
       
        currentNode->next->previus = newNode;
        newNode->next = currentNode->next;
        newNode->previus = currentNode;
        currentNode->next = newNode;
    }

    // Delete methods

    void deleteAtBiginning(){

        Node* currentNode = head;
        head = head->next;

        delete currentNode;

    }

    void deleteAtEnd(){

        if( head == nullptr){
            cout << "Empty list" << "\n";
            return;
        }

        Node* currentNode = tail;

        if( tail = head){
            head = nullptr;
            tail = nullptr;
        }
        tail = tail->previus;
        tail->next = nullptr;
        
        delete currentNode;       

    }

    void deleteAtPosition( int position ){

        Node* currentNode = head;

        int counter = 1;
        while( true ){
            if( counter == position ) break;
            currentNode = currentNode->next;
            counter++;
        }

        Node* temporalNode = currentNode;

        currentNode->previus->next = currentNode->next;
        currentNode->next->previus = currentNode->previus;

        currentNode->next = nullptr;
        currentNode->previus = nullptr;

        delete temporalNode;


    }
    

    // Print methods
    void printAsc(){
        Node* firstNode = head;

        while( firstNode->next != nullptr ){
            cout << firstNode->data << " ";
            firstNode = firstNode->next;
        }
        cout << firstNode->data << "\n";
    }

    void printDesc(){
         Node* lastNode = tail;

        while( lastNode->previus != nullptr ){
            cout << lastNode->data << " ";
            lastNode = lastNode->previus;
        }
        cout << lastNode->data << "\n";
    }


};




int main(int argc, char const *argv[])
{
    //Pruebas de insercion
    DoubleLinkedList firstList = DoubleLinkedList();

    //control de error insertar primero atras
    firstList.insertAtEnd(2);
    //impresion de control
    firstList.printAsc();

    //inserciones normales adelante
    firstList.insertAtbeginning(4);
    firstList.insertAtbeginning(6);
    firstList.insertAtbeginning(7);
    firstList.insertAtbeginning(2);
    firstList.insertAtbeginning(8);

    firstList.printAsc();

    //inserciones por posicion

    firstList.insertAtPosition(3, 1);

    firstList.insertAtPosition(28,3);

    firstList.printAsc();

    //Pruebas de eliminacion

    //eliminacion al inicio
    firstList.deleteAtBiginning();

    firstList.printAsc();

    //eliminacion al final
    firstList.deleteAtEnd();

    firstList.printAsc();

    //eliminacion posicion
    firstList.deleteAtPosition(3);

    firstList.printAsc();

    return 0;
}
