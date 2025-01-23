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
    bool isEmpty(){
        return head == nullptr;
    }

    void enqueue( int data ){
        
        Node* newNode = new Node( data );

        if( head == nullptr ){
            tail = newNode;
        }

        newNode->next = head;
        head = newNode;
        tail->next = head;

    }

    void dequeue(){

        if( isEmpty() ){
            cout << "Error: Queue is empty" << endl;
            return;
        }

        Node* currentNode = head;

        while( currentNode->next != head ){
            currentNode= currentNode->next;
            if( currentNode->next == tail ) break;
        }
        Node* temporalNode = tail;

        currentNode->next = head;
        tail = currentNode;

        delete temporalNode;

    }

    void peek(){
        cout << head->data << endl;
    }

    void printQueue(){
        Node* currentNode = head;

        while( currentNode->next != head ){
            cout << currentNode->data << " ";
            currentNode = currentNode->next;
        }
        cout << currentNode->data << endl;
    }

};

int main(int argc, char const *argv[])
{
    CircularQueue queue = CircularQueue();

    cout << "Enqueue data" << endl;
    queue.enqueue(2);
    queue.enqueue(4);
    queue.enqueue(3);
    queue.enqueue(5);
    queue.enqueue(9);
    queue.enqueue(6);
    queue.enqueue(7);

    queue.printQueue();

    cout << "Deque data" << endl;

    queue.dequeue();
    queue.dequeue();

    queue.printQueue();

    return 0;
}
