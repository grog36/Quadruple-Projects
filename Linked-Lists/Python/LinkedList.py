#Gregory Ecklund
#September 2022

class LinkedList:
    """
        LinkedList Class - Data Structure

        Fields:
            private head (default = firstNode/None) - The first node in the LinkedList
            private tail (default = firstNode/None) - The last node in the LinkedList
            private size (default = 0/1) - The size of the LinkedList
    """

    def __init__(self, firstNode = None):
        """
            Constructor() - Basic constructor 0/1 parameters
            
            Parameters:
                firstNode (default = None) - The desired initial first Node in the LinkedList
            
            TypeError:
                firstNode argument is not of type Node or None
        """

        if (type(firstNode == Node) or firstNode == None):
            self.__head = firstNode
            self.__tail = firstNode
            if (firstNode == None):
                self.__size = 0
            else:
                self.__size = 1
        else:
            raise TypeError("firstNode argument is not of type Node or None")

    def setHead(self, newHeadNode):
        """
            setHead(newHeadNode) - Adds newHeadNode to the start of the LinkedList

            Parameters:
                newHeadNode - A pointer to a Node you wish to be the new Head

            TypeError:
                newheadNode argument is not of type Node
        """

        if (type(newHeadNode) == Node):
            currentHead = self.__head
            newHeadNode.setNextNode(currentHead)
            self.__head = newHeadNode
            self.__size += 1
        else:
            raise TypeError("neadHeadNode argument is not of type Node")

    def getHead(self):
        """
            getHead() - Gets the head Node of the LinkedList
            
            Returns:
                Returns the head field of the LinkedList
        """

        return self.__head

    def append(self, newTailNode):
        """
            append(newTailNode) - Adds newTailNode to the end of the LinkedList

            Parameters:
                newTailNode - The new Node you wish to add to the LinkedList

            TypeError:
                newTailNode argument is not of type Node
        """

        if (type(newTailNode) == Node):
            self.__tail.setNextNode(newTailNode)
            self.__tail = newTailNode
            self.__size += 1
        else:
            raise TypeError("newTailNode argument is not of type Node")

    def getTail(self):
        """
            getTail() - Gets the tail Node of the LinkedList

            Returns:
                Returns the tail field of the LinkedList
        """

        return self.__tail

    def getSize(self):
        """
            getSize() - Gets the size of the LinkedList

            Returns:
                Returns the size field of the LinkedList
        """

        return self.__size

    def getNode(self, index):
        """
            getNode(index) - Gets the Node at the requested index of the LinkedList

            Parameters:
                index - The index of the Node you would like to get from LinkedList

            Returns:
                Returns the Node at the requested index of LinkedList
            
            IndexError:
                index argument is out of bounds for length of LinkedList
            
            TypeError:
                index argument is not of type int
        """

        if (type(index) == int):
            if (index < self.__size):
                output = self.__head
                for i in range(index):
                    output = output.getNextNode()
                return output
            else:
                raise IndexError("index argument is out of bounds for length of LinkedList")
        else:
            raise TypeError("index argument is not of type int")

    def insert(self, index, newNode):
        """
            insert(index, newNode) - Inserts newNode at the requested index of the LinkedList

            Parameters:
                index - The index of the LinkedList you wish to insert newNode into
                newNode - The new Node you wish to insert into LinkedList at requested index
            
            IndexError:
                index argument is out of bounds for length of LinkedList
            
            TypeError:
                newNode argument is not of type Node
        """

        if (type(newNode) == Node):
            if (index < self.__size):
                if (index == 0):
                    self.setHead(newNode)
                elif (index == self.__size):
                    self.append(newNode)
                else:
                    nextNode = self.getNode(index)
                    prevNode = self.getNode(index - 1)
                    prevNode.setNextNode(newNode)
                    newNode.setNextNode(nextNode)
                    self.__size += 1
            else:
                raise IndexError("index argument is out of bounds for length of LinkedList")
        else:
            raise TypeError("newNode argument is not of type Node")
    
    def pop(self, index = None):
        """
            pop(index) - Removes and returns the Node from LinkedList at requested index

            Parameters:
                index (default = tail) - The index of the Node you wish to remove and return from LinkedList
            
            Returns:
                Returns the Node at the requested index of LinkedList
            
            IndexError:
                index argument is out of bounds for length of LinkedList
        """

        output = None
        if (index > (self.__size - 1) or index < 0 or this.__size == 0):
            raise IndexError("index argument is out of bounds for length of LinkedList")
        elif ((index < (self.__size - 1)) and (index > 0)):
            prev = self.getNode(index - 1)
            output = self.getNode(index)
            prev.setNextNode(self.getNode(index + 1))
            self.__size -= 1
        elif (index == 0):
            output = self.__head
            self.__head = self.__head.getNextNode()
            self.__size -= 1
        elif (index == (self.__size - 1) or (index == None)):
            output = self.getNode(index)
            prev = self.getNode(index - 1)
            prev.setNextNode(None)
            self.__size -= 1
        return output

    def reverse(self):
        """
            reverse() - Reverses the order of the LinkedList
        """

        if (self.__size > 1):
            start = self.__head
            prev = self.__head
            current = self.__head.getNextNode()
            for i in range(self.__size - 1):
                next = current.getNextNode()
                current.setNextNode(prev)
                prev = current
                current = next
            self.__head = prev
            start.setNextNode(None)

    def __str__(self):
        """
            To String Method

            Returns:
                Returns a string representation of LinkedList
        """

        output = ""
        currentNode = self.__head
        for i in range(self.__size):
            output += currentNode.getData()
            if (i != (self.__size - 1)):
                output += " ->\n"
            else:
                output += " (END)"
            currentNode = currentNode.getNextNode()
        return output

class Node:
    """
        Node Class - Data Structure

        Fields:
            private data (default = None) - Data to be held inside of a Node
            private nextNode (default = None) - A pointer reference to the next Node
    """

    def __init__(self, data = None, nextNode = None):
        """
            Constructor

            Parameters:
                data (default = None) - Data to be held inside of the Node
                nextNode (default = None) - A pointer reference to the next Node

            TypeError:
                nextNode argument is not of type Node or None
        """

        self.__data = data
        if (type(nextNode) == Node or nextNode == None):
            self.__nextNode = nextNode
        else:
            raise TypeError("nextNode argument is not of type Node or None")
    
    def getNextNode(self):
        """
            getNextNode() - Gets and returns the nextNode field from the Node

            Returns:
                Returns the nextNode field of the Node
        """

        return self.__nextNode
    
    def setNextNode(self, newNextNode):
        """
            setNextNode(newNextNode) - Sets the nextNode field to newNextNode for the Node

            Parameters:
                newNextNode - A pointer to the Node you wish for this Node to point to
            
            TypeError:
                newNextNode argument is not of type Node or None
        """

        if (type(newNextNode) == Node or newNextNode == None):
            self.__nextNode = newNextNode
        else:
            raise TypeError("newNextNode argument is not of type Node or None")
    
    def getData(self):
        """
            getData() - Gets and returns the data field from the Node
            
            Returns:
                Returns the data field of the Node
        """

        return self.__data

    def setData(self, newData):
        """
            setData(newData) - Sets the data field to newData for the Node

            Parameters:
                newData - The new data you wish to be stored inside the Node
        """

        self.__data = newData

    def __str__(self):
        """
            To String Method
        
            Returns:
                Returns a string representation of the Node
        """

        output = "Data: " + str(self.__data) + "\nNext Node: "
        if (self.__nextNode != None):
            output += str(self.__nextNode.getData())
        else:
            output += "None"
        return output