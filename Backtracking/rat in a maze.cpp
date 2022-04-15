/******************************************************************************
Rat in a MAze
*******************************************************************************/

#include <iostream>
#include <vector>
// #include <memset>
#include <cstring>

using namespace std;

bool vis[100][100]; // 2d matrix to check visited
bool go(vector<vector<int>> &v, int sx, int sy, int dx,int dy, int r, int c){
    if(sx < 0 or sy < 0 or sx>=r or sy >= c or v[sx][sy]==0 or vis[sx][sx]==true)
    return false;
    if(sx==dx and sy==dy)
    return true;
    vis[sx][sy]=true;
    if(go(v, sx, sy+1, dx, dy, r, c))
    return true;
    
    if(go(v, sx, sy-1, dx, dy, r, c))
    return true;
    if(go(v, sx+1, sy, dx, dy, r, c))
    return true;
    if(go(v, sx-1, sy, dx, dy, r, c))
    return true;
    return false;
}

int main()
{
    int r, c;
    cin >> r >> c;
    vector<vector<int>> v(r, vector<int>(c));
    for(int i = 0; i < r; i++)
    {
        for(int j = 0; j < c; j++)
        cin >> v[i][j];
    }
    memset(vis, false, sizeof(vis));
    cout << go(v, 0,0,r-1, c-1, r,c);
    return 0;
}
