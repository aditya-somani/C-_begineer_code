/*

-Inserting in Linked List -> Code is written multiple times in order to inccrease unnderstanding
so, please don't ingnore it unless you have a strong grip on basics

#include<iostream>
using namespace std;

// Define a class for a node in a singly linked list
class node {
public:
    int val;
    node* next;
    
    // Constructor to initialize the node with a value and set next to NULL
    node(int data) {
        val = data;
        next = NULL;
    }
};

// Function to insert a new node at the head of the linked list
void insertAtHead(node* &head, int val) {
    // Create a new node with the given value
    node* newnode = new node(val);
    
    // Set the next of the new node to the current head
    newnode->next = head;
    
    // Update the head to point to the new node
    head = newnode;
}

// Function to insert a new node at the tail (end) of the linked list
void insertAtTail(node* &head, int val) {
    // Create a new node with the given value
    node* newnode = new node(val);
    
    // If the list is empty, set the new node as the head
    if (head == NULL) {
        head = newnode;
        return;
    }
    
    // Traverse to the end of the list
    node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    
    // Add the new node to the end
    temp->next = newnode;
}

// Function to display the elements of the linked list
void display(node* head) {
    node* temp = head;
    
    // Traverse the linked list and print each element
    while (temp != NULL) {
        cout << temp->val << " -> ";
        temp = temp->next;
    }
    
    // Print NULL to indicate the end of the list
    cout << "NULL" << endl;
}

int main() {
    // Initialize the head of the linked list as NULL
    node* head = NULL;
    
    // Insert elements at the head of the linked list
    insertAtHead(head, 2);
    display(head);
    
    insertAtHead(head, 1);
    display(head);
    
    // Insert an element at the tail of the linked list
    insertAtTail(head, 3);
    display(head);
    
    return 0;
}
```
Output:-
2 -> NULL
1 -> 2 -> NULL
1 -> 2 -> 3 -> NULL

-Time complexity of insertAtHead -> O(1);
-Time compelxity of insertAtTail -> O(n) in worst case and if tail pointer is given O(1)

**Explanation:**

- The `node` class:
  - Defines a class to represent a node in a singly linked list.
  - Each node has an integer value `val` and a pointer `next` to the next node.
  - The constructor initializes a node with a given `data` value and sets `next` to NULL.

- The `insertAtHead` function:
  - Adds a new node with a specified value to the beginning (head) of the linked list.
  - Creates a new node with the provided `val`.
  - Sets the `next` of the new node to the current head.
  - Updates the `head` pointer to point to the new node.

- The `insertAtTail` function:
  - Adds a new node with a specified value to the end (tail) of the linked list.
  - Handles the case when the list is empty by setting the new node as the head.
  - Traverses the list to find the last node and adds the new node there.

- The `display` function:
  - Traverses the linked list starting from the `head`.
  - Prints each element's value followed by an arrow `->`.
  - Finally, it prints "NULL" to indicate the end of the list.

- In the `main` function:
  - Initializes the `head` of the linked list as `NULL`.
  - Inserts two elements (2 and 1) at the head of the linked list.
  - Inserts an element (3) at the tail of the linked list.
  - Displays the linked list after each insertion to show the changes.

-Inserion at 'k'th position


#include<iostream>
using namespace std;

// Define a class for a singly-linked list node
class node{
    public:
    int val;
    node* next;
    node(int data){
        val = data;
        next = NULL;
    }
};

// Function to insert a new node at the beginning of the linked list
void insertAtHead(node* &head, int val){
    // Create a new node with the given value
    node* newnode = new node(val);
    
    // Set the next of the new node to the current head
    newnode->next = head;
    
    // Update the head to point to the new node
    head = newnode;
}

// Function to insert a new node at the end of the linked list
void insertAtTail(node* &head, int val){
    // Create a new node with the given value
    node* newnode = new node(val);
    
    // If the list is empty, set the new node as the head
    if (head == NULL) {
        head = newnode;
        return;
    }
    
    // Traverse to the last node of the linked list
    node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    
    // Set the next of the last node to the new node
    temp->next = newnode;
}

// Function to insert a new node at a specified position in the linked list
void insertAtPosition(node* &head, int val, int pos){
    // If the position is 0, insert at the head
    if (pos == 0){
        insertAtHead(head, val);
        return;
    }
    
    // Create a new node with the given value
    node* new_node = new node(val);
    
    // Traverse to the node before the specified position
    node* temp = head;
    int current_pos = 0;
    while (current_pos != pos - 1) {
        temp = temp->next;
        current_pos++;
    }
    
    // Update the pointers to insert the new node
    new_node->next = temp->next;
    temp->next = new_node;
}

// Function to display the elements of the linked list
void display(node* head){
    node* temp = head;
    while (temp != NULL){
        cout << temp->val << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int main(){
    node* head = NULL;
    
    // Insert elements at the head of the linked list
    insertAtHead(head, 2);
    display(head);
    
    insertAtHead(head, 1);
    display(head);
    
    // Insert an element at the end of the linked list
    insertAtTail(head, 3);
    display(head);
    
    // Insert an element at a specified position in the linked list
    insertAtPosition(head, 4, 2);
    display(head);
    
    return 0;
}

Output:-
2 -> NULL
1 -> 2 -> NULL
1 -> 2 -> 3 -> NULL
1 -> 2 -> 4 -> 3 -> NULL

**Explanation:**

- The code defines a class `node` for creating linked list nodes with an integer value (`val`) and a pointer to the next node (`next`).

- Three functions are defined to manipulate the linked list:
  - `insertAtHead`: Inserts a new node with the given value at the beginning of the list.
  - `insertAtTail`: Inserts a new node with the given value at the end of the list.
  - `insertAtPosition`: Inserts a new node with the given value at a specified position in the list.

- The `display` function is used to print the elements of the linked list.

- In the `main` function, the code demonstrates how to use these functions to insert and display elements in the linked list.

-> Below is a practice that I did in order to get deeper understanding of inserting in Linked List

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
void insertAtHead(node* &head , int val){
  node* newnode = new node(val);
  newnode->next=head;
  head=newnode;
}
void insertAtTail(node* &head, int val){
  node* newnode=new node(val);
  if (head==NULL)
  {
    head = newnode;
    return;
  }
  node* temp=head;
  while (temp->next!=NULL)
  {
    temp=temp->next;
  }
  temp->next=newnode;
}
void insertAtPosition(node* &head, int val , int pos){
  if (pos==0)
  {
    insertAtHead(head,val);
    return;
  }
  node* newnode=new node(val);
  int currentpos=0;
  node* temp = head;
  while (currentpos!=pos-1)
  {
    temp=temp->next;
    currentpos++;
  }
  newnode->next=temp->next;
  temp->next=newnode;
  
}
void display(node* head){
  node* temp = head;
  while (temp!=NULL)
  {
    cout<<temp->val<<" -> ";
    temp=temp->next;
  }
  cout<<"NULL"<<endl;
}
int main(){
  cout<<"Enter the size of numbers you want in linked list : ";
  int n;
  cin>>n;
  cout<<"Enter the numbers : ";
  vector<int> v(n);
  node* head =  NULL;
  
  for (int i = 0; i < n; i++)
  {
    cin>>v[i];
    insertAtTail(head,v[i]);
  }
  insertAtPosition(head,6,3);
  insertAtPosition(head,9,5);
  cout<<"Linked list : ";
  display(head);
  return 0;
}
Output:-
Enter the size of numbers you want in linked list : 5
Enter the numbers : 1 2 3 4 5
Linked list : 1 -> 2 -> 3 -> 6 -> 4 -> 9 -> 5 -> NULL

-Update the value at 'K'th position

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
void insertAtHead(node* &head,int val){
  node* newnode =new node(val);
  newnode->next=head;
  head=newnode;
}
void insertAtTail(node* head,int val){
  node* newnode=new node(val);
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
void insertAtPosition(node* &head , int val,int pos){
  if (pos==0)
  {
    insertAtHead(head,val);
    return;
  }
  node* newnode = new node(val);
  node* temp=head;
  int currpos=0;
  while (currpos!=pos-1)
  {
    temp=temp->next;
    currpos++;
  }
  newnode->next=temp->next;
  temp->next=newnode;
  
}
void updateAtPosition(node* &head,int val,int pos){
  node*temp=head;
  int currpos=0;
  while (currpos!=pos)
  {
    temp=temp->next;
    currpos++;
  }
  temp->val=val;
}
void display(node* &head){
  node* temp=head;
  while (temp!=NULL)
  {
    cout<<temp->val<<" -> ";
    temp=temp->next;
  }
  cout<<"NULL"<<endl;
}
int main(){
  node* head=NULL;
  insertAtHead(head,2);
  display(head);
  insertAtHead(head,3);
  display(head);
  insertAtHead(head,4);
  display(head);
  insertAtTail(head,1);
  display(head);
  insertAtPosition(head,5,3);
  display(head);
  updateAtPosition(head,8,3);
  display(head);
  return 0;
}
Ouput:-
2 -> NULL
3 -> 2 -> NULL
4 -> 3 -> 2 -> NULL
4 -> 3 -> 2 -> 1 -> NULL
4 -> 3 -> 2 -> 5 -> 1 -> NULL
4 -> 3 -> 2 -> 8 -> 1 -> NULL

-Deletion of node at the start of linked list
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
void insertAtHead(node* &head,int val){
  node* newnode=new node(val);
  newnode->next=head;
  head=newnode;
}
void deleteAtHead(node* &head){
  node* temp=head;
  head=head->next;
  free(temp);
}
void display(node* &head){
  node* temp=head;
  while (temp!=NULL)
  {
    cout<<temp->val<<" -> ";
    temp=temp->next;
  }
  cout<<"NULL"<<endl;
}
int main(){
  node* head=NULL;
  insertAtHead(head,1);
  display(head);
  insertAtHead(head,2);
  display(head);
  insertAtHead(head,3);
  display(head);
  deleteAtHead(head);
  display(head);
  deleteAtHead(head);
  display(head);
  return 0;
}
-Time complexity -> O(1)
Output:-
1 -> NULL
2 -> 1 -> NULL
3 -> 2 -> 1 -> NULL
2 -> 1 -> NULL
1 -> NULL

-Deleting node at the end of linked list

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
void insertAtTail(node* &head,int val){
  node* newnode=new node(val);
  if (head==NULL)
  {
    head=newnode;
    return;
  }
  node* temp= head;
  while (temp->next!=NULL)
  {
    temp=temp->next;
  }
  temp->next=newnode;
}
void display(node* &head){
  node*temp=head;
  while (temp!=NULL)
  {
    cout<<temp->val<<" -> ";
    temp=temp->next;
  }
  cout<<"NULL"<<endl;

}
void deleteAtTail(node* &head){
  node* second_last = head;
  while (second_last->next->next!=NULL)
  {
    second_last=second_last->next;
  }
  node*temp = second_last->next;
  second_last->next=NULL;
  free(temp);

}
int main(){
  node* head=NULL;
  insertAtTail(head,2);
  display(head);
  insertAtTail(head,3);
  display(head);
  insertAtTail(head,4);
  display(head);
  deleteAtTail(head);
  display(head);
  deleteAtTail(head);
  display(head);
  return 0;
}
Output:-
2 -> NULL
2 -> 3 -> NULL
2 -> 3 -> 4 -> NULL
2 -> 3 -> NULL
2 -> NULL

-Time complexity - O(n)

-Deletion at arbitary position

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
void insertAtHead(node* &head , int val){
  node* newnode=new node(val);
  newnode->next=head;
  head=newnode;

}
void insertAtPosition(node* &head,int val,int pos){
  if (pos==0)
  {
    insertAtHead(head,val);
    return;
  }
  node* newnode=new node(val);
  node*temp = head;
  int currpos=0;
  while (currpos!=pos-1)
  {
    temp=temp->next;
    currpos++;
  }
  newnode->next=temp->next;
  temp->next=newnode;
}
void deleteAtHead(node* &head){
  node*temp=head;
  head=head->next;
  free(temp);
}
void deleteAtPosition(node* &head,int pos){
  if (pos==0)
  {
    deleteAtHead(head);
    return;
  }
  int curr_pos=0;
  node* prev=head;
  while (curr_pos!=pos-1)
  {
    prev=prev->next;
    curr_pos++;
  }
  node*temp = prev->next;
  prev->next=prev->next->next;
  free(temp);
  
}
void display(node* &head){
  node* temp=head;
  while (temp!=NULL)
  {
    cout<<temp->val<<" -> ";
    temp=temp->next;
  }
  cout<<"NULL"<<endl;

}
int main(){
  node* head=NULL;
  insertAtHead(head,2);
  display(head);
  insertAtHead(head,3);
  display(head);
  insertAtPosition(head,4,2);
  display(head);
  deleteAtPosition(head,2);
  display(head);
  deleteAtPosition(head,0);
  display(head);
  return 0;
}
Output:-
2 -> NULL
3 -> 2 -> NULL
3 -> 2 -> 4 -> NULL
3 -> 2 -> NULL
2 -> NULL
-Time complexity - O(n);

*/
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
void insertAtHead(node* &head,int val){
  node* newnode=new node(val);
  newnode->next=head;
  head=newnode;
}
void insertAtTail(node* &head ,int val){
  node* newnode=new node(val);
  if (head==NULL)
  {
    head=newnode;
    return;
  }
  node* temp = head;
  while (temp->next!=NULL)
  {
    temp=temp->next;
  }
  temp->next=newnode;
}
void insertAtPosition(node* &head,int val ,int pos){
  if (pos==0)
  {
    insertAtHead(head,val);
    return;
  }
  node* newnode=new node(val);
  node* temp = head;
  int curr_pos=0;
  while (curr_pos!=pos-1)
  {
    temp=temp->next;
    curr_pos++; 
  }
  newnode->next=temp->next;
  temp->next=newnode;
}
void deleteAtHead(node* &head){
  node*temp = head;
  head=head->next;
  free(temp);
}
void deleteAtTail(node* &head){
  if (head==NULL)
  {
    deleteAtHead(head);
    return;
  }
  node* second_last=head;
  while (second_last->next->next!=NULL)
  {
    second_last=second_last->next;
  }
  node* temp=second_last->next;
  second_last->next=NULL;
  free(temp);
}

void deleteAtPosition(node* &head,int pos){
  if (pos==0)
  {
    deleteAtHead(head);
    return;
  }
  node* prev=head;
  int curr_pos=0;
  while (curr_pos!=pos-1)
  {
    prev=prev->next;
    curr_pos++;
  }
  node*temp = prev->next;
  prev->next=prev->next->next;
  free(temp);
}
void display(node* &head){
  node*temp = head;
  while (temp!=NULL)
  {
    cout<<temp->val<<" -> ";
    temp=temp->next;
  }
  cout<<"NULL"<<endl;
}
int main(){
  node* head=NULL;
  insertAtHead(head,2);
  display(head);
  insertAtHead(head,3);
  display(head);
  insertAtTail(head,4);
  display(head);
  insertAtTail(head,5);
  display(head);
  insertAtPosition(head,5,2);
  display(head);
  insertAtPosition(head,6,2);
  display(head);
  deleteAtHead(head);
  display(head);
  deleteAtHead(head);
  display(head);
  deleteAtTail(head);
  display(head);
  deleteAtTail(head);
  display(head);
  deleteAtPosition(head,1);
  display(head);
  return 0;
}

Output:-
2 -> NULL
3 -> 2 -> NULL
3 -> 2 -> 4 -> NULL
3 -> 2 -> 4 -> 5 -> NULL
3 -> 2 -> 5 -> 4 -> 5 -> NULL
3 -> 2 -> 6 -> 5 -> 4 -> 5 -> NULL
2 -> 6 -> 5 -> 4 -> 5 -> NULL
6 -> 5 -> 4 -> 5 -> NULL
6 -> 5 -> 4 -> NULL
6 -> 5 -> NULL
6 -> NULL


