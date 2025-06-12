#include <iostream>
#include <climits>
#include <queue>
using namespace std;

bool visited[1005][1005];

int scan_(char map[][1005], int& thanos, int killed, int x, int y, int& maxx, int& maxy, int route){
    queue<int> x_, y_, dist;
    x_.push(x);
    y_.push(y);
    dist.push(route);
    visited[x][y] = true;
    while(!x_.empty() && !y_.empty()){
        int map_x = x_.front();
        int map_y = y_.front();
        int route_ = dist.front();
        if(map[map_x][map_y] == 'T') killed++;
        x_.pop(); y_.pop(); dist.pop();

        if(thanos == killed) return route_;

        if(map_x-1 >= 0 && visited[map_x-1][map_y] == false){
            x_.push(map_x-1); 
            y_.push(map_y);
            dist.push(route_+1);
            visited[map_x-1][map_y] = true;
        }
        if(map_x+1 < maxx && visited[map_x+1][map_y] == false){
            x_.push(map_x+1); 
            y_.push(map_y);
            dist.push(route_+1);
            visited[map_x+1][map_y] = true;
        }
        if(map_y-1 >= 0 && visited[map_x][map_y-1] == false){
            x_.push(map_x); 
            y_.push(map_y-1);
            dist.push(route_+1);
            visited[map_x][map_y-1] = true;
        }
        if(map_y+1 < maxy && visited[map_x][map_y+1] == false){
            x_.push(map_x); 
            y_.push(map_y + 1);
            dist.push(route_+1);
            visited[map_x][map_y+1] = true;
        }
    }
    return -1;
}

int main(){
    int n, m;
    cin >> n >> m;
    char map[1005][1005];
    int init[2];
    int thanos =0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> map[i][j];
            visited[i][j] = false;
            if(map[i][j] == 'I'){
                init[0] = i, init[1] = j;
            } else if( map[i][j] == 'T') thanos++;
            else if(map[i][j] == 'C'){
                visited[i][j] = true;
            }
        }
    }
    cout << scan_(map, thanos, 0, init[0], init[1], n, m, 0) << endl;
}