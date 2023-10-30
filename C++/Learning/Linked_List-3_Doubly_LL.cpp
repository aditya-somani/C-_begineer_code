/*
-Doubly Linked List - bidirectional unlike singly linked list
i.e. transversal both ways -> advantage over singly linked list

-Insertion and deletion becomes more efficient
-disadvantage -> extra space for previous ptr

-creating a doubly linked list and inserting in it

#include<iostream>
using namespace std;
class node{
    public:
    int val;
    node* prev;
    node* next;
    node(int data){
        val=data;
        prev=NULL;
        next=NULL;
    }
};
class doublyLinkedList{
    public:
    node* head;
    node* tail;

    doublyLinkedList(){
        head=NULL;
        tail=NULL;
    }

    void display(){
        node* temp=head;
        while (temp!=NULL)
        {
            cout<<temp->val<<" <-> ";
            temp=temp->next;
        }
        cout<<endl;
    }

    void insertAtStart(int val){
        node* newnode=new node(val);
        if (head==NULL)
        {
            head=newnode;
            tail=newnode;
            return;
        }
        newnode->next=head;
        head->prev=newnode;
        head=newnode;
        return;

    }

    void insertAtLast(int val){
        node* newnode=new node(val);
        if (tail==NULL)
        {
            head=newnode;
            tail=newnode;
        }
        
        tail->next=newnode;
        newnode->prev=tail;
        tail=newnode;
    }

    void insertAtPosition(int val,int k){

        //assuming k is less or equal to length of doubly Linked List
        node* temp=head;
        int count = 0;
        while (count<(k-1))
        {
            temp=temp->next;
            count++;
        }
        
        //temp will be pointing to the node at (k-1)th position
        node* newnode=new node(val);
        newnode->next=temp->next;
        temp->next=newnode;

        newnode->prev=temp;
        newnode->next->prev=newnode;
        return;

        //Time complexity -> O(k) or in worsst case ->O(n);

    }

};
int main(){
    doublyLinkedList dll;
    dll.insertAtStart(1);
    dll.insertAtStart(2);
    dll.insertAtStart(3);
    dll.display();
    dll.insertAtLast(1);
    dll.insertAtLast(2);
    dll.insertAtLast(3);
    dll.display();
    dll.insertAtPosition(7,3);
    dll.insertAtPosition(9,6);
    dll.display();
    return 0;
}

Output:-
3 <-> 2 <-> 1 <-> 
3 <-> 2 <-> 1 <-> 1 <-> 2 <-> 3 <->
3 <-> 2 <-> 1 <-> 7 <-> 1 <-> 2 <-> 9 <-> 3 <->


#include<iostream>
#include<vector>
using namespace std;
class node{
    public:
    int val;
    node* next;
    node* prev;
    node(int data){
        val=data;
        prev=NULL;
        next=NULL;
    }
};
class doublyll{
    public:
    node* head;
    node* tail;
    doublyll(){
        head=NULL;
        tail=NULL;
    }

    void insert(int val){
        node* newnode=new node(val);
        if (tail==NULL)
        {
            head=newnode;
            tail=newnode;
        }
        tail->next=newnode;
        newnode->prev=tail;
        tail=newnode;

    }

    void display(){
        node* temp=head;
        while (temp!=NULL)
        {
            cout<<temp->val<<" <-> ";
            temp=temp->next;

        }
        cout<<endl;
    }

    void deleteAtStart(){
        if (head==NULL)
        {
            return;
        }

        node* temp=head;
        head=head->next;
        if (head==NULL)  //if doubly Linked  List  had only 1 node
        {
            tail=NULL;
        }else{
            head->prev=NULL;
        }
        free(temp);
        return;
        
    }

    void deleteAtEnd(){
        if (head==NULL)
        {
            return;
        }
        node* temp=tail;
        tail=tail->prev;
        if (tail==NULL)
        {
            head=NULL;
        }else{
            tail->next=NULL;
        }
        free(temp);
        return;
    }

    void deleteAtPosition(int k){

        //assuming k is less than or equal to length of dll

        node* temp=head;
        int counter =1;
        while (counter<k)
        {
            temp=temp->next;
            counter++;
        }
        
        //now temp is pointing at node at kth position
        temp->prev->next=temp->next;
        temp->next->prev=temp->prev;
        free(temp);
        return;
    }

};
int main(){
    doublyll dll;
    int n;
    cout<<"Enter the size of Liked List : ";
    cin>>n;
    vector<int> v(n);
    cout<<"Enter the Linked List : ";
    for (int i = 0; i < n; i++)
    {
        cin>>v[i];
        dll.insert(v[i]);
    }
    cout<<"Linked List is : ";
    dll.display();
    cout<<"Deletion at start : ";
    dll.deleteAtStart();
    dll.display();
    cout<<"Deletion at end : ";
    dll.deleteAtEnd();
    dll.display();
    cout<<"Deleting at pos 2 is : ";
    dll.deleteAtPosition(2);
    dll.display();
    return 0;
}

Output:-
Enter the size of Liked List : 6
Enter the Linked List : 1 2 3 4 5 6
Linked List is : 1 <-> 2 <-> 3 <-> 4 <-> 5 <-> 6 <-> 
Deletion at start : 2 <-> 3 <-> 4 <-> 5 <-> 6 <->
Deletion at end : 2 <-> 3 <-> 4 <-> 5 <->
Deleting at pos 2 is : 2 <-> 4 <-> 5 <->



*/