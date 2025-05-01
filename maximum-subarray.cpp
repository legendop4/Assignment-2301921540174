//problem link : https://leetcode.com/problems/maximum-subarray
// submission link : https://leetcode.com/problems/maximum-subarray/submissions/1623068740
//Kadanes algorithm ( optimal solution)

class Solution {
public:
    int maxSubArray(vector<int>& arr) {
        long long max = LONG_MIN;
        long long sum = 0;
        int n = arr.size();
        
        for(int i = 0;i<n;i++){
            sum += arr[i];
            
            if(sum>max){
                max = sum;
            }
            
            if(sum<0){
                sum = 0;
            }
        }
        return max;
    }
};
