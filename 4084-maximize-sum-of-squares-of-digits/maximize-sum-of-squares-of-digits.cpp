class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        string  ans="";

        while(sum>9){
            ans+='9';
            sum-=9;
            num--;
            if(num==0)
                return  "";
        }


        num--;
        ans+='0'+sum;


        while(num){
            ans+='0';
            num--;
        }


        return ans;
    }
};