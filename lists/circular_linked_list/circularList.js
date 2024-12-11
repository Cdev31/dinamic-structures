class Node{
    constructor( value = 0 ){
        this.value = value;
        this.next = null;
    }
}

class CircularList{

    constructor(){
        this.firstNode = null;
        this.endNode = null;
        this.size = 0;
    }

    insertAtBeginningToList( value ){
        const newNode = new Node( value );

        if( this.firstNode == null ){
            this.endNode = newNode;
            this.firstNode = newNode;
            newNode.next = newNode;
        }
        else{
            newNode.next = this.firstNode;
            this.endNode.next = newNode;
            this.firstNode = newNode;
        }
        this.size++;
    }

    insertAtPositionToList( value = 0, position = 0 ){
        
        if( position > this.size || position < 0){ 
            throw new Error("Invalid Position");
        }

        const newNode = new Node( value );

        if( position == this.size ){
            newNode.next = this.endNode.next;
            this.endNode.next = newNode;
            this.endNode = newNode;
            return;
        }

        if( position == 1 ){
            this.endNode.next = newNode;
            newNode.next = this.firstNode
            this.firstNode = newNode
            return;
        }

        let currentNode = this.firstNode;
        let count = 1;

        while( currentNode != null ){
            if( count == position -1 ) break;
            currentNode = currentNode.next;
            count++
        }

        newNode.next = currentNode.next;
        currentNode.next = newNode;

    }

    printList(){
        let currentNode = this.endNode.next;

        while( true ){
            process.stdout.write(`${ currentNode.value } `);
            currentNode = currentNode.next;
            if( currentNode == this.firstNode ) break;
        }
        console.log("");

    }
}


const list = new CircularList();

list.insertAtBeginningToList(1);
list.insertAtBeginningToList(2);
list.insertAtBeginningToList(3);
list.insertAtBeginningToList(4);
list.insertAtBeginningToList(5);

list.printList();

list.insertAtPositionToList( 6, 5 );

list.printList();
