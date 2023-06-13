class Solution {
    bool static cmp(pair<int,int> &a, pair<int,int> &b) {
        return a.first < b.first;
    }
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int, int>> indexNums;
        for(int i=0; i<nums.size(); i++)
                indexNums.push_back({nums[i], i});

        sort(indexNums.begin(), indexNums.end(), cmp);
        int start = 0, end = indexNums.size()-1;
        while(start < end) {
            int tempSum = indexNums[start].first + indexNums[end].first;
            if(tempSum == target) {
                return {indexNums[start].second, indexNums[end].second};
            }
            else if(tempSum > target) {
                end--;
            }
            else
                start++;
        }
        return {};
    }
};
