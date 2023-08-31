#include<iostream>
#include<limits.h>
using namespace std;

class Node{
    public:
        int data;
        Node* next;
        Node* prev;
    
    Node(int data){
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }

    ~Node(){
        if(this->next!=NULL){
            delete next;
            this->next = NULL;
        }
    }
};

class DoublyLinkedList{
    private:
        Node* head;
        Node* tail;
    public:
        // find previous node of given position(e.g if position=3 it will give 2nd node of linked list)
        Node* getPrevNode(int position){
            int count = 1;
            Node* node = this->head;
            while(count<(position-1) && node!=NULL){
                count++;
                node = node->next;
            }
            return node;
        }

        void insertAtHead(int data){
            Node* newNode = new Node(data);
            // if linked list is empty
            if(this->head==NULL){
                this->head = newNode;
                this->tail = newNode;
                return;
            }

            newNode->next = this->head;
            this->head->prev = newNode;
            this->head = newNode;
        }

        void insertAtTail(int data){
            if(this->tail==NULL){
                this->insertAtHead(data);
                return;
            }

            Node* newNode = new Node(data);

            newNode->prev = this->tail;
            this->tail->next = newNode;
            this->tail = newNode;

        }

        void insertAtPosition(int position, int data){
            if(position<1){
                cout<<"The position must be greater than 0"<<endl;
                return;
            }
            if(position==1){
                this->insertAtHead(data);
                return;
            }

            Node*  nodeBeforeInsertingNode = this->getPrevNode(position);

            // if nodeBeforeInsertingNode is null then it means the element cannot be inserted at given position
            if(nodeBeforeInsertingNode==NULL){
                cout<<"The position must be less than or equal to "<<this->length()+1<<endl;
                return;
            }

            // if position is just after tail(means last pe add kro)
            if(nodeBeforeInsertingNode->next==NULL){
                this->insertAtTail(data);
                return;
            }
            
            Node* newNode = new Node(data);
            newNode->next = nodeBeforeInsertingNode->next;
            nodeBeforeInsertingNode->next->prev = newNode;

            newNode->prev = nodeBeforeInsertingNode;
            nodeBeforeInsertingNode->next = newNode;

        }

        void deleteNode(int element){
            int position = this->search(element);
            if(position==-1){
                cout<<element<<" is not found in linked list"<<endl;
                return;
            }  

            // if head & tail are pointing to same node or null(means either the linked has only 1 node or the linked list is empty)
            if(this->head==this->tail){
                // if linked list is not empty(means 1 element)
                if(this->head!=NULL){
                    delete this->head;
                    this->head = NULL;
                    this->tail = NULL;
                }
                // else if linked list is empty then no need to do anything
                else{
                    cout<<"Linked list is empty"<<endl;
                }
                return;
            }

            // delete head node
            if(position==1){
                Node* node = this->head;

                this->head = node->next;
                this->head->prev = NULL;

                node->next = NULL;
                delete node;
                return;
            }

            Node* nodeToDelete = this->head;
            while(nodeToDelete!=NULL){
                if(nodeToDelete->data==element){
                    break;
                }
                nodeToDelete = nodeToDelete->next;
            }

            // delete tail node
            if(nodeToDelete->next==NULL){
                Node* node = this->tail;

                this->tail = this->tail->prev;
                this->tail->next = NULL;

                node->prev = NULL;
                delete node;
                return;
            }

            // delete any middle node
            Node* prevNode = nodeToDelete->prev;
            Node* nextNode = nodeToDelete->next;

            prevNode->next = nextNode;
            nextNode->prev = prevNode;

            nodeToDelete->prev = NULL;
            nodeToDelete->next = NULL;
            delete nodeToDelete;

        }

        int search(int element){
            int position = 1;
            Node* temp = this->head;
            while(temp!=NULL){
                if(temp->data==element){
                    return position;
                }
                position++;
                temp = temp->next;
            }
            // element not found in linked list
            return -1;
        }

        // bool isPresent(int element){
        //     Node* temp = this->head;
        //     while(temp!=NULL){
        //         if(temp->data==element){
        //             return true;
        //         }
        //         temp = temp->next;
        //     }
        //     return false;
        // }

        int findNthNode(int n){
            int nodeData;

            int position = 1;
            Node* temp = this->head;
            while(temp!=NULL){
                if(position==n){
                    nodeData = temp->data;
                    break;
                }
                position++;
                temp = temp->next;
            }
            return nodeData;
        }

        int getCount(int element){
            int count = 0;
            Node* temp = this->head;
            while(temp!=NULL){
                if(temp->data==element){
                    count++;
                }
                temp = temp->next;
            }
            return count;
        }

        int getMax(){
            int max = INT_MIN;
            Node* temp = this->head;
            while(temp!=NULL){
                if(temp->data>max){
                    max = temp->data;
                }
                temp = temp->next;
            }
            return max;            
        }

        int getMin(){
            int min = INT_MAX;
            Node* temp = this->head;
            while(temp!=NULL){
                if(temp->data<min){
                    min = temp->data;
                }
                temp = temp->next;
            }
            return min;
        }

        int length(){
            int count = 0;
            Node* temp = this->head;
            while(temp!=NULL){
                count++;
                temp = temp->next;
            }
            return count;
        }

        void print(){
            Node* temp = this->head;
            while(temp!=NULL){
                cout<<temp->data<<" ";
                temp = temp->next;
            }
            cout<<endl;
        }

    DoublyLinkedList(){
        this->head = NULL;
        this->tail = NULL;
    }
};

int main(){
    DoublyLinkedList* doublyLL = new DoublyLinkedList();

    doublyLL->insertAtHead(5);
    doublyLL->print();
    cout<<"Size of DLL is "<<doublyLL->length()<<endl;

    doublyLL->insertAtHead(10);
    doublyLL->print();
    cout<<"Size of DLL is "<<doublyLL->length()<<endl;

    doublyLL->insertAtTail(11);
    doublyLL->print();
    cout<<"Size of DLL is "<<doublyLL->length()<<endl;

    cout<<"Max is "<<doublyLL->getMax()<<endl;
    cout<<"Min is "<<doublyLL->getMin()<<endl;
    cout<<"10 is present at position "<<doublyLL->search(10)<<endl;
    cout<<"2 is present at position "<<doublyLL->search(2)<<endl;
    cout<<"2nd Node is "<<doublyLL->findNthNode(2)<<endl;

    doublyLL->insertAtPosition(1,11);
    doublyLL->insertAtPosition(3,2);
    doublyLL->insertAtPosition(6,99);
    doublyLL->print();
    cout<<"11 is present times "<<doublyLL->getCount(11)<<endl;

    doublyLL->deleteNode(11);
    doublyLL->print();
    doublyLL->deleteNode(2);
    doublyLL->print();
    doublyLL->deleteNode(99);
    doublyLL->print();
    return 0;
}