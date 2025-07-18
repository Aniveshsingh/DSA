#include<iostream>
using namespace std;

int maxofthree(int num1, int num2, int num3){
    if (num1>=num2 && num1>=num3) return num1;
   else if (num2>=num3 && num2>=num3) return num2;
    else return num3;
}  // brute force
 
int max(int num1, int num2, int num3) {
    int ans1 = max(num1, num2);
    int final_ans = max(ans1, num3);
    return final_ans;
} // inbuilt max function

void CountingtoN (int n) {
    for (int i=1; i<=n; i++) {
        cout<< i<< endl;
    }
}

bool checkPrime (int n) {
for (int i = 2; i<=(n-1); i++){
    if (n%i == 0){
        return false;
    }
}
if(n=1) return false;

return true;
}

void checkEvenOdd (int n) {
    if ((n & 1) == 0) cout<<"Even";
    else cout<<"odd";
}

void sumOfAllEven (int n) {
    int sum = 0;
    for (int i = 1; i<=n; i++){
        if((i&1) == 0) sum = sum + i;
     }
     cout<<"total sum is :"<< sum;
}
int main() {

//   int ans = max(10,5,9) ;
//   cout<<ans;

// CountingtoN(5);
// bool prime = checkPrime(1);
// if (prime) cout<<"its a prime number";
// else cout<<"it is not a prime number";

checkEvenOdd(2305);
sumOfAllEven(10);
    return 0 ;
}