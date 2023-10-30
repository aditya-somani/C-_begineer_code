/*

Q1 - Given a 2D matrix with m rows and n columns containing integers, find and print the
maximum value present in the array.
m=3
n=3
arr[] = {{1,2,3}, {4,5,6}, {7,8,9}}
Output: 9


#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    int m,n;
    cout<<"Enter the number of rows for vector : ";
    cin>>m;
    cout<<"Enter the number of column for vector : ";
    cin>>n;
    vector<vector<int>> v(m,vector<int> (n));
    cout<<"Enter the vector : ";
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin>>v[i][j];
        }
        
    }
    int greatest=INT_MIN;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            greatest = max(greatest,v[i][j]);
        }
        
    }
    cout<<"Greatest number is vector is : "<<greatest;
    return 0;
    
}

Output:-
Enter the number of rows for vector : 3
Enter the number of column for vector : 3
Enter the vector : -1 -100 0 -55 -99 -11 -9 1 2
Greatest number is vector is : 2

Q2 - You are given a n*n square matrix, you need to rotate the matrix by 90 degrees in
clockwise direction. You need to do it in-place i.e. you are not allowed to make a new
matrix and allocate the elements to it. Make the changes in the same matrix and print it.

n=3
arr[] = {{1,2,3}, {4,5,6}, {7,8,9}}
Output: {{7,4,1},{8,5,2},{9,6,3}}

*/
#include<iostream>
#include<vector>

using namespace std;
void rotate(vector<vector <int>> &v, int m , int n){
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            swap(v[i][j],v[j][i]);
        }
        
    }
    
    
}
int main(){
    int m,n;
    cout<<"Enter the number of rows for vector : ";
    cin>>m;
    cout<<"Enter the number of column for vector : ";
    cin>>n;
    vector<vector<int>> v(m,vector<int> (n));
    cout<<"Enter the vector : ";
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin>>v[i][j];
        }
        
    }
    rotate(v,m,n);
    cout<<"Vector are transpose is : ";
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout<<v[i][j]<<" ";
        }
        
    }
    return 0;
}




