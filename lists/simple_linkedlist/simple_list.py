from typing import Optional

class Node:
    data: int
    next: Optional["Node"]

    def __init__( self, _data: int ):
        self.data = _data
        self.next = None


class LinkedList:
    head: Node | None

    def __init__( self):
        self.head = None

    def insert_at_beginning( self, data:int )->None:

        newNode:Node = Node( data )
        newNode.next = self.head
        self.head = newNode

    def print(self)->None:
        currentNode = self.head

        while( currentNode.next != None):
            print( currentNode.data, end=" " )
            currentNode = currentNode.next
        
        print( currentNode.data, end=" " )  
        print()          


def main():
    
    firstList: LinkedList = LinkedList()

    firstList.insert_at_beginning(2)
    firstList.insert_at_beginning(4)
    firstList.insert_at_beginning(7)
    firstList.insert_at_beginning(8)

    firstList.print()


if __name__ == '__main__':
    main()