class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        while (i < n) {
            if (nums[i] <= 0 || nums[i] > n) {
                i++;
            } else {
                int correctindex = nums[i] - 1;
                if (nums[i] > 0 && nums[i] <= n &&
                    nums[i] != nums[correctindex]) {
                        swap(nums[i], nums[correctindex]);
                    // int temp = nums[i];
                    // nums[i] = nums[correctindex];
                    // nums[correctindex] = temp;
                } else {
                    i++;
                }
            }
        }

        for (int j = 0; j < n; j++) {
            if (nums[j] != j + 1) {
                return j + 1;
            }
        }
        return n + 1;
    }
};