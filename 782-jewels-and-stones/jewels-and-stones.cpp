class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        unordered_map<char,int> hash;


        for(char ch: stones)
            hash[ch]++;
        
        int ans=0;

        for(char ch: jewels)
            ans+=hash[ch];

        return ans;
    }
};