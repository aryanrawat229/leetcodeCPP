class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int i = 0;
        int n = nums.size();

        while(i<n){
            int correctindex = nums[i]-1;
            if(nums[i]!=nums[correctindex]){
                int temp = nums[i];
                nums[i]=nums[correctindex];
                nums[correctindex]=temp;
            }
            else{i++;}
        }

        vector <int>ans;
        for(int j=0;j<n;j++){
            if(nums[j]!=j+1){
                ans.push_back(nums[j]);
            }
        }
        return ans;
    }
};