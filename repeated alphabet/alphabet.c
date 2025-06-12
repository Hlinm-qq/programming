#include <stdio.h>
#include <ctype.h>
int main(){
    int n, n1, alpha[27]={0}, ans=0;
    char temp;
    scanf("%d", &n);
    n1 =n;
    while(n){
        scanf("%c", &temp);
        // printf("%d", isspace(temp));
        if (!isspace(temp)) n--;
        alpha[temp-97]++;
    }
    for (int a=0; a<27; a++){
        // printf("%d_", alpha[a]);
        if(alpha[a] > 1) {
            ans = 1;
            break;
        }
    }
    if(n1 == 1) ans=1;
    if(ans) printf("I'm the god of Knuckles!\n");
    else printf("Different makes perfect\n");
}