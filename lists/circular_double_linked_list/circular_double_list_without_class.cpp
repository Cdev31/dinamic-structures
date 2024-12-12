#include <iostream>

using namespace std;

struct Node{
    int data;
    Node* next;
    Node* previus;

    Node( int _data ): data( _data ), next( nullptr ), previus( nullptr ){};
};


void insertAtBeginningToList( Node*& head, Node*& tail, int value ){

    Node* newNode = new Node( value );
    if( head == nullptr ){
        head = newNode;
        tail = newNode;
        head->next = tail;
        tail->next = head;
        tail->previus = head;
        head->previus = tail;
        return;
    }

    newNode->next = head;
    head->previus = newNode;
    newNode->previus = tail;
    tail->next = newNode;
    head = newNode;
}

void insertAtEndToList( Node*& head, Node*& tail, int value ){

    if( head == nullptr ) return;

    Node* newNode = new Node( value );
    newNode->previus = tail;
    tail->next = newNode;
    newNode->next = head;
    tail = newNode;

}

void insertPositionToList(){

}

void deletePositionNode(){

}

void printAscList( Node* head ){
    Node* currentNode = head->next;

    while( true ){
        cout << currentNode->data << " ";
        if( currentNode->next == head->next ) break;
        currentNode = currentNode->next; 
    }
    cout << "\n";

}

void printDescList( Node* tail ){
    Node* currentNode = tail->previus;

    while( true ){
        cout << currentNode->data << " ";
        if( currentNode->previus == tail->previus ) break;
        currentNode = currentNode->previus;
    }
    cout << "\n";
}


int main (){

    Node* firstNode = nullptr;
    Node* endNode = nullptr;

    insertAtBeginningToList( firstNode, endNode, 1 );
    insertAtBeginningToList( firstNode, endNode, 2 );
    insertAtBeginningToList( firstNode, endNode, 3 );
    insertAtBeginningToList( firstNode, endNode, 4 );
    insertAtBeginningToList( firstNode, endNode, 5 );

    printAscList( endNode );
    printDescList( firstNode );
  
}

