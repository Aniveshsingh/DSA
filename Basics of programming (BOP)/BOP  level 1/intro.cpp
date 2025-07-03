#include<iostream>
using namespace std;

int main() {
    // newline character and endl 
    cout<<"hello \n world"<<endl;
    cout<<'\n';
    cout<<"hello world"<<endl;
    cout<<"hello world"<<'\n';
    cout<<"this is the end";    
    cout<<'\n';

    // Garbage value
    int num ;   
    cout<<num;   // GARBAGE VALUE : because we have not assigned any value to num
    cout<<'\n';

    int a ;
    // cout<<'size of a is : '<<sizeof(a)<<endl;  // gives a garbage vaue: because of single quotes '' it is a character literals we have to use string literals ""
    cout<<"size of a is : "<<sizeof(a)<<endl;

    char ch1 = -108;
    char ch2 = -107;
    cout << "Char for -108: " << ch1 << endl;  
    cout << "Char for -107: " << ch2 << endl;

    char ch = 'a';
    cout << "Character: " << ch << endl; 
    cout << "Character: " << int(ch) << endl; // int(ch) it works this way but it is not recommended to use this way bcz it is not a typecast operator, it calls constructor in classes  
    cout << "Character: " << (int)ch << endl; // this represent the ASCII value of the character , (int)ch is a type cast operator that converts the character to its ASCII value

    char ch5 = 65; // ASCII value of 'A'
    cout << "Character for 65: " << ch5 << endl; // prints 'A'
    
    // char ch2 = 'abcd'; 
    // cout << "Character for 'abcd': " << ch2 << endl; // warning: overflow in conversion from 'int' to 'char' changes value from '1633837924' to '100' [-Woverflow]

//     signed char ch3 = -191; // gives a warning: overflow in conversion from 'int' to 'signed char' changes value from '-191' to '65' [-Woverflow] meaning it is out of range for signed char
//     unsigned char ch4 = -191; // gives a warning: overflow in conversion from 'int' to 'unsigned char' changes value from '-191' to '65' [-Woverflow] meaning it is out of range for unsigned char
//    cout << "Character for unsigned -5: " << ch4 << endl;  // Prints 'A' (ASCII 65)
// cout << "Character for signed -5: " << ch3 << endl;    // Also prints 'A'

// In both cases, the value wraps via modulo and maps to the same ASCII character when printed
// This holds true only when printing as a char, not when casting to (int)gative value

    cout<< "Character for unsigned -5: " << (int)ch4 << endl; //prints 251
    cout<< "Character for signed -5: " << (int)ch3 << endl; //prints -5
    // but in this case where we are printing the integer value of the character, it will give different results positive for unsigned and negative for signed

    int var = -10;
    cout<< "Integer: " << var << endl; // by default it is signed i.e prints -10

    unsigned int uvar = -10; // unsigned int cannot hold negative values, it will wrap around goes under moduluo conversion
    cout<< "Unsigned Integer: " << uvar << endl; // prints a large positive value due to wrap around, it will take modulo of 2^32 and give the result
    return 0;
}