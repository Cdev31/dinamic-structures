

class Queue:

    def __init__(self, size: int ):
        self.front: int = 0
        self.rear: int = -1
        self.capacity: int = size
        self.queue: list = [None] * size

    def isFull( self ) -> bool:
        return ( self.rear - self.front + 1 ) == self.capacity

    def isEmpty( self ) -> bool:
        return self.front > self.rear
    
    def enqueue( self , value: int ) -> None:
        if( self.isFull() ):
            print("is Full") 
            return
        self.rear +=1
        self.queue[self.rear] = value

    def dequeu( self )-> int:
        if( self.isEmpty()):
            print("is Empty")  
            return
        value: int = self.queue[self.front]
        self.front+=1
        return value
    
    def showQueue( self ) -> None:
        for i in range( self.front, len( self.queue )):
            if( self.queue[i] is None ): break
            print( f"{ self.queue[i]}", end=" ")
        print("")


def main():
    queue:Queue = Queue(9)

    queue.enqueue(5)
    queue.enqueue(6)
    queue.enqueue(2)
    queue.enqueue(4)
    queue.enqueue(3)
    
    queue.showQueue()

    queue.dequeu()

    queue.showQueue()


if __name__ == "__main__":
    main()
        