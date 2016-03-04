class Solution {
   public:
    vector<int> minv;
    vector<int> maxv;
    bool increasingTriplet(vector<int>& nums) {
        if (nums.empty()) {
            return false;
        }

        minv.reserve(nums.size());
        maxv.reserve(nums.size());

        minv[0] = *nums.begin();
        maxv[nums.size() - 1] = *nums.rbegin();

        for (int i = 1; i < nums.size(); i++) {
            minv[i] = min(minv[i - 1], nums[i]);
            maxv[nums.size() - 1 - i] =
                max(maxv[nums.size() - i], nums[nums.size() - 1 - i]);
        }

        for (int i = 1; i < nums.size() - 1; i++) {
            if (minv[i - 1] < nums[i] && maxv[i + 1] > nums[i]) {
                return true;
            }
        }

        return false;
    }
};
