#include <iostream>
#include <cmath>
#define lln long long
using namespace std;

lln solve_(lln x){
    for (int i=0; i<64; i++){
        lln power_ = pow(2, i);
        if(power_ == x+1)
            return power_;
        if(power_ > x) break;

        lln l = 0, r = 2e9, ans = -1;
        lln mid, k, guess;
        while(l<r){
            mid = l + (r-l)/2;
            k = mid * 2 + 1;
            guess = (power_-1) + (k-1)/2;
            if(guess == ((long double)x/k)){
                r = mid;
                ans = k;
            } 
            else if(guess > ((long double)x/k)) r = mid;
            else l = mid + 1;
        }
        if((power_-1) + (ans-1)/2 == ((long double)x/ans))
            return ans * power_;
    }
    return -1;
}

// y = ((2^i - 1)/2^i)*x + k(k-1)/2
// y/k = (2^i - 1) + (k-1)/2

int main(){
    int t;
    lln n, l, r, ans_;
    cin >> t;
    while(t--){
        cin >> n;
        if(n > 1)
            cout << solve_(n) << endl;
        else
            cout << 2 << endl;
    }
}