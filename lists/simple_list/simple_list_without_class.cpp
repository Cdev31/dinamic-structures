#include <iostream>
#include <cstdlib>

using namespace std;

// our node
struct Node{
    int data;
    Node* next;

    Node( int _data ): data(_data), next(nullptr){}
};

// function to insert a newNode at the end of the list
void insertAtEnd( Node*& head , int value ){

    Node* newNode = new Node(value);

    Node* currentNode = head;

    while( currentNode->next != nullptr ){
        currentNode = currentNode->next;
    }    
    currentNode->next = newNode;
}
//function to inser a new Node at start of the list
void insertAtBeginning( Node*& head, int value ){
    
    Node* newNode = new Node(value);

    newNode->next = head;
    head = newNode;

}

void insertNodeWithPosition( Node*& head, int position, int value ){

    Node* newNode = new Node( value );
    Node* currentNode = head;

    if( position == 1 ){
        insertAtBeginning( head, value );
        return;
    }

    int count = 1;
    while( currentNode != nullptr ){
        if( count == position - 1 ) break;
        currentNode = currentNode->next;
        count++;
    }
    
    if( currentNode == nullptr ) return;

    newNode->next = currentNode->next;
    currentNode->next = newNode;
}

void enlisList( Node* firsNode  ){
   
    Node* currentNode = firsNode;

    while( currentNode != nullptr ){
        cout << currentNode->data << " ";
        currentNode = currentNode->next;
    }
    cout << "\n";
}

int main(){

    Node* firstNode = nullptr;

    insertAtBeginning( firstNode, 3);
    insertAtEnd( firstNode, 1);
    insertAtBeginning( firstNode, 4);
    insertAtEnd( firstNode, 9);
    insertAtBeginning( firstNode , 6);
    insertNodeWithPosition( firstNode, 9, 10);

    enlisList( firstNode);
}