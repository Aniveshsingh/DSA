#include<iostream>
using namespace std;    

int main() {
    // Bitwise AND
    int a = 5; // 0101
    int b = 3; // 0011
    cout << "Bitwise AND: " << (a & b) << endl; // 0001 => 1

    // Bitwise OR
    cout << "Bitwise OR: " << (a | b) << endl; // 0111 => 7

    // Bitwise NOT
    cout << "Bitwise NOT of a: " << (~a) << endl; // Inverts bits of a

    // Bitwise XOR
    cout << "Bitwise XOR: " << (a ^ b) << endl; // 0110 => 6

    // Left Shift
    cout << "Left Shift of a by 2: " << (a << 2) << endl; // 10100 => 20

    // Right Shift
    cout << "Right Shift of a by 2: " << (a >> 2) << endl; // 0001 => 1


    cout<<(a << -1); // kisi bhi number ko left shift kro -ve number se toh uss case mein GARBAGE VALUE MILTI HAI 
    return 0;
}