/*Input: LinkedList: 1 -> 2 -> 3 -> 4 -> 5 -> 6, k = 2
Output: 1 -> 3 -> 5 
Explanation: After removing every 2nd node of the linked list, the resultant linked list will be: 1 -> 3 -> 5 .


Input: LinkedList: 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7 -> 8 -> 9 -> 10, k = 3
Output: 1 -> 2 -> 4 -> 5 -> 7 -> 8 -> 10
Explanation: After removing every 3rd node of the linked list, the resultant linked list will be: 1 -> 2 -> 4 -> 5 -> 7 -> 8 -> 10.*/

#include <iostream>

using namespace std;

struct Node{
    int data;
    Node* next;

    Node( int _data ): data( _data ), next( nullptr ){};
};

class LinkList{

    private:
      Node* firstNode = nullptr;
      Node* previusNode = nullptr;

    public:
      void insertAtBeginningToList( int value ){
        Node* newNode = new Node( value );
        newNode->next = firstNode;
        firstNode = newNode;
      }

      int findLengthList(){
        int length = 0;

        Node* currentNode = firstNode;

        while( currentNode != nullptr ){
            length++;
            currentNode = currentNode->next;
        }
        return length;
      }

      void deleteKNode( int k ){
        
        int size = findLengthList();
        
        Node* currentNode = firstNode;

        for( short i =1; size + 1 > i; i++ ){
           
            if( i%k == 0 ){
                previusNode->next = currentNode->next;
            }else{
                previusNode = currentNode;
            }
            currentNode = currentNode->next;
        }
      }

      void printList(){
        Node* currentNode = firstNode;

        while( currentNode != nullptr){
            cout << currentNode->data << " ";
            currentNode = currentNode->next;
        }
        cout << "\n";
      }
};

int main(){
    LinkList list =  LinkList();
    list.insertAtBeginningToList(9);
    list.insertAtBeginningToList(8);
    list.insertAtBeginningToList(7);
    list.insertAtBeginningToList(6);
    list.insertAtBeginningToList(5);
    list.insertAtBeginningToList(4);
    list.insertAtBeginningToList(3);
    list.insertAtBeginningToList(2);
    list.insertAtBeginningToList(1);
    
    list.printList();

    list.deleteKNode(3);

    list.printList();
}