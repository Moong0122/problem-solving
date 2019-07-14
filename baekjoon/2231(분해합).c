#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int partition(int n);

int main()
{
    int num,sum, n = 0, result, check = 0;
    scanf("%d",&num);
    
    sum = num;
    while(1){
        if(sum == 0)
        break;
        n++;
        sum /= 10;
    }
    
    for(int i=num-(9*n);i<num;i++){
        if(partition(i) == num){
            result = i;
            check = 1;
            break;
        }
    }
    if(check == 1)
    printf("%d\n",result);
    else
    printf("0\n");
    
    return 0;
}
int partition(int n){
    int answer = n;
    while(1){
        answer += n % 10;
        n /= 10;
        if(n == 0)
        break;
    }
    return answer;
}
