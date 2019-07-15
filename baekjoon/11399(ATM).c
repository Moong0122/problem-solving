#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int *number;
int main(){
    int n,tmp,sum = 0,s;
    scanf("%d",&n);
    number = (int*)malloc(sizeof(int)*n);
    for(int i=0;i<n;i++){
        scanf("%d",&number[i]);
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n-1;j++){
            if(number[j]>number[j+1]){
                tmp = number[j];
                number[j] = number[j+1];
                number[j+1] = tmp;
            }
        }
    }
    s = n;
    for(int i=0;i<n;i++){
        sum += s * number[i];
        s--;
    }
    printf("%d\n",sum);
    
    return 0;
}
