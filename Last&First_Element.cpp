// WAP to find the first and last position of an element in sorted array.

#include <iostream>
using namespace std;

void bubbleSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main()
{
    int n;
    cout << "Enter the Size of array: ";
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cout << "Enter the Element " << i << ": ";
        cin >> arr[i];
    }

    bubbleSort(arr, n);

    int element;
    cout << "Enter the Element value to find its positions: ";
    cin >> element;

    int first = -1;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == element)
        {
            first = i;
            break;
        }
    }

    if (first == -1)
    {
        cout << "Element not found, returning [-1, -1]." << endl;
        cout << "[-1, -1]" << endl;
    }
    else
    {
        int last = first;
        for (int i = first; i < n; i++)
        {
            if (arr[i] == element)
            {
                last = i;
            }
            else
            {
                break;
            }
        }

        cout << "First and Last positions of " << element << " are: [" << first << ", " << last << "]" << endl;
    }

    return 0;
}
