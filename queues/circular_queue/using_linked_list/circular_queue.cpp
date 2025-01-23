 #include <iostream>

using namespace std;

struct Node{
    int data;
    Node* next;

    Node( int _data ): data( _data ), next( nullptr ){}
};

class CircularQueue{
    Node* head = nullptr;
    Node* tail = nullptr;

    public:
    bool isEmpty(){}

    void enqueue( int data ){
        
        Node* newNode = new Node( data );

        if( head == nullptr ){
            tail = newNode;
        }

        newNode->next = head;
        head = newNode;
        tail->next = head;

    }

    void dequeue(){}

    void peek(){}



};
