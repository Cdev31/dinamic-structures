

class Node:
    def __init__(self, data: int):
        self.data = data
        self.next = None


class LinkedList:

    firstNode: Node = None

    def insertAtStart( self, value:int ):
        newNode: Node = Node(value)

        newNode.next = self.firstNode
        self.firstNode = newNode

    def printList( self ):
        currentNode: Node = self.firstNode

        while currentNode is not None:
            print( f"la data: { currentNode.data } la direccion {id(currentNode)}" )
            print( currentNode.data )
            currentNode = currentNode.next    

def main():
    list: LinkedList = LinkedList()

    list.insertAtStart(2)
    list.insertAtStart(5)
    list.insertAtStart(1)
    list.insertAtStart(6)

    list.printList()

    print( f"{id( list.firstNode.next)} "  )


if __name__ == "__main__":
    main()

    