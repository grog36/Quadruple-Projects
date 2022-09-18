//Gregory Ecklund
//September 2022

public class LinkedList {
    /**
        LinkedList Class - Data Structure

        Fields:
            private Node head (default = startingNode/null) - The first node in the LinkedList
            private Node tail (default = startingNode/null) - The last node in the LinkedList
            private int size (default = 0/1) - The size of the LinkedList
    */

    private Node head;
    private Node tail;
    private int size;

    public LinkedList() {
        /**
            Constructor() - Base constructor, no parameters
        */
        this.head = null;
        this.tail = null;
        this.size = 0;
    }

    public LinkedList(Node startingNode) {
        /**
            Constructor(Node startingNode) - Constructor containing a single starting Node

            Parameters:
                Node startingNode - The desired initial first Node in the LinkedList
        */

        this.head = startingNode;
        this.tail = startingNode;
        this.size = 1;
    }

    public void setHead(Node newHead) {
        /**
            setHead(Node newHead) - Adds newHead to the start of the LinkedList

            Parameters:
                Node newHead - The Node you wish to be the new Head
        */

        Node oldHead = this.head;
        this.head = newHead;
        this.head.setNextNode(oldHead);
        this.size++;
    }

    public Node getHead() {
        /**
            getHead() - Gets the head Node of the LinkedList

            Returns:
                Node - Returns the head field of the LinkedList
        */

        return this.head;
    }

    public void append(Node newTail) {
        /**
            append(Node newTail) - Adds newTail to the end of the LinkedList

            Parameters:
                Node newTail - The new Node you wish to add to the LinkedList
        */

        if (this.size != 0) {
            this.tail.setNextNode(newTail);
            this.tail = newTail;
        }
        else {
            this.head = newTail;
            this.tail = newTail;
        }
        this.size++;
    }

    public Node getTail() {
        /**
            getTail() - Gets the tail Node of the LinkedList

            Returns:
                Node - Returns the tail field of the LinkedList
        */

        return this.tail;
    }

    public int getSize() {
        /**
            getSize() - Gets the size of the LinkedList

            Returns:
                int - Returns the size field of the LinkedList
        */

        return this.size;
    }

    public Node getNode(int index) {
        /**
            getNode(int index) - Gets the Node at the requested index of the LinkedList

            Parameters:
                int index - The index of the Node you would like to get from LinkedList
            
            Returns:
                Node - Returns the Node at the requested index of LinkedList

            IndexOutOfBoundsException:
                index argument is out of bounds for length of LinkedList
        */

        if (index < this.size && index > -1) {
            Node output = this.head;
            for (int i = 0; i < index; i++) {
                output = output.getNextNode();
            }
            return output;
        }
        else {
            throw new IndexOutOfBoundsException("index argument is out of bounds for length of LinkedList");
        }
    }

    public void insert(int index, Node node) {
        /**
            insert(int index, Node node) - Inserts node at the requested index of the LinkedList

            Parameters:
                int index - The index of the LinkedList you wish to insert node into
                Node node - The new Node you wish to insert into LinkedList at requested index
            
            IndexOutOfBoundsException:
                index argument is out of bounds for length of LinkedList
        */
    
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
            throw new IndexOutOfBoundsException("index argument is out of bounds for length of LinkedList");
        }
    }

    public Node pop() {
        /**
            pop() - Removes and returns the tail from LinkedList

            Returns:
                Node - Returns the tail
        */

        return pop(this.size - 1);
    }

    public Node pop(int index) {
        /**
            pop(int index) - Removes and returns the Node from LinkedList at requested index

            Parameters:
                int index - The index of the Node you wish to remove and return from LinkedList

            Returns:
                Node - Returns the Node at the requested index of LinkedList
            
            IndexOutOfBoundsException:
                index argument is out of bounds for length of LinkedList
        */

        Node output = null;
        if ((index < (this.size - 1)) && (index > 0) && (this.size != 0)) {
            Node prev = this.getNode(index - 1);
            output = this.getNode(index);
            prev.setNextNode(this.getNode(index + 1));
            this.size--;
        }
        else if (index == 0 && this.size != 0) {
            output = this.head;
            this.head = this.head.getNextNode();
            this.size--;
        }
        else {
            throw new IndexOutOfBoundsException("index argument is out of bounds for length of LinkedList");
        }
        return output;
    }

    public void reverse() {
        /**
            reverse() - Reverses the order of the LinkedList
        */

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

    public String toString() {
        /**
            To String Method

            Returns:
                Returns a string representation of the LinkedList
        */

        String output = "";
        Node currentNode = this.head;
        for (int i = 0; i < this.size; i++) {
            output += currentNode.getData();
            if (i != (this.size - 1)) {
                output += " ->\n";
            }
            else {
                output += " (END)";
            }
            currentNode = currentNode.getNextNode();
        }
        return output;
    }
}