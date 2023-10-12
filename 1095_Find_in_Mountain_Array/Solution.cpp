#include "Solution.hpp" // header in local directory

using namespace leetcode;
using namespace std;

pair<int,int> Solution::findMaximum(MountainArray &mountainArr, int low, int high) {
    if (low == high)
        return make_pair(mountainArr.get(high), high);
    int mid = low + (high - low) / 2;
    int getatmid = mountainArr.get(mid);
    int getprevious = mid > 0 ? mountainArr.get(mid - 1) : -1;
    int getnext = mid > mountainArr.length()- 1 ? -1 : mountainArr.get(mid + 1);

    if (getatmid > getprevious && getatmid > getnext)
        return make_pair(getatmid, mid);
    else if (getatmid < getnext)
        return findMaximum(mountainArr, mid + 1, high);
    else
        return findMaximum(mountainArr, low, mid - 1);
}

int Solution::binarySearch(MountainArray &mountainArr, int low, int high, int target, bool ascending) {
    if (high >= low) {
        int mid = low + (high - low) / 2;
        int getatmid = mountainArr.get(mid);

        if (getatmid == target)
            return mid;

        if(ascending) {
            if (getatmid > target)
                return binarySearch(mountainArr, low, mid - 1, target, ascending);

            return binarySearch(mountainArr, mid + 1, high, target, ascending);
        }
        else {
            if (getatmid < target)
                return binarySearch(mountainArr, low, mid - 1, target, ascending);

            return binarySearch(mountainArr, mid + 1, high, target, ascending);
        }
            
    }
    return -1;
}

int Solution::findInMountainArray(int target, MountainArray &mountainArr) {
    pair<int,int> max = findMaximum(mountainArr, 0, mountainArr.length() - 1);
    if(target > max.first) return -1;
    if (target == max.first) return max.second;
    int found = binarySearch(mountainArr, 0, max.second, target, true);
    if(found != -1) return found;
    else return binarySearch(mountainArr, max.second, mountainArr.length() - 1, target, false);
}