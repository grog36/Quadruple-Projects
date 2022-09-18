public class Node {
    /**
        Node Class - Data Structure

        Fields:
            private String data (default = data/null) - Data to be held inside of a Node
            private Node nextNode (default = nextNode/null) - A pointer reference to the next Node
    */

    private String data;
    private Node nextNode;

    public Node() {
        /**
            Constructor() - Base constructor, no parameters
        */

        this.data = null;
        this.nextNode = null;
    }

    public Node(String data) {
        /**
            Constructor(String data) - Constructor containing only the data field

            Parameters:
                String data (default = null) - Data to be held inside of the Node
        */

        this.data = data;
        this.nextNode = null;
    }

    public Node(Node nextNode) {
        /**
            Constructor(Node nextNode) - Constructor containing only the nextNode field

            Parameters:
                Node nextNode (default = null) - A pointer reference to the next Node
        */

        this.data = null;
        this.nextNode = nextNode;
    }

    public Node(String data, Node nextNode) {
        /**
            Constructor(String data, Node nextNode) - Constructor containing both fields

            Parameters:
                String data (default = null) - Data to be held inside of the Node
                Node nextNode (default = null) - A pointer reference to the next Node
        */
        
        this.data = data;
        this.nextNode = nextNode;
    }
    
    public Node getNextNode() {
        /**
            getNextNode() - Gets and returns the nextNode field from the Node

            Returns:
                Node - Returns the nextNode field of the Node
        */

        return this.nextNode;
    }

    public void setNextNode(Node nextNode) {
        /**
            setNextNode(Node nextNode) - Sets the nextNode field to nextNode for the Node

            Parameters:
                Node nextNode - A pointer to the Node you wish for this Node to point to
        */

        this.nextNode = nextNode;
    }

    public String getData() {
        /**
            getData() - Gets and returns the data field from the Node

            Returns:
                String - Returns the data field of the Node
        */

        return this.data;
    }

    public void setData(String newData) {
        /**
            setData(String newData) - Sets the data field to newData for the Node

            Parameters:
                String newData - The new data you wish to be stored inside the Node
        */

        this.data = newData;
    }

    public String toString() {
        /**
            To String Method

            Returns:
                Returns a String representation of the Node
        */

        String output = "Data: " + this.data + "\nNextNode: ";
        if (this.nextNode != null) {
            output += this.nextNode.getData();
        }
        else {
            output += "NULL";
        }
        return output;
    }
}