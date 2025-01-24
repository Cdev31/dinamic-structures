#include <iostream>

using namespace std;

struct Node{
    int data;
    Node* next;

    Node( int _data ): data( _data ), next( nullptr){}
};

class AscendingUnorderedPriorityQueue{
    Node* head = nullptr;

    public:
    bool isEmpty(){
        return head == nullptr;
    }
    
    void enqueue( int data ){

        Node* newNode = new Node( data );

        newNode->next = nullptr;
        head = newNode;

    }

    void dequeue(){}

    void peek(){}

    void print(){}

    void deleteAll(){}
};

class DescendingUnorderedPriorityQueue{};

int main(int argc, char const *argv[])
{
    AscendingUnorderedPriorityQueue firstQueue = AscendingUnorderedPriorityQueue();

    return 0;
}
