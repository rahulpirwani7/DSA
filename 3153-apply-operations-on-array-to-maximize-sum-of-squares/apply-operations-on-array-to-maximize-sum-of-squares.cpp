#define ll long long
class Solution {
public:
    const ll mod = 1e9+7;
    int maxSum(vector<int>& nums, int k) {
        int n = nums.size();
        map<int,int>mp;
        int cnt = 0;
        for(int i=31;i>=0;i--){
            for(auto &x : nums){
                if(x & (1<<i)){
                    mp[i]++;
                    cnt  = max(cnt,mp[i]);
                }
            }
        }

        vector<int>arr(cnt+1,0);

        for(int i = 31;i>=0;i--){
            int ind = 0;
            while(mp[i]>0){
                arr[ind] = arr[ind] | (1<<i);
                mp[i]--;
                ind++;
            }
        }

        ll sum = 0;
        cnt = k;
        for(auto &x : arr){
            if(cnt==0) break;
            sum = (sum +(1LL*x*x)%mod)%mod;
            cnt--;
        }
        return (int)sum;
    }
};