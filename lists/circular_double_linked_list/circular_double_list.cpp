#include <iostream>

using namespace std;

struct Node{
    int data;
    Node* next;
    Node* previus;

    Node( int _data ): data( _data ), next( nullptr ), previus( nullptr ){}
};

class CircularDoubleLinkedList{
    
    Node* head = nullptr;
    Node* tail = nullptr;

    public:
    //insert methods
    void insertAtBeginnig( int data ){
        Node* newNode = new Node( data );
        
        if( head == nullptr){
            head = tail = newNode;
            head->next = head;
            head->previus = head;
            return;
        }
        newNode->next = head;
        head->previus = newNode;
        head = newNode;
        head->previus = tail;
        tail->next = head;
    }

    void printAsc(){
        Node* currentNode = head;

        while( currentNode->next != head){
            cout << currentNode->data << " ";
            currentNode = currentNode->next;
        }
        cout << currentNode->data << "\n";
    }

    void printDesc(){
        Node* currentNode = tail;

        while( currentNode != head){
            cout << currentNode->data << " ";
            currentNode = currentNode->previus;
        }
        cout << currentNode->data << "\n";
    }
};



int main(int argc, char const *argv[])
{
    CircularDoubleLinkedList firstList = CircularDoubleLinkedList();

    firstList.insertAtBeginnig(2);
    firstList.insertAtBeginnig(3);
    firstList.insertAtBeginnig(8);
    firstList.insertAtBeginnig(1);
    firstList.insertAtBeginnig(9);
    firstList.insertAtBeginnig(6);
    
    firstList.printAsc();
    firstList.printDesc();

    return 0;
}
