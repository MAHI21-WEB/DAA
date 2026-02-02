#include <iostream>
using namespace std;

void merge(int a[], int l, int m, int r)
{
    int i = l, j = m + 1, k = 0;
    int temp[r - l + 1];

    while (i <= m && j <= r)
    {
        if (a[i] < a[j]) temp[k++] = a[i++];
        else temp[k++] = a[j++];
    }

    while (i <= m) temp[k++] = a[i++];
    while (j <= r) temp[k++] = a[j++];

    for (int i = l, x = 0; i <= r; i++, x++)
        a[i] = temp[x];
}

void mergeSort(int a[], int l, int r)
{
    if (l < r)
    {
        int m = (l + r) / 2;
        mergeSort(a, l, m);
        mergeSort(a, m + 1, r);
        merge(a, l, m, r);
    }
}



int main()
{
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    int a[n];
    cout << "Enter array:\n";
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    mergeSort(a, 0, n - 1);

    cout << "Merge Sort:\n";
    for (int i = 0; i < n; i++) cout << a[i] << " ";



    return 0;
}



//Iterative
void mergeSort(int a[], int l, int r)
{
    int n=r-l+1;
    for(int i=1;i<n;i++)
    {
        for(int l=0;l<n-1;l+=2*i)
        {
            int m=min(l+i-1,n-1);
            int r=min(l+(2*i)-1,n-1);
            merge(a, l , m ,r);
        }
    }
}

