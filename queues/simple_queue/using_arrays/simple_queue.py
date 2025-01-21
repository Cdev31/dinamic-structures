
class SimpleQueue:

    front:int = 0
    rear:int = 0
    array = []
    size: int =0

    def __init__( self, _size: int):
        self.front = -1
        self.rear = -1
        self.array = [0] * _size
        self.size = _size

    def is_full( self )->bool:
       return ( self.rear + 1 )== self.size

    def is_empty( self )->bool:
        return self.front == -1

    def enqueue( self, data:int )->None:
        
        if( self.is_full() ):
            print("Error: queue is full")
            return

        if( self.is_empty() ):
            self.front = 0   

        self.rear= (self.rear + 1) % self.size
        self.array[self.rear] = data 
           


    def dequeue(self)->None:

        if( self.is_empty()):
            print("Error: queue is empty")
            return
    
        for index, element in enumerate( self.array ) :
            if( self.rear == index):
                self.array[index] == 0
            self.array[index -1] = self.array[index]
           


    def peek(self)->None:
        return self.array[0]

    def print_queue(self):
        for  element in self.array :
            if( element == 0 ):
                break
            print(element, end=" ")
        print()    
            


def main():
    queue: SimpleQueue = SimpleQueue(10)
    queue.enqueue(2)
    queue.enqueue(3)
    queue.enqueue(6)
    queue.enqueue(1)
    queue.enqueue(8)
    queue.enqueue(7)
    queue.enqueue(9)
    queue.enqueue(4)

    queue.print_queue()

    queue.dequeue()

    queue.print_queue()

if __name__ == '__main__':
    main()