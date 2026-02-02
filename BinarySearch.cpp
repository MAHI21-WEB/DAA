#include <iostream>
using namespace std;

int binarySearchIterative(int a[], int n, int key)
{
    int l = 0, r = n - 1;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (a[mid] == key) return mid;
        else if (a[mid] < key) l = mid + 1;
        else r = mid - 1;
    }
    return -1;
}

int binarySearchRecursive(int a[], int l, int r, int key)
{
    if (l > r) return -1;
    int mid = (l + r) / 2;

    if (a[mid] == key) return mid;
    else if (a[mid] < key)
        return binarySearchRecursive(a, mid + 1, r, key);
    else
        return binarySearchRecursive(a, l, mid - 1, key);
}

int main()
{
    int n, key;
    cout << "Enter number of elements: ";
    cin >> n;

    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];

   
    cin >> key;

    int pos1 = binarySearchIterative(a, n, key);
    int pos2 = binarySearchRecursive(a, 0, n - 1, key);

    cout << "Iterative Result: " << pos1 << endl;
    cout << "Recursive Result: " << pos2 << endl;

    return 0;
}


