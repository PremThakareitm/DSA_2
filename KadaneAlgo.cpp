#include <iostream>
using namespace std;

int kadanesAlgorithm(int arr[], int size)
{
    int max_so_far = arr[0];
    int max_ending_here = arr[0];

    for (int i = 1; i < size; ++i)
    {
        max_ending_here = (arr[i] > max_ending_here + arr[i]) ? arr[i] : max_ending_here + arr[i];
        max_so_far = (max_so_far > max_ending_here) ? max_so_far : max_ending_here;
    }

    return max_so_far;
}

int main()
{
    int nums1[] = {5, 4, -1, 7, 8};
    int size1 = sizeof(nums1) / sizeof(nums1[0]);
    cout << "Maximum subarray sum for nums1: " << kadanesAlgorithm(nums1, size1) << endl; 

    int nums2[] = {1};
    int size2 = sizeof(nums2) / sizeof(nums2[0]);
    cout << "Maximum subarray sum for nums2: " << kadanesAlgorithm(nums2, size2) << endl; 

    int nums3[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int size3 = sizeof(nums3) / sizeof(nums3[0]);
    cout << "Maximum subarray sum for nums3: " << kadanesAlgorithm(nums3, size3) << endl; 

    return 0;
}
