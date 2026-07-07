class Solution {
public:
    int maxJumps(vector<int>& arr, int d) {
        vector<int> indexes(arr.size(),0);
        vector<int> dp(arr.size(),0);

    for(int i = 0; i < arr.size(); i++)
        indexes[i] = i;

    for(int i = 0; i < arr.size(); i++) {
        int minIndex = i;

        for(int j = i + 1; j < arr.size(); j++) {
             if(arr[indexes[j]] < arr[indexes[minIndex]])
                    minIndex = j;
    }
    
    swap(indexes[i], indexes[minIndex]);
    }

    dp[indexes[0]]=1;
    int maxx=1;
    for(int i=1;i<arr.size();i++){
        int ans=1;
        for(int j=indexes[i]-1;j>=0 && j>=indexes[i]-d;j--){
                if(arr[j]>=arr[indexes[i]])
                    break;
                ans=max(ans,1+dp[j]);
                
        }

        for(int j=indexes[i]+1;j<arr.size() && j<=indexes[i]+d;j++){
                if(arr[j]>=arr[indexes[i]])
                    break;
                ans=max(ans,1+dp[j]);
        }

        maxx=max(maxx,ans);
        dp[indexes[i]]=ans;
    }
    
    return maxx;
}

};