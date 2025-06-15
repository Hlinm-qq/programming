#include <iostream>
#include <cstring>
using namespace std;

int main(){
    int t, a, b, c, d;
    long long int sum[50010], ans[50010], total;
    cin >> t;
    while(t--){
        total = 0;
        cin >> a >> b >> c >> d;
        memset(sum, 0, sizeof(sum));
        memset(ans, 0, sizeof(ans));
        for(int i=a; i<=b; i++){
            sum[i+b] += 1;
            sum[i+c+1] -= 1;
        }
        for(int i=a+b; i<=b+c; i++)
            sum[i+1] += sum[i];

        for(int i=c+1; i<=b+c; i++)
            ans[c] += sum[i];

        for(int i=c+1; i<=d; i++)
            ans[i] = ans[i-1] - sum[i];

        for(int i=c; i<=d; i++) 
            total += ans[i];
            
        cout << total << endl;
    }
}