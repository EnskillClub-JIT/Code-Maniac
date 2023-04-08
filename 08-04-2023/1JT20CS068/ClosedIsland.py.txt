def closedIsland(grid):
    def dfs(i, j):
        if i < 0 or i >= len(grid) or j < 0 or j >= len(grid[0]):
            return False
        if grid[i][j] == 1:
            return True
        grid[i][j] = 1
        res = True
        for di, dj in [(-1, 0), (0, -1), (1, 0), (0, 1)]:
            res &= dfs(i + di, j + dj)
        return res

    count = 0
    for i in range(len(grid)):
        for j in range(len(grid[0])):
            if grid[i][j] == 0 and dfs(i, j):
                count += 1
    return count


grid = [[1, 1, 1, 1, 1, 1, 1],
        [1, 0, 0, 0, 0, 0, 1],
        [1, 0, 1, 1, 1, 0, 1],
        [1, 0, 1, 0, 1, 0, 1],
        [1, 0, 1, 1, 1, 0, 1],
        [1, 0, 0, 0, 0, 0, 1],
        [1, 1, 1, 1, 1, 1, 1]]
print(closedIsland(grid))