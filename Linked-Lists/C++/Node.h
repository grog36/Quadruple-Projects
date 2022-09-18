//Gregory Ecklund
//September 2022

#include <iostream>
#include <string>
using namespace std;

class Node {
    /**
        Node Class - Data Structure

        Fields:
            private string data (default = data/"") - Data to be held inside of a Node
            private Node* nextNode (default = nextNode/NULL) - A pointer reference to the next Node
    */

    private:
        string data;
        Node* nextNode;

    public:
        Node() {
            /**
                Constructor() - Base constructor, no parameters
            */

            data = "";
            nextNode = NULL;
        }

        Node(string startingData) {
            /**
                Constructor(string startingData) - Constructor containing only the data field

                Parameters:
                    string startingData (default = "") - Data to be held inside of the Node
            */

            data = startingData;
            nextNode = NULL;
        }

        Node(Node* startingNextNode) {
            /**
                Constructor(Node* startingNextNode) - Constructor containing only the nextNode field

                Parameters:
                    Node startingNextNode (default = NULL) - A pointer reference to the next Node
            */

            data = "";
            nextNode = startingNextNode;
        }

        Node(string startingData, Node* startingNextNode) {
            /**
                Constructor(string startingData, Node* startingNextNode) - Constructor containing both fields

                Parameters:
                    string startingData (default = "") - Data to be held inside of the Node
                    Node* nextNode (default = NULL) - A pointer reference to the next Node
            */

            data = startingData;
            nextNode = startingNextNode;
        }

        Node* getNextNode() {
            /**
                getNextNode() - Gets and returns the nextNode field from the Node

                Returns:
                    Node* - Returns a pointer to the nextNode field of the Node
            */

            return nextNode;
        }

        void setNextNode(Node* newNextNode) {
            /**
                setNextNode(Node* newNextNode) - Sets the nextNode field to newNextNode for the Node

                Parameters:
                    Node* newNextNode - A pointer to the Node you wish for this Node to point to
            */

            nextNode = newNextNode;
        }

        string getData() {
            /**
                getData() - Gets and returns the data field from the Node

                Returns:
                    string - Returns the data field of the Node
            */

            return data;
        }

        void setData(string newData) {
            /**
                setData(string newData) - Sets the data field to newData for the Node

                Parameters:
                    string newData - The new data you wish to be stored inside the Node
            */

            data = newData;
        }

        string toString() {
            /**
                To String Method

                Returns:
                    Returns a String representation of the Node
            */
            
            string output = "Data: " + data + "\nNextNode: ";
            if (nextNode != NULL) {
                output += (*nextNode).getData();
            }
            else {
                output += "NULL";
            }
            return output;
        }
};