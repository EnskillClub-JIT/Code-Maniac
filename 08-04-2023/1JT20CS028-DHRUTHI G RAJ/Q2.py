
def dfs(matrix, visited, x, y, n, m):
	
	if (x < 0 or y < 0 or
		x >= n or y >= m or
		visited[x][y] == True or
		matrix[x][y] == 0):
		return
		

	visited[x][y] = True


	dfs(matrix, visited, x + 1, y, n, m);
	dfs(matrix, visited, x, y + 1, n, m);
	dfs(matrix, visited, x - 1, y, n, m);
	dfs(matrix, visited, x, y - 1, n, m);


def countClosedIsland(matrix, n, m):
	
	
	visited = [[False for i in range(m)]
					for j in range(n)]


	for i in range(n):
		for j in range(m):
			
			
			if ((i * j == 0 or i == n - 1 or
				j == m - 1) and matrix[i][j] == 1 and
				visited[i][j] == False):
				dfs(matrix, visited, i, j, n, m)

	
	result = 0

	for i in range(n):
		for j in range(m):
			
			
			if (visited[i][j] == False and
				matrix[i][j] == 1):
				result += 1
				
				
				dfs(matrix, visited, i, j, n, m)

	
	return result


N = 5
M = 8

matrix = [ [ 0, 0, 0, 0, 0, 0, 0, 1 ],
		[ 0, 1, 1, 1, 1, 0, 0, 1 ],
		[ 0, 1, 0, 1, 0, 0, 0, 1 ],
		[ 0, 1, 1, 1, 1, 0, 1, 0 ],
		[ 0, 0, 0, 0, 0, 0, 0, 1 ] ]
			

print(countClosedIsland(matrix, N, M))

