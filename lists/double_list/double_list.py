
class Node:
    def __init__( self, _data: int  ):
        self.data = _data
        self.next: None = None
        self.previus: None = None

class DoubleLinkList:
    
    firstNode: Node | None = None
    endNode: Node | None = None

    def inserAtBeginningToList( self, value: int ):
        
        newNode: Node = Node(value)

        if( self.firstNode == None ):
            self.endNode = newNode

        newNode.next = self.firstNode

        if( self.firstNode != None ):
            self.firstNode.previus = newNode

        self.firstNode = newNode

    def printListAsc( self ):
        currentNode: Node = self.firstNode

        while( currentNode != None ):
            print(f"{currentNode.data}", end=" ")
            currentNode = currentNode.next
        print()

    def printListDesc( self ):
        currentNode: Node = self.endNode

        while( currentNode != None):
            print(f"{currentNode.data}", end=" ")
            currentNode = currentNode.previus
        print()    
            

def main():
    list: DoubleLinkList = DoubleLinkList()

    list.inserAtBeginningToList(1)
    list.inserAtBeginningToList(2)
    list.inserAtBeginningToList(3)
    list.inserAtBeginningToList(4)
    list.inserAtBeginningToList(5)

    list.printListAsc()
    list.printListDesc()


if __name__ == "__main__":
    main()




    