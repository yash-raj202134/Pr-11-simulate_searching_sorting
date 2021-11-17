/*A program to simulate the various searching and sorting algorithms and
compare their timings of a list of 1000 elements.*/
#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;
void linearSearch(int arr[], int n, int key)
{
    clock_t start = clock();
    int flag = 1;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == key)
        {
            cout << "Element found at index :" << i;
            cout << endl;
            flag = 0;
            break;
        }
    }
    if (flag == 1)
        cout << "No result found for " << key;

    cout << fixed << "\nExecution time of Linear Search: " << float(clock() - start) / CLOCKS_PER_SEC << endl;
}
void binarySearch(int arr[], int left, int right, int key)
{
    clock_t start = clock();
    int flag = 1;
    while (left <= right)
    {
        int mid = left + ((right - left) / 2);

        if (arr[mid] == key)
        {
            cout << "Element found at index : " << mid;
            flag = 0;
            break;
        }
        if (arr[mid] < key)
            left = mid + 1;
        else
            right = mid - 1;
    }
    if (flag == 1)
        cout << "No result found for " << key;

    cout << fixed << "\nExecution time of Binary Search: " << float(clock() - start) / CLOCKS_PER_SEC << endl;
}
void swap(int &x, int &y)
{
    int temp = x;
    x = y;
    y = temp;
}

int bubbleSort(int arr[], int n)
{
    clock_t start = clock();
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);
        }
    }
    cout << fixed << "\nExecution time of Bubble Sort: " << float(clock() - start) / CLOCKS_PER_SEC << endl;
    return 0;
}

int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}
void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int partition_index = partition(arr, low, high);
        quickSort(arr, low, partition_index - 1);
        quickSort(arr, partition_index + 1, high);
    }
}
void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}
int main()
{
    int size = 1000;
    int *Arr = (int *)malloc(size * sizeof(int));
    for (int i = 0; i < size; i++)
        Arr[i] = i * 2;

    int *Arr2 = (int *)malloc(size * sizeof(int));
    for (int i = 0; i < size; i++)
        Arr2[i] = rand() % 365;

    cout << "\n......For Searching comparision......\n Array[1000]:\n"; // Searching comparision..
    printArray(Arr, size);
    linearSearch(Arr, size, 1998);
    binarySearch(Arr, 0, 999, 1998);

    cout << "\n......For Sorting comparision......\nRandom Array[1000]:\n"; // Sorting comparision..
    printArray(Arr2, size);
    bubbleSort(Arr2, size);
    clock_t start = clock();
    quickSort(Arr2, 0, 999);
    cout << fixed << "\nExecution time of Quick Sort: " << float(clock() - start) / CLOCKS_PER_SEC << endl;

    return 0;
}