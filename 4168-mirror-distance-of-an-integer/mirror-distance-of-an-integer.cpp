class Solution {
public:
    int mirrorDistance(int n) {
        int n1=0;
        int temp=n;
        while(n){
            n1=n1*10+n%10;
            n/=10;
        }
        
        return abs(n1-temp);
    }
};