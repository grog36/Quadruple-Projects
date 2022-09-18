//Gregory Ecklund
//September 2022

/**
 * LinkedList Class - Data Structure
 * 
 * Fields:
 *  private head (default = firstNode/null) - The first node in the LinkedList
 *  private tail (default = firstNode/null) - The last node in the LinkedList
 *  private size (default = 0/1) - The size of the LinkedList
 */
class LinkedList {
    #head;
    #tail;
    #size;

    /**
     * Constructor() - Basic constructor 0/1 parameters
     * @param {Node} firstNode (default = null) - The desired initial first Node in the LinkedList
     * @throws {Error} firstNode argument is not of type Node or null
     */
    constructor(firstNode = null) {
        if (firstNode === null || firstNode instanceof(Node)) {
            this.#head = firstNode;
            this.#tail = firstNode;
            if (firstNode === null) {
                this.#size = 0;
            }
            else {
                this.#size = 1;
            }
        }
        else {
            throw new Error("firstNode argument is not of type Node or null");
        }
    }

    /**
     * setHead(newHeadNode) - Adds newHeadNode to the start of the LinkedList
     * @param {Node} newHeadNode The desired initial first Node in the LinkedList
     * @throws {Error} newHeadNode argument is not of type Node
     */
    setHead(newHeadNode) {
        if (newHeadNode instanceof(Node)) {
            let currentHead = this.#head;
            newHeadNode.setNextNode(currentHead);
            this.#head = newHeadNode;
            this.#size++;
        }
        else {
            throw new Error("newHeadNode argument is not of type Node");
        }
    }

    /**
     * getHead() - Gets the head Node of the LinkedList
     * @returns Returns the head field of the LinkedList
     */
    getHead() {
        return this.#head;
    }

    /**
     * append(newTailNode) - Adds newTailNode to the end of the LinkedList
     * @param {Node} newTailNode The new Node you wish to add to the LinkedList
     * @throws {Error} newTailNode argument is not of type Node
     */
    append(newTailNode) {
        if (newTailNode instanceof(Node)) {
            this.#tail.setNextNode(newTailNode);
            this.#tail = newTailNode;
            this.#size++;
        }
        else {
            throw new Error("newTailNode argument is not of type Node");
        }
    }

    /**
     * getTail() - Gets the tail Node of the LinkedList
     * @returns Returns the tail field of the LinkedList
     */
    getTail() {
        return this.#tail;
    }

    /**
     * getSize() - Gets the size of the LinkedList
     * @returns Returns the size field of the LinkedList
     */
    getSize() {
        return this.#size;
    }

    /**
     * getNode(index) - Gets the Node at the required index of the LinkedList
     * @param {Number} index The index of the Node you would like to get from LinkedList
     * @returns Returns the Node at the requested index of LinkedList
     * @throws {Error} index argument is out of bounds for length of LinkedList
     * @throws {Error} index argument is not of type Number
     */
    getNode(index) {
        if (typeof(index) === "number") {
            if (index < this.#size) {
                let output = this.#head;
                for (let i = 0; i < index; i++) {
                    output = output.getNextNode();
                }
                return output;
            }
            else {
                throw new Error("index argument is out of bounds for length of linkedList");
            }
        }
        else {
            throw new Error("index argument is not of type Number");
        }
    }

    /**
     * insert(index, newNode) - Inserts newNode at the requested index of the LinkedList
     * @param {Number} index The index of the LinkedList you wish to insert newNode into
     * @param {Node} newNode The new Node you wish to insert into LinkedList at requested index
     * @throws {Error} index argument is out of bounds for length of LinkedList
     * @throws {Error} newNode argument is not of type Node
     */
    insert(index, newNode) {
        if (newNode instanceof Node) {
            if (index < this.#size) {
                if (index === 0) {
                    this.setHead(newNode);
                }
                else if (index === this.#size) {
                    this.append(newNode);
                }
                else {
                    let nextNode = this.getNode(index);
                    let prevNode = this.getNode(index - 1);
                    prevNode.setNextNode(newNode);
                    newNode.setNextNode(nextNode);
                    this.#size++;
                }
            }
            else {
                throw new Error("index argument is out of bounds for length of LinkedList");
            }
        }
        else {
            throw new Error("newNode argument is not of type Node");
        }
    }

    /**
     * pop(index) - Removes and returns the Node from LinkedList at requested index
     * @param {Number} index (default = tail) - The index of the Node you wish to remove and return from LinkedList
     * @returns Returns the Node at the requested index of LinkedList
     * @throws {Error} index argument is out of bounds for length of LinkedList
     */
    pop(index = (this.#size - 1)) {
        let output = null
        if ((index < (this.#size - 1)) && (index > 0)) {
            let prev = this.getNode(index - 1)
            output = this.getNode(index)
            prev.setNextNode(this.getNode(index + 1))
            this.#size--
        }
        else if (index === 0) {
            output = this.#head
            this.#head = this.#head.getNextNode()
            this.#size--
        }
        else {
            throw new Error("index argument is out of bounds for length of LinkedList");
        }
        return output
    }

    /**
     * reverse() - Reverses the order of the LinkedList
     */
    reverse() {
        if (this.#size > 1) {
            let start = this.#head
            let prev = this.#head
            let current = this.#head.getNextNode()
            for (let i = 0; i < this.#size - 1; i++) {
                let next = current.getNextNode();
                current.setNextNode(prev);
                prev = current
                current = next
            }
            this.#head = prev;
            start.setNextNode(null);
        }
    }

    /**
     * To String Method
     * @returns Returns a string representation of LinkedList
     */
   toString() {
        let output = "";
        let currentNode = this.#head;
        for (let i = 0; i < this.#size; i++) {
            output += currentNode.toString();
            if (i != (this.#size - 1)) {
                output += " ->\n";
            }
            else {
                output += " (END)"
            }
            currentNode = currentNode.getNextNode();
        }
        return output;
   }
}

/**
 * Node Class - Data Structure
 * 
 * Fields:
 *  private data (default = data/null) - Data to be held inside of a Node
 *  private nextNode (default = nextNode/null) - A pointer reference to the next Node
 */
class Node {
    #nextNode;
    #data;

    /**
     * Constructor() - Basic constructor 0/1/2 parameters
     * @param {String} data (default = null) - Data to be held inside of the Node
     * @param {Node} nextNode (default = null) - A pointer reference to the next Node
     * @throws {Error} data argument is not of type String or null
     */
    constructor(data = null, nextNode = null) {
        if (typeof(data) === "string" || data === null) {
            this.#data = data;
            this.#nextNode = nextNode;
        }
        else {
            throw new Error("data argument is not of type String or null");
        }
    }

    /**
     * getNextNode() - Gets and returns the nextNode field from the Node
     * @returns Returns the nextNode field of the Node
     */
    getNextNode() {
        return this.#nextNode;
    }

    /**
     * setNextNode(newNextNode) - Sets the nextNode field to newNextNode for the Node
     * @param {Node} newNextNode A pointer to the Node you wish for this Node to point to
     * @throws {Error} newNextNode argument is not of type Node or null
     */
    setNextNode(newNextNode) {
        if (newNextNode instanceof(Node) || newNextNode === null) {
            this.#nextNode = newNextNode;
        }
        else {
            throw new Error("newNextNode argument is not of type Node or null");
        }
    }

    /**
     * getData() - Gets and returns the data field from the Node
     * @returns Returns the data field of the Node
     */
    getData() {
        return this.#data;
    }

    /**
     * setData(newData) - Sets the data field to newData for the Node
     * @param {String} newData The new data you wish to be stored inside the Node
     * @throws {Error} newData argument is not of type String or null
     */
    setData(newData) {
        if (typeof(newData) === "string" || newData === null) {
            this.#data = newData;
        }
        else {
            throw new Error("newData argument is not of type String or null");
        }
    }

    /**
     * To String Method
     * @returns Returns a string representation of the Node
     */
    toString() {
        let output = "Data: " + this.#data + "\nNext Node: ";
        if (this.#nextNode != null) {
            output += this.#nextNode.getData();
        }
        else {
            output += "NULL";
        }
        return output;
    }
}