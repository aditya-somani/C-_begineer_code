/*
Q1- Write a program which takes the values of length and breadth from user and check if it is a
square or not.
#include<iostream>
using namespace std;
int main(){
    int a,b;
    cout<<"Enter the length: "<<endl;
    cin>>a;
    cout<<"Enter the breadth: "<<endl;
    cin>>b;
    a==b ? cout<<"Yes , it is a square : "<<a*b<<endl : cout<<"No it is not a square"<<endl;
    return 0; 

}
Q. - Write a program to make greatest integer of any number input by user
#include <iostream>
using namespace std;
int main(){
    float a,b;
    cout<<"Enter the number"<<endl;
    cin>>a;
    if (a==int(a))
    {
        cout<<"Greatest integer of the number is : "<<a<<endl;
    }
    else{
        cout<<"Greatest integer of the number is : "<<int(a)<<endl;
    }
    return 0;
}
Q2- Write a program to print absolute value of a number entered by the user.
#include<iostream>
using namespace std;
int main(){
    int a,b;
    cout<<"Enter the number"<<endl;
    cin>>a;
    a>0 ? cout<<"Absolute value of function is : "<<a<<endl : cout<<"Absolute value of function is : "<<a*(-1)<<endl;
}
Q3- Write a program to take input from user for Cost Price (C.P.) and Selling Price (S.P.) and calculate
Profit or Loss.

#include<iostream>
using namespace std;
int main(){
    int a,b;
    cout<<"enter the selling price"<<endl;
    cin>>a;
    cout<<"enter the cost price"<<endl;
    cin>>b;
    a>b ? cout<<"Profit : "<<a-b<<endl : cout<<"loss : "<<b-a<<endl;
    return 0;

}
Q4- Write a program to print positive number entered by the user, if user enters a negative number,
it is skipped
#include<iostream>
using namespace std;
int main(){
    int a,b;
    cout<<"enter a number"<<endl;
    cin>>a;
    a>0 ? cout<<a<<endl : cout<<"Negative number , hence skipped"<<endl;
    return 0;
}Q5- Create a calculator using switch statement to perform addition,
subtraction, multiplication and division.

#include<iostream>
using namespace std;
int main(){
    int a,b;
    char c;
    cout<<"Enter First number : "<<endl;
    cin>>a;
    cout<<"Enter Second Number : "<<endl;
    cin>>b;
    cout<<"Ennter the operator sign (+,-,*,/) : "<<endl;
    cin>>c;
    switch (c)
    {
    case '+':
        cout<<"Sum : "<<a+b<<endl;
        break;
    case '-':
        cout<<"Difference : "<<a-b<<endl;
        break;
    case '*':
        cout<<"Product : "<<a*b<<endl;
        break;
    case '/':
        cout<<"Division : "<<a/b<<endl;
        break;
    default:
        cout<<"Invalid Operator"<<endl;
        break;
    }

}
Q6- Write a program to calculate marks to grades . Follow the conversion rule as given below :
#include<iostream>
using namespace std;
int main(){
    int a,b;
    cout<<"Enter the marks "<<endl;
    cin>>a;
    if (a>90){
        cout<<"Excellent Marks : "<<a<<endl;
    }
    else if (a>80)
    {
        
        cout<<"Very Good : "<<a<<endl;
    }
    else if (a>70)
    {
        cout<<"Good : "<<a<<endl;
        
    }
    else if (a>60)
    {
        
        cout<<"Average : "<<a<<endl;
    }
    else if (a>33)
    {
        cout<<"Pass : "<<a<<endl;
    }
    else {
        cout<<"Failed : "<<a<<endl;
    }
}*/






