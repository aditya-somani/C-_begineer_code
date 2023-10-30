/*
-The questions are easy and really makes mind run , so try to solve them by yourself not with just logic but 
write the entire damn code because you really lack that part but I know you can do it ! 
so, just keep learning and keep trying . BYE HAVE A GOOD DAY AHEAD!!!

-1.Write a program to reverse a doubly linked list

#include <iostream>
using namespace std; 
class Node
{
public:
    int data;
    Node *next, *prev;
 
 
    Node(int val)
    {
        data = val;
        next = prev = NULL;
    }
};
 
 
class linked_list
{
public:
    Node *head = NULL, *tail = NULL;
 
 
    void insert(int val)
    {
        if (head == NULL)
        {
            head = tail = new Node(val);
            return;
        }
        Node *new_node = new Node(val);
        tail->next = new_node;
        new_node->prev = tail;
        tail = new_node;
    }
 
 
    void print()
    {
        Node *curr = head;
        while (curr != NULL)
        {
            cout << curr->data;
            if (curr->next != NULL)
                cout << "->";
            curr = curr->next;
        }
        cout << '\n';
    }
};
 
 
Node *reverse(Node *head)
{
    Node *curr = head;
    while (curr != NULL)
    {
        Node *temp = curr->next;
        curr->next = curr->prev;
        curr->prev = temp;
        head = curr;
        curr = curr->prev;
    }
    return head;
}
 
 
int main()
{
    int n;
    cin >> n;
    linked_list ll;
    while (n--)
    {
        int val;
        cin >> val;
        ll.insert(val);
    }
    ll.head = reverse(ll.head);
    ll.print();
    return 0;
}

Output:-
5
1 2 3 4 5
5->4->3->2->1

-2.Write a prgramm to check if the the given number is Palindrome or not? 

#include<iostream>
using namespace std;
class node{
    public:
    int val;
    node* next;
    node* prev;
    node(int data){
        val=data;
        next=NULL;
        prev=NULL;

    }
};
class doubly{
    public:
    node* head=NULL;
    node* tail=NULL;

    void insert(int val){
        if (tail==NULL)
        {
            head=tail=new node(val);
            return;
        }
        node* newnode= new node(val);
        tail->next=newnode;
        newnode->prev=tail;
        tail=newnode;
        

        
    }
    
    void print(){
        node* temp=head;
        while (temp)
        {
            cout<<temp->val;
            if (temp->next!=NULL)
            {
                cout<<" <-> ";
            }
            temp=temp->next;
            
        }
        cout<<endl;
    }

    bool isPlaindrome(node* head,node* tail){
        while (head!=tail && tail!=head->prev)
        {
            if (head->val!=tail->val)
            {
                return false;
            }
            head=head->next;
            tail=tail->prev;
        }
        return true;
    }
    
};
int main(){
    cout<<"ENter the size of LL : ";
    int n;
    cin>>n;
    doubly dll;
    cout<<"Enter the linked list : ";
    while (n--)
    {
        int val;
        cin>>val;
        dll.insert(val);
    }
    cout<<"Linked List is : ";
    dll.print();
    if (dll.isPlaindrome(dll.head,dll.tail))
    {
        cout<<"yes, the linnkedd list is palindrome in nature ";
    }else{
        cout<<"No, it is not palindrome in nature ";
    }
    return 0;
}


Output:-
ENter the size of LL : 6
Enter the linked list : 1 2 3 3 2 1
Linked List is : 1 <-> 2 <-> 3 <-> 3 <-> 2 <-> 1
yes, the linnkedd list is palindrome in nature


-3.Given the head of a doubly linked list, delete the nodes whose neighbors have the same value. 
Traverse the list from right to left.

#include<iostream>
using namespace std;
class node{
    public:
    int val;
    node* next;
    node* prev;
    node(int data){
        val=data;
        next=NULL;
        prev=NULL;

    }
};

class doubly{
    public:
    node* head;
    node* tail;
    doubly(){
        head=NULL;
        tail=NULL;

    }

    void insert(int val){
        node* newnode=new node(val);
        if (head==NULL)
        {
            head=newnode;
            tail=newnode;
        }
        tail->next=newnode;
        newnode->prev=tail;
        tail=newnode;

        
    }

    void print(){
        node* temp=head;
        while (temp)
        {
            cout<<temp->val;
            if (temp->next!=NULL)
            {
                cout<<" -> ";
            }
            temp=temp->next;
            
        }
        cout<<endl;
        
    }

    void deleteSameNeighbourNode(node* &head,node* &tail){
        node* currNode= tail->prev; //second last node
        while (currNode!=head)
        {
            node* prevNode=currNode->prev;
            node* nextNode=currNode->next;
            if (prevNode->val==nextNode->val)
            {
                //I need to delete the curr node
                prevNode->next=nextNode;
                nextNode->prev=prevNode;
                free(currNode);
            }
            currNode=prevNode;  //because we are transversing from right to left
            
        }
    }
};
int main(){
    doubly dll;
    cout<<"Enter the size of Linked List : ";
    int n;
    cin>>n;
    cout<<"Enter the Linked list : ";
    while (n--)
    {
        int val;
        cin>>val;
        dll.insert(val);
    }
    cout<<"The same neighbour deleted List is : ";
    dll.deleteSameNeighbourNode(dll.head,dll.tail);
    dll.print();
    return 0;

}

Output:-
Enter the size of Linked List : 5
Enter the Linked list : 2 1 1 2 1
The same neighbour deleted List is : 2 -> 1 -> 1


-4.A critical point in a linked list is defined as either a local maxima or a local minima. 
Given a linked list tail, return an array of length 2 containing [minDistance, maxDistance] where 
minDistance is the minimum distance between any two distinct critical points and maxDistance is the 
maximum distance between any two distinct critical points. If there are fewer than two critical points, return [-1,-1].
Note that a node can only be a local maxima/minima if there exists both a previous node and a next node.


#include <iostream>
#include <vector>
using namespace std;

class node {
public:
    int val;
    node* next;
    node* prev;
    node(int data) {
        val = data;
        next = NULL;
        prev = NULL;
    }
};

class doubly {
public:
    node* head;
    node* tail;
    doubly() {
        head = NULL;
        tail = NULL;
    }

    void insert(int val) {
        node* newnode = new node(val);
        if (head == NULL) {
            head = newnode;
            tail = newnode;
        }
        tail->next = newnode;
        newnode->prev = tail;
        tail = newnode;
    }

    void print() {
        node* temp = head;
        while (temp) {
            cout << temp->val;
            if (temp->next != NULL) {
                cout << " -> ";
            }
            temp = temp->next;
        }
        cout << endl;
    }
};

bool isCriticalPoint(node* &currNode) {
    if (currNode->prev->val < currNode->val && currNode->next->val < currNode->val) {
        return true;
    }
    if (currNode->prev->val > currNode->val && currNode->next->val > currNode->val) {
        return true;
    }
    return false;
}

vector<int> distanceBetweenCriticalPoints(node* head, node* tail) {
    vector<int> v(2, INT_MAX);
    int firstCP = -1, lastCP = -1;

    node* currNode = tail->prev;
    if (currNode == NULL) {
        v[0] = v[1] = -1;
        return v;
    }

    int currpos = 0;
    while (currNode!=head  ) {
        if (isCriticalPoint(currNode)) {
            if (firstCP == -1) {
                firstCP = lastCP = currpos;
                currpos++;
            } else {
                v[0] = min(v[0], currpos - lastCP); // min distance 
                v[1] = currpos - firstCP; // max distance
                
            }
        }
        currpos++;
        currNode = currNode->prev;
    }

    if (v[0] == INT_MAX) {
        v[0] = v[1] = -1;
    }

    return v;
}

int main() {
    doubly dll;
    cout << "Enter the size of Linked List : ";
    int n;
    cin >> n;
    cout << "Enter the Linked list : ";
    while (n--) {
        int val;
        cin >> val;
        dll.insert(val);
    }
    vector<int> ans = distanceBetweenCriticalPoints(dll.head, dll.tail);
    cout << "Min distance between critical points is : " << ans[0]-1 << endl;
    cout << "Max distance between critical points is : " << ans[1]-1 << endl;
    return 0;
}

Output:-
Enter the size of Linked List : 5
Enter the Linked list : 1 5 2 6 3
Min distance between critical points is : 1
Max distance between critical points is : 2

-5.Given the head of a doubly linked list. The values of the linked list are sorted in non-decreasing order. 
Find if there exists a pair of distinct nodes such that the sum of their values is x. Return the pair in the form of 
a vector [1, r], where I and r are the values stored in the 2 nodes pointed by the pointers. 
If there are multiple such pairs, return any of them. If there is no such pair return [-1, -1].


#include <iostream>
#include <vector>
using namespace std;

class node {
public:
    int val;
    node* next;
    node* prev;
    node(int data) {
        val = data;
        next = NULL;
        prev = NULL;
    }
};

class doubly {
public:
    node* head;
    node* tail;
    doubly() {
        head = NULL;
        tail = NULL;
    }

    void insert(int val) {
        node* newnode = new node(val);
        if (head == NULL) {
            head = newnode;
            tail = newnode;
        }
        tail->next = newnode;
        newnode->prev = tail;
        tail = newnode;
    }

    void print() {
        node* temp = head;
        while (temp) {
            cout << temp->val;
            if (temp->next != NULL) {
                cout << " -> ";
            }
            temp = temp->next;
        }
        cout << endl;
    }
};

vector<int> pairSumDLL(node* head,node* tail , int x){
    vector<int> ans(2,-1);
    while (head!=tail)
    {
        int sum=head->val+tail->val;
        if (sum==x)
        {
            ans[0]=head->val;
            ans[1]=tail->val;
            return ans;
        }
        if (sum>x)  //i need smaller values , i will move my tail back
        {
            tail=tail->prev;
        }
        else{  //i need bigger values , i will move head forward
            head=head->next;
        }
        
    }
    return ans;
}

int main() {
    doubly dll;
    cout << "Enter the size of Linked List : ";
    int n;
    cin >> n;
    cout << "Enter the Linked list : ";
    while (n--) {
        int val;
        cin >> val;
        dll.insert(val);
    }
    int x;
    cout<<"The number whose sum you want to check : ";
    cin>>x;
    vector<int> ans = pairSumDLL(dll.head,dll.tail,x);
    cout<<"The sum of "<<x<<" in the linked list is : "<<ans[0]<<" and "<<ans[1];
    return 0;
}

Output:-
Enter the size of Linked List : 5
Enter the Linked list : 1 2 3 4 5
The number whose sum you want to check : 7
The sum of 7 in the linked list is : 2 and 5


*/