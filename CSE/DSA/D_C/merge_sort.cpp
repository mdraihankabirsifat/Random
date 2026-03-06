#include <iostream>
using namespace std;

// time complexity O(nlog(n))
//  Merge function to combine two sorted arrays
void merge(int arr[], int left, int mid, int right)
{

    int n1 = mid - left + 1; // n1=4
    int n2 = right - mid;    // n2=4
    int leftArr[n1], rightArr[n2];

    for (int i = 0; i < n1; i++)
    {
        leftArr[i] = arr[left + i]; // 3 4 6 8 9
    }
    for (int j = 0; j < n2; j++)
    {
        rightArr[j] = arr[mid + 1 + j]; // 1 2 5 7
    }

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2)
    {
        if (leftArr[i] <= rightArr[j]) // i=0, j=2, k=2
        {
            arr[k] = leftArr[i]; // arr[0]==1 ,arr[1]=2,, arr[2]=3
            k++;
            i++;
        }
        else
        {
            arr[k] = rightArr[j]; // arr[0]==1 ,arr[1]=2,
            k++;
            j++;
        }
    }

    while (i < n1)
    {
        arr[k++] = leftArr[i++];
    }
    while (j < n2)
    {
        arr[k++] = rightArr[j++];
    }
}

// Function to divide the array and call merge
void mergeSort(int arr[], int left, int right)
{
    if (left < right)
    {
        // divide
        int mid = left + (right - left) / 2; // left=0, right=7, mid=3
        mergeSort(arr, left, mid);           // Left half
        mergeSort(arr, mid + 1, right);      // Right half
        // merge
        merge(arr, left, mid, right); // Merge both halves
    }
}

// Function to print the array
void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main()
{
    int arr[] = {6, 4, 3, 8, 1, 5, 2, 7};
    int size = 8;

    cout << "Unsorted Array: ";
    printArray(arr, size);

    mergeSort(arr, 0, size - 1);

    cout << "Sorted Array: ";
    printArray(arr, size);

    return 0;
}