/*

-So, that was all we has in Maps , really interesting and important STL container it was . So, make
sure to revise and understand it thoroughy!
HAVE A GOOD DAY!!


-We are gonna study about Maps! 

-Maps - It is an STL container which stores key-value pairs 
      - Key is that part of our pair using which we identify our pair
      - This elements are stored in ascending or decending order 
      - Maps cannot have duplicate keys i.e. keys are unique 
      
-Maps in STL are implemented using Binary Search tree

-Implementation:- 

#include<map>

map<key_datatype , value_datatype> map_name = {{key1,value1} , {key2,value2} ...};
map<string,int> directory;

-By default order is acending , for decending -> map<key_datatype , value_datatype , greater<key_datatype>>

->To make a pair we use make_pair(keys,values);
then to insert we use 'dire.insert(make_pair("naman",738383));'
 or we can use direct[key]=value;

-For printing the elements :- for each loop 
    for(auto element:map1){  //element will have same datatype as  key
        key=element.first;
        value=element.second;
    }


#include<iostream>
#include<map>
using namespace std;
int main(){
    map<string,int> directory;
    directory["Aditya"]=34567;directory["Adi"]=33467;directory["itya"]=345938067;directory["Adieeitya"]=3644567;
    directory["Aditya"]=0000;directory["Adi"]=3467;directory["itya"]=345938067;directory["Adieeitya"]=3644567;
    directory.insert(make_pair("SHA",456789)); 
    // Name - SHA
    // Number - 456789

    for(auto element:directory){
        cout<<"Name - "<<element.first<<endl;
        cout<<"Number - "<<element.second<<endl;
    }
    return 0;
}

// Output:-  when output taken first time
// Name - Adi
// Number - 33467
// Name - Adieeitya
// Number - 3644567
// Name - Aditya
// Number - 34567
// Name - itya
// Number - 345938067

// Output:-  when output taken to test updationa nd duplicate value;
// Name - Adi
// Number - 3467
// Name - Adieeitya
// Number - 3644567
// Name - Aditya
// Number - 0
// Name - itya
// Number - 345938067

-To erase a element in hashmap:-

m.erase(itr) - deleted the element at itr iterator
m.erase(key) - deletes the element with the key 'key'
m.erase(start_it,end_itr) - erases the elementss from start to end but "end iterator value will not be deleted"

-erase time complexity is :- O(logn);

-swap() - is used to swap maps
m1.swap(m2) or swap(m1,m2); here m1 and m2 should be same type;

-clear() - is used to delted the whole map;
-empty() - returns if map is empty or not
-size() - give us the size of map
-max_size() - it iis the max. size of the map , asthey are dynamic in nature so this max_size is a threshold 
which gets increases whenever we arrive near it
-find() - returns itr to element if present , else it returns map.end() itr.
-count() - no. of  occurences of key - always will give constant value
-upper_bound() - returns an itr to next greater element
-lower_bound() - returns itr to element if present else itr to next greater element
-begin() - return iterator to the first element 
-end() - returns the iterator after the last element
-rbegin() - iterator to first element in reverse order
-rend() - itertaor to position after the last element in reverse order 


-Example for transversing through our map!


#include<iostream>
#include<map>
#include<vector>
using namespace std;
int main(){
    cout<<"Enter the size of map : ";
    int n;
    cin>>n;

    vector<string> na(n);
    vector<int> nu(n);
    cout<<"Enter the names : ";
    for (int i = 0; i < n; i++)
    {
        cin>>na[i];
    }
    cout<<"Enter the number : ";
    for (int i = 0; i < n; i++)
    {
        cin>>nu[i];
    }
    
    map<string,int> direc;
    for (int i = 0; i < n; i++)
    {
        direc.insert(make_pair(na[i],nu[i]));
    }
    // cout<<"Map is : "<<endl;
    // map<string,int>::iterator itr; // declaring an iterator for my map
    // for (itr = direc.begin(); itr != direc.end(); itr++)
    // {
    //     cout<<itr->first<<" - "<<itr->second<<endl;
    // }

    cout<<"Map in reverse order is : "<<endl;
    map<string,int>::reverse_iterator itr;
    for ( itr = direc.rbegin(); itr != direc.rend(); itr++)
    {
        cout<<itr->first<<" - "<<itr->second<<endl;
    }
    
    return 0;
}

// -Output:- when map is transveresed normally 
// Enter the size of map : 4
// Enter the names : aditya gang orange aditya
// Enter the number : 55 100 90 -500
// Map is : 
// aditya - 55
// gang - 100
// orange - 90

// -Output:- when map is printed in reverse order
// Enter the size of map : 4
// Enter the names : aditya vinay unil unil
// Enter the number : 55 150 26 90
// Map in reverse order is : 
// vinay - 150
// unil - 26
// aditya - 55

-1.Sum of Repetitive Elements
You are given an integer n, representing the number of elements. Then, you will be given n elements. 
You have to return the sum of repetitive elements i.e. the elements that appear more than one time.


#include<iostream>
#include<vector>
#include<map>
using namespace std;
int main(){
    int n;
    cout<<"Enter the size of vector : ";
    cin>>n;
    vector<int> v(n);
    cout<<"Enter the vector : ";
    for (int i = 0; i < n; i++)
    {
        cin>>v[i];
    }
    map<int,int> m;
    for (int i = 0; i < n; i++)
    {
        //storing frequency of every element in input array
        m[v[i]]++;  // 'm' map ke 'v[i]' key pe value incraese kardo by '1'
    }
    int sum=0;
    //find sum of repetitive elements
    // par -> element , frequency
    for(auto pair:m){
        if(pair.second>1){
            sum+=pair.first;
        }
    }
    cout<<"Sum of elements which are repetitve are : "<<sum;
}

Output:-
Enter the size of vector : 7
Enter the vector : 5 5 1 2 3 -1 -1
Sum of elements which are repetitve are : 4

-Now , we are gonna study about unordered maps

-Unordered Map - Same as Maps but here elements are not in order i.e. random order
               - Here all insertion , deletion and retrival(search) happens in O(1) time complexity
               - It's very efficient due to which it is used in many cases
               - It's implemented using hashing(Revise hashing once if you arrive at this point)


      
#include<iostream>
#include<unordered_map>
using namespace std;
int main(){
    unordered_map<int,string> record;
    record.insert(make_pair(2,"aia"));
    record[4]="dev";
    record[55]="nauna";
    record[4]="ria"; // when we write like this then the value of 4 get updated 
    // but if we write record.insert(make_pair(4,"ria")) -> in this case value will not get updated
    for(auto key:record){
        cout<<key.first<<" - "<<key.second<<endl;
    }
    return 0;

}

// Output:- Randomly keys are stored instead of sorted like in maps
// 55 - nauna
// 4 - dev
// 2 - aia

-In average cases time complexity will be O(1) then in worst cases the time complexity will be O(n)

-Funtions in unordered maps act same as functions in ordered maps

-To erase a element in hashmap:-

m.erase(itr) - deleted the element at itr iterator
m.erase(key) - deletes the element with the key 'key'
m.erase(start_it,end_itr) - erases the elementss from start to end but "end iterator value will not be deleted"

-erase time complexity is :- O(logn);

-swap() - is used to swap maps
m1.swap(m2) or swap(m1,m2); here m1 and m2 should be same type;

-clear() - is used to delted the whole map;
-empty() - returns if map is empty or not
-size() - give us the size of map
-max_size() - it iis the max. size of the map , asthey are dynamic in nature so this max_size is a threshold 
which gets increases whenever we arrive near it
-find() - returns itr to element if present , else it returns map.end() itr.
-count() - no. of  occurences of key - always will give constant value
-upper_bound() - returns an itr to next greater element
-lower_bound() - returns itr to element if present else itr to next greater element
-begin() - return iterator to the first element 
-end() - returns the iterator after the last element
-rbegin() - iterator to first element in reverse order
-rend() - itertaor to position after the last element in reverse order 


-Multimap - stores key-value pairs , elements are stored in an order
          - Duplicates keys are allowed
          - Time compelxity is O(logN) for insertion , deletion and searcch  


#include<iostream>
#include<map>
using namespace std;
int main(){
    multimap<string,int> di;
    di.insert(make_pair("adi",3456));
    di.insert(make_pair("san",4567));
    di.insert(make_pair("nan",109876));di.insert(make_pair("nan",4567));di.insert(make_pair("nan",00000));
    for(auto ele:di){
        cout<<ele.first<<" - "<<ele.second<<endl;
    }
    return 0;

    ** //here di["ansh"]=679; -> this type of syntax is not allowed
}

// Output:-
// adi - 3456
// nan - 109876
// nan - 4567
// nan - 0
// san - 4567

-To erase a element in hashmap:-

m.erase(itr) - deleted the element at itr iterator
m.erase(key) - deletes the element with the key 'key'
m.erase(start_it,end_itr) - erases the elementss from start to end but "end iterator value will not be deleted"

-erase time complexity is :- O(logn);

-swap() - is used to swap maps
m1.swap(m2) or swap(m1,m2); here m1 and m2 should be same type;

-clear() - is used to delted the whole map;
-empty() - returns if map is empty or not
-size() - give us the size of map
-max_size() - it iis the max. size of the map , asthey are dynamic in nature so this max_size is a threshold 
which gets increases whenever we arrive near it
-find() - returns itr to element if present , else it returns map.end() itr.
-count() - no. of  occurences of key as duplicates are allowed in multiset
-upper_bound() - returns an itr to next greater element
-lower_bound() - returns itr to element if present else itr to next greater element
-begin() - return iterator to the first element 
-end() - returns the iterator after the last element
-rbegin() - iterator to first element in reverse order
-rend() - itertaor to position after the last element in reverse order 

-Unordered Multimap - elements are not ordered and duplicates keys are allowed


#include<iostream>
#include<unordered_map>
using namespace std;
int main(){
    unordered_multimap<string,int> fc;
    fc.insert(make_pair("apple",66));
    fc.insert(make_pair("banana",906));
    fc.insert(make_pair("ape",886));
    fc.insert(make_pair("apple",90));
    fc.insert(make_pair("oats",-567));
    fc.insert(make_pair("jaunga",988778));
    fc.insert(make_pair("aaaa",66));
    for(auto ele:fc){
        cout<<ele.first<<" - "<<ele.second<<endl; 
    }
    return 0;
}

-Time complexity - O(1) in avg cases and O(N) in worst cases;

-To erase a element in hashmap:-

m.erase(itr) - deleted the element at itr iterator
m.erase(key) - deletes the element with the key 'key'
m.erase(start_it,end_itr) - erases the elementss from start to end but "end iterator value will not be deleted"

-erase time complexity is :- O(logn);

-swap() - is used to swap maps
m1.swap(m2) or swap(m1,m2); here m1 and m2 should be same type;

-clear() - is used to delted the whole map;
-empty() - returns if map is empty or not
-size() - give us the size of map
-max_size() - it iis the max. size of the map , asthey are dynamic in nature so this max_size is a threshold 
which gets increases whenever we arrive near it
-find() - returns itr to element if present , else it returns map.end() itr.
-count() - no. of  occurences of key as duplicates are allowed in unordered multiset
-upper_bound() - returns an itr to next greater element
-lower_bound() - returns itr to element if present else itr to next greater element
-begin() - return iterator to the first element 
-end() - returns the iterator after the last element
-rbegin() - iterator to first element in reverse order
-rend() - itertaor to position after the last element in reverse order



-equal_range() - returns bounds of elements with key passed in pair form
*/






