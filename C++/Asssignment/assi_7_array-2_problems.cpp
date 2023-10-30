/*
Summary :- These questions are really interesting as well as require a through practice and revesion!!

Current status : - Revesion not done!

Q1 - Given two vectors arr1[] and arr2[] of size m and n sorted in increasing order. Merge the
two arrays into a single sorted array of size m+n.

#include<iostream>
using namespace std;
int main(){
    int a,b;
    cout<<"Enter the size of array 1 : ";
    cin>>a;
    int arr1[a];
    cout<<"Enter the array 1 : ";
    for (int i = 0; i < a; i++)
    {
        cin>>arr1[i];
    }
    cout<<"Enter the size of array 2 : ";
    cin>>b;
    int arr2[b];
    cout<<"Enter the array 2 : ";
    for (int i = 0; i < b; i++)
    {
        cin>>arr2[i];
    }
    int k=a+b-1;
    int m=a-1;
    int n = b-1;
    int arr3[k];
    while (m>=0 && n>=0)
    {
        if (arr1[m]<arr2[n])
        {
            arr3[k--]=arr2[n--];
        }
        else{
            arr3[k--]=arr1[m--];
        }
    }
    while (m>=0)
    {
        arr3[k--]=arr1[m--];
    }
    while (n>=0)
    {
        arr3[k--]=arr2[n--];
    }
    cout<<"Combined array is : ";
    for (int i = 0; i < a+b; i++)
    {
        cout<<arr3[i]<<" ";
    }
    return 0;
    
}
Output:-
Enter the size of array 1 : 4
Enter the array 1 :  1 2 3 44
Enter the size of array 2 : 3
Enter the array 2 : -10 -1 1000
Combined array is : -10 -1 1 2 3 44 1000 

Q2 - Given a vector arr[] sorted in increasing order of n size and an integer x, find if there exists
a pair in the array whose sum is exactly x.

#include<iostream>
using namespace std;
void sum(int arr[] , int size , int num){
    int m=0;
    int n=size-1;
    bool found =false;
    while (m<n)
    {
        if (arr[m]+arr[n]==num)
        {
            cout<<"Yes! "<<arr[m]<<" + "<<arr[n]<<" = "<<num;
            found=true;
            break;
        }
        else if (arr[m]+arr[n]>num)
        {
            n--;
        }
        else{
            m++;
        }
    }
    if(found==false){
        cout<<"NO required sum not found ";
    }
    
}
int main(){
    int n;
    cout<<"Enter the size of array : ";
    cin>>n;
    cout<<"Enter the array : ";
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    int m;
    cout<<"The number whose who is targeted sum : ";
    cin>>m;
    sum(arr,n,m);
    return 0;
}
Output:-
Enter the size of array : 5
Enter the array : 1 2 3 4 5
The number whose who is targeted sum : 9
Yes! 4 + 5 = 9

Q3 - Given a vector arr[] sorted in increasing order of n size and an integer x, find if there exists
a pair in the array whose absolute difference is exactly x.

#include<iostream>
using namespace std;
void abs11(int arr[], int size, int num){
    int x=num;
    int m=0;
    int n=1;
    bool possible = false;
    while (m<size && n<size)
    {
        if ((arr[n]-arr[m])==(x))
        {
            cout<<"Yes the absolute difference of "<<arr[n]<<" and "<<arr[m]<<" is "<<x;
            possible = true;
            break;
        }
        if ((arr[n]-arr[m])<(x))
        {
            n++;
        }
        else{
            m--;
        }
    }
    if (possible == false)
    {
        cout<<"Absolte difference does not equal to "<<x;
    }
    
    
}
int main(){
    int n;
    cout<<"Enter the size of array : ";
    cin>>n;
    cout<<"Enter the array : ";
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    int m;
    cout<<"The number whose who is targeted absolute difference you want : ";
    cin>>m;
    abs11(arr,n,m);
    return 0;
}
Output:-
Enter the size of array : 5
Enter the array : 1 2 3 4 5
The number whose who is targeted absolute difference you want : 3
Yes the absolute difference of 4 and 1 is 3

Q4 - Given a vector arr[] sorted in increasing order. Return an array of squares of each
number sorted in increasing order. Where size of vector 1<size<101.

#include<iostream>
using namespace std;
void sorted(int arr[],int n){
    for (int i = 0; i < n-1; i++)
    {
        for (int j = 0; j < n-1; j++)
        {
            if (arr[j+1]<arr[j])
            {
            int temp= arr[j+1];
            arr[j+1]=arr[j];
            arr[j]=temp;
            }
        
        }
        
    }
    
}
void square(int arr[] , int n){
    for (int i = 0; i < n; i++)
    {
        arr[i]*=arr[i];   
    }
    sorted(arr,n);
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
       
}
int main(){
    int n;
    cout<<"Enter the size of array : ";
    cin>>n;
    cout<<"Enter the array : ";
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    cout<<"Sorted array of sqaure of number is : ";
    square(arr,n);
    return 0;
}
Output:-
Enter the size of array : 5
Enter the array : -6 -5 3 4 9
Sorted array of sqaure of number is : 9 16 25 36 81 

Q5 - Given a vector arr[] sorted in increasing order of n size and an integer x, find the number
of unique pairs that exist in the array whose absolute sum is exactly x.

#include<iostream>
using namespace std;
void positive(int arr[], int n){
    for (int i = 0; i < n; i++)
    {
        if (arr[i]<0)
        {
            arr[i]=abs(arr[i]);
        }
        
    }
    
}
void absSum(int arr[] , int n , int x){
    int m=0;
    int l=n-1;
    int ans=0;
    
    positive(arr,n);
    cout<<"Possible pairs : ";
    for (int i = 0; i < n; i++)
    {
        if (arr[m]+arr[l]==x && m!=l)
        {
            ans++;
            cout << "(" << arr[m] << ", " << arr[l] << ")" << "  "; // Display the pair
            l--;
            m++;
            
        }
        if (arr[m]+arr[l]>x)
        {
            l--;
        }
        else{
            m++;
        }
        
    }
    cout<<endl;
    cout << "Number of unique pairs for which absolute sum is possible is: " << ans << endl;
    
}
int main(){
    int n;
    cout<<"Enter the size of array : ";
    cin>>n;
    cout<<"Enter the array : ";
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    int m;
    cout<<"The number whose who is targeted absolute sum you want : ";
    cin>>m;
    absSum(arr,n,m);
    return 0;
}

Output:-
Enter the size of array : 5
Enter the array : -1 -2 3 4 5
The number whose who is targeted absolute sum you want : 6
Possible pairs : (1, 5)  (4, 2)  
Number of unique pairs for which absolute sum is possible is: 2

Q6 - Given a vector array nums, print the count of triplets [nums[i], nums[j], nums[k]] such
that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == x. Where k is an integer
given by the user.
Note: The solution set must not contain duplicate triplets and should not have 3 loops.

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void triplet(vector<int>& v , int x){
    int count = 0;
    int n= v.size();
    sort(v.begin(),v.end());  //Ascending Order
    cout<<"Triplets are : ";
    for (int i = 0; i < n-2; i++)
    {
        int j= i+1;  //Left-pointer
        int k = n-1;  //Right-Pointer
        while (j<k)
        {
            int sum = v[i]+v[j]+v[k];
            if (sum == x)
            {
                cout<<"(" << v[i] << ", " << v[j] <<" , "<< v[k] << ")" << "  ";
                count++;
                j++;
                k--;
            }
            if (sum<x)
            {
                j++;
            }
            if (sum>x)
            {
                k--;
            } 
        } 
    }
    cout<<endl;
    cout<<"Total number of unique triplets is : "<<count;
}
int main(){
    int s;
    cout<<"Enter the size of vector : ";
    cin>>s;
    vector<int> v(s);
    cout<<"Enter integers : ";
    
    for (int i = 0; i < s; i++)
    {
        cin>>v[i];
    }
    
    int n;
    cout<<"Enter the number whose triplet summ you wish to find : ";
    cin>>n;
    triplet(v,n);
    return 0;
    
}

Output:-
Enter the size of vector : 7
Enter integers : -1 -4 1 0 4 0 7
Enter the number whose triplet summ you wish to find : 0
Triplets are : (-4, 0 , 4)  (-1, 0 , 1)  
Total number of unique triplets is : 2

*/












