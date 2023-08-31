// Given a linked list consisting of L nodes and given a number N. The task is 
// to find the Nth node from the end of the linked list.
// Example 1:
// Input:
// N = 2
// LinkedList: 1->2->3->4->5->6->7->8->9
// Output: 8

// Example 2:

// Input:
// N = 5
// LinkedList: 10->5->100->5
// Output: -1

#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* next;

    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};

class SinglyLinkedList{
    private:
        Node* head;
    public:
        void insertAtHead(int data){
            Node* newNode = new Node(data);

            // if linked list is empty
            if(this->head==NULL){
                this->head = newNode;
                return;
            }

            newNode->next = this->head;
            this->head = newNode;
        }

        int length(){
            int length = 0;
            Node* temp = this->head;
            while(temp!=NULL){
                length++;
                temp = temp->next;
            }
            return length;
        }

        int getNthNodeFromLast(int n){
            int length = this->length();

            if(length<n){
                return -1;
            }

            // repeat until head points to nth node from right side
            while(length!=n){
                length--;
                this->head = this->head->next;
            }

            return this->head->data;
        }


    SinglyLinkedList(){
        this->head = NULL;
    }

};

int main(){
    SinglyLinkedList* singlyLL = new SinglyLinkedList();
    singlyLL->insertAtHead(9);
    singlyLL->insertAtHead(8);
    singlyLL->insertAtHead(7);
    singlyLL->insertAtHead(6);
    singlyLL->insertAtHead(5);
    singlyLL->insertAtHead(4);
    singlyLL->insertAtHead(3);
    singlyLL->insertAtHead(2);
    singlyLL->insertAtHead(1);

    cout<<"3rd last element of linked list is "<<singlyLL->getNthNodeFromLast(3)<<endl;
    return 0;
}