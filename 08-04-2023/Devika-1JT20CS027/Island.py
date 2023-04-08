def closedIsland(grid):
    m, n = len(grid), len(grid[0])
    def dfs(i, j):
        if 0 <= i < m and 0 <= j < n and grid[i][j] == 0:
            grid[i][j] = 1
            dfs(i+1, j)
            dfs(i-1, j)
            dfs(i, j+1)
            dfs(i, j-1)
    # mark all land cells connected to the boundary as visited
    for i in range(m):
        dfs(i, 0)
        dfs(i, n-1)
    for j in range(n):
        dfs(0, j)
        dfs(m-1, j)
    # traverse the remaining unvisited land cells and count closed islands
    count = 0
    for i in range(1, m-1):
        for j in range(1, n-1):
            if grid[i][j] == 0:
                dfs(i, j)
                count += 1
    return count
