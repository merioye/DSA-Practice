#include<iostream>
#include<limits.h>
using namespace std;

class Node{
    public:
        int data;
        Node* next;

    Node(int data){
        this->data = data;
        this->next = NULL;
    }

    ~Node(){
        cout<<"deleted "<<this->data<<endl;
        if(this->next!=NULL){
            delete next;
            this->next = NULL;
        }
    }
};

class SinglyLinkedList{
    private:
        Node* head;
        Node* tail;
    public:
        // find previous node of given position(e.g if position=3 it will give 2nd node of linked list
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
            this->head = newNode;
        }

        void insertAtTail(int data){
            if(this->tail==NULL){
                this->insertAtHead(data);
                return;
            }

            Node* newNode = new Node(data);
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

            // if nodeBeforeDeletingNode is null then it means the element cannot be inserted at given position
            if(nodeBeforeInsertingNode==NULL){
                cout<<"The position must be less than or equal to "<<this->length()+1<<endl;
                return;
            }

            // if position is just after tail(means last pe add kro)
            if(nodeBeforeInsertingNode->next==NULL){
                this->insertAtTail(data);
                return;
            }

            // middle men add kro
            Node* newNode = new Node(data);
            newNode->next = nodeBeforeInsertingNode->next;
            nodeBeforeInsertingNode->next = newNode;
        }

        bool isPresent(int element){
            Node* temp = this->head;
            while(temp!=NULL){
                if(temp->data==element){
                    return true;
                }
                temp = temp->next;
            }
            return false;
        }

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

        void deleteNode(int element){
            bool isPresent = this->isPresent(element);
            if(!isPresent){
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
            

            int nodePosition = 1;
            Node* nodeToDelete = this->head;
            while(nodeToDelete!=NULL){
                if(nodeToDelete->data==element){
                    break;
                }
                nodePosition++;
                nodeToDelete = nodeToDelete->next;
            }

            // delete the head node
            if(nodePosition==1){
                this->head = this->head->next;
                nodeToDelete->next = NULL;
                delete nodeToDelete;
                return;
            }

            Node* nodeBeforeDeletingNode = this->getPrevNode(nodePosition);

            // delete the tail node
            if(nodeToDelete->next==NULL){
                delete this->tail;
                nodeBeforeDeletingNode->next = NULL;
                this->tail = nodeBeforeDeletingNode;
                return;
            }

            // delete any middle node
            nodeBeforeDeletingNode->next = nodeToDelete->next;
            nodeToDelete->next = NULL;
            delete nodeToDelete;
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

    SinglyLinkedList(){
        this->head = NULL;
        this->tail = NULL;
    }
};





int main(){
    SinglyLinkedList* singlyLL = new SinglyLinkedList();

    singlyLL->insertAtHead(7);
    singlyLL->print();
    cout<<"Size of SLL is "<<singlyLL->length()<<endl;

    singlyLL->insertAtHead(10);
    singlyLL->print();
    cout<<"Size of SLL is "<<singlyLL->length()<<endl;

    singlyLL->insertAtTail(11);
    singlyLL->print();
    cout<<"Size of SLL is "<<singlyLL->length()<<endl;

    cout<<"Max is "<<singlyLL->getMax()<<endl;
    cout<<"Min is "<<singlyLL->getMin()<<endl;
    cout<<"10 is present? "<<singlyLL->isPresent(10)<<endl;
    cout<<"2 is present? "<<singlyLL->isPresent(2)<<endl;
    cout<<"2nd Node is "<<singlyLL->findNthNode(2)<<endl;

    singlyLL->insertAtPosition(1,11);
    singlyLL->insertAtPosition(3,2);
    singlyLL->insertAtPosition(6,99);
    singlyLL->print();
    cout<<"11 is present times "<<singlyLL->getCount(11)<<endl;

    singlyLL->deleteNode(11);
    singlyLL->print();
    singlyLL->deleteNode(7);
    singlyLL->print();
    singlyLL->deleteNode(99);
    singlyLL->print();

    return 0;
}