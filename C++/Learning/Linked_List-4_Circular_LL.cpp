/*

-Circular Linked List 

-Here Head and Tail nodes are connexted to each other -> which makes it a circle pattern

-Advantages of Circular Linked List over singular or doubly
->we can start transversing from any node to  print all node until wer reach visited node 
->when we have to traverse linked list 


-Insertion in a singular Linked List at START!


#include<iostream>
using namespace std;
class node{
    public:
    int val;
    node* next;
    node(int data){
        val=data;
        next=NULL;
    }
};
class circular{
    public:
    node* head;
    circular(){
        head=NULL;
    }

    void display(){
        node* temp=head;  //because temp is already head so first we need to change it and them check condition
        do
        {
            cout<<temp->val<<" -> ";
            temp=temp->next;
        } while (temp!=head);
        cout<<endl;
        
    }
    
    void insertAtStart(int val){
        node* newnode=new node(val);
        if (head==NULL)
        {
            head=newnode;
            newnode->next=head; //circular Linked List
            return;
        }
        node* tail=head;
        while (tail->next!=head)
        {
            tail=tail->next;
        }
        //now tail is pointing to the last node

        tail->next=newnode;
        newnode->next=head;
        head=newnode;

    }

};

int main(){
    circular sd;
    sd.insertAtStart(1);
    sd.display();
    sd.insertAtStart(2);
    sd.display();
    sd.insertAtStart(3);
    sd.display();
    return 0;
}

Output:-
1 -> 
2 -> 1 -> 
3 -> 2 -> 1 -> 

->>To check if its is circular or not just run a loop more than its size and print temp->val , which normally should not give values 
exceeding its size but here it will start repeating the loop in a circular manner

-Insertion at the the end of the Linked List

#include<iostream>
using namespace std;
class node{
    public:
    int val;
    node* next;
    node(int data){
        val=data;
        next=NULL;
    }
};
class circular{
    public:
    node* head;
    circular(){
        head=NULL;
    }

    void display(){
        node* temp=head;  //because temp is already head so first we need to change it and them check condition
        do
        {
            cout<<temp->val<<" -> ";
            temp=temp->next;
        } while (temp!=head);
        cout<<endl;
        
    }
    
    void insertAtTail(int val){
        node* newnode= new node(val);
        if (head==NULL)
        {
            head=newnode;
            newnode->next=head; //circular Linked List
            return;
        }
        node* tail=head;
        while (tail->next!=head)
        {
            tail=tail->next;
        }
        //here tail will be pointing to last node

        tail->next=newnode;
        newnode->next=head;
        tail=newnode;
        
    }

};

int main(){
    circular sd;
    sd.insertAtTail(1);
    sd.display();
    sd.insertAtTail(2);
    sd.display();
    sd.insertAtTail(3);
    sd.display();
    return 0;
}

Output:-
1 -> 
1 -> 2 ->
1 -> 2 -> 3 ->

->Insertion at the start is of same time complexity as insertion at the end -> O(n)

-Insertion at the Kth position -> no great change just temp->next=newnode and newnode->next=temp->next->next 


#include<iostream>
using namespace std;
class node{
    public:
    int val;
    node* next;
    node(int data){
        val=data;
        next=NULL;
    }
};
class circular{
    public:
    node* head;
    circular(){
        head=NULL;
    }

    void display(){
        node* temp=head;
        do
        {
            cout<<temp->val<<" -> ";
            temp=temp->next;

        } while (temp!=head);
        cout<<endl;
    }
    
    void insertAtTail(int val){
        node* newnode=new node(val);
        if (head==NULL)
        {
            head=newnode;
            newnode->next=head; //circular
            return;
        }
        
        node*tail=head;
        while (tail->next!=head)
        {
            tail=tail->next;
        }
        
        tail->next=newnode;
        newnode->next=head;
        tail=newnode;
    }

    void deleteAtStart(){
        if (head==NULL)
        {
            return;
        }
        node* temp=head;
        node* tail=head;
        while (tail->next!=head)
        {
            tail=tail->next;
        }
        head=head->next;
        tail->next=head;
        free(temp);
    }
};

int main(){
    circular sd;
    sd.insertAtTail(1);
    sd.display();
    sd.insertAtTail(2);
    sd.display();
    sd.insertAtTail(3);
    sd.display();
    sd.deleteAtStart();
    sd.display();
    sd.deleteAtStart();
    sd.display();
    return 0;
}

Output:-
1 -> 
1 -> 2 ->
1 -> 2 -> 3 ->
2 -> 3 ->
3 ->

-Deletion of Node at the end of Linked List


#include<iostream>
using namespace std;
class node{
    public:
    int val;
    node* next;
    node(int data){
        val=data;
        next=NULL;
    }
};
class circular{
    public:
    node* head;
    circular(){
        head=NULL;
    }

    void display(){
        node* temp=head;
        do
        {
            cout<<temp->val<<" -> ";
            temp=temp->next;

        } while (temp!=head);
        cout<<endl;
    }
    
    void insertAtTail(int val){
        node* newnode=new node(val);
        if (head==NULL)
        {
            head=newnode;
            newnode->next=head; //circular
            return;
        }
        
        node*tail=head;
        while (tail->next!=head)
        {
            tail=tail->next;
        }
        
        tail->next=newnode;
        newnode->next=head;
        tail=newnode;
    }

    void deleteAtEnd(){
        if (head==NULL)
        {
            return;
        }
        node* tail=head;
        while (tail->next->next!=head)
        {
            tail=tail->next;
        }
        
        //here tail is pointing to the second last node
        node* temp=tail->next;
        tail->next=head;
        free(temp);

    }
};

int main(){
    circular sd;
    sd.insertAtTail(1);
    sd.display();
    sd.insertAtTail(2);
    sd.display();
    sd.insertAtTail(3);
    sd.display();
    sd.deleteAtEnd();
    sd.display();
    sd.deleteAtEnd();
    sd.display();
    return 0;
}

Output:-
1 -> 
1 -> 2 ->
1 -> 2 -> 3 ->
1 -> 2 ->
1 ->

-Time complexity for both deletion at  end and start is O(n);
*/




