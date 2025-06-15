#include <iostream>
#include <cstring>
using namespace std;

int main(){
    int t, n, q, count, temp, total, remove_;
    int border[5005], blocker[5005][2];
    cin >> t;
    while(t--){
        memset(border, 0, sizeof (border));
        memset(blocker, 0, sizeof (blocker));
        count = 5000, total = 0;
        cin >> n >> q;
        for(int i=1; i<=q; i++){
            cin >> blocker[i][0] >> blocker[i][1];
            for(int j=blocker[i][0]; j<=blocker[i][1]; j++){
                border[j]++;
                if(border[j] == 1) total++;
            }
        }
        for(int i=1; i<=q; i++){
            temp = 0;
            for(int j=blocker[i][0]; j<=blocker[i][1]; j++){
                if(border[j]-1 == 0) temp++;
            }
            if(count > temp){
                count = temp;
                remove_ = i;
            }
        }
        total -= count;
        for(int i=blocker[remove_][0]; i<=blocker[remove_][1]; i++){
            border[i]--;
        }
        count = 5000;
        for(int i=1; i<=q; i++){
            temp = 0;
            if(i != remove_){
                for(int j=blocker[i][0]; j<=blocker[i][1]; j++){
                    if(border[j]-1 == 0) temp++;
                }
                if(count > temp){
                    count = temp;
                }
            }
        }
        cout << total - count << endl;
    }
}