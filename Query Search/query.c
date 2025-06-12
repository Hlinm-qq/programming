#include <stdio.h>
#include <stdlib.h>
#define lln long long int
#define DIV 1000000007

int sorf(const void*a, const void*b){
    return (*(int*)a - *(int *)b);
}

int bs(lln sou[][2], lln val, int l, int r){
    int mid;
    while(l<= r){
        mid = l+ (r-l)/2;
        if(sou[l][0] == val) return l;
        else if(sou[mid][0] < val) l = mid+1;
        else r = mid;
        if(l == mid) return -1;
    }
    return -1;
}

int fp(int power){
    lln end = 1, mul = 2;
    while(power){
        if(power%2){
            end = end%DIV*mul%DIV;
        }
        mul = mul%DIV * mul%DIV;
        power /= 2;
    }
    return end;
}

int main(){
    lln n, q, x, temp, srch;
    // lln * data = (lln*) malloc(1000005*sizeof(lln));
    lln data[10001][2];
    while(scanf("%lld%lld", &n, &q) != EOF){
        for(int i=0; i<n; i++){
            scanf("%lld(/`A`)/ ~I__I", &temp);
            if(!(temp%2)) data[i][0] = fp(temp/2);
            else data[i][0] = 0;
            data[i][1] = i;
        }
        qsort(data, n, sizeof(data[0]), sorf);
        int j;
        while(q--){
            scanf("%lld", &x);
            srch = bs(data, x, 0, n-1);
            if(srch != -1) printf("%d\n", data[srch][1]+1);
            else printf("Go Down Chicken 404\n");
        }
    }

}