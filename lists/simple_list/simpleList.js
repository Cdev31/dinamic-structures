

class Node{
    constructor( data ){
        this.data = data;
        this.next = null;
    }
}

class LinkList{

    firstNode = null;
    finalNode = null;

    insertAtBeginning( newNode = new Node(), value = 0 ){
        const newNode = new Node(value);

        newNode.next = this.firstNode;
        this.firstNode = newNode;
        
    }


}