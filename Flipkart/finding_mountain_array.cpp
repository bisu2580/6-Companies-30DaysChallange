#include <bits/stdc++.h>
using namespace std;
class MountainArray
{
public:
    vector<int> num = {1, 2, 3, 4, 5, 3, 1};
    int get(int index)
    {
        return num[index];
    }
    int length()
    {
        return num.size();
    }
};

class Solution
{
private:
    int peakIndex(MountainArray &mountainArr)
    {
        int s = 0;
        int e = mountainArr.length() - 1;
        int mid = s + (e - s) / 2;
        while (s < e)
        {
            if (mountainArr.get(mid) < mountainArr.get(mid + 1))
            {
                s = mid + 1;
            }
            else
            {
                e = mid;
            }
            mid = s + (e - s) / 2;
        }
        return s;
    }
    int search(int target, MountainArray &mountainArr, int s, int e)
    {
        int mid = s + (e - s) / 2;
        bool isIncreasing = mountainArr.get(s) < mountainArr.get(e);
        while (s <= e)
        {
            if (target == mountainArr.get(mid))
            {
                return mid;
            }
            if (isIncreasing)
            {
                if (target > mountainArr.get(mid))
                {
                    s = mid + 1;
                }
                else
                {
                    e = mid - 1;
                }
            }
            else
            {
                if (target < mountainArr.get(mid))
                {
                    s = mid + 1;
                }
                else
                {
                    e = mid - 1;
                }
            }
            mid = s + (e - s) / 2;
        }
        return -1;
    }

public:
    int findInMountainArray(int target, MountainArray &mountainArr)
    {
        int peak = peakIndex(mountainArr);
        int firstOcc = search(target, mountainArr, 0, peak);
        if (firstOcc != -1)
        {
            return firstOcc;
        }

        return search(target, mountainArr, peak + 1, mountainArr.length() - 1);
    }
};
int main()
{
    Solution s;
    MountainArray m;
    cout << "Minimum index: " << s.findInMountainArray(3, m);
}