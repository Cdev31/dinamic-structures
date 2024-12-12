#include <iostream>

using namespace std;

struct Node{
    int data;
    Node* next;

    Node( int _data ): data(_data), next(nullptr){}
};

void insertAtBeginningToList( Node*& head, Node*& endNode, int value ){
    Node* newNode = new Node( value );

    if( head == nullptr ){
        endNode = newNode;
        head = newNode;
        newNode->next = newNode;
    }
    else {
        newNode->next = head;
        endNode->next = newNode;
        head = newNode;
    }
    
}

void printList( Node* end ){
    Node* head = end->next;

    while( true ){
        cout << head->data << " ";
        head = head->next;
        if( head == end->next) break;
    }
    cout << "\n";

}

int main(){

    Node* firstNode = nullptr;
    Node* lastNode = nullptr;

    insertAtBeginningToList( firstNode, lastNode, 1);
    insertAtBeginningToList( firstNode, lastNode, 2);
    insertAtBeginningToList( firstNode, lastNode, 3);
    insertAtBeginningToList( firstNode, lastNode, 4);
    insertAtBeginningToList( firstNode, lastNode, 5);

    printList( lastNode );
    

}
