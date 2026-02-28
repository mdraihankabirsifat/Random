#include <iostream>
#include <vector>
using namespace std;

int countFreq(vector<int> &arr, int candidate, int low, int high)
{
    int count = 0;
    for (int i = low; i <= high; i++)
    {
        if (arr[i] == candidate)
            count++;
    }
    return count;
}

int majorityElement(vector<int> &arr, int low, int high)
{
    // Base case
    if (low == high)
        return arr[low];

    int mid = low + (high - low) / 2;

    // Divide
    int leftMajor = majorityElement(arr, low, mid);
    int rightMajor = majorityElement(arr, mid + 1, high);

    // Conquer
    if (leftMajor == rightMajor)
        return leftMajor;

    int leftCount = countFreq(arr, leftMajor, low, high);
    int rightCount = countFreq(arr, rightMajor, low, high);

    return (leftCount > rightCount) ? leftMajor : rightMajor;
}

int main()
{
    vector<int> arr = {2, 2, 1, 1, 1, 2, 2};
    int n = arr.size();
    cout << "Majority Element: " << majorityElement(arr, 0, n - 1);
    return 0;
}