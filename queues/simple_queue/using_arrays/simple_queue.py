
class SimpleQueue:

    def __init__( self, _size: int):
        self.front = -1
        self.rear = -1
        self.array = []
        self.size = _size

    def is_full( self )->bool:
        return ( self.rear + 1 ) % self.size == self.front

    def is_empty( self )->bool:
        return self.front == -1

    def enqueue( self, data:int )->None:
        if( self.is_full() ):
            print("Error: Queue is full")

        if( self.is_empty() ):
            self.front = 0

        self.rear = ( self.rear + 1 ) % self.size 
        self.array[self.rear] = data    


    def dequeue()->None:
        pass

    def peek()->None:
        pass

    def print_queue():
        pass

def main():
    pass

if __name__ == '__main__':
    main()