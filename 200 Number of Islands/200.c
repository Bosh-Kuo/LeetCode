void vistIsland(char **grid , int gridSize, int* gridColSize, int i, int j)
{
    if (i < 0 || j < 0 || i >= gridSize || j >= gridColSize[i])
        return;
    else if(grid[i][j]=='0')
        return;
    else 
    {
        grid[i][j] = '0';  // 拜訪過的路地區域填0
        vistIsland(grid, gridSize, gridColSize, i+1, j);    // 向右 
        vistIsland(grid, gridSize, gridColSize, i-1, j);    // 向左
        vistIsland(grid, gridSize, gridColSize, i, j+1);    // 向下
        vistIsland(grid, gridSize, gridColSize, i, j-1);    // 向上
    }
        
}
int numIslands(char** grid, int gridSize, int* gridColSize){
    int numOfIsland = 0;
    for (int i = 0; i < gridSize; i++)
    {
        for (int j = 0; j < gridColSize[i]; j++)
        {
            if (grid[i][j] == '1')
            {
                vistIsland(grid, gridSize, gridColSize, i, j);
                numOfIsland ++;
            }
                
        }
    }
    return numOfIsland;
}
