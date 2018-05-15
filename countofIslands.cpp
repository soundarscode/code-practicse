class Solution {
    //do dfs 
    void doDfs(vector<vector<char>>& grid, int x, int y, int m, int n)
    {
         stack< pair<int,int> > dfsStack;
         dfsStack.emplace(make_pair(x, y));
         pair<int,int> currentVertex;
         int currx, curry;
        
         while(dfsStack.empty() == false)
         {
            currentVertex = dfsStack.top();
            currx = currentVertex.first;
            curry = currentVertex.second;
            grid[currx][curry] = '3';
            dfsStack.pop(); 
            //push right 
            if(currx+1 < m )
            {
                if(grid[currx+1][curry] == '1')
                    dfsStack.emplace(make_pair(currx+1, curry));
                else
                    grid[currx+1][curry] = '3';
            }
            //push down
            if(curry+1 < n )
            {
                if(grid[currx][curry+1] == '1')
                    dfsStack.emplace(make_pair(currx, curry+1));
                else
                    grid[currx][curry+1] = '3';
            }
            //push left
            if(currx-1 >= 0 )
            {
                if(grid[currx-1][curry] == '1')
                    dfsStack.emplace(make_pair(currx-1, curry));
                else
                    grid[currx-1][curry] = '3';
            }
            //push  up
            if(curry-1 >=0 )
            {
                if(grid[currx][curry-1] == '1')
                    dfsStack.emplace(make_pair(currx, curry-1));
                else
                    grid[currx][curry-1] = '3';
            } 
             
         }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        if(m < 1)
            return 0;
        int n = grid[0].size();
        int i, j, count = 0;
        
        for(i = 0 ; i < m; i++)
        {
            for(j = 0 ; j < n; j++)
            {
                if(grid[i][j] == '1')
                {
                    doDfs(grid, i, j, m, n);
                    count++;
                }
            }
        }
        
        return count;
        
    }
};
