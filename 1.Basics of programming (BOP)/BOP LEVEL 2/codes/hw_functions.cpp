#include<iostream>

using namespace std;

// if we have to check whether a number suppose 11 is prime or not
// we will check whether it is divisible by any number from 2 to 10 leaving 1 and itself i.e 11
// if it is divisible by any number then it is not prime else it is prime
bool checkPrime (int n) {
for (int i = 2; i<=(n-1); i++){
    if (n%i == 0){
        return false;
    }
}
if(n==1) return false;

return true;
}

void printPrime(int n) {
    for (int i=2; i<=n; i++){
           if(checkPrime(i)) {
            cout<<i;}
    } 
}

void Factorial(int n) {
    int multiply = 1;
    for (int i = n; i>1; i--) {
        multiply = multiply * i ;
    }
    cout<<"factorial of "<<n<<"is"<< multiply;
}

void makeInteger(int n) {
    int num=0;
     for (int i=0; i<n; i++){
        int digit ;
        cout<<"Enter the digit :"<<endl;
        cin>>digit;
        num = num *10 + digit;
    }
    cout<<num;
}




int main() {

    // printPrime(11);
    // Factorial(10);

    int n ;
    cout<<"enter the number of digits you wanna enter"<<endl;
    cin>>n;
    makeInteger(n);
    return 0;
}