class Solution {
public:
    int totalWaviness(int num1, int num2) {
        vector<bool> dp(1000,false);

        int ans=0;
        for(int i=max(100,num1);i<=num2;i++){
            int temp=i;
            while(temp>100){
                int num=temp%1000;

                int n1=num%10;
                int n2=(num%100)/10;
                int n3=num/100;

                if((n1 < n2 && n3 < n2 ) || (n1 > n2 && n3 > n2 ))
                    ans++;
                
                temp/=10;
            }
        }

        return ans;
    }
};