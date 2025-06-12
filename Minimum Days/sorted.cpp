#include <iostream>
using namespace std;

int coffee[200005];

int try_(int days, int &n){
    int lines = 0, count = 0, minus_ = 1;
    for(int i=0; i<days; i++){
        lines+=coffee[i];
    }
    for(int i=days; i<n; i++){
        count++;
        if(coffee[i] >= minus_){
            lines += coffee[i] - minus_;
        } else break;
        if(count == days){
            minus_++, count = 0;
        }
    }
    return lines;
}

int main(){
    int t, n, m, l, r, day, ans;
    cin >> t;
    while(t--){
        ans = -1;
        cin >> n >> m;
        for(int i=0; i<n; i++){
            cin >> coffee[i];
        }
        r = n+1, l = 1;
        while(l<r){
            day = l + (r-l)/2;
            if(try_(day, n) >= m){
                ans = day;
                r = day;
            } else l = day+1;
        }
        cout << ans << endl;
    }
}