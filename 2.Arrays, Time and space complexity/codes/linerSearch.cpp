 #include <iostream>
using namespace std;
 int main (){ 
    int arr[] = {2,4,6,8,10,12};
    int target= 10;
    int size = sizeof(arr)/4;

    for (int i = 0; i<size; i++){
        if(arr[i] == target){
            cout<<"target found at index: " << i<< endl;
            break;
        }
        else {
            cout<< "target not found at index: " << i << endl;
        }
    }
    // in the above code it will print the else again and again how to know ki loop ke bahar target nhi mila ??

    // loops se bhr aa gye but kaise pta chlega ki target nahi mila
    // HERE COMES THE CONCEPT OF FLAG VARIABLE

    int arr[] = {2,4,6,8,10,12};
    int target= 10;
    int size = sizeof(arr)/4; // size of array
    bool flag = 0;
    // 0 --> not found
    // 1 --> found

    for (int i = 0; i<size; i++){
        if(arr[i] == target){
            flag = 1;
            break;
        }
    }

    if(flag == 0){
        cout << "Target not found in the array." << endl;
    }
    else {
        cout << "Target found in the array." << endl;
    }
    return 0;
}