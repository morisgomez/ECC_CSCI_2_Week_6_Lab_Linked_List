/*
 Program Name: LinkedList.cpp
 Programmer: Moris Gomez
 Date: Sunday 03/17/2024
 Version Control: 5.0
 About: Week 5, CSCI 2, Lab.
 Description:
    Design a linked list class to hold a series of integers. The class should have member functions for
    appending (adding a node at the end of the list), adding a node at the beginning of the list,
    delete a node function, insert a node function, and printing & counting the nodes. Demonstrate
    the class with a driver program to test the member functions and display the result after calling
    each member function.
*/

#include <iostream>
using namespace std;

class LinkedList //to create objects of Linked Lists.
{
    struct Node //when using struct to create Node objects, struct is nested in LinkedList class.
    {
        int data = 0; //data initialized to 0 for each Node creation.
        Node *next = NULL; //next Node pointer initialized to NULL for each Node creation.
    }; //end structure for Node.

private:
    Node *head; //head pointer always created for each LinkedList object.
public:
    //constructor:
    LinkedList()
    {
        head = NULL; //head pointer always assigned NULL for each LinkedList object.
    }
    
    //member functions:
//FUNCTION #1: to display Linked List:
    void display()
    {
        Node *current = head; //current points to w/e head is pointing to. //used to traverse Nodes.
        int counter = 1; //tracks each Node passed via current.
        while(current != NULL) //as long as Linked List exists keep iterating...
        {
            cout << "this is Node " << counter << " with address of: " << current << endl; //for 1st Node.
            cout << "Node " << counter << " has 'data' value of: " << current->data << endl; //for 1st Node.
            cout << "Node " << counter << " has 'next' value of: " << current->next << endl; //for 1st Node.
            cout << "----------------" << endl;
            current = current->next; //assign the next address (2nd Node) of 1st node to current pointer.
            counter = counter + 1; //add 1.
        } //end while loop.
    } //end display function.
    
//FUNCTION #2: to append a new Node to end of Linked List:
    void append(int m) //m holds data of new Node.
    {
        Node *n = new Node; //create new Node & n points to address of it.
        n->data = m; //data of new Node is m.
        
        //create a pointer not referencing a Node yet.
        Node *current; //used to traverse Nodes.
        
        if (head != NULL) //if Linked List exists, do this...
        {
            current = head; //make current point to the same Node head is pointing to (1st Node).
            //nested while loop:
            while (current->next != NULL) //as long as next points to another Node (2nd Node), keep iterating...
            {
                current = current->next; //keep assigning Nodes to current pointer //keep traversing.
            } //end nested while loop.
            current->next = n; //when reach last Node (its next is NULL), make its Node point to new Node.
        }
        else //if Linked List has not been made (0 Nodes)...
        {
            head = n; //make head point to new Node.
        }
    } //end append function.
    
//FUNCTION #3: to delete a Node of List:
    void deleteNode(int m) //m holds data of new Node.
    {
        Node * x = NULL; //pointer pointing to NULL in charge of holding matching m for deletion.
        Node *current; //empty pointer used to traverse Nodes.
        Node *temp; //empty poiner to hold Node value after current moves to next Node.
        temp = head; //point to first Node.
        current = head; //point to first Node.
        
        while(current != NULL && current->data != m) //while there is a 1st Node & data value of 1st Node is not m...
        {
            //keep trasversing the list...
            temp = current; //assign temp current.
            current = current->next; //move to next Node.
        }  //end while loop.
        if (current == NULL) //we are at the last Node which next points to NULL.
        {
            cout << m << "not in list" << endl;
            delete x; //delete the pointer of x since we are not going to use it since not found.
        } //end if.
        else //current is matching m value (delete current)...????
        {
            x = current; //assign x to whatever current is pointing to delete.
            current = current->next; //this right here is in charge of adjusting surronding nodes before deleting selected Node?????
            temp->next = current; //this right here is in charge of adjusting surronding nodes before deleting selected Node?????
            if(x == head) //if x is the first Node... special case.
            {
                head = head->next; //assign head to the 2nd Node
                temp = NULL; //have temp point to NULL.
            } //end inner if.
            delete x; //delete matching m.
        } //end else.
        cout << endl << endl << "NODE WITH THE VALUE " << m << " HAS BEEN DELETED." << endl << endl << endl;
    } //end deleteNode function.
    
    
//FUNCTION #4: to add a new Node at the front of the Linked List:
    void addNode(int m) //m holds data of new Node.
    {
        Node *n = new Node; //create new Node & n points to address of it.
        n->data = m; //data of new Node is m.
        if (head != NULL) //if Linked List exists, do this..
        {
            n->next = head; //make next of new Node point to head (2nd Node).
            head = n; //head is no new Node.
        } //end if.
        else //head is NULL, so 0 Nodes.
        {
            head = n; //make head point to new Node.
            n->next = NULL; //next of new Node points to NULL bc it is 1st & last Node.
        } //end else.
    } //end addNode function.
    
//FUNCTION #5: to add a node b/w 2 other Nodes:
    void insertNode(int num) //num holds data of new Node.
    {
        Node *n = new Node; //create new Node & n points to address of it.
        n->data = num; //data of new Node is num.
        Node *current; //empty pointer used to traverse Nodes.
        Node *preNode; //empty pointer for previous Node.
        if (head == NULL) //if Linked List does not exist (0 Nodes), do this...
        {
            head = n; //new Node becomes the 1st Node, so head points to it.
        } //end if.
        else //if a Linked List exist, do this...
        {
            current = head; //current points to head (1st Node).
            preNode = NULL; //can also do this outside on same line it was declared.
            while (current != NULL && current->data < num) //as long as current points to a Node & the data vale of current is less than num, keep iterating...????
            {
                preNode = current; //current becomes preNode.
                current = current->next; //move on to next Node.
            } //end while.
            if (preNode == NULL) //num is smaller than all data values on existing Nodes, put new Node at front.
            {
                head = n; //head points to new Node.
                n->next = current; //previous 1st Node becomess 2nd Node.
            } //end nested if.
            else //current reaches a Node where num is > than data...???
            {
                preNode->next = n; //previous Node next becomes new Node.
                n->next = current; //new Node next becomes current.
            }
            cout << endl << endl << "NODE WITH THE VALUE " << num << " HAS BEEN INSERTED." << endl << endl << endl;
        } //end else.
    } //end insertNode function.
    
//FUNCTION #6: to get size of Linked List function:
    int getSize()
    {
        Node *current = head; //current points to w/e head is pointing to (1st Node).
        int counter = 1; //tracks each Node passed in current.
        if (current == NULL) //if there are 0 Nodes, do this...
        {
            cout << "there is no existing Linked List." << endl;
        }
        else //if there is minimum 1 Node, do this...
        {
            while(current->next != NULL) //as long as next points to another Node (2nd Node), keep iterating...
            {
                current = current->next; //go to 2nd Node.
                counter = counter + 1;
            } //end nested while loop.
            //exit while loop bc you have reached last Node.
        } //end else.
        return counter; //after if-else.
    } //end getSize function.
}; //end class for LinkedList.

int main()
{
    LinkedList listOne; //create a list w/ default pointer of 'head' that points to NULL.
    listOne.append(3); //append new Node.
    listOne.append(6); //append new Node.
    listOne.append(9); //append new Node.
    listOne.append(12); //append new Node.
    listOne.display(); //display 4 Nodes in List.
    
    listOne.deleteNode(9); //delete 3rd Node in List.
    listOne.display(); //display remaining 3 Nodes in List.
    
    listOne.insertNode(7); //insert Node b/w 2nd and 3rd Node.
    listOne.display(); //display 4 Nodes in List.
    cout << endl << endl << "THE LINKED LIST HAS: " << listOne.getSize() << " NODES TOTAL!" << endl << endl; //4 Nodes.
    return 0;
}

/*
 QUESTIONS/NOTES:
 1. I am having a hard time understanding logic of delete and insert member functions, especially insert.
 2. Try practicing delete on a separate project with just that function, then same for insert.
 3. This project uses struct to create Node types, so struct has to be nested in LinkedList class.
 4. When using class for Node types, can just have Node class and LinkedLIst class after it (no nesting).
 5. Look at slides provided by Tiffany for more practice on Linked Lists.
 */

