#include <iostream>

using namespace std;

struct Node{
    int data;
    Node* next;

    Node( int _data ): data( _data ), next( nullptr ){}
};

class AscendingPriorityQueue{
    Node* head = nullptr;

    public:
    bool isEmpty(){
        return head == nullptr;
    }

    void enqueueAtMaxValue( int data ){
        
        Node* newNode = new Node( data );

        if( isEmpty() || data < head->data ){
            newNode->next = head;
            head = newNode;
            return;
        }

        Node* currentNode = head;

        while( currentNode->next != nullptr && currentNode->next->data <= data ){
            currentNode = currentNode->next;
        }
        newNode->next = currentNode->next;
        currentNode->next = newNode;

    }

    void dequeueAtMaxValue(){

        if( isEmpty()){
            cout << "Error: Queue is empty" << endl;
            return;
        }

        Node* temporalNode = head;

        head = temporalNode->next;

        delete temporalNode;
        
    }

    void deleteAll(){

        Node* currentNode = head;

        while( currentNode->next != nullptr ){
            Node* temporalNode = currentNode;
            head = temporalNode->next;
            currentNode = currentNode->next; 
            delete temporalNode;
        }
        head = nullptr;

        delete currentNode;

    }

    void peek(){
        if( isEmpty()){
            cout << "Error: Queue is empty" << endl;
            return;
        }

        cout << head->data << endl;
    }

    void size(){

        if( isEmpty() ){
            cout << "Size: " << 0 << endl;
            return;
        }
        Node* currentNode = head;

        int size = 1;

        for( int i =0; currentNode->next != nullptr; i++){
            currentNode = currentNode->next;
            size++;
        }

        cout << "Size: " << size << endl;
    }

    void print(){

        if( isEmpty() ){
            cout << "Error: Queue is empty" << endl;
            return;
        }
        Node* currentNode = head;

        while( currentNode->next != nullptr ){
            cout << currentNode->data << " ";
            currentNode = currentNode->next;
        }

        cout << currentNode->data << endl;


    }
};

class DescendingPriorityQueue{

    Node* head = nullptr;

    public:

    bool isEmpty(){
        return head == nullptr;
    }

    void enqueue( int data ){

        Node* newNode = new Node( data );

        if( isEmpty() || data < head->data){
            newNode->next = head;
            head = newNode;
            return;
        }
        Node* currentNode = head;

        while( data <= currentNode->data && currentNode->next != nullptr ){
            currentNode = currentNode->next;
        }

        newNode->next = currentNode->next;
        currentNode->next = newNode;
    }

    void dequeue(){

        if( isEmpty()){
            cout << "Error: Queue is empty" << endl;
            return;
        }

        Node* firstNode = head;
        head = firstNode->next;

        delete firstNode;
    }

    void size(){

        if( isEmpty() ){
            cout << "Size: 0" << endl;
            return;
        }

        Node* currentNode = head;

        int size = 1;

        for( int i =0; currentNode->next != nullptr; i++ ){
            currentNode = currentNode->next;
            size++;
        }

        cout << "Size: " << size << endl;
    }

    void peek(){
        cout << head->data << endl;
    }

    void deleteAll(){
        Node* currentNode = head;

        while( currentNode->next != nullptr){
            Node* temporalNode = currentNode;
            currentNode = currentNode->next;
            head = currentNode;
            delete temporalNode;
        }

        head = nullptr;

        delete currentNode;
    }

    void print(){
        Node* currentNode = head;

        while ( currentNode->next != nullptr)
        {
            cout << currentNode->data << " ";
            currentNode = currentNode->next;
        }

        cout << currentNode->data << endl;
        
    }
};

int main(int argc, char const *argv[])
{
     cout << "Ascending Priority Queue" << endl;
    AscendingPriorityQueue queue = AscendingPriorityQueue();

    cout << "Insert in queue" << endl;
    queue.enqueueAtMaxValue(2);
    queue.enqueueAtMaxValue(3);
    queue.enqueueAtMaxValue(9);
    queue.enqueueAtMaxValue(1);
    queue.enqueueAtMaxValue(8);
    queue.enqueueAtMaxValue(4);
    queue.enqueueAtMaxValue(6);

    queue.print();

    cout << "Dequeue" << endl;

    queue.dequeueAtMaxValue();
    queue.dequeueAtMaxValue();

    queue.print();

    cout << "Print size" << endl;

    queue.size();

    cout << "Delete all" << endl;

    queue.deleteAll();

    queue.size();
    queue.print();

    cout << "Descending Priority Queue" << endl;

    DescendingPriorityQueue secondQueue = DescendingPriorityQueue();

    secondQueue.enqueue(3);
    secondQueue.enqueue(2);
    secondQueue.enqueue(1);
    secondQueue.enqueue(9);
    secondQueue.enqueue(6);
    secondQueue.enqueue(8);

    secondQueue.print();

    return 0;
}
