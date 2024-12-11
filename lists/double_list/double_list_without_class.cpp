#include <iostream>

using namespace std;

struct Node{
    int data;
    Node* next;
    Node* previus;

    Node( int _data ): data( _data ), next( nullptr ), previus( nullptr ){}
};

void printListDesc( Node* head ){
    Node* currentNode = head;
    
    while( currentNode != nullptr ){
        cout << currentNode->data << " ";
        currentNode = currentNode->next;
    }
    cout << "\n";
}

void printListAsc( Node* tail ){
     Node* currentNode = tail;
    
    while( currentNode != nullptr ){
        cout << currentNode->data << " ";
        currentNode = currentNode->previus;
    }
    cout << "\n";
}

void insertAtBeginningToList( Node*& head, Node*& tail, int value ){
    Node* newNode = new Node( value );

    if( head == nullptr ){
        tail = newNode;
    }
    newNode->next = head;
    if( head != nullptr){
        head->previus = newNode;
    }
    head = newNode;
}


void insertPositionList( Node* head, int position, int value ){
    
    Node* newNode = new Node( value );
    Node* currentNode = head;
    
    int count = 0;
    while( currentNode != nullptr ){
        if( count == position  ) break;
        count++;
        currentNode = currentNode->next;
    }

    newNode->previus = currentNode->previus;
    currentNode->previus->next = newNode;
    newNode->next = currentNode;
    currentNode->previus = newNode;

}

int main(){
    Node* firstNode = nullptr;
    Node* endNode = nullptr;

    insertAtBeginningToList(firstNode, endNode, 1);
    insertAtBeginningToList(firstNode, endNode, 2);
    insertAtBeginningToList(firstNode, endNode, 3);
    insertAtBeginningToList(firstNode, endNode, 4);
    insertAtBeginningToList(firstNode, endNode, 5);
    insertPositionList( firstNode, 3, 10 );

    printListDesc(firstNode);
    printListAsc(endNode);
}