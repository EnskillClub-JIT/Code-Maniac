// C++ program for the above approach
#include <bits/stdc++.h>
using namespace std;
 
// DFS Traversal to find the count of
// island surrounded by water
void dfs(vector<vector<int> >& matrix,
         vector<vector<bool> >& visited, int x, int y,
         int n, int m)
{
    // If the land is already visited
    // or there is no land or the
    // coordinates gone out of matrix
    // break function as there
    // will be no islands
    if (x < 0 || y < 0 || x >= n || y >= m
        || visited[x][y] == true || matrix[x][y] == 0)
        return;
 
    // Mark land as visited
    visited[x][y] = true;
 
    // Traverse to all adjacent elements
    dfs(matrix, visited, x + 1, y, n, m);
    dfs(matrix, visited, x, y + 1, n, m);
    dfs(matrix, visited, x - 1, y, n, m);
    dfs(matrix, visited, x, y - 1, n, m);
}
 
// Function that counts the closed island
int countClosedIsland(vector<vector<int> >& matrix, int n,
                      int m)
{
 
    // Create boolean 2D visited matrix
    // to keep track of visited cell
 
    // Initially all elements are
    // unvisited.
    vector<vector<bool> > visited(n,
                                  vector<bool>(m, false));
 
    // Mark visited all lands
    // that are reachable from edge
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
 
            // Traverse corners
            if ((i * j == 0 || i == n - 1 || j == m - 1)
                and matrix[i][j] == 1
                and visited[i][j] == false)
                dfs(matrix, visited, i, j, n, m);
        }
    }
 
    // To stores number of closed islands
    int result = 0;
 
    for (int i = 0; i < n; ++i) {
 
        for (int j = 0; j < m; ++j) {
 
            // If the land not visited
            // then there will be atleast
            // one closed island
            if (visited[i][j] == false
                and matrix[i][j] == 1) {
 
                result++;
 
                // Mark all lands associated
                // with island visited.
                dfs(matrix, visited, i, j, n, m);
            }
        }
    }
 
    // Return the final count
    return result;
}
 
// Driver Code
int main()
{
    // Given size of Matrix
    int N = 5, M = 8;
 
    // Given Matrix
    vector<vector<int> > matrix
        = { { 1, 0, 1, 0, 1 },
            { 0, 0, 1, 0, 0 },
            { 0, 0, 1, 1, 0 },
            { 0, 1, 0, 1, 0 },
            { 1, 1, 1, 0, 0 },
            { 0,0,0,0,1},
            {0,1,0,1,0},
            {0,0,1,1,0},
            {0,0,0,1,1},
            {1,1,0,0,0},
        };
 
    // Function Call
    cout << countClosedIsland(matrix, N, M);
    return 0;
}