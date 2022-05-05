/*Given a binary array nums and an integer k, return the maximum number of consecutive 1's in the array if you can flip at most k 0's.*/
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int low=0,high=0;
        int numberOfZeroes=0;
        int ans=0;
        while(high<nums.size())
        {
            if(nums[high]==0)
                numberOfZeroes++;
            while(numberOfZeroes>k&&low<nums.size())
            {
                if(nums[low]==0)
                    numberOfZeroes--;
                low++;
            }
           ans=max(ans,high-low+1);
            high++;
        }
        return ans;
    }
};

