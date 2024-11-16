#include <iostream>
using namespace std;

void findPairWithSum(int arr[], int size, int target)
{
    int left = 0;
    int right = size - 1;

    while (left < right)
    {
        int current_sum = arr[left] + arr[right];
        if (current_sum == target)
        {
            cout << "Pair found: " << arr[left] << ", " << arr[right] << endl;
            return;
        }
        else if (current_sum < target)
        {
            left++;
        }
        else
        {
            right--;
        }
    }
    cout << "No pair found." << endl;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target = 9;

    findPairWithSum(arr, size, target);

    return 0;
}
