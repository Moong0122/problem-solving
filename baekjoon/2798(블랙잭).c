#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
    int n,m,max = -1;
    int find = 0;
    scanf("%d%d",&n,&m);
    int card[n];

    for(int i=0;i<n;i++){
        scanf("%d",&card[i]);
    }
    for(int i=0;i<n-2;i++){
        for(int j = i+1;j<n-1;j++){
            for(int k = j+1; k<n ;k++){
                if(card[i]+card[j]+card[k] > max && card[i]+card[j]+card[k] <= m)
                    max = card[i]+card[j]+card[k];
                if(max == m){
                    find = 1;
                    break;
                }
            }
            if(find == 1)
                break;
        }
        if(find == 1)
                break;
    }
    printf("%d\n",max);
    return 0;
}
