class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        long long n = nums.size();
         long long  sum =0;
        long long  k =0;
        long long  count =0;
        for(long long  i =0 ; i<n ; i++){
            sum += nums[i];
        }
        for(int i =0 ; i<nums.size();i++){
            k += nums[i];
            if( (2*k >=sum) && i < n-1 ){
                count++;
            }
             
        }
        return count;
        
    }
};