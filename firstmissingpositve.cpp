//Problem Link : https://leetcode.com/problems/first-missing-positive
//Solution link:https://leetcode.com/problems/first-missing-positive/submissions/1623029095

// Using  my approach of hashing(not optimal)
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans (n+1,0);
        for(int i = 0;i<n;i++){
           if(nums[i]>0 && nums[i]<=n){
            ans[nums[i]]++;
           }
        }
        for(int i = 1;i<=n;i++){
            if(ans[i] == 0){
                return i;
            }
        }
        return n+1;
    }
};

// Using inplace hashing (optimal)
// solution link : https://leetcode.com/problems/first-missing-positive/submissions/1623038952

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        
        for(int i = 0;i<n;i++){
           while(nums[i]>0 && nums[i]<=n && nums[nums[i]-1]!= nums[i]){
                swap(nums[i],nums[nums[i]-1]);
           }
        }
        for(int i = 0;i<n;i++){
            if(nums[i] != i+1){
                return i+1;
            }
        }
        return n+1;
    }
};
