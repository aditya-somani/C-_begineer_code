/*
-Pattern : Slow - Fast Pointer

-1.Find the middle element of a given linked list

#include<iostream>
#include<vector>
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
class linkedlist{
    public:
    node* head;
    linkedlist(){
        head=NULL;
    }
    void insert(int value){
        node* newnode=new node(value);
        if (head==NULL)
        {
            head=newnode;
            return;
        }
        node* temp=head;
        while (temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=newnode;
        
    }
    void display(){
        node* temp=head;
        while (temp!=NULL)
        {
            cout<<temp->val<<" -> ";
            temp=temp->next;
        }
        cout<<"NULL"<<endl;
    }
};
node* findMiddleNode(node* &head){
    node* slow=head;
    node* fast=head;

    //for even -> fast!=NULL
    //for odd -> fast->next=NULL
    while (fast!=NULL && fast->next!=NULL)
    {
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;
}
int main(){
    linkedlist ll1;
    int n;
    cout << "Enter the size of Linked List : ";
    cin >> n;
    vector<int> v(n);
    cout << "Enter the Linked List : ";
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        // Insert each input element into the linked list.
        ll1.insert(v[i]);
    }
    
    cout << "Linked List is : ";
    ll1.display();
    node* middleNode=findMiddleNode(ll1.head);
    cout<<"Middle Elemnt is : "<<middleNode->val;
}

Output:-
Enter the size of Linked List : 6
Enter the Linked List : 1 2 3 4 5 6
Linked List is : 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> NULL
Middle Elemnt is : 4

-2.Given head, the head of a linked list, determine if the linked list has a cycle in it.

#include<iostream>
#include<vector>
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
class linkedlist{
    public:
    node* head;
    linkedlist(){
        head=NULL;
    }
    void insert(int value){
        node* newnode=new node(value);
        if (head==NULL)
        {
            head=newnode;
            return;
        }
        node* temp=head;
        while (temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=newnode;
        
    }
    void display(){
        node* temp=head;
        while (temp!=NULL)
        {
            cout<<temp->val<<" -> ";
            temp=temp->next;
        }
        cout<<"NULL"<<endl;
    }
};

bool detectCycle(node* head){
    if (!head)
    {
        return false;
    }
    

    node* slow=head;
    node* fast=head;

    while (fast && fast->next)
    {
        slow=slow->next;
        fast=fast->next->next;

        if (slow==fast)
        {
            return true;
        }
        
    }
    return false;
} 


int main(){
    linkedlist ll1;
    int n;
    cout << "Enter the size of Linked List : ";
    cin >> n;
    vector<int> v(n);
    cout << "Enter the Linked List : ";
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        // Insert each input element into the linked list.
        ll1.insert(v[i]);
    }
    
    cout << "Linked List is : ";
    ll1.display();


    node* end=ll1.head;
    while (end->next!=NULL)
    {
        end=end->next;
    }
    end->next=ll1.head->next->next; //Here we made a cycle to test our function
    
    if (detectCycle(ll1.head))
    {
        cout<<"Yes, the Linked List contains Cycle!";
    }
    else{
        cout<<"No,the Linked List does not contain any cycle ";
    }
}

Output:-
Enter the size of Linked List : 6
Enter the Linked List : 1 2 3 4 5 6
Linked List is : 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> NULL
Yes, the Linked List contains Cycle!

-2.1.Given head, the head of a linked list, determine if the linked list has a cycle in it and then remove it.

#include<iostream>
#include<vector>
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
class linkedlist{
    public:
    node* head;
    linkedlist(){
        head=NULL;
    }
    void insert(int value){
        node* newnode=new node(value);
        if (head==NULL)
        {
            head=newnode;
            return;
        }
        node* temp=head;
        while (temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=newnode;
        
    }
    void display(){
        node* temp=head;
        while (temp!=NULL)
        {
            cout<<temp->val<<" -> ";
            temp=temp->next;
        }
        cout<<"NULL"<<endl;
    }
};

bool detectCycle(node* head){
    if (!head)
    {
        return false;
    }
    

    node* slow=head;
    node* fast=head;

    while (fast && fast->next)
    {
        slow=slow->next;
        fast=fast->next->next;

        if (slow==fast)
        {
            return true;
        }
    }
    return false;
} 
void removeCycle(node* &head){
    node* slow=head;
    node* fast=head;
    do
    {
        slow=slow->next;
        fast=fast->next->next;
    } while (slow!=fast);
    fast=head;
    while (slow->next!=fast->next)
    {
        slow=slow->next;
        fast=fast->next;
    }
    slow->next=NULL;
    
}

int main(){
    linkedlist ll1;
    int n;
    cout << "Enter the size of Linked List : ";
    cin >> n;
    vector<int> v(n);
    cout << "Enter the Linked List : ";
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        // Insert each input element into the linked list.
        ll1.insert(v[i]);
    }
    
    cout << "Linked List is : ";
    ll1.display();
    node* end=ll1.head;
    while (end->next!=NULL)
    {
        end=end->next;
    }
    end->next=ll1.head->next->next; //Here we made a cycle to test our function
    
    if (detectCycle(ll1.head))
    {
        cout<<"Yes, the Linked List contains Cycle! ";
        removeCycle(ll1.head);
        
        cout<<"After removing Cycle and rechecking Linked List (1-True,0-False): "<<detectCycle(ll1.head);
        
    }
    else{
        cout<<"No,the Linked List does not contain any cycle ";
    }
}

Output:-
Enter the size of Linked List : 6 
Enter the Linked List : 1 2 3 4 5 6
Linked List is : 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> NULL
Yes, the Linked List contains Cycle! After removing Cycle and rechecking Linked List (1-True,0-False): 0

-3.- Given head of a linked list, determine if the linked list is a palindrome
-A palindrome is a word, phrase, number, or other sequence of characters that reads the same forward and backward. 
In other words, it's a symmetrical sequence. 

#include<iostream>
#include<vector>
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
class linkedlist{
    public:
    node* head;
    linkedlist(){
        head=NULL;
    }
    void insert(int value){
        node* newnode=new node(value);
        if (head==NULL)
        {
            head=newnode;
            return;
        }
        node* temp=head;
        while (temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=newnode;
        
    }
    void display(){
        node* temp=head;
        while (temp!=NULL)
        {
            cout<<temp->val<<" -> ";
            temp=temp->next;
        }
        cout<<"NULL"<<endl;
    }
};

bool findPalindrome(node* head){

    //step1: find middle element
    node* slow=head;
    node* fast=head;
    while (fast!=NULL && fast->next!=NULL)
    {
        slow=slow->next;
        fast=fast->next->next;
    }
    
    //now slow is pointing to middle element
    //step2: break the linked list in the midddle 
    node* curr=slow->next;
    node* prev=slow;
    slow->next=NULL;

    //step3: reverse the second half of the Linked List
    while (curr)
    {
        node* nextNode=curr->next;
        curr->next=prev;
        prev=curr;
        curr=nextNode;
    }
    
    //step4: check if two linked lists are equal
    node* head1=head;
    node* head2=prev;
    while (head2 && head1)
    {
        if (head2->val!=head1->val)
        {
            return false;
        }
        head1=head1->next;
        head2=head2->next;
    }
    return true;
}

int main(){
    linkedlist ll1;
    int n;
    cout << "Enter the size of Linked List : ";
    cin >> n;
    vector<int> v(n);
    cout << "Enter the Linked List : ";
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        // Insert each input element into the linked list.
        ll1.insert(v[i]);
    }
    
    cout << "Linked List is : ";
    ll1.display();
    if (findPalindrome(ll1.head))
    {
        cout<<"Yes, the linked list is Palindrome in nature ";
    }
    else{
        cout<<"No, it is not Palindrome ";
    }
    return 0;
}

Output:-
Enter the size of Linked List : 6
Enter the Linked List : 1 2 3 3 2 1
Linked List is : 1 -> 2 -> 3 -> 3 -> 2 -> 1 -> NULL
Yes, the linked list is Palindrome in nature
*/