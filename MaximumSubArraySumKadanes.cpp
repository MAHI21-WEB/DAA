#include <iostream>
#include <climits>
using namespace std;

int main()
{
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];

    int maxSum = INT_MIN;
    int currSum = 0;

    for (int i = 0; i < n; i++)
    {
        currSum = currSum + a[i];

        if (currSum > maxSum)
            maxSum = currSum;

        if (currSum < 0)
            currSum = 0;
    }

    cout << maxSum;

    return 0;
}












#include <bits/stdc++.h>
using namespace std;


int maxCrossingSum(int a[], int l, int m, int r) {
    int sum = 0;
    int leftSum = INT_MIN;

    
    for (int i = m; i >= l; i--) {
        sum += a[i];
        leftSum = max(leftSum, sum);
    }

    sum = 0;
    int rightSum = INT_MIN;

    
    for (int i = m + 1; i <= r; i++) {
        sum += a[i];
        rightSum = max(rightSum, sum);
    }

    return leftSum + rightSum;
}


int maxSubArraySum(int a[], int l, int r) {

    if (l == r)
        return a[l];

    int m = l + (r - l) / 2;

   
    return max({
        maxSubArraySum(a, l, m),
        maxSubArraySum(a, m + 1, r),
        maxCrossingSum(a, l, m, r)
    });
}

int main() {
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];
    cout<<maxSubArraySum(a,0,n-1);

    return 0;
}


