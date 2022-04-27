class Node {
    #nextNode;
    #data;

    constructor(data = 0, nextNode = null) {
        this.#data = data;
        this.#nextNode = nextNode;
    }

    getNextNode() {
        return this.#nextNode;
    }
    getData() {
        return this.#data;
    }
    setData(newData) {
        this.#data = newData;
    }
    setNextNode(newNextNode) {
        this.#nextNode = newNextNode;
    }
    toString() {
        let output = "Data: "
        output += this.#data + "\nNext Node: "
        if (this.#nextNode != null) {
            output += this.#nextNode.getData()
        }
        else {
            output += "NULL"
        }
        return output
    }


}

class LinkedList {
    #head;
    #tail;
    #size;

    constructor(firstNode = null) {
        this.#head = firstNode;
        this.#tail = firstNode;
        if (firstNode == null) {
            this.#size = 0;
        }
        else {
            this.#size = 1;
        }
    }

    setHead(newHeadNode) {
        let currentHead = this.#head;
        newHeadNode.setNextNode(currentHead);
        this.#head = newHeadNode;
        this.#size++;
    }
    getHead() {
        return this.#head;
    }
    append(newTailNode) {
        this.#tail.setNextNode(newTailNode);
        this.#tail = newTailNode;
        this.#size++;
    }
    getTail() {
        return this.#tail;
    }
    getSize() {
        return this.#size;
    }

    getNode(index) {
        if (index < this.#size) {
            let output = this.#head;
            for (let i = 0; i < index; i++) {
                output = output.getNextNode();
            }
            return output;
        }
        else {
            throw "INDEX OUT OF BOUNDS ERROR";
        }
    }

    insert(index, newNode) {
        if (index < this.#size) {
            if (index == 0) {
                this.setHead(newNode);
            }
            else if (index == this.#size) {
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
            throw "INDEX OUT OF BOUNDS ERROR";
        }
    }

    pop(index = (this.#size - 1)) {
        let output = null
        if ((index < (this.#size - 1)) && (index > 0)) {
            let prev = this.getNode(index - 1)
            output = this.getNode(index)
            prev.setNextNode(this.getNode(index + 1))
            this.#size--
        }
        else if (index == 0) {
            output = this.#head
            this.#head = this.#head.getNextNode()
            this.#size--
        }
        return output
    }

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

    toString = function() => {

    }

   toString() {
        let output = "";
        for (let i = 0; i < this.#size; i++) {
            if (i != (this.#size - 1)) {
                output += this.getNode(i).getData() + " ->\n";
            }
            else {
                output += this.getNode(i).getData() + " (END)"
            }
        }
        return output;
   }
}
let list = new LinkedList(new Node("Twenty"))
ist.append(new Node("TwentyOne"))
list.append(new Node("TwentyTwo"))
ist.setHead(new Node("Nineteen"))
ist.insert(3, new Node("TwentyOnePointFive"))
ist.insert(1, new Node("HELLO"))
ist.pop(1)
console.log(list.toString())
list.reverse()
console.log(list.toString())

console.log("\n")
console.log(list)