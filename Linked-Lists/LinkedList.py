from asyncio.windows_events import NULL


class Node:
    
    def __init__(self, data = 0, nextNode = NULL):
        self.__data = data
        self.__nextNode = nextNode
    
    def getNextNode(self):
        return self.__nextNode
    def setNextNode(self, newNextNode):
        self.__nextNode = newNextNode
    def getData(self):
        return self.__data
    def setData(self, newData):
        self.__data = newData

    def __str__(self):
        output = "Data: "
        output += self.__data + "\nNext Node: "
        if (self.__nextNode != NULL):
            output += self.__nextNode.getData()
        else:
            output += "NULL"
        return output

class LinkedList:

    def __init__(self, firstNode = NULL):
        self.__head = firstNode
        self.__tail = firstNode
        if (firstNode == NULL):
            self.__size = 0
        else:
            self.__size = 1

    def setHead(self, newHeadNode):
        currentHead = self.__head
        newHeadNode.setNextNode(currentHead)
        self.__head = newHeadNode
        self.__size += 1
    def getHead(self):
        return self.__head
    def append(self, newTailNode):
        self.__tail.setNextNode(newTailNode)
        self.__tail = newTailNode
        self.__size += 1
    def getTail(self):
        return self.__tail
    def getSize(self):
        return self.__size

    def getNode(self, index):
        if (index < self.__size):
            output = self.__head
            for i in range(index):
                output = output.getNextNode()
            return output
        else:
            raise IndexError("INDEX OUT OF BOUNDS")

    def insert(self, index, newNode):
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
            raise IndexError("INDEX OUT OF BOUNDS")
    
    def pop(self, index):
        output = NULL
        if ((index < (self.__size - 1)) and (index > 0)):
            prev = self.getNode(index - 1)
            output = self.getNode(index)
            prev.setNextNode(self.getNode(index + 1))
            self.__size -= 1
        elif (index == 0):
            output = self.__head
            self.__head = self.__head.getNextNode()
            self.__size -= 1
        elif (index == (self.__size - 1)):
            output = self.getNode(index)
            prev = self.getNode(index - 1)
            prev.setNextNode(NULL)
            self.__size -= 1
        return output

    def splice(self, startingIndex, length):
        print("FINISH THIS")


    def reverse(self):
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
            start.setNextNode(NULL)


    def __str__(self):
        output = ""
        for i in range(self.__size):
            if (i != (self.__size - 1)):
                output += str(self.getNode(i).getData()) + " ->\n"
            else:
                output += str(self.getNode(i).getData()) + " (END)"
        return output

list = LinkedList(Node("Twenty"))
list.append(Node("TwentyOne"))
list.append(Node("TwentyTwo"))
list.setHead(Node("Nineteen"))
list.insert(3, Node("TwentyOnePointFive"))
list.insert(1, Node("HELLO"))
list.pop(1)

print(list)
list.reverse()
print(list)

print()
print(list.getNode(2))