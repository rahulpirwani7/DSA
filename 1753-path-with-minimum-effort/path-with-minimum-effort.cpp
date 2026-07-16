class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int dir[2][4]={{0,0,-1,1},{-1,1,0,0}};


        // {dis,row,col}
        priority_queue<vector<int>, vector<vector<int>>, 
        greater<vector<int>>> pq;

        vector<vector<int>> dis(heights.size(),vector<int>(heights[0].size(),INT_MAX));

        dis[0][0]=0;
        pq.push({0,0,0});

        while(!pq.empty()){
            int weight=(pq.top())[0];
            int row=(pq.top())[1];
            int col=(pq.top())[2];

            pq.pop();

            if (row==heights.size()-1 && col==heights[0].size()-1)
                return weight;

for (int i = 0; i < 4; i++) {

    int newRow = row + dir[0][i];
    int newCol = col + dir[1][i];

    if (newRow >= 0 && newRow < heights.size() &&
        newCol >= 0 && newCol < heights[0].size()) {

        int newEffort = max(
            dis[row][col],
            abs(heights[newRow][newCol] - heights[row][col])
        );

        if (newEffort < dis[newRow][newCol]) {
            dis[newRow][newCol] = newEffort;
            pq.push({newEffort, newRow, newCol});
        }
    }
}
            
        }

        return -1;
    }
};