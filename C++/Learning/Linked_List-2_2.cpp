/*


-Pattern : Rearrangement of nodes in a list

-1.Rearrange the nodes in a list - Given the head of a linked list, rotate the list to right by k places


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
node* rotateByK(node* &head , int k){

    //1.find length of Linked Lists
    int n=0;
    //2.find tail of ll
    node* tail=head;

    while (tail->next!=NULL)
    {
        n++; //finding length
        tail=tail->next;  //finding last node
    }
    n++; //including last node as it does not get counted in the loop

    k=k%n; //if value of k>n 
    if (k==0)
    {
        return head;
    }

    tail->next=head; //now my last node is pointing towards first node
    
    //3. traverse 'n-k' nodes
    node* temp=head;
    for (int i = 1; i < n-k; i++)
    {
        temp=temp->next;
    }

    //temp is now pointing at (n-k)th nodes
    node* new_head=temp->next;
    temp->next=NULL;
    return new_head;
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
    int k;
    cout<<"Enter the number of times you wish to rotate Linked List : ";
    cin>>k;
    cout << "Linked List is : ";
    ll1.display();
    ll1.head=rotateByK(ll1.head,k);
    cout<<"Linked List after rotating "<<k<<" times is : ";
    ll1.display();
}

Output:-
Enter the size of Linked List : 7
Enter the Linked List : 1 2 3 4 5 6 7
Enter the number of times you wish to rotate Linked List : 3
Linked List is : 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7 -> NULL
Linked List after rotating 3 times is : 5 -> 6 -> 7 -> 1 -> 2 -> 3 -> 4 -> NULL

-Time complexity -> O(n+(n-k)) -> O(2n+k)

-2.Given the head of a singly linked list, 
group all the nodes with odd indices together followed by the nodes with even indices and return the reordered list

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

    void insert(int val){
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
node* oddEvenLinkedList(node* &head){
    if (!head)
    {
        return head;
    }
    

    node* evenhead=head->next;
    node* oddptr=head;
    node* evenptr=evenhead;
    while (evenptr && evenptr->next)
    {
        oddptr->next=oddptr->next->next;
        evenptr->next=evenptr->next->next;
        oddptr=oddptr->next;
        evenptr=evenptr->next;

    }
    oddptr->next=evenhead;
    return head;
}
int main(){
    linkedlist atul;
    cout<<"Enter the size of linked list : ";
    int n;
    cin>>n;
    cout<<"Enter the linked list : ";
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin>>v[i];
        atul.insert(v[i]);
    }
    cout<<"Linked List is : ";
    atul.display();
    atul.head=oddEvenLinkedList(atul.head);
    cout<<"The Reordered Linked list is : ";
    atul.display();
    return 0;
    
}

Output:-
Enter the size of linked list : 6
Enter the linked list : 1 2 3 4 5 6
Linked List is : 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> NULL
The Reordered Linked list is : 1 -> 3 -> 5 -> 2 -> 4 -> 6 -> NULL

-3.Reordering a linked list in the given form 

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
node* reorder(node* &head){

    //can check if linked list have atleast 3 nodes

    //1.findng the middle element
    node* slow=head;
    node* fast=head;
    while (fast && fast->next)
    {
        slow=slow->next;
        fast=fast->next->next;
    }

    //now slow is pointing to the  middl element
    //2.separate the linked list and reverse second half
    node* curr=slow->next;
    slow->next=NULL;
    node* prev=slow;
    
    while (curr)
    {
        node* next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }

    //3. Merging the two halves of the linked List
    node* head1 = head; //starting
    node* head2 = prev;  //at end
    

    //now we starting with pattern

    while (head1!= head2)
    {
        node* temp=head1->next;
        head1->next=head2;
        head1=head2;
        head2=temp;
        
    }
    return head;

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
    ll1.head=reorder(ll1.head);
    cout<<"The reordered Linked List is : ";
    ll1.display();
}

Output:-
Enter the size of Linked List : 6
Enter the Linked List : 1 2 3 4 5 6
Linked List is : 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> NULL
The reordered Linked List is : 1 -> 6 -> 2 -> 5 -> 3 -> 4 -> NULL

-4. For a given linked list swap every adjacent node and return its head

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
node* swapadjacent(node* &head){
    //base case
    if (head==NULL || head->next==NULL)
    {
        return head;
    }
    

    //recursive case
    node* secondnode= head->next;
    head->next=swapadjacent(secondnode->next);
    secondnode->next=head;  //reversed the link between the first and second node
    return secondnode;
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
    ll1.head=swapadjacent(ll1.head);
    cout<<"The swaped Linked List is : ";
    ll1.display();
}

Output:-
Enter the size of Linked List : 6
Enter the Linked List : 1 2 3 4 5 6
Linked List is : 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> NULL
The swaped Linked List is : 2 -> 1 -> 4 -> 3 -> 6 -> 5 -> NULL

*/