/*
-Make sure to do all these questions by yourself once again because they will really make you dive
into the world of DSA!! HAVE A GOOD DAY!!!

-Problems on 2-Pointers.

-1.Given 2 linked lists, Tell if they are equal or not. Two Linked lists are equal if they
have the same data and the arrangement of data is also the same. 

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
bool checkEqualLinkedList(node* head1,node* head2){
    node* ptr1=head1;
    node* ptr2=head2;
    while (ptr1!=NULL && ptr2!=NULL)
    {
        if (ptr1->val!=ptr2->val)
        {
            return false;
        }
        ptr1=ptr1->next;
        ptr2=ptr2->next;
    }
    return (ptr1==NULL && ptr2==NULL);
}
int main(){
    linkedlist ll1;
    linkedlist ll2;
    int n;
    cout << "Enter the size of Linked List 1 : ";
    cin >> n;
    vector<int> v(n);
    cout << "Enter the Linked List 1 : ";
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        // Insert each input element into the linked list.
        ll1.insert(v[i]);
    }
    int m;
    cout << "Enter the size of Linked List 2 : ";
    cin >> m;
    vector<int> v1(m);
    cout << "Enter the Linked List 2 : ";
    for (int i = 0; i < m; i++) {
        cin >> v1[i];
        // Insert each input element into the linked list.
        ll2.insert(v1[i]);
    }
    cout << "Linked List 1 is : ";
    ll1.display();
    cout << "Linked List 2 is : ";
    ll2.display();
    if(checkEqualLinkedList(ll1.head,ll2.head)){
        cout<<"Yes, they are equal ";
    }
    else{
        cout<<"No, they are not equal ";
    }
    return 0;
}

Output:-
Enter the size of Linked List 1 : 3
Enter the Linked List 1 : 1 2 3
Enter the size of Linked List 2 : 3
Enter the Linked List 2 : 1 2 0
Linked List 1 is : 1 -> 2 -> 3 -> NULL
Linked List 2 is : 1 -> 2 -> 0 -> NULL
No, they are not equal

-2.Given the heads of 2 linked list, return the node at which both linked list intersect. If they don't, return null

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
int getLength(node* head){
    node* temp=head;
    int length=0;
    while (temp!=NULL)
    {
        length++;
        temp=temp->next;
    }
    return length;
}
node* moveHeadByK(node* head,int k){
    node* ptr=head;
    while (k--)
    {
        ptr=ptr->next;
    }
    return ptr;
}
node* getIntersection(node* head1,node* head2){
    node* ptr1=head1;
    node* ptr2=head2;

    //step1 : calculate lengths of both linked lists
    int l1=getLength(head1);
    int l2=getLength(head2);

    //step2 : find difference 'k' between Linked List and move longer Linked List ptr
    if (l1>l2) //l1 is longer
    {
        int k=l1-l2;
        ptr1=moveHeadByK(head1,k);
        ptr2=head2;
    }
    else{  //l2 is longer
        int k=l2-l1;
        ptr1=head1;
        ptr2=moveHeadByK(head2,k);
    }

    //compare ptr1 and ptr2
    while (ptr1)
    {
        if (ptr1==ptr2)
        {
            return ptr1;
        }
        ptr1=ptr1->next;
        ptr2=ptr2->next;
    }
    
    return NULL; 
}
int main(){
    linkedlist ll1;
    linkedlist ll2;
    int n;
    cout << "Enter the size of Linked List 1 : ";
    cin >> n;
    vector<int> v(n);
    cout << "Enter the Linked List 1 : ";
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        // Insert each input element into the linked list.
        ll1.insert(v[i]);
    }
    int m;
    cout << "Enter the size of Linked List 2 : ";
    cin >> m;
    vector<int> v1(m);
    cout << "Enter the Linked List 2 : ";
    for (int i = 0; i < m; i++) {
        cin >> v1[i];
        // Insert each input element into the linked list.
        ll2.insert(v1[i]);
    }
    cout << "Linked List 1 is : ";
    ll1.display();
    cout << "Linked List 2 is : ";
    ll2.display();
    ll1.head->next->next=ll2.head->next->next->next;
    node* intersection = getIntersection(ll1.head,ll2.head);
    if (intersection)
    {
        cout<<"Interestion is at value : "<<intersection->val;
    }
    else{
        cout<<"Intersection point does not exits ";
    }
    return 0;
}

Output:-
Enter the size of Linked List 1 : 5
Enter the Linked List 1 : 1 2 3 4 5
Enter the size of Linked List 2 : 4
Enter the Linked List 2 : 2 3 4 5
Linked List 1 is : 1 -> 2 -> 3 -> 4 -> 5 -> NULL
Linked List 2 is : 2 -> 3 -> 4 -> 5 -> NULL
Interestion is at value : 5

-3.Given the head of a linked list, remove the kth node from the end of the list and return its head

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

//assuming k is always less tahn/equal length of linked list 
void removeKthNodeFromEnd(node* &head,int k){
    node* ptr1=head;
    node* ptr2=head;

    //move ptr2 by k steps ahead
    int count =k;
    while (count--)
    {
        ptr2=ptr2->next;
    }

    if (ptr2==NULL)  //k is equal to length of linked list
    {
        //we have to delete head node
        node* temp=head;
        head=head->next;
        free(temp);
        return;
    }
    

    //Now ptr2 is 'K' steps ahead of ptr1
    //when ptr2 is at NULL (end of the list), ptr1 will be at node to be deleted
    while (ptr2->next!=NULL)
    {
        ptr1=ptr1->next;
        ptr2=ptr2->next;
    }

    //now ptr1 is pointing to the node before kth node from end
    //node to be deleted is ptr1->next
    node* temp=ptr1->next; 
    ptr1->next=ptr1->next->next;
    free(temp);


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
    cout<<"Enter the index of linked list you want to delete from back : ";
    int k;
    cin>>k;
    removeKthNodeFromEnd(ll1.head,k);
    cout<<"Linked List after removing Kth index from back is : ";
    ll1.display();
    return 0;
}

Output:-
Enter the size of Linked List : 6
Enter the Linked List : 1 2 3 4 5 6
Linked List is : 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> NULL
Enter the index of linked list you want to delete from back : 4
Linked List after removing Kth index from back is : 1 -> 2 -> 4 -> 5 -> 6 -> NULL

-4.Given 2 sorted linked lists, merge them into 1 singly linked list such that the resulting list is also sorted
-Use Merge Sort in Linked List but instead of creating a new Linked List we will just change its link! unlike Merge Sort


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

node* mergeLinkedList(node* &head1,node* &head2){
    node* dummyHeadNode= new node(-1);
    node* ptr1=head1;
    node* ptr2=head2;
    node* ptr3=dummyHeadNode;
    while (ptr1 && ptr2)
    {
        if (ptr1->val<ptr2->val)
        {
            ptr3->next=ptr1;
            ptr1=ptr1->next;
        }
        else{
            ptr3->next=ptr2;
            ptr2=ptr2->next;
        }
        ptr3=ptr3->next;
    }
    if (ptr1)
    {
        ptr3->next=ptr1;
    }
    else{
        ptr3->next=ptr2;
    }
    return dummyHeadNode->next;  //head of the Merge LInked List
}
int main(){
    linkedlist ll1;
    int n;
    cout << "Enter the size of Linked List 1 : ";
    cin >> n;
    vector<int> v(n);
    cout << "Enter the Sorted Linked List 1 : ";
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        // Insert each input element into the linked list.
        ll1.insert(v[i]);
    }
    linkedlist ll2;
    int m;
    cout << "Enter the size of Linked List 2 : ";
    cin >> m;
    vector<int> v1(m);
    cout << "Enter the Sorted Linked List 2 : ";
    for (int i = 0; i < m; i++) {
        cin >> v1[i];
        // Insert each input element into the linked list.
        ll2.insert(v1[i]);
    }
    cout << "Linked List is 1 :  ";
    ll1.display();    
    cout << "Linked List is 2 :  ";
    ll2.display();
    linkedlist ll3;
    ll3.head=mergeLinkedList(ll1.head,ll2.head);
    
    cout<<"Merge Linked List is : ";
    ll1.display();
    return 0;
}

Output:-
Enter the size of Linked List 1 : 5
Enter the Sorted Linked List 1 : 1 2 3 4 5 
Enter the size of Linked List 2 : 3
Enter the Sorted Linked List 2 : 3 7 8
Linked List is 1 :  1 -> 2 -> 3 -> 4 -> 5 -> NULL
Linked List is 2 :  3 -> 7 -> 8 -> NULL
Merge Linked List is : 1 -> 2 -> 3 -> 3 -> 4 -> 5 -> 7 -> 8 -> NULL

-5.Given an array of k linked list, each linked list is sorted in ascending order, 
merge all the linked list in one sorted linked list and return it

-Here the smart way would have been using a loop by asking the value of K but as It clicked me at end time 
I am skipping it!!

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

node* mergeLinkedList(node* &head1,node* &head2){
    node* dummyHeadNode= new node(-1);
    node* ptr1=head1;
    node* ptr2=head2;
    node* ptr3=dummyHeadNode;
    while (ptr1 && ptr2)
    {
        if (ptr1->val<ptr2->val)
        {
            ptr3->next=ptr1;
            ptr1=ptr1->next;
        }
        else{
            ptr3->next=ptr2;
            ptr2=ptr2->next;
        }
        ptr3=ptr3->next;
    }
    if (ptr1)
    {
        ptr3->next=ptr1;
    }
    else{
        ptr3->next=ptr2;
    }
    return dummyHeadNode->next;  //head of the Merge LInked List
}
node* mergeKLinkedList(vector<node*> &lists){
    if (lists.size()==0)
    {
        return NULL;
    }
    while (lists.size()>1)
    {
        node* mergeHead = mergeLinkedList(lists[0],lists[1]);
        lists.push_back(mergeHead);
        lists.erase(lists.begin());
        lists.erase(lists.begin());
    }
    return lists[0];
}
int main(){
    linkedlist ll1;
    int n;
    cout << "Enter the size of Linked List 1 : ";
    cin >> n;
    vector<int> v(n);
    cout << "Enter the Sorted Linked List 1 : ";
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        // Insert each input element into the linked list.
        ll1.insert(v[i]);
    }
    linkedlist ll2;
    int m;
    cout << "Enter the size of Linked List 2 : ";
    cin >> m;
    vector<int> v1(m);
    cout << "Enter the Sorted Linked List 2 : ";
    for (int i = 0; i < m; i++) {
        cin >> v1[i];
        // Insert each input element into the linked list.
        ll2.insert(v1[i]);
    }
    linkedlist ll3;
    int l;
    cout << "Enter the size of Linked List 3 : ";
    cin >> l;
    vector<int> v3(l);
    cout << "Enter the Sorted Linked List 3 : ";
    for (int i = 0; i < l; i++) {
        cin >> v3[i];
        // Insert each input element into the linked list.
        ll3.insert(v3[i]);
    }
    cout << "Linked List 1 is  :  ";
    ll1.display();    
    cout << "Linked List 2 is :  ";
    ll2.display();
    cout << "Linked List 3 is :  ";
    ll3.display();
    vector<node*> lists;
    lists.push_back(ll1.head);
    lists.push_back(ll2.head);
    lists.push_back(ll3.head);
    linkedlist mergeLL;
    mergeLL.head=mergeKLinkedList(lists);
    cout<<"Merge Linked List is : ";
    mergeLL.display();
    return 0;
}

Output:-
Enter the size of Linked List 1 : 5
Enter the Sorted Linked List 1 : 1 2 3 4 5
Enter the size of Linked List 2 : 3
Enter the Sorted Linked List 2 : 2 3 4
Enter the size of Linked List 3 : 2 
Enter the Sorted Linked List 3 : 1 99
Linked List 1 is  :  1 -> 2 -> 3 -> 4 -> 5 -> NULL
Linked List 2 is :  2 -> 3 -> 4 -> NULL
Linked List 3 is :  1 -> 99 -> NULL
Merge Linked List is : 1 -> 1 -> 2 -> 2 -> 3 -> 3 -> 4 -> 4 -> 5 -> 99 -> NULL

*/