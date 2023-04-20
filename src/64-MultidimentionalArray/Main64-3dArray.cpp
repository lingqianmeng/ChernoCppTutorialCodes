#include <iostream>

/*
* Demonstrate how to build up and delete THREE dimentional array.
*/

int main()
{
    // pointer of pointers of pointers to integer 
    int*** arr3d = new int** [50];

    // Method 1:
    for (int i = 0; i < 50; i++)
    {
        arr3d[i] = new int* [50]; // 1/50 pointer points to 50 pointers
        for (int j = 0; j < 50; j++)
            arr3d[i][j] = new int[50]; // 1/50 pointer points to an integer array.
    }

    // Method 2: 
    for (int i = 0; i < 50; i++)
    {
        arr3d[i] = new int* [50]; // 1/50 pointer points to 50 pointers
        int** arr2d = new int* [50];
        for (int j = 0; j < 50; j++)
        {
            arr2d[j] = new int[50]; // 1/50 pointer points to an integer array.
        }
    }

    // so totoal 50*50 pointers and 50*50*50 elements in this 3d array. 

    arr3d[0][0][0] = 0;
    arr3d[0][0][1] = 0;
    arr3d[0][0][2] = 0;

    // HOW To Delete THREE Dimentional Array:
    for (int i = 0; i < 50; i++)
    {
        for (int j = 0; j < 50; j++)
            delete[] arr3d[i][j]; // 1. delete the integer array
        delete[] arr3d[i]; // 2. delete pointers array pointed to the integer array
    }
    delete[] arr3d;// 3. finally delete pointers array pointed to the pointers array


    std::cin.get();
}
