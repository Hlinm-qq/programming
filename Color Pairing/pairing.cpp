#include <iostream>
using namespace std;

int main(){
    int t, r, g, b, days;
    cin >> t;
    while(t--){
        cin >> r >> g >> b;
        if(r >= g && r >= b){
            if(g+b >=r){
                days = (r + g + b)/2;
            } else{
                days = g + b;
            }
        } else if(g >= r && g >= b){
            if(r+b >=g){
                days = (r + g + b)/2;
            } else{
                days = r + b;
            }
        } else{
            if(g+r >=b){
                days = (r + g + b)/2;
            } else{
                days = g + r;
            }
        }
        cout << days << endl;
    }
}