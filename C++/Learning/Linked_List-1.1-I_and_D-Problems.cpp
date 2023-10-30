/*
-1.Given the head of a linked list , delete every alternate element from the list starting from the second element

-TRIED BY MYSELF BUT AT END USED CHATGPT!

#include<iostream>
#include<vector>
using namespace std;

class node {
public:
    int val;
    node* next;
    node(int data) {
        val = data;
        next = NULL;
    }
};

void insertAtHead(node* &head, int val) {
    node* newnode = new node(val);
    newnode->next = head;
    head = newnode;
}

void insert(node* &head, int val) {
    node* newnode = new node(val);
    if (head == NULL) {
        insertAtHead(head, val);
        return;
    }
    node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    newnode->next = temp->next;
    temp->next = newnode;
}

node* deleteAlternate(node* &head) {
    node* temp = head;
    if (head == NULL || head->next == NULL) {
        return head;
    }
    
    while (temp != NULL && temp->next != NULL) {
        node* toDelete = temp->next; // Get the node to be deleted
        temp->next = temp->next->next; // Skip the next node
        delete toDelete; // Delete the skipped node
        temp = temp->next; // Move to the next node
    }
    
    return head;
}

void display(node* &head) {
    node* temp = head;
    while (temp != NULL) {
        cout << temp->val << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int main() {
    cout << "Enter the size of Linked List : ";
    int n;
    cin >> n;
    cout << "Enter the Linked List : ";
    vector<int> v(n);
    node* head = NULL;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        insert(head, v[i]);
    }
    cout << "Linked List is : ";
    display(head);
    cout << "Alternate Linked List is : ";
    head = deleteAlternate(head);
    display(head);
    
    // Clean up memory by deleting all nodes
    while (head != NULL) {
        node* temp = head;
        head = head->next;
        delete temp;
    }
    
    return 0;
}

->By MAM!!

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
void insert(node* &head , int val){
    node* newnode=new node(val);
    newnode->next=head;
    head=newnode;
}
node* deleteAtAlternate(node* &head){
    node*curr=head;
    while (curr!=NULL && curr->next!=NULL)
    {
        node*temp = curr->next;
        curr->next=curr->next->next;
        free(temp);
        curr=curr->next;
    }
    return head;
}
void  display(node* &head){
    node*temp=head;
    while (temp!=NULL)
    {
        cout<<temp->val<<" -> ";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;
}
int main(){
    node* head=NULL;
    cout<<"Enter the size of Linked List : ";
    int n;
    cin>>n;
    cout<<"Enter the Linked List : ";
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin>>v[i];
        insert(head,v[i]);
    }
    cout<<"Entered Linked List is : ";
    display(head);
    head=deleteAtAlternate(head);
    cout<<"ALternative Linked List : ";
    display(head);
    return 0;

}

Output:-
Enter the size of Linked List : 6
Enter the Linked List : 1 2 3 4 5 6
Entered Linked List is : 6 -> 5 -> 4 -> 3 -> 2 -> 1 -> NULL
ALternative Linked List : 6 -> 4 -> 2 -> NULL

-Another way:-

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
class LinkedList{
public:
    node* head;
    LinkedList(){
        head=NULL;
    }
    void insertAtTail(int value){
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
void deleteAlternateNodes(node* &head){
    node* curr_node=head;
    while (curr_node!=NULL && curr_node->next!=NULL)
    {
        node* temp= curr_node->next;
        curr_node->next=curr_node->next->next;
        free(temp);
        curr_node=curr_node->next;
    }
    
}
int main(){
    LinkedList ll;
    cout<<"Enter the size of Linked List : ";
    int n;
    cin>>n;
    cout<<"Enter the Linked List : ";
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin>>v[i];
        ll.insertAtTail(v[i]);
    }
    cout<<"Entered Linked List is : ";
    ll.display();
    cout<<"Alternate Linked List : ";
    deleteAlternateNodes(ll.head);
    ll.display();
    return 0; 
}

Output:-
Enter the size of Linked List : 6
Enter the Linked List : 1 2 3 4 5 6
Entered Linked List is : 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> NULL
Alternate Linked List : 1 -> 3 -> 5 -> NULL


-2.Given the head of a sorted linked list. delete all duplicates such that each element
appears only once. Return the linked list sorted as well.



#include<iostream>
#include<vector>
using namespace std;

// Define a class for a singly linked list node
class node {
public:
    int val;
    node* next;
    
    // Constructor to initialize a node with data
    node(int data) {
        val = data;
        next = NULL;
    }
};

// Define a class for a singly linked list
class linkedList {
public:
    node* head;
    
    // Constructor to initialize an empty linked list
    linkedList() {
        head = NULL;
    }
    
    // Function to insert a new element at the end of the linked list
    void insert(int val) {
        node* newnode = new node(val);
        if (head == NULL) {
            // If the list is empty, the new node becomes the head.
            head = newnode;
            return;
        }
        node* temp = head;
        while (temp->next != NULL) {
            // Traverse to the end of the list to add the new node.
            temp = temp->next;
        }
        temp->next = newnode;
    }
    
    // Function to display the linked list
    void display() {
        node* temp = head;
        while (temp != NULL) {
            // Print each element's value followed by "->" and "NULL" for the end.
            cout << temp->val << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

// Function to delete duplicate elements from a sorted linked list
void deleteDuplicate(node* &head) {
    node* curr = head;
    while (curr != NULL) {
        while (curr->next != NULL && curr->val == curr->next->val) {
            // Remove duplicate nodes while preserving the order.
            node* temp = curr->next;
            curr->next = curr->next->next;
            free(temp);
        }
        curr = curr->next;
    }
}

int main() {
    linkedList ll;
    int n;
    cout << "Enter the size of Linked List: ";
    cin >> n;
    vector<int> v(n);
    cout << "Enter the Linked List: ";
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        // Insert each input element into the linked list.
        ll.insert(v[i]);
    }
    cout << "Linked List is: ";
    ll.display();
    cout << "Linked List after removing duplicates is: ";
    deleteDuplicate(ll.head);
    ll.display();
    return 0;
}

Explanation:

-'node' Class:

-Represents individual elements (nodes) of the singly linked list.
-Contains int val to store the node's value and node* next to point to the next node.
-The constructor initializes a node with the provided data and sets next to NULL.

-'linkedList' Class:

-Represents a singly linked list and provides methods to manipulate it.
-Contains a node* head pointer, initially set to NULL to indicate an empty list.
-The constructor initializes an empty linked list with a NULL head.
-The insert method inserts a new element at the end of the linked list.
-The display method prints the elements of the linked list in order.

-'deleteDuplicate' Function:

-Removes duplicate elements from a sorted linked list while preserving order.
-Takes a reference to the head of the linked list as a parameter.

-'main' Function:

-Creates an instance of the linkedList class.
-Inputs the size of the linked list and its elements from the user.
-Displays the original linked list using the display method.
-Calls the deleteDuplicate function to remove duplicate elements.
-Displays the modified linked list to show the result.

Output:-
Enter the size of Linked List : 9
Enter the Linked List : 1 1 2 2 2 2 3 3 4  
Linked List is : 1 -> 1 -> 2 -> 2 -> 2 -> 2 -> 3 -> 3 -> 4 -> NULL
Linked List after removing duplicates is : 1 -> 2 -> 3 -> 4 -> NULL

-3.Given the head of a singly Linked List , print it in reveresed order

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
class linkedList{
    public:
    node* head;
    linkedList(){
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
        newnode->next=temp->next;
        temp->next=newnode;
    }
    void display(){
        node* temp = head;
        while (temp!=NULL)
        {
            cout<<temp->val<<" -> ";
            temp=temp->next;
        }
        cout<<"NULL"<<endl;
    }
};
void reverse(node* &head){
    if (head==NULL)
    {
        return;
    }
    reverse(head->next);
    cout<<head->val<<" -> ";
}
int main(){
    linkedList ll;
    int n;
    cout << "Enter the size of Linked List: ";
    cin >> n;
    vector<int> v(n);
    cout << "Enter the Linked List: ";
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        // Insert each input element into the linked list.
        ll.insert(v[i]);
    }
    cout << "Linked List is: ";
    ll.display();
    cout << "Reversed Linked List is: ";
    reverse(ll.head);
    cout<<"NULL";
    return 0;
}

Output:-
Enter the size of Linked List: 5
Enter the Linked List: 1 2 3 4 5
Linked List is: 1 -> 2 -> 3 -> 4 -> 5 -> NULL
Reversed Linked List is: 5 -> 4 -> 3 -> 2 -> 1 -> NULL

-Get a good grasp of both the ways , they can be asked in the interview
-3.Given the head of a singly Linked List , reverse the linked list

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
class linkedList{
    public:
    node* head;
    linkedList(){
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
        newnode->next=temp->next;
        temp->next=newnode;
    }
    void display(){
        node* temp = head;
        while (temp!=NULL)
        {
            cout<<temp->val<<" -> ";
            temp=temp->next;
        }
        cout<<"NULL"<<endl;
    }
};
node* reverse(node* &head){
    node* prevptr=NULL;
    node* currptr=head;
    while (currptr!=NULL)
    {
        node* nextptr= currptr->next;
        currptr->next=prevptr;
        prevptr=currptr;
        currptr=nextptr;
    }
    node* new_head= prevptr;
    return new_head;
}
int main(){
    linkedList ll;
    int n;
    cout << "Enter the size of Linked List: ";
    cin >> n;
    vector<int> v(n);
    cout << "Enter the Linked List: ";
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        // Insert each input element into the linked list.
        ll.insert(v[i]);
    }
    cout << "Linked List is: ";
    ll.display();
    cout << "Reversed Linked List is: ";
    ll.head=reverse(ll.head);
    ll.display();
    return 0;
}

Output:-
Enter the size of Linked List: 5
Enter the Linked List: 1 2 3 4 5 
Linked List is: 1 -> 2 -> 3 -> 4 -> 5 -> NULL
Reversed Linked List is: 5 -> 4 -> 3 -> 2 -> 1 -> NULL  

-Now let's solve this question using Recursion , quite easy if you jsut apply a little BRAIN!!


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
class linkedList{
    public:
    node* head;
    linkedList(){
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
        newnode->next=temp->next;
        temp->next=newnode;
    }
    void display(){
        node* temp = head;
        while (temp!=NULL)
        {
            cout<<temp->val<<" -> ";
            temp=temp->next;
        }
        cout<<"NULL"<<endl;
    }
};
node* reverseUsingRecursion(node* &head){

    //base case
    if (head==NULL || head->next==NULL)
    {
        return head;
    }
    //recuresive case
    node* new_head=reverseUsingRecursion(head->next);
    head->next->next=head;
    head->next=NULL;
    return new_head;

}
int main(){
    linkedList ll;
    int n;
    cout << "Enter the size of Linked List: ";
    cin >> n;
    vector<int> v(n);
    cout << "Enter the Linked List: ";
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        // Insert each input element into the linked list.
        ll.insert(v[i]);
    }
    cout << "Linked List is: ";
    ll.display();
    cout << "Reversed Linked List is: ";
    ll.head=reverseUsingRecursion(ll.head);
    ll.display();
    return 0;
}

-This question was quite interesting , make sure you give it a thorough practise
-Given the head of a linked list, reverse the nodes of the list k at a time , and rteurn the modified list.
*/

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
class linkedList{
    public:
    node* head;
    linkedList(){
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
        newnode->next=temp->next;
        temp->next=newnode;
    }
    void display(){
        node* temp = head;
        while (temp!=NULL)
        {
            cout<<temp->val<<" -> ";
            temp=temp->next;
        }
        cout<<"NULL"<<endl;
    }
};
node* reverseLL(node* &head,int k){

    node* prevptr=NULL;
    node* currptr=head;
    int counter=0;
    while (currptr!=NULL && counter<k)  //reversing first 'k' nodes
    {
        node* nextptr=currptr->next;
        currptr->next=prevptr;
        prevptr=currptr;
        currptr=nextptr;
        counter++;
    }
    //currptr will give us (k+1) node
    if (currptr!=NULL)
    {
        node* new_head=reverseLL(currptr,k); //recursive call
        head->next=new_head;
    }
    
    return prevptr;  //prevptr will give the new_head of connected LinkedList
    
}
int main(){
    linkedList ll;
    int n;
    cout << "Enter the size of Linked List: ";
    cin >> n;
    vector<int> v(n);
    cout << "Enter the Linked List: ";
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        // Insert each input element into the linked list.
        ll.insert(v[i]);
    }
    cout<<"Enter the value of 'K' : ";
    int k;
    cin>>k;
    cout << "Linked List is: ";
    ll.display();
    cout << "Reversed Linked List is: ";
    ll.head=reverseLL(ll.head,k);
    ll.display();
    return 0;
}

Output:-
Enter the size of Linked List: 7
Enter the Linked List: 1 2 3 4 5 6 7
Enter the value of 'K' : 3
Linked List is: 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7 -> NULL
Reversed Linked List is: 3 -> 2 -> 1 -> 6 -> 5 -> 4 -> 7 -> NULL


