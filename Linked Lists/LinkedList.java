public class LinkedList {
    private Node head;
    private Node tail;
    private int size;



    public LinkedList() {
        this.head = null;
        this.tail = null;
        this.size = 0;
    }
    public LinkedList(Node startingNode) {
        this.head = startingNode;
        this.tail = startingNode;
        this.size = 1;
    }

    public void setHead(Node newHead) {
        Node oldHead = this.head;
        this.head = newHead;
        this.head.setNextNode(oldHead);
        this.size++;
    }
    public Node getHead() {
        return this.head;
    }
    public void append(Node newTail) {
        if (this.size != 0) {
            this.tail.setNextNode(newTail);
            this.tail = newTail;
            this.size++;
        }
        else {
            this.head = newTail;
            this.tail = newTail;
            this.size = 1;
        }
    }
    public Node getTail() {
        return this.tail;
    }
    public int getSize() {
        return this.size;
    }

    public Node getNode(int index) {
        if (index < this.size && index > -1) {
            Node output = this.head;
            for (int i = 0; i < index; i++) {
                output = output.getNextNode();
            }
            return output;
        }
        else {
            return null;
        }
    }

    public void insert(int index, Node node) {
    
        if (index < this.size && index > -1) {
            if (index == 0) {
                this.setHead(node);
            }
            else if (index == this.size) {
                this.append(node);
            }
            else {
                Node oldNode = this.getNode(index);
                Node prevNode = this.getNode(index - 1);
                prevNode.setNextNode(node);
                node.setNextNode(oldNode);
                this.size++;
            }
        }
        else {
            System.out.println("Index " + index + " is out of bounds. Nothing Changed!");
        }

    }

    public String toString() {
        String output = "";
        for (int i = 0; i < this.size; i++) {
            if (i != (this.size - 1)) {
                output += this.getNode(i).getData() + " ->\n";
            }
            else {
                output += this.getNode(i).getData() + " (END)";
            }
        }
        return output;
    }

    public Node pop(int index) {
        Node output = null;
        if ((index < (this.size - 1)) && (index > 0)) {
            Node prev = this.getNode(index - 1);
            output = this.getNode(index);
            prev.setNextNode(this.getNode(index + 1));
            this.size--;
        }
        else if (index == 0) {
            output = this.head;
            this.head = this.head.getNextNode();
            this.size--;
        }
        return output;
    }

    public void reverse() {
        if (this.size > 1) {
            Node start = this.head;
            Node prev = this.head;
            Node current = this.head.getNextNode();
            Node next;
            for (int i = 0; i < (this.size - 1); i++) {
                next = current.getNextNode();
                current.setNextNode(prev);
                prev = current;
                current = next;
            }
            this.head = prev;
            start.setNextNode(null);
        }
    }

    /**
     * "zips" the calling list and listIn into a single list. Which list starts is determined by 
     * the parameter order.
     *
     * If someList contains A->B->C and listIn contains G->H->I then
     *
     * someList.zip(listIn, 0) would result in A->G->B->H->C->I
     *
     * someList.zip(listIn, 1) would result in G->A->H->B->I->C
     *
     * =====================================================================================
     * DO NOT USE ANY HELPER METHODS EXCEPT FOR THE getStart() METHOD THAT HAS BEEN PROVIDED.
     * ====================================================================================
     *
     * @param listIn Node representing the head of a list that is guaranteed to be the same length
     * as the calling list
     * 
     * @param order integer representing which list starts the combined list  
     */
    public void zip(LinkedList listIn, int order) throws IndexOutOfBoundsException {
        Node thisCurrentNode = this.getHead();
        Node otherCurrentNode = listIn.getHead();
        Node thisNextNode;
        Node otherNextNode;
        if (order == 0) {
            for (int i = 0; i < this.size; i++) {
                thisNextNode = thisCurrentNode.getNextNode();
                otherNextNode = otherCurrentNode.getNextNode();
                thisCurrentNode.setNextNode(otherCurrentNode);
                otherCurrentNode.setNextNode(thisNextNode);
                thisCurrentNode = thisNextNode;
                otherCurrentNode = otherNextNode;
            }
            this.tail = otherCurrentNode;
        }
        else if (order == 1) {
            Node startNode = listIn.getHead();
            for (int i = 0; i < this.size; i++) {
                thisNextNode = thisCurrentNode.getNextNode();
                otherNextNode = otherCurrentNode.getNextNode();
                otherCurrentNode.setNextNode(thisCurrentNode);
                thisCurrentNode.setNextNode(otherNextNode);
                thisCurrentNode = thisNextNode;
                otherCurrentNode = otherNextNode;
            }
            this.head = startNode;
        }
        this.size *= 2;
    }

    public int test() {
        System.out.println(this.size);
        return this.size / 2;
    }

}
