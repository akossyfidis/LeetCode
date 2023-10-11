#include "Solution.hpp" // header in local directory

using namespace leetcode;
using namespace std;

vector<int> Solution::fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        vector<int> start(flowers.size(),0), end(flowers.size(),0);
        int count = 0;
        for (auto& f : flowers)
        {
            start[count] = f[0];
            end[count] = f[1];
            count++;
        }
        sort(start.begin(), start.end());
        sort(end.begin(), end.end());

        vector<int> bloom(people.size(), 0);
        count = 0;
        for (int t : people) {
            int started = upper_bound(start.begin(), start.end(), t) - start.begin();
            int ended = lower_bound(end.begin(), end.end(), t) - end.begin();
            bloom[count++] = (started - ended);
        }
        return bloom;
    }