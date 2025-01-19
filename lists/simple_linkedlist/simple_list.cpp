#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;

    //constructor
    Node( int _data ): data( _data ), next(nullptr){} 

}; 

class LinkedList{

    // head pointer
    Node* head = nullptr;

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
    
   // insert methods
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

        int counter = 1;
        while( currentNode->next != nullptr ){
            if( counter == ( position -1 )) break;
            currentNode = currentNode->next;
            counter++;
        }
        newNode->next = currentNode->next;
        currentNode->next = newNode;
    }

    // delete methods

    void deleteAtBeginning( ){

        if( head == nullptr ){
            cout << "Empty list" << endl;
            return;
        }

        Node* temporalNode = head;
        head = head->next;

        delete temporalNode;
    }

    void deleteAtEnd(){

        if( head == nullptr ){
            cout << "Empty list" << endl;
            return;
        }

        if( head->next == nullptr ){
            delete head;
            return;
        }

        Node* currentNode = head;

        while( currentNode->next->next != nullptr ){
            currentNode = currentNode->next;
        }

        delete currentNode->next;

        currentNode->next = nullptr;

    }

    void deleteAtPosition( int position ){

        if( position == 0 || position == 1 ){
            cout << "Invalid position" << endl;
            return;
        }

        Node* currentNode = head;
    
        int counter = 1;
        while( currentNode->next != nullptr ){
            if( counter == ( position -1 )) break;
            currentNode = currentNode->next;
            counter++;
        }

        Node* temporalNode = currentNode->next;
        
        currentNode->next = temporalNode->next;
        delete  temporalNode;
    }


    // print methods
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
    LinkedList thirdList = LinkedList();

    cout << "evaluacion de metodos de insercion" << endl;
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
    thirdList.insertAtBeginning(2);
    thirdList.insertAtBeginning(3);
    thirdList.insertAtBeginning(4);
    thirdList.insertAtPosition(2,2);

    thirdList.print();
    cout << endl;

    cout << "evaluacion de metodos de eliminacion" << endl;
    // test about delete elements

    LinkedList quarterList = LinkedList();

    quarterList.insertAtBeginning(1);
    quarterList.insertAtBeginning(2);
    quarterList.insertAtBeginning(3);
    quarterList.insertAtBeginning(4);
    quarterList.insertAtBeginning(5);
    quarterList.insertAtBeginning(6);
    quarterList.insertAtBeginning(7);
    quarterList.insertAtBeginning(8);
    quarterList.insertAtBeginning(9);
    quarterList.insertAtBeginning(10);

    //before print
    quarterList.print();

    //delete first element
    quarterList.deleteAtBeginning();

    //after print
    quarterList.print();

    //delete final element
    quarterList.deleteAtEnd();

    //after print
    quarterList.print();

    //delet position
    quarterList.deleteAtPosition(5);

     //after print
    quarterList.print();

    return 0;
}
