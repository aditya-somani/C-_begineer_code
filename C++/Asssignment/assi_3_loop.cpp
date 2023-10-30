/*
Did not got one question out of all and summary is written at the end of all question .** Q.8 ** 
Q1- Write a program to calculate factorial of a number.
#include<iostream>
using namespace std;
int main(){
    int n,m,a;
    cout<<"Enter the number : ";
    cin>>n;
    m=1;
    for (int i = n; i >= 1; i--)
    {
        
        m=m*i;
        
    }
    cout<<"Factorial of number is : "<<m;
    return 0;
}

Q2- Write a program to print all Armstrong numbers between two specified points.
#include<iostream>
#include<cmath>
using namespace std;
int number(int z){
    int a=0;
    while (z!=0)
    {
        z=z/10;
        a++;
    }
    return a;  
}
int main(){
    int a,b;
    cout<<"Enter starting point"<<endl;
    cin>>a;
    cout<<"Enter ending number"<<endl;
    cin>>b;
    cout<<"Armstrong Number between"<<a<<" and "<<b<< " is : "<<endl;
    for(int i=a; i<=b ;i++){
        int temp = i;
        int sum=0;
        while(temp!=0){
            int digit = temp%10;
            sum += pow(digit,number(i));
            temp = temp/10;
        }
        if (sum==i){
            cout<<i<<endl;
        }
    }
    return 0;
}
Q3- Write a program to find the sum of n natural number.
#include<iostream>
using namespace std;
int main(){
    int n,m;
    cout<<"Enter the number : ";
    cin>>n;
    m=0;
    for (int i = 0; i <= n; i++)
    {
        m=m+(n-i);
    }
    cout<<"Sum of number is : "<<m;
    return 0;
}
Q4 - Write a program to reverse a given integer number.
#include<iostream>
using namespace std;
int main(){
    int n,m;
    cout<<"Enter the number : ";
    cin>>n;
    cout<<"Reverse is : ";
    while (n>=1)
    {
        m= n%10;
        n=n/10;
        cout<<m;
    }
    return 0;
}
Q5 - Write a program to print the cross pattern given below (in the shape of X):
#include<iostream>
using namespace std;
int main(){
    int n;
    char a;
    cout<<"Enter pattern : ";
    cin>>a;
    cout<<"Enter the number of rows : ";
    cin>>n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j<=n; j++) {
            if (i==j || i+j==(n+1))
            {
                cout<<a;
            }
            else{
                cout<<" ";
            }

        }
        cout<<endl;
    }
    return 0;    
}
Q6- Write a program to print alphabet diamond pattern:

    A
   ABC
  ABCDE
 ABCDEFG
ABCDEFGHI
 ABCDEFG
  ABCDE
   ABC
    A

#include<iostream>
using namespace std;
int main(){
    int n,m;
    char a;
    cout<<"Enter the number of rows : ";
    cin>>n;
    for (int i = 1; i<=n ; i++ ) {
        for (int j=1 ; j<=(n-i);j++){
            cout<<" ";
        }
        for (int k =0 ; k< (2*i-1) ; k++){
            char q = (char)('A'+k);
            cout<<q;
        }
        cout<<endl;
    }
    for (int l= n-1 ; l>=1 ; l--){
        for (int a = 1 ; a<= n-l ; a++){
            cout<<" ";
        }
        for (int b = 0 ; b<(2*l-1)  ; b++){
            char p = (char)('A'+b);
            cout<<p;  
        }
        cout<<endl;
    }
    return 0;
}


Q9- Write a C++ program to check whether a Number can be expressed as a Sum of Two Prime Numbers.

#include <iostream>
using namespace std;
int main(){
    int n,m;
    cout<<"Enter number of rows : ";
    cin>>n;
    for (int i=0 ; i<n; i++){
        for (int j=0 ; j<n ; j++){
            if (n/2==i || n/2==j){
            cout<<"*";
        }
        else{
            cout<<" ";
        }
        }
        cout<<endl;
    }
    return 0;
}

#include<iostream>
using namespace std;
int isprime(int n){
    int flag=1;
    for (int i = 2; i <= n/2; i++)
    {
        if (n%i==0)
        {
            flag=0;
            break;
        }  
    }
    return flag;  
}
int main(){
    int n;
    cout<<"Enter the number of rows : ";
    cin>>n;
    for (int i = 2; i < n; i++)
    {
        
        if (isprime(i)==1)
        {
            if (isprime(n-i)==1)
            {
                cout<<"Yes "<<n<<" can be expressed as sum of "<<i<<" and "<<n-i;
                break; //So, that it gives only one output. For more than that just remove break
            }   
        }
        else{
            cout<<"Cn't be exepressed as sum of prime numbers ";
            break;
        }    
    }
    return 0;   
}
Output :-
Enter the number of rows : 100
Yes 100 can be expressed as sum of 3 and 97





Q8 - Write a C++ program to print a triangle of prime numbers upto given number of lines of the triangle.
->I did  not got this question even after trying and reading answer so understand it with some one help
Till today I don't how it is solved so I need to solve and understand it with open mind in the morning!

#include <iostream>
#include <cmath>

// Function to check if a number is prime
bool isPrime(int num) {
    if (num <= 1)
        return false;

    for (int i = 2; i <= sqrt(num); i++) {
        if (num % i == 0)
            return false;
    }

    return true;
}

// Function to print a triangle of prime numbers
void printPrimeTriangle(int lines) {
    int count = 0;
    int num = 2;

    for (int i = 1; i <= lines; i++) {
        for(int k=1;k<=lines-i;k++){ //added by me
            std::cout<<" ";          // by me
        }
        for (int j = 1; j <= i; j++) {
            while (!isPrime(num))
                num++;

            std::cout << num << " ";
            num++;
            count++;

            if (count >= lines)
                return;
        }

        std::cout << std::endl;
    }
}

// Main function
int main() {
    int numLines;
    std::cout << "Enter the number of lines for the prime number triangle: ";
    std::cin >> numLines;

    printPrimeTriangle(numLines * (numLines + 1) / 2);

    return 0;
}
Output:-
Enter the number of lines for the prime number triangle: 5
              2 
             3 5
            7 11 13 
           17 19 23 29
          31 37 41 43 47 
          
Q7- Write a program to print + pattern given below : plus 

  *  
  *
*****
  *
  *    
#include<iostream>
using namespace std;
int main(){
    int a;
    cout<<"Enter the number of rows : ";
    cin>>a;
    char b;
    cout<<"Enter the pattern you want to display : ";
    cin>>b;
    for (int i = 0; i < a; i++)
    {
        for (int j = 0; j < a; j++)
        {
            if (i==a/2 || j==a/2)
            {
                cout<<b;
            }
            else{
                cout<<" ";
            }
            
        }
        cout<<endl;
        
    }
    return 0;
}
Q10- Write a C++ program to print a rectangle out of *

#include<iostream>
using namespace std;
int main(){
    int a,b;
    cout<<"Enter the number of rows : ";
    cin>>a;
    cout<<"Enter the number of columns : ";
    cin>>b;
    char c;
    cout<<"Enter the symbol you want to display : ";
    cin>>c;
    cout<<"The rectangle is : "<<endl;
    for (int i = 0; i < a; i++)
    {
        for (int j = 0; j < b; j++)
        {
            cout<<c;
        }
        cout<<endl;
    }
    return 0;
}
Output:-
Enter the number of rows : 3
Enter the number of columns : 5
Enter the symbol you want to display : *
The rectangle is : 
*****
*****
*****

And with this I finished my last question of assignment 
So, now let's talk about the things that I learned while doing this assig.:-
-Don't look assign. as a baggage with you need to complete , look at it as an oppourtunity to improve your skills 
-Further , try to apply your mind and don't directly jump to internet for solution or hints
-And be consistent!! 

Thankss and have a great Day ahead!!

*/




















