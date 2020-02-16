#include <bits/stdc++.h>
using namespace std;
#define SIZE 11

void print_array(int a[])
{
    for (int i = 0; i < SIZE; i++)
        cout << a[i] << " ";
}

void reverse(int arr[], int l, int r)
{
    if (l < r)
    {
        swap(arr[l], arr[r]);
        reverse(arr, ++l, --r);
    }
}

void merge(int arr[], int l, int m, int r)
{
    int i = l;
    int j = m + 1;

    while (i <= m && arr[i] < 0)
        i++;

    while (j <= r && arr[j] < 0)
        j++;

    reverse(arr, i, m);
    reverse(arr, m + 1, j - 1);
    reverse(arr, i, j - 1);
}

void rearrange_pos_neg(int arr[], int l, int r)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;
        rearrange_pos_neg(arr, l, m);
        rearrange_pos_neg(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

int main()
{
    int a[SIZE] = {4, -3, 9, 8, 7, -4, -2, -1, 0, 6, -5};
    cout << "Before: { ";
    print_array(a);
    cout << " }" << endl;
    rearrange_pos_neg(a, 0, SIZE - 1);
    cout << "After: { ";
    print_array(a);
    cout << " }" << endl;
    return 0;
}