#include <stdio.h>
#include <string.h>

int main(){
    char main[1005], sub[1005];
    int main_len, sub_len, q, sum[1002], l,r, max, temp;
    sum[0] = 0;
    while(scanf("%s", main) != EOF){
        scanf("%s", sub);
        scanf("%d", &q);
        max = temp = 0;
        main_len = strlen(main);
        sub_len = strlen(sub);
        for(int i=1; i<=main_len; i++){
            for(int j=0; j<sub_len; j++){
                // printf("%d==", i+j-1);
                if(main[i+j-1] != sub[j]){
                    sum[i] = sum[i-1];
                    break;
                } 
                if(j == sub_len-1) sum[i] = sum[i-1] +1;
            }
        }
        while(q--){
            scanf("%d%d", &l, &r);
            if(r - sub_len + 1 < 0 ) temp = 0;
            else temp = sum[r - sub_len+1] - sum[l-1];
            if(temp > max) max = temp;
        }
        printf("%d\n", max);
    }
    return 0;
}