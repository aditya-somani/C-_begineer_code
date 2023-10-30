/*

-And with this we completed this assignment , yep it was quite good ~medium level but as I did it 
in pieces I should revise it once!

Q1 - Given an integer array and two integers L and R. Find the sum of elements between the
index L and index R.
Note: Both L and R inclusive.

-This is how it is normally done

#include<iostream>
using namespace std;
void sumRange(int arr[] , int l , int r){
    int sum=0;
    for (int i = l; i <= r; i++)
    {
        sum+=arr[i];
    }
    cout<<"Sum of integers from index "<<l<<" to "<<r<<" is "<<sum;
    
}
int main(){
    int l,r,n;
    cout<<"Enter the size of array : ";
    cin>>n;
    int arr[n];
    cout<<"Enter the array : ";
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    cout<<"Enter the starting index : ";
    cin>>l;
    cout<<"Enter the ending index : ";
    cin>>r;
    if (l<r && r<n)
    {
        sumRange(arr,l,r);
    }
    else{
        cout<<"Incorrect values input ";
    }
    return 0;
}

Output:-
Enter the size of array : 5
Enter the array : 1 -1 3 5 6
Enter the starting index : 0
Enter the ending index : 3
Sum of integers from index 0 to 3 is 8

-Now using prefix sum 

#include<iostream>
using namespace std;
void prefixSum(int array[] , int l , int r){
    int totalsum=0;
    int initialsum=0;
    for (int i = 0; i <= r; i++)
    {
        totalsum+=array[i];
    }
    for (int i = 0; i < l; i++)
    {
        initialsum+=array[i];
    }
    cout<<"Sum of integers from index number "<<l<<" to "<<r<<" is "<<totalsum-initialsum;
}
int main(){
    int l,r,n;
    cout<<"Enter the size of array : ";
    cin>>n;
    int arr[n];
    cout<<"Enter the array : ";
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    cout<<"Enter the starting index : ";
    cin>>l;
    cout<<"Enter the ending index : ";
    cin>>r;
    if (l<r && r<n)
    {
        prefixSum(arr,l,r);
    }
    else{
        cout<<"Incorrect values input ";
    }
    return 0;
}

Output:-
Enter the size of array : 5
Enter the array : 1 2 3 4 5
Enter the starting index : 2
Enter the ending index : 4
Sum of integers from index number 2 to 4 is 12

-In This one each element is the sum of all numbers precending it! , so just  minus the previous one
and you will get the answer! 

#include<iostream>
using namespace std;
int main(){
    int L=2,R=4,n=5;
    int arr[n]={1,2,3,4,5};
    for(int i=1;i<n;i++)
    {
    arr[i]+=arr[i-1];
    }
    int ans=arr[R]-arr[L-1];
    cout<<ans;
}

Q3 - ​Given an integer array arr consisting of 0’s and 1’s only, return the max length of
sequence which contains equal numbers of 0 and 1.


#include<iostream>
using namespace std;
void maxLen(int arr[] , int n ){
    int count =0;
    int count0 = 0;
    int count1= 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i]==0)
        {
            count0++;
        }
        if (arr[i]==1)
        {
            count1++;
        }
        if (count0==count1)
        {
            int curcount = count0 + count1;
            count= max(curcount , count); 
        }   
    } 
    cout<<"Nuber of consecutive 0's and 1's are : "<<count;
}
int main(){
    int n;
    cout<<"Enter the size of array : ";
    cin>>n;
    int array[n];
    cout<<"Enter the array consisting of only 0's and 1 : ";
    for (int i = 0; i < n; i++)
    {
        cin>>array[i];
    }
    maxLen(array,n);
    return 0;

}
Output:-
Enter the size of array : 9
Enter the array consisting of only 0's and 1 : 0 1 0 0 1 1 0 1 1
Nuber of consecutive 0's and 1's are : 8

Q4 - ​Given an integer array arr, return the number of consecutive sequences(subarrays) with
odd sum.

#include<iostream>
using namespace std;
void oddSum(int arr[] , int n){
    int count =0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i]%2!=0)
        {
            count++;
        }
        
    }
    
    for (int i = 1; i < n; i++)
    {
        arr[i]+=arr[i-1]; // prefix sum
    }
    for (int i = 0; i < n; i++)
    {
        if (arr[i]%2!=0)
        {
            count++;
        }
    }
    
    cout<<"Number of consecutive numbers whose is odd is : "<<count;
}
int main(){
    int n;
    cout<<"Enter the size of array : ";
    cin>>n;
    int array[n];
    cout<<"Enter thee array : ";
    for (int i = 0; i < n; i++)
    {
        cin>>array[i];
    }
    oddSum(array,n);
    return 0;
}
Output:-
Enter the size of array : 3
Enter thee array : 1 3 5
Number of consecutive numbers whose is odd is : 5

Q5 - Given an integer array arr, return an array ans such that ans[i] is equal to the product of
all the elements of arr except arr[i].

#include<iostream>
#include<vector>
using namespace std;

void proArray(int arr[], int n) {
    vector<int> v(n, 1);
    int totalProduct = 1;
    int zeroCount = 0; // Count of zeros in the array

    for (int i = 0; i < n; i++) {
        if (arr[i] != 0) {
            totalProduct *= arr[i];
        } else {
            zeroCount++;
        }
    }

    for (int i = 0; i < n; i++) {
        if (zeroCount > 1) {
            v[i] = 0;
        } else if (zeroCount == 1) {
            v[i] = (arr[i] == 0) ? totalProduct : 0;
        } else {
            v[i] = totalProduct / arr[i];
        }
    }

    cout << "Answer array is: ";
    for (int i = 0; i < n; i++) {
        cout << v[i] << " ";
    }
    cout << endl;
}

int main() {
    int n;
    cout << "Enter the size of array: ";
    cin >> n;
    int array[n];

    cout << "Enter the array: ";
    for (int i = 0; i < n; i++) {
        cin >> array[i];
    }

    proArray(array, n);
    return 0;
}

Output:-
Enter the size of array: 5
Enter the array: -5 -4 0 4 5
Answer array is: 0 0 400 0 0 

Q6 - ​Given an array of size ‘n’ (initially zero) and ‘Q’ updates (increase the value of all index
from l to r with value x) and in the end print all the numbers of the array.

#include<iostream>
#include<vector>
using namespace std;
int main(){
    int l,r,x,q,n;
    cout<<"Enter the size of vector : ";
    cin>>n;
    vector<int> v(n,0);
    cout<<"Number of queries : ";
    cin>>q;
    cout<<"The number you want to be updated(sum) with : ";
    cin>>x;
    for (int i = 0; i < q; i++)
    {
        cout<<"Enter the starting and ending indices : ";
        cin>>l>>r;
        if (l>=0 && r<n)
        {
            for (int j = l; j <= r; j++)
            {
                v[j]+=x;
            }
        }
        else{
            cout<<"Value of 'l' or 'r' is incorrect ";
            return -1;
        }
    }
    
    cout<<"Updated vector is : ";
    for (int i = 0; i < n; i++)
    {
        cout<<v[i]<<" ";
    }
    return 0;
}

Output:-
Enter the size of vector : 5
Number of queries : 3
The number you want to be updated(sum) with : 5
Enter the starting and ending indices : 0 3
Enter the starting and ending indices : 4 4
Enter the starting and ending indices : 1 2
Updated vector is : 5 10 10 5 5

*/