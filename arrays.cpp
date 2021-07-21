

// DO NOT MODIFY THESE NEXT 6 LINES - DO NOT ADD TO THEM
#include <iostream> // for cout, cin
#include <fstream>  // for ifstream
#include <cstdlib>  // for exit
using namespace std;
#include "headers.h"    // contains the function declarations
#include "constants.h"  // contains 4 global variables

int main( )
{
    // DO NOT MODIFY THESE NEXT 3 LINES - DO NOT ADD TO THEM
    ifstream ifs;
    int size = MAXSIZE, array[MAXSIZE];
    getArray(ifs, FILENAME, array, size);


    // hints for the tasks: 
    // all that needs to be in here is simple calls the functions, like these: 
    // in addition to, some print to std.out statements.
    // 
    // Your main() will ideally look clean and uncluttered and be made up
    // mostly of function calls.
    // 
    // Example:
    // ...
    // printArray(array, size);
    // max = maxArray(array, size);
    // min = minArray(array, size);
    // ...
    // ...etc...
    

    // PUT MISSING CODE HERE
    print_array(array, size);
    int max = maxArray(array, size);
    int min = minArray(array, size);
    int sum = sumArray(array, size);
    std::cout<<"Max = "<<max<<std::endl;
    std::cout<<"Min = "<<min<<std::endl;
    std::cout<<"Sum = "<<sum<<std::endl;
    evensArray(array,size);
    primesArray(array,size);
    AllSearches(array, size);

    return 0;
}

// PUT MISSING FUNCTION DEFINITIONS HERE
void print_array(int arr[], int asize)
{
    for (int i = 0; i!=asize; ++i)
    {
        std::cout<<arr[i];
        if (i == asize-1)
        {
            break;
        }
        std::cout<<", ";
    }
    std::cout<<endl;
}
// Pre-Condition: takes in an integer array and its size.
// Post-Condition: prints all elements in the array.

int maxArray(int arr[], int asize)
{
    int max = arr[0];
    for (int i = 1; i!=asize; ++i)
    {
        if (arr[i] >= max)
        {
            max = arr[i];
        }
    }
    return max;
}
// Pre-Condition: takes in an integer array and its size.
// Post-Condition: returns the maximum number in the array.

int minArray(int arr[], int asize)
{
    int min = arr[0];
    for (int i = 1; i!=asize; ++i)
    {
        if (arr[i] <= min)
        {
            min = arr[i];
        }
    }
    return min;
}
// Pre-Condition: takes in an integer array and its size.
// Post-Condition: returns the minimum number in the array.

int sumArray(int arr[], int asize)
{
    int sum = 0;
    for (int i = 0; i!=asize; ++i)
    {
        sum+=arr[i];
    }
    return sum;
}
// Pre-Condition: takes in an integer array and its size.
// Post-Condition: returns the sum of the array.

void evensArray(int arr[], int asize)
{
    std::cout<<"Evens: ";
    for (int i = 0; i!=asize; ++i)
    {
        if (arr[i]%2==0)
        {
            std::cout<<arr[i]<<", ";
        }

        if (i == asize-1)
        {
        }
    }
            std::cout<<"end"<<std::endl;
}
// Pre-Condition: takes in an integer array and its size.
// Post-Condition: prints all the even numbers in the array.

void primesArray(int arr[], int asize)
{
    std::cout<<"Primes: ";
    for (int i = 0; i!= asize; ++i)
    {
        int temp = arr[i];
        if (temp <= 0)
        {
            temp *= -1;
            continue;
        }
        bool is_prime = true;
        if (temp < 2)
        {
            is_prime = false;
        }
        for (int j = 2; j<=temp-1; ++j)
        {               
            if (temp % j == 0)
            {
                is_prime = false;
            }
        }
        if (is_prime)
        {
            std::cout<<arr[i]<<", ";
        }
        if (i == asize-1)
        {
        }
    }
            std::cout<<"end"<<std::endl;
}
// Pre-Condition: takes in an integer array and its size
// Post-Condition: prints all the prime numbers in the array.

int SeqSearch(int arr[], int array_size, int target)
{
    for (int i = 0; i!=array_size; ++i)
    {
        if (arr[i] == target)
        {
            return i;
        }
    }
    return -1;
}
// Pre-Condition: takes in an integer array, its size, and an int target.
//                  This function must be called within AllSearches().
// Post-Condition: if the function finds "target", it returns its index in the array, otherwise it returns -1.
//                  the function only takes ONE integer (at a time) when searching.

void AllSearches(int array[], int array_size)
{
    std::cout<<"Searches:"<<std::endl;
    for (int i = 0; i!=NSEARCHES; ++i)
    {
        int pos = SeqSearch(array, array_size, SEARCHES[i]);
        std::cout<<"Looking for "<<SEARCHES[i]<<". ";
        if (pos!=-1)
        {
            std::cout<<"Found at index: "<<pos<<std::endl;
        }
        else{
            std::cout<<"Not Found!"<<std::endl;
        }
    }
}

