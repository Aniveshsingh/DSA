#include<iostream>
using namespace std;

int main() {
    // conditionals
    // i/p ==> num , o/p ==> check even  or odd 
    int num = 8;
     if (num % 2 == 0 ) cout << "Even" << endl;  // why == not = ?
     else cout << "Odd" << endl;

     // i/p ==> num , o/p ==> check +ve, -ve or zero 

     // loops 
     // print 11 times your name
     for(int i = 1; i<=11; i++) {
        cout<<"Anivesh"<<endl;
     }


     // print 19 table
     for (int i = 1; i<=10; i++) {
        cout<<"19 * " << i<< " = " << 19*i << endl;
     }

     // 1 to 100 print even no 
    //  for (int i = 0; i<=100; i++){
    //     if(i%2 == 0) {
    //         cout<<i<<endl;
    //     }
    //  }


        // Nested loops 
        for (int i = 1; i<= 3; i++){
            cout<<"Outer loop iteration: " << i << endl;
            cout<<'\n';
            for (int j = 1; j<=4; j++){
                cout<<" Inner loop iteration: " << j << endl;
            }
            cout<<'\n';

        }

        
    return 0 ;
}