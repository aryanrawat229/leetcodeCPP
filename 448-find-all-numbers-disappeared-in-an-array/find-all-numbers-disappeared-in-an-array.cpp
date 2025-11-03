class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n=nums.size();
        int i=0;
        while(i<n){
            int correctindex=nums[i]-1;
            if (nums[i]!=nums[correctindex]){
                int temp=nums[i];
                nums[i]=nums[correctindex];
                nums[correctindex]=temp;
            }
            else{i++;}
        }
        vector<int>ans;
        for(int j=0;j<n;j++){
            if(nums[j]!=j+1){
                ans.push_back(j+1);
            }

        }
        return ans;
    }
};