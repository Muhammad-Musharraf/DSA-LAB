#include <iostream>
#include <vector>
#include <queue>
#include <ctime>
#include <cstdlib>

using namespace std;

//-----------------------------------------------------
// Structure to store row and column
//-----------------------------------------------------
struct Cell
{
    int row;
    int col;
};

//-----------------------------------------------------
// Check if cell is inside maze
//-----------------------------------------------------
bool valid(int x,int y,int n,int m)
{
    return (x>=0 && x<n && y>=0 && y<m);
}

int main()
{
    int n,m;

    cout<<"Enter Rows : ";
    cin>>n;

    cout<<"Enter Columns : ";
    cin>>m;

    //-------------------------------------------------
    // Create Maze
    //-------------------------------------------------
    vector<vector<int>> maze(n,vector<int>(m));

    srand(time(0));

    // Fill randomly with 0 and 1
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
            maze[i][j]=rand()%2;
    }

    // Start and End should always be open
    maze[0][0]=0;
    maze[n-1][m-1]=0;

    //-------------------------------------------------
    // Print Maze
    //-------------------------------------------------
    cout<<"\nMaze\n";

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
            cout<<maze[i][j]<<" ";

        cout<<endl;
    }

    //-------------------------------------------------
    // Eight Directions
    //-------------------------------------------------
    int dx[8]={-1,-1,-1,0,0,1,1,1};

    int dy[8]={-1,0,1,-1,1,-1,0,1};

    //-------------------------------------------------
    // BFS
    //-------------------------------------------------
    queue<Cell> q;

    vector<vector<bool>> visited(n,vector<bool>(m,false));

    vector<vector<Cell>> parent(n,vector<Cell>(m,{-1,-1}));

    q.push({0,0});

    visited[0][0]=true;

    while(!q.empty())
    {
        Cell current=q.front();
        q.pop();

        if(current.row==n-1 && current.col==m-1)
            break;

        for(int k=0;k<8;k++)
        {
            int nx=current.row+dx[k];
            int ny=current.col+dy[k];

            if(valid(nx,ny,n,m)
               && !visited[nx][ny]
               && maze[nx][ny]==0)
            {
                visited[nx][ny]=true;

                parent[nx][ny]=current;

                q.push({nx,ny});
            }
        }
    }

    //-------------------------------------------------
    // Print Path
    //-------------------------------------------------
    if(!visited[n-1][m-1])
    {
        cout<<"\nNo Path Exists";
        return 0;
    }

    vector<Cell> path;

    Cell current={n-1,m-1};

    while(current.row!=-1)
    {
        path.push_back(current);

        current=parent[current.row][current.col];
    }

    cout<<"\nShortest Path\n";

    for(int i=path.size()-1;i>=0;i--)
    {
        cout<<"("<<path[i].row<<","<<path[i].col<<") ";

        if(i!=0)
            cout<<"-> ";
    }

    cout<<endl;

    return 0;
}