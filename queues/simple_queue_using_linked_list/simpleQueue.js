
class Node{
    constructor( value = 0 ){
        this.value = value;
        this.next = null;
    }
}

class Queue {

    constructor( ){
        this.front = null;
        this.rear = null;
    }

    enqueue( value = 0 ){
        const newNode = new Node(value);

        if( this.front == null){
            this.front = newNode;
            this.rear = newNode;
            return;
        }

        this.rear.next = newNode;
        this.rear = newNode;
    }

    dequeue(){

        if( this.front == null){
            console.log("Is empty");
            return;
        }

        this.front = this.front.next;
    }

    showQueue(){
        let currentNode = this.front;

        while( currentNode != null ){
            process.stdout.write(`${ currentNode.value } `);
            currentNode = currentNode.next;
        }
        console.log();
    }

}


const queue = new Queue();

queue.enqueue(2);
queue.enqueue(9);
queue.enqueue(6);
queue.enqueue(5);
queue.enqueue(4);

queue.showQueue();

queue.dequeue();

queue.showQueue();