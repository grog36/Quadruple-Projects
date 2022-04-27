public class Node {
    private String data;
    private Node nextNode;

    public Node() {
        this.data = null;
        this.nextNode = null;
    }
    public Node(String data) {
        this.data = data;
        this.nextNode = null;
    }
    public Node(Node nextNode) {
        this.data = null;
        this.nextNode = nextNode;
    }
    public Node(String data, Node nextNode) {
        this.data = data;
        this.nextNode = nextNode;
    }
    
    public String getData() {
        return this.data;
    }
    public void setData(String newData) {
        this.data = newData;
    }
    public Node getNextNode() {
        return this.nextNode;
    }
    public void setNextNode(Node nextNode) {
        this.nextNode = nextNode;
    }

    public String toString() {
        String output = "Data: ";
        output += this.data + "\nNext Node: ";
        if (this.nextNode != null) {
            output += this.nextNode.getData();
        }
        else {
            output += "NULL";
        }
        return output;
    }

}