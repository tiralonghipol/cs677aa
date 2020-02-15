#include <iostream>
using namespace std;
#define SIZE 11

int getMaxIndex(int arr[], int size)
{
    if (size == 1)
        return 0;

    int recMaxIndex = getMaxIndex(arr, size - 1);
    if (arr[recMaxIndex] < arr[size - 1])
        return size - 1;
    else
        return recMaxIndex;
}

void print_vector(int a[])
{
    for (int i = 0; i < SIZE; i++)
        cout << a[i] << ", ";
}

int main()
{
    int a[SIZE] = {1, 4, 9, 3, 4, 9, 5, 6, 9, 3, 7};
    int max = getMaxIndex(a, SIZE - 1);
    cout << "Index of max element of vector { ";
    print_vector(a);
    cout << " }"
         << " is " << max + 1 << endl;
    return 0;
}