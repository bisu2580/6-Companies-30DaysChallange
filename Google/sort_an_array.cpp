#include <bits/stdc++.h>
using namespace std;
class Solution
{
private:
    void merge(vector<int> &arr, int left, int mid, int right)
    {

        int firstArray = mid - left + 1;
        int secondArray = right - mid;

        vector<int> leftArray;
        vector<int> rightArray;

        for (auto i = 0; i < firstArray; i++)
        {
            leftArray.push_back(arr[left + i]);
        }
        for (auto i = 0; i < secondArray; i++)
        {
            rightArray.push_back(arr[mid + 1 + i]);
        }

        int firstIndex = 0, secondIndex = 0, mergeIndex = left;
        while (firstIndex < firstArray && secondIndex < secondArray)
        {
            if (leftArray[firstIndex] <= rightArray[secondIndex])
            {
                arr[mergeIndex] = leftArray[firstIndex];
                firstIndex++;
            }
            else
            {
                arr[mergeIndex] = rightArray[secondIndex];
                secondIndex++;
            }
            mergeIndex++;
        }

        while (firstIndex < firstArray)
        {
            arr[mergeIndex] = leftArray[firstIndex];
            firstIndex++;
            mergeIndex++;
        }

        while (secondIndex < secondArray)
        {
            arr[mergeIndex] = rightArray[secondIndex];
            secondIndex++;
            mergeIndex++;
        }
    }
    void mergeSort(vector<int> &arr, int left, int right)
    {
        if (left >= right)
        {
            return;
        }
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }

public:
    vector<int> sortArray(vector<int> &nums)
    {
        mergeSort(nums, 0, nums.size() - 1);
        return nums;
    }
};
int main()
{
    vector<int> nums = {3, 7, 1, 9, 4, 6};
    Solution s;
    nums = s.sortArray(nums);
    cout << "Sorted Array: \n";
    for (auto i : nums)
    {
        cout << i << " ";
    }
}