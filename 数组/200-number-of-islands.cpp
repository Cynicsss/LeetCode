/*
200. 岛屿数量  难度：中等
给你一个由 '1'（陆地）和 '0'（水）组成的的二维网格，请你计算网格中岛屿的数量。

岛屿总是被水包围，并且每座岛屿只能由水平方向或竖直方向上相邻的陆地连接形成。

此外，你可以假设该网格的四条边均被水包围。



示例 1:

输入:
11110
11010
11000
00000
输出: 1
示例 2:

输入:
11000
11000
00100
00011
输出: 3
解释: 每座岛屿只能由水平和/或竖直方向上相邻的陆地连接而成。



思路1：
深度优先搜索

*/

class Solution {
public:

    void dfs(vector<vector<char>> &grid, int row, int col)
    {
        int nrow = grid.size(), ncol = grid[0].size();
        grid[row][col] = '0';
        if((row-1) >= 0 && grid[row-1][col] == '1') dfs(grid, row-1, col);
        if((row+1) < nrow && grid[row+1][col] == '1') dfs(grid, row+1, col);
        if((col-1) >= 0 && grid[row][col-1] == '1') dfs(grid, row, col-1);
        if((col+1) < ncol && grid[row][col+1] == '1') dfs(grid, row, col+1);
    }

    int numIslands(vector<vector<char>>& grid)
    {
        int nrow = grid.size();
        if(nrow == 0) return 0;
        int ncol = grid[0].size();
        int island = 0;
        for(int i = 0; i < nrow; i++)
        {
            for(int j = 0; j < ncol; j++)
            {
                if(grid[i][j] == '1')
                {
                    island++;
                    dfs(grid, i, j);
                }
            }
        }
        return island;
    }
};


/*
广度优先搜索
*/
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int nr = grid.size();
        if (!nr) return 0;
        int nc = grid[0].size();

        int num_islands = 0;
        for (int r = 0; r < nr; ++r) {
            for (int c = 0; c < nc; ++c) {
                if (grid[r][c] == '1') {
                    ++num_islands;
                    grid[r][c] = '0';
                    queue<pair<int, int>> neighbors;
                    neighbors.push({r, c});
                    while (!neighbors.empty()) {
                        auto rc = neighbors.front();
                        neighbors.pop();
                        int row = rc.first, col = rc.second;
                        if (row - 1 >= 0 && grid[row-1][col] == '1') {
                            neighbors.push({row-1, col});
                            grid[row-1][col] = '0';
                        }
                        if (row + 1 < nr && grid[row+1][col] == '1') {
                            neighbors.push({row+1, col});
                            grid[row+1][col] = '0';
                        }
                        if (col - 1 >= 0 && grid[row][col-1] == '1') {
                            neighbors.push({row, col-1});
                            grid[row][col-1] = '0';
                        }
                        if (col + 1 < nc && grid[row][col+1] == '1') {
                            neighbors.push({row, col+1});
                            grid[row][col+1] = '0';
                        }
                    }
                }
            }
        }

        return num_islands;
    }
};

