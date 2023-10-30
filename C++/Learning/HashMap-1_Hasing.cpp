/*

-In this lecture we studied about Hashing and all concept and subtopics related to it!

And hashing is so important because it helps us make our code efficient -> used in unordered set and Maps
by making our basic insert , deletion and search operation in time complexity O(1);

-So, I think that's all I had in store for you keep Learning and have a GOOD DAY AHEAH!!!!



'-Number.*' -> represents the main topics 
'-' -> represents the sybtopics or notes of the main topic 
'-Number.' -> represent the questions or sub topics


-*Hashing - through hashing you can use insert ,deletion and especially search! in O(1) time complexity

In hashing we assign a unique value to our every number using a hashing function

-These unique indexes are called hash values which are made using a hash function

-*Types of hash functions :-

1.Division Method :- h(k) = k mod m
    ex- 126 - 126%10 = 6 so, 126 will be stored at index 6
2.Mid square method :- h(k) = k^2 and extract middle digits and that will be your hash values
    ex- 60 - pow(60,2) = 3600 - middle digits = 60 , therefore 60 will be stored at hash value 60
3.Digit folding method :- fold key into equal size parts 
    ex- 12345 - 12+34+5 = 51 , therefore 12345 will stored at 51 , here we can also take group of threes or more
4.Multiplication Method :- h(k) = floor(M(kA mod 1)) here 0<A<1 and M->size of hash table , mod 1->will give me the decimal part , 
floor means largest integer which is less than that decimal number
    ex- k=12345 , M=10 , A=0.01 
        k*A=123.45 
        kA mod 1 = 0.45
        M(kA mod 1) = 4.5
        floor(M(kA mod 1)) = 4

-*Collisions -  when elements have samee has values - such type of situation is called collison

They can be resolved using :- These are all for general formula -> h(k) = k mod M where M is the size of Hash table

1.Open hashing/Close addressing -> separate chaining is used i.e. we use linked list and attach that second element with same hash value to the 
next of position where our element of first same hash value is stored

-Asan bhasha me same ho to bas uske age next element insert hojayega using linked list if the hash values is same.
-Time complexity :- O(l) where l is the size of linked list
-Advantages - simple to implement and table will never fill up
-Disadvantages - many buckets of our table will remain empty and in some cases the LL will be too long which will increase the Time complexity


2.Closed hashing -> There are three method in closed hashing

    -Linear probing - {(h(k)+i) mod M} where 0<=i<=M(size of bucket)
                    - Probes are chances/transversal that we are taking to reach the empty space 
                    - Problem is that many times cluster gets form when they have the same hash value

    -Quadratic probing - {(h(k) + i^2) mod M} where 0<=i<=M(which is size of hash table )
                       -  Rest working is same as Linear probig

    -Double Hashing - (h1(k) + i(h2(k)) mod M) where 0<=i<=M
                    - here h1(k) = k mod (any number) and h2(k) = k mod (any other number) 
                    - Its more optimal than linear or quadratic probing

-*Load factor - On an avergae how many entires will be there in one bucket 
              - It is the division of no. of elements with no. of buckets of hash table
              - we want our load factor should be smaller 
              - In most of the cases the value of Load factor is '0.75'

if n-> no. of elements and m->no.of buckets then the Load factor will be 'n/m';


--**Whenever our load factor suprasses a pre set value then at that time we rehashing

-*Rehasing - means increasing size of hash table 
           - Redistributing elements in it.
           - Its a very costly operation
           - if we won't do rehasing then the collision will increase which will increase the Tinme Complexity!!

-Questions!!

-1.Implement hash table with closed addressing
*/

#include<iostream>
#include<list>
#include<vector>
#include<algorithm>
using namespace std;

class Hashing{  // here we will be creating a vector of Linked List
   
    vector<list<int>> hashtable;
    int buckets;
public: 
    Hashing(int size){
        buckets=size;
        hashtable.resize(size);
    }

    int hashvalue(int key){
        return key % buckets; // buckets is the size of hash table
    //mam used division function here i can use anything i want 
    }

    void addKey(int key){
        int idx=hashvalue(key);
        hashtable[idx].push_back(idx);   //vector ke index pe he to linked list hi, to operation LL wale hi honge
    }


    list<int>::iterator searchKey(int key){
        int idx=hashvalue(key);
        return find(hashtable[idx].begin(),hashtable[idx].end(),key);
    }

    void deleteKey(int key){
        int idx = hashvalue(key);
        if (searchKey(key)!=hashtable[idx].end())  // that is key is present in the linked list
        {
            hashtable[idx].erase(searchKey(key));
            cout<<key<<" is deleted from hashtable "<<endl;
        }
        else{
            cout<<"Key is  not present inside the hashtable "<<endl;
        }
        
    }

};

int main(){
    Hashing h(10);
    cout<<"NO. of keys you want to add : ";
    int a;
    cin>>a;
    while (a--)
    {
        int b;
        cin>>b;
        h.addKey(b);
    }
    h.deleteKey(5);
    h.deleteKey(9);
    return 0;
}

Output:-
NO. of keys you want to add : 5
1 2 3 4 5
5 is deleted from hashtable 
Key is  not present inside the hashtable

-All the function on an average have a timme complexity of O(1) which is really amazing
only in the worst case when all of my elements would be present ins ame linked list will my 
time complexity be O(N).










