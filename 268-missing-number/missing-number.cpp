class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size();
        int i=0;
        while(i<n){
            int correctindex=nums[i];
            if(nums[i]<n && nums[i]!=i){
                int temp= nums[i];
                nums[i]=nums[correctindex];
                nums[correctindex]=temp;
            }
            else{ i++;}
        }

            //checking for missing number
            for(int i=0;i<n;i++){
                if(i!=nums[i]){
                    return i;
                }
            }
            return n;   
    }

};