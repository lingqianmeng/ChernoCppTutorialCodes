#include <iostream>

/*
* Demonstrate how to build up and delete TWO dimentional array.
*/

int main()
{
    // pointer of 50 pointers to integer 
    int** arr2d = new int* [50];
    for (int i = 0; i < 50; i++)
        arr2d[i] = new int[50]; // each pointer references one integer array
    arr2d[0][0] = 0;
    arr2d[0][1] = 0;
    arr2d[0][2] = 0;
    std::cin.get();

    // How To Delete TWO Dimentional Array:
    for (int i = 0; i < 50; i++) // 1. Delete all integer arrays
        delete[] arr2d[i];
    detelte[] arr2d;            // 2. Delete all pointers pointed to all this arrays
}
