/*
Q1 - Given an integer array(arr) and its size(n), print the count of odd and even integers present in the array.

#include<iostream>
using namespace std;
int main(){
    int n , arr[n];
    cout<<"Enter the size of array  : ";
    cin>>n;
    cout<<"Enter the array : ";
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    int a=0,b=0;
    for (int i = 0; i < n; i++)
    {
        if (i%2==0)
        {
            a++;
        }
        else{
            b++;
        }
    }
    cout<<"Number of even number is : "<<a<<endl;
    cout<<"Number of odd number is : "<<b;
    return 0;
    
}
Output:-
Enter the size of array  : 5
Enter the array : 2 3 4 5 6
Number of even number is : 3
Number of odd number is : 2 

Q2 - Given an integer array and its size, find the sum of the greatest and the smallest integer present in the array. Here 1< size <101

#include<iostream>
using namespace std;

int main(){
    int a;
    cout<<"Enter the size of array (between 1 to 101) : ";
    cin>>a;
    int arr[a];
    cout<<"Enter the array : ";
    for (int i = 0; i < a; i++)
    {
        cin>>arr[i];
    }
    int b=arr[0];
    int c=arr[0];
    for (int i = 0; i < a-1; i++)
    {
        if (b<arr[i+1])
        {
            b=arr[i+1];
        }
        if (c>arr[i+1])
        {
            c=arr[i+1];
        }    
    }
    cout<<"Biggest number is : "<<b<<endl;
    cout<<"Smallest number is : "<<c;
    return 0;
}
Output:-
Enter the size of array (between 1 to 101) : 5
Enter the array : 11 22 -100 10 9999
Biggest number is : 9999
Smallest number is : -100

Q3 - Given an integer array and its size, reverse the array and print it. Here 1<size<101 

#include<iostream>
using namespace std;
int main(){
    int a;
    cout<<"Enter the size of array (between 1 to 101) : ";
    cin>>a;
    int arr[a];
    cout<<"Enter the array : ";
    for (int i = 0; i < a; i++)
    {
        cin>>arr[i];
    }
    cout<<"Rverse of the array is : ";
    for (int i = a-1; i >= 0; i--)
    {
        cout<<arr[i]<<" ";  
    }
    return 0;
}
Output:-
Enter the size of array (between 1 to 101) : 5
Enter the array : 1 2 3 4 5
Rverse of the array is : 5 4 3 2 1 

Q4 - Given two arrays a[] and b[] of same size.Your task is to find the minimum sum of two elements such
that they belong to different arrays and are not at the same index. Here 1<size<101   




#include<iostream>
using namespace std;
int min(int ar1[], int ar2[] ,int a){
    int minsum= INT_MAX;
    for (int i = 0; i < a; i++)
    {
        for (int j = 0; j < a; j++)
        {
            if (i!=j)
            {
                int sum= ar1[i]+ar2[j];
                if (sum<minsum)
                {
                    minsum=sum;
                }
                
            }
            
        }
        
    }
    return minsum;
}
int main(){
    int n;
    cout<<"Enter the size of array (Between 1 to 100) : ";
    cin>>n;
    if(n<2 || n>100){
        cout<<"Size above range";
        return 1;     // This way we can terminate the code 
    }
    //Output:-
    
    //Enter the size of array (Between 1 to 100) : 200
    //Size above range         
    
    int arr1[n];
    cout<<"Enter the array 1 : ";
    for (int i = 0; i < n; i++)
    {
        cin>>arr1[i];
    }
    int arr2[n];
    cout<<"Enter the array 2 : ";
    for (int i = 0; i < n; i++)
    {
        cin>>arr2[i];
    }
    cout<<"Minimum sum is : "<<min(arr1 , arr2 , n);
    
    return 0;

}

output:-
Enter the size of array : 5
Enter the array 1 : 1 2 3 4 5
Enter the array 2 : 2 3 4 5 6
Minimum sum is : 4 

Q5 - Given an array containing n distinct integers in the range [0,n] (inclusive of both 0 and n) (inclusive of both
0 and n). Find and return the only number of the range that is not present in the array. Here 1<n<101. 

-Using NET!

#include <iostream>
using namespace std;

int findMissingNumber(int arr[], int n) {
    int totalSum = (n * (n + 1)) / 2;
    int arraySum = 0;

    for (int i = 0; i < n; i++) {
        arraySum += arr[i];
    }

    int missingNumber = totalSum - arraySum;
    return missingNumber;
}

int main() {
    int n;
    cout << "Enter the value of n: ";
    cin >> n;

    if (n <= 1 || n >= 101) {
        cout << "Invalid input! n should be between 2 and 100." << endl;
        return 1;
    }

    int arr[n - 1]; // Array size is n-1, as it contains distinct integers from 0 to n (inclusive)
    cout << "Enter " << n - 1 << " distinct integers in the range [0, " << n << "]: ";
    for (int i = 0; i < n - 1; i++) {
        cin >> arr[i];
    }

    int missingNumber = findMissingNumber(arr, n);
    cout << "The missing number is: " << missingNumber << endl;

    return 0;
}
Output:-
Enter the value of n: 7
Enter 6 distinct integers in the range [0, 7]: 1 3 6 4 7 5 
The missing number is: 2

-By ME!

#include<iostream>
using namespace std;
int missingnNum(int arr[] , int n){
    int totalsum = ((n)*(n+1))/2;
    int sum=0;
    for (int i = 0; i < n-1; i++)
    {
        sum+=arr[i];
    }
    return totalsum-sum;
}
int main(){
    int n;
    cout<<"Enter the size of array : ";
    cin>>n;
    int arr[n-1];
    cout << "Enter " << n - 1 << " distinct integers in the range [0, " << n << "]: ";
    for (int i = 0; i < n-1; i++)
    {
        cin>>arr[i];
    }
    cout<<"Missing number is : "<<missingnNum(arr,n);
    return 0;
}
Output:-
Enter the size of array : 5
Enter 4 distinct integers in the range [0, 5]: 1 2 3 4
Missing number is : 5

Q6 - Given an integer array containing n elements. Find the element in the array for which all the elements to its
left are smaller than it and all the elements to the right of it are larger than it.Here 1<n<101

(Solved by me ) 
#include<iostream>
using namespace std;
void num(int *arr , int n){
    int a = INT_MAX;
    int b= INT_MIN;
    for (int i = 0; i < n; i++)
    {
        if (b<=arr[i])
        {
            b=arr[i];
        }
        if (a>=arr[n-i-1])
        {
            a=arr[n-i-1];
        }
        if (a==b)
        {
            cout<<"Number whose digits in the left are smaller and digits in the right is bigger is : "<<a;
            break;
        } 
    }  
}
int main(){
    int n,m;
    cout<<"Enter the size of array : ";
    cin>>n;
    int arr[n];
    cout<<"Enter the array : ";
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    num(arr,n);
    return 0;
}
Output:-
Enter the size of array : 5
Enter the array : 150 90 210 500 1000
Number whose digits in the left are smaller and digits in the right is bigger is : 210

-By internet ^_^ 

#include<iostream>
using namespace std;
int findnum(int arr[],int n){
    int prefix[n];
    int suffix[n];
    prefix[0]=INT_MIN;
    suffix[n-1]=INT_MAX;
    for (int i = 1; i < n; i++)
    {
        prefix[i] = max(arr[i-1],prefix[i-1]);
    }
    for (int i = n-2; i >= 0; i--)
    {
        suffix[i]= min(arr[i+1],suffix[i+1]);
    }
    for (int i = 0; i < n; i++)
    {
        if (prefix[i]<arr[i] && arr[i]<suffix[i])
        {
            return arr[i];
        } 
    }
    return -1;
}
int main(){
    int n;
    cout<<"Enter the size of array : ";
    cin>>n;
    int arr[n];
    cout<<"Enter the array : ";
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    int result = findnum(arr, n);
    if (result != -1) {
        cout << "The element that satisfies the condition is: " << result << endl;
    } 
    else {
        cout << "No element in the array satisfies the condition." << endl;
    }
    return 0;
}
Output:-
Enter the size of array : 5
Enter the array : 90 99 100 150 1000
The element that satisfies the condition is: 90
*/






















