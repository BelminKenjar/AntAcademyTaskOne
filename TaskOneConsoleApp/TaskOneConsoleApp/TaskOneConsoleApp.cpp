#include <iostream>
using namespace std;

struct MyStruct {
    int id;
    int value;
};

int findNextID(MyStruct arr[], int arrSize) {
    int nextID = 1;
    // Iterate through my array of structs. 
    for (int i = 0; i < arrSize; i++)
    {
        // Look for lowest possible ID that isn't used and reset iteration in case IDs aren't ordered by ascending values.
        if (arr[i].id == nextID)
        {
            nextID++;
            i = -1;
        }
    }
    return nextID;
}

bool hasIntegerTwice(MyStruct arr[], int & doubleIntegerValue, int arrSize) {
    // Check my array of structs values against every value in the array
    for (int i = 0; i < arrSize; i++) {
        for (int j = 0; j < arrSize; j++) {
            // If I find a value that appears twice, check if it's lower than previous double value in array and set it to my referenced doubleIntegerValue
            if (i != j && arr[i].value == arr[j].value && doubleIntegerValue > arr[j].value)
            {
                doubleIntegerValue = arr[j].value;
                break;
            }
        }
    }
    //If doubleIntegerValue has changed, it means we found a double value in array and return true
    if (doubleIntegerValue < INT_MAX) return true;
    // No value in array appears twice
    return false;
}

int findNextPositiveInteger(MyStruct arr[], int minimalValue, int arrSize) {
    // Integer for my new struct needs to be higher than the value that appears twice in array
    int nextInteger = minimalValue;
    if (minimalValue < 1)
    {
       nextInteger = 1;
    }
    for (int i = 0; i < arrSize; i++)
    {
        // Find next lowest unused value in array of structs
        if (arr[i].value == nextInteger)
        {
            nextInteger++;
            i = -1;
        }
    }
    return nextInteger;
}

// Function that uses the other functions I made to generate a new struct with specific values
MyStruct createNewStruct(MyStruct arr[], int minimalValue, int arrSize) {
    int nextID = findNextID(arr, arrSize);
    int nextValue = findNextPositiveInteger(arr, minimalValue, arrSize);
    MyStruct newStruct = { nextID, nextValue };
    return newStruct;
}

int main()
{
    //example arrays used for testing different cases that might cause errors, please comment all arrays that aren't being used!
        //array to test case with multiple instances of duplicate values
        MyStruct arr[] = {
            {6, 1},
            {1, 6},
            {4, 6},
            {2, 9},
            {3, 4},
            {5, 4},
            {7, 8},
            {8, 2},
            {9, 2},
        };

        //array to test case with negative values and double digit values
        /*MyStruct arr[] = {
            {1, -1},
            {2, -1},
            {3, 10},
            {4, 10},
            {5, 20},
            {6, 30},
            {7, 40},
            {8, 40},
            {9, 100},
            {10, 2},
        };*/

        // array to test case with no duplicate values
        /*MyStruct arr[] = {
            {6, 1},
            {1, 2},
            {4, 3},
            {2, 4},
            {3, 5},
            {5, 6},
            {7, 7},
            {8, 8},
            {9, 9},
        };*/

    //Get length of array of structs for usage in functions
    int arrSize = sizeof(arr) / sizeof(arr[0]);

    //Max integer value which will get reduced to lowest integer that appears twice in array
    int doubleIntegerValue = INT_MAX;
    //Print my array of structs in console
    for (int i = 0; i < sizeof(arr)/sizeof(arr[0]); i++)
    {
        cout << "{ " << "ID: " << arr[i].id << ", " << "Value: " << arr[i].value << " }" << endl;
        cout << "--------------------\n";
    }

    // Functions will not execute if array of structs do not have a value that appears twice
    if (hasIntegerTwice(arr, doubleIntegerValue, arrSize))
    {
        //Print info about lowest value that occurs twice in array
        cout << "Lowest value that occurs twice: " << doubleIntegerValue << "\n" << endl;

        //Create new struct with specific values and print it
        MyStruct newStruct = createNewStruct(arr, doubleIntegerValue, arrSize);
        cout << "New struct: " << "{ " <<"ID: "<< newStruct.id << ", " << "Value: " << newStruct.value << " }" << endl;
    }
    else {
        cout << "Struct array does not contain value that appears twice!" << endl;
    }
    return 0;
}
