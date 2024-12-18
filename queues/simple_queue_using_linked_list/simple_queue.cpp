#include <iostream>

using namespace std;

struct Node{
    int data;
    Node* next;

    Node( int _data ): data( _data ), next( nullptr ){}
};

void enqueue( Node*& front, Node*& rear, int value ){

    Node* newNode = new Node( value );

    if( front == nullptr ){
        front = newNode;
        rear = newNode;
        return;
    }
    rear->next = newNode;
    rear = newNode;
}

void dequeue( Node*& front ){
    if( front == nullptr ){
        cout << "Is empty\n";
        return;
    }
    front = front->next;
}

void showQueue( Node* front ){
    Node* currentNode = front;

    while( currentNode != nullptr ){
        cout << currentNode->data << " ";
        currentNode = currentNode->next;
    }
    cout << "\n";
}


int main(){
    Node* front = nullptr;
    Node* rear = nullptr;

    enqueue( front, rear, 3);
    enqueue( front, rear, 5);
    enqueue( front, rear, 8);
    enqueue( front, rear, 2);
    enqueue( front, rear, 3);
    enqueue( front, rear, 9);

    showQueue( front );

    dequeue( front );

    showQueue( front );
}