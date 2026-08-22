class Solution {
public:
    bool checkDivisibility(int n) {
        int temp=n;
        int product=1;
        int sum=0;

        while(temp){
            sum+=temp%10;
            product*=temp%10;
            temp/=10;
        }

        return n%(product+sum)==0;
    }
};