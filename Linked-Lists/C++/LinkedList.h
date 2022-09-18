//Gregory Ecklund
//September 2022

#include <iostream>
#include "./Node.h"
#include <stdexcept>
using namespace std;


class LinkedList {
    /**
        LinkedList Class - Data Structure

        Fields:
            private Node* head (default = startingNode/NULL) - The first node in the LinkedList
            private Node* tail (default = startingNode/NULL) - The last node in the LinkedList
            private int size (default = 0/1) - The size of the LinkedList
    */

    private:
        Node* head;
        Node* tail;
        int size;

    public:
        LinkedList() {
            /**
                Constructor() - Base constructor, no parameters
            */

            head = NULL;
            tail = NULL;
            size = 0;
        }

        LinkedList(Node* startingNode) {
            /**
                Constructor(Node* startingNode) - Constructor containing a single starting Node

                Parameters:
                    Node* startingNode - A pointer to the desired initial first Node in the LinkedList
            */

            head = startingNode;
            tail = startingNode;
            size = 1;
        }

        void setHead(Node* newHead) {
            /**
                setHead(Node* newHead) - Adds newHead to the start of the LinkedList

                Parameters:
                    Node* newHead - A pointer to a Node you wish to be the new Head
            */

            Node* oldHead = head;
            head = newHead;
            (*head).setNextNode(oldHead);
            size++;
        }

        Node* getHead() {
            /**
                getHead() - Gets the pointer to the head Node of the LinkedList

                Returns:
                    Node* - Returns a pointer to the head field of the LinkedList
            */

            return head;
        }

        void append(Node* newTail) {
            /**
                append(Node* newTail) - Adds newTail to the end of the LinkedList

                Parameters:
                    Node* newTail - A pointer to the Node you wish to append to the LinkedList
            */

            if (size != 0) {
                (*tail).setNextNode(newTail);
                tail = newTail;
            }
            else {
                head = newTail;
                tail = newTail;
            }
            size++;
        }

        Node* getTail() {
            /**
                getTail() - Gets the tail Node of the LinkedList

                Returns:
                    Node* - Returns a pointer to the tail field of the LinkedList
            */

            return tail;
        }

        int getSize() {
            /**
                getSize() - Gets the size of the LinkedList

                Returns:
                    int - Returns the size field of the LinkedList
            */

            return size;
        }

        Node* getNode(int index) {
            /**
                getNode(int index) - Gets the Node at the requested index of the LinkedList

                Parameters:
                    int index - The index of the Node you would like to get from LinkedList
                
                Returns:
                    Node* - Returns a pointer to the Node at the requested index of LinkedList
                
                Exceptions:
                    out_of_range - index argument is out of bounds for length of LinkedList
            */

            if (index < size && index > -1) {
                Node* output = head;
                for (int i = 0; i < index; i++) {
                    output = (*output).getNextNode();
                }
                return output;
            }
            else {
                throw std::out_of_range("index argument is out bounds for length of LinkedList");
            }
        }

        void insert(int index, Node* node) {
            /**
                insert(int index, Node* node) - Inserts node at the requested index of the LinkedList

                Parameters:
                    int index - The index of the LinkedList you wish to insert node into
                    Node* node - A pointer to the Node you wish to insert into LinkedList at requested index
                
                Exceptions:
                    out_of_range - index argument is out of bounds for length of LinkedList
            */

            if (index < size && index > -1) {
                if (index == 0) {
                    setHead(node);
                }
                else if (index == size) {
                    append(node);
                }
                else {
                    Node* oldNode = getNode(index);
                    Node* prevNode = getNode(index - 1);
                    (*prevNode).setNextNode(node);
                    (*node).setNextNode(oldNode);
                    size++;
                }
            }
            else {
                throw std::out_of_range("index argument is out of bounds for length of LinkedList");
            }
        }

        Node* pop() {
            /**
                pop() - Removes and returns the tail from the LinkedList

                Returns:
                    Node* - Returns a pointer to the tail Node of LinkedList
            */

            return pop(size - 1);
        }

        Node* pop(int index) {
            /**
                pop(int index) - Removes and returns the Node from LinkedList at the requested index

                Parameters:
                    int index - The index of the Node you wish to remove and return from LinkedList

                Returns:
                    Node* - Returns a pointer to the Node at the requested index of LinkedList
                
                Exceptions:
                    out_of_range - index argument is out bounds for length of LinkedList
            */

            Node* output = NULL;
            if ((index < (size - 1)) && (index > 0) && (size != 0)) {
                Node* prev = getNode(index - 1);
                output = getNode(index);
                (*prev).setNextNode(getNode(index + 1));
                size--;
            }
            else if (index == 0 && size != 0) {
                output = head;
                head = (*head).getNextNode();
                size--;
            }
            else {
                std::out_of_range("index argument is out of bounds for length of LinkedList");
            }
            return output;
        }

        void reverse() {
            /**
                reverse() - Reverses the order of the LinkedList
            */

            if (size > 1) {
                Node* start = head;
                Node* prev = head;
                Node* current = (*head).getNextNode();
                Node* next;
                for (int i = 0; i < (size - 1); i++) {
                    next = (*current).getNextNode();
                    (*current).setNextNode(prev);
                    prev = current;
                    current = next;
                }
                head = prev;
                (*start).setNextNode(NULL);
            }
        }

        string toString() {
            /**
                To String Method

                Returns:
                    Returns a string representation of the LinkedList
            */
            
            string output = "";
            Node* currentNode = head;
            for (int i = 0; i < size; i++) {
                output += (*currentNode).getData();
                if (i != (size - 1)) {
                    output += " ->\n";
                }
                else {
                    output += " (END)";
                }
                currentNode = (*currentNode).getNextNode();
            }
            return output;
        }

};