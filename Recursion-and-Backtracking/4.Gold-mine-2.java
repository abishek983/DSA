//https://leetcode.com/problems/path-with-maximum-gold/

class Solution {
    public int[] xDir = {-1, 1, 0, 0};
    public int[] yDir = {0, 0, -1, 1};
    
    public int solve(int[][] grid, int i, int j){
        //base case
        int ans = grid[i][j];
        grid[i][j] = 0;
        int maxSoFar = 0;
        for(int d=0; d<4; d++){
            int x = xDir[d] + i;
            int y = yDir[d] + j;
            
            if(x>=0 && x<grid.length && y>=0 && y<grid[0].length && grid[x][y]!=0){
                maxSoFar = Math.max(maxSoFar, solve(grid, x, y));
            }
        }
        grid[i][j] = ans;
        return ans + maxSoFar;
        
    }
    
    
    public int getMaximumGold(int[][] grid) {
        int ans = 0;
        
        for(int i=0; i<grid.length; i++){
            for(int j=0; j<grid[0].length; j++){
                if(grid[i][j]!=0){
                    ans = Math.max(ans, solve(grid, i, j));
                }
            }
        }
        
        return ans;
    }
}