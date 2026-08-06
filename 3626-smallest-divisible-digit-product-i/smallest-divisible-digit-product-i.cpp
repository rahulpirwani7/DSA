class Solution {
public:
    int smallestNumber(int n, int t) {
        int n_term=n;

        while(true){
            int product=1;

            int temp=n_term;

            while(temp!=0){
                product*=temp%10;
                temp/=10;
            }

            if(product%t==0)
                return n_term;
            n_term++;
        }

        return 0;
    }
};