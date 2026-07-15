#include <iostream>
#include <vector>
#include <queue>
#include <ctime>
#include <cstdlib>
using namespace std;

//-----------------------------------------------------
// Structure to represent a cell in the maze
//-----------------------------------------------------
struct Cell
{
    int row;
    int col;
};

//-----------------------------------------------------
// Check whether a cell is inside the maze boundaries
//-----------------------------------------------------
bool isValid(int x, int y, int n, int m)
{
    return (x >= 0 && x < n && y >= 0 && y < m);
}

int main()
{
    int n, m;

    // Input maze size
    cout << "Enter Number of Rows : ";
    cin >> n;

    cout << "Enter Number of Columns : ";
    cin >> m;

    //-------------------------------------------------
    // Dynamically create a 2D maze
    //-------------------------------------------------
    vector<vector<int>> maze(n, vector<int>(m));

    srand(time(0));

    // Fill the maze randomly with 0 and 1
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            maze[i][j] = rand() % 2;
        }
    }

    // Make sure start and destination are open
    maze[0][0] = 0;
    maze[n-1][m-1] = 0;

    //-------------------------------------------------
    // Print the generated maze
    //-------------------------------------------------
    cout << "\nGenerated Maze\n";

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
            cout << maze[i][j] << " ";

        cout << endl;
    }

    //-------------------------------------------------
    // Arrays for 8 possible directions
    //-------------------------------------------------
    int dx[8] = {-1,-1,-1,0,0,1,1,1};
    int dy[8] = {-1,0,1,-1,1,-1,0,1};

    //-------------------------------------------------
    // Queue for Breadth First Search
    //-------------------------------------------------
    queue<Cell> q;

    // Keep track of visited cells
    vector<vector<bool>> visited(n, vector<bool>(m, false));

    // Store parent of every cell to reconstruct the path
    vector<vector<Cell>> parent(n, vector<Cell>(m, {-1,-1}));

    // Start BFS from (0,0)
    q.push({0,0});
    visited[0][0] = true;

    while(!q.empty())
    {
        Cell current = q.front();
        q.pop();

        // Destination reached
        if(current.row == n-1 && current.col == m-1)
            break;

        // Explore all 8 neighboring cells
        for(int k = 0; k < 8; k++)
        {
            int nx = current.row + dx[k];
            int ny = current.col + dy[k];

            if(isValid(nx, ny, n, m) &&
               !visited[nx][ny] &&
               maze[nx][ny] == 0)
            {
                visited[nx][ny] = true;
                parent[nx][ny] = current;
                q.push({nx, ny});
            }
        }
    }

    //-------------------------------------------------
    // Check if a path exists
    //-------------------------------------------------
    if(!visited[n-1][m-1])
    {
        cout << "\nNo Path Exists!";
        return 0;
    }

    //-------------------------------------------------
    // Reconstruct the path from destination to source
    //-------------------------------------------------
    vector<Cell> path;
    Cell current = {n-1, m-1};

    while(current.row != -1)
    {
        path.push_back(current);
        current = parent[current.row][current.col];
    }

    //-------------------------------------------------
    // Print the shortest path
    //-------------------------------------------------
    cout << "\nShortest Path\n";

    for(int i = path.size()-1; i >= 0; i--)
    {
        cout << "(" << path[i].row << "," << path[i].col << ")";

        if(i != 0)
            cout << " -> ";
    }

    cout << endl;

    return 0;
}