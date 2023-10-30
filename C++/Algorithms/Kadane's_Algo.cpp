/*

-Kadane's Algorithm 

Kadane's algorithm is a dynamic programming algorithm that finds the maximum sum of a contiguous subarray in an array of numbers. 
The algorithm was proposed by Jay Kadane in 1984. 

-Kitne possible subarrays bantae he of my arrays starting form first one



*/
#include<iostream>
using namespace std;

long long maxSubarraySum(int arr[], int n){
    long long int cs=arr[0];
    long long int ms=arr[0];
    for(int i=1;i<n;i++){
        cs=max(cs+arr[i],(long long)arr[i]);
        ms=max(ms,cs);
    }
    return ms;
}

int main(){
    int n=5;
    int arr[5]={5,1,3,0,-5};
    maxSubarraySum(arr,n);
}












