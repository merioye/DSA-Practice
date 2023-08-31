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
        if(this->next!=NULL){
            delete this->next;
            this->next = NULL;
        }
    }
};

class CircularLinkedList{
    private:
        Node* tail;
    public:
        // find previous node of given position(e.g if position=3 it will give 2nd node of linked list
        Node* getPrevNode(int position){
            if(position>this->length()+1){
                return NULL;
            }

            int count = 1;
            Node* node = this->tail->next;
            while(count<(position-1)){
                count++;
                node = node->next;
            }

            return node;
        }

        void insertAtHead(int data){
            Node* newNode = new Node(data);

            // if linked list is empty
            if(this->tail==NULL){
                this->tail = newNode;
                this->tail->next = newNode;
                return;
            }

            Node* head = this->tail->next;
            this->tail->next = newNode;
            newNode->next = head;
        }

        void insertAtTail(int data){
            Node* newNode = new Node(data);

            // if linked list is empty
            if(this->tail==NULL){
                this->tail = newNode;
                this->tail->next = newNode;
                return;
            }

            Node* head = this->tail->next;
            this->tail->next = newNode;
            this->tail = newNode;
            newNode->next = head;
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

            Node* nodeBeforeInsertingNode = this->getPrevNode(position);

            // if nodeBeforeDeletingNode is null then it means the element cannot be inserted at given position
            if(nodeBeforeInsertingNode==NULL){
                cout<<"The position must be less than or equal to "<<this->length()+1<<endl;
                return;
            }

            if(nodeBeforeInsertingNode==this->tail){
                this->insertAtTail(data);
                return;
            }

            Node* newNode = new Node(data);
            newNode->next = nodeBeforeInsertingNode->next;
            nodeBeforeInsertingNode->next = newNode;
        }

        void deleteNode(int element){
            if(this->tail==NULL){
                return;
            }

            // if linked list has only single node
            if(this->tail==this->tail->next){
                if(this->tail->data==element){
                    this->tail->next = NULL;
                    delete this->tail;
                    this->tail = NULL;
                }
                return;
            }

            // delete first node
            if(this->tail->next->data==element){
                Node* firstNode = this->tail->next;

                this->tail->next = firstNode->next;

                firstNode->next = NULL;
                delete firstNode;
                return;
            }

            int position = 1;
            Node* nodeToDelete = this->tail->next;
            while(nodeToDelete!=this->tail){
                if(nodeToDelete->data==element){
                    break;
                }
                position++;
                nodeToDelete = nodeToDelete->next;
            }

            Node* nodeBeforeDeletingNode = this->getPrevNode(position);

            // delete tail node
            if(nodeToDelete==this->tail && nodeToDelete->data==element){
                nodeBeforeDeletingNode->next = this->tail->next;
                this->tail->next = NULL;
                delete this->tail;
                this->tail = nodeBeforeDeletingNode;
                return;
            }

            // delete any middle element
            nodeBeforeDeletingNode->next = nodeToDelete->next;
            nodeToDelete->next = NULL;
            delete nodeToDelete;
        }
        
        bool isPresent(int element){
            // check tail node
            if(this->tail->data==element){
                return true;
            }

            // check for remaining nodes
            Node* temp = this->tail->next;
            while(temp!=this->tail){
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
            Node* temp = this->tail->next;
            // compare from 1st to tail-1 node's position
            while(temp!=this->tail){
                if(position==n){
                    nodeData = temp->data;
                    break;
                }
                position++;
                temp = temp->next;
            }

            // check if tail node position is the nth node
            if(n==position+1){
                nodeData = this->tail->data;
            }

            return nodeData;
        }

        int getCount(int element){
            if(this->tail==NULL){
                return 0;
            }

            int count = 0;
            Node* temp = this->tail->next;
            // compare from 1st to tail-1 node's data
            while(temp!=this->tail){
                if(temp->data==element){
                    count++;
                }
                temp = temp->next;
            }

            // check if tail node data is equal to element
            if(this->tail->data==element){
                count++;
            }
            return count;
        }

        int getMax(){
            if(this->tail==NULL){
                cout<<"Linked list list empty"<<endl;
                return INT_MAX;
            }

            int max = this->tail->data;
            Node* temp = this->tail->next;
            while(temp!=this->tail){
                if(temp->data>max){
                    max = temp->data;
                }
                temp = temp->next;
            }
            return max;
        }

        int getMin(){
            if(this->tail==NULL){
                cout<<"Linked list list empty"<<endl;
                return INT_MIN;
            }

            int min = this->tail->data;
            Node* temp = this->tail->next;
            while(temp!=this->tail){
                if(temp->data<min){
                    min = temp->data;
                }
                temp = temp->next;
            }
            return min;
        }

        int length(){
            if(this->tail==NULL){
                return 0;
            }

            int count = 1;
            Node* temp = this->tail->next;
            while(temp!=this->tail){
                count++;
                temp = temp->next;
            }
            return count;
        }

        void print(){
            if(this->tail==NULL){
                return;
            }

            Node* temp = this->tail->next;
            // it will print elements from 1st to tail-1 position
            while(temp!=this->tail){
                cout<<temp->data<<" ";
                temp = temp->next;
            }
            // print tail element
            cout<<this->tail->data<<endl;
        }
};

int main(){
    CircularLinkedList* circularLL = new CircularLinkedList();

    circularLL->insertAtHead(5);
    circularLL->print();
    cout<<"Size of CLL is "<<circularLL->length()<<endl;

    circularLL->insertAtHead(10);
    circularLL->print();
    cout<<"Size of CLL is "<<circularLL->length()<<endl;

    circularLL->insertAtTail(11);
    circularLL->print();
    cout<<"Size of CLL is "<<circularLL->length()<<endl;

    cout<<"Max is "<<circularLL->getMax()<<endl;
    cout<<"Min is "<<circularLL->getMin()<<endl;
    cout<<"10 is present? "<<circularLL->isPresent(10)<<endl;
    cout<<"2 is present? "<<circularLL->isPresent(2)<<endl;
    cout<<"2nd Node is "<<circularLL->findNthNode(2)<<endl;

    circularLL->insertAtPosition(1,11);
    circularLL->insertAtPosition(3,2);
    circularLL->insertAtPosition(6,99);
    circularLL->print();
    cout<<"11 is present times "<<circularLL->getCount(11)<<endl;

    circularLL->deleteNode(11);
    circularLL->print();
    circularLL->deleteNode(2);
    circularLL->print();
    circularLL->deleteNode(99);
    circularLL->print();
    return 0;
}