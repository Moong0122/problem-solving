#include<stdio.h>

int calculate(int num1, int num2){
    int big, small,nameji;
    if(num1 > num2){
        big = num1;
        small = num2;
    }else{
        big = num2;
        small = num1;
    }
    while(1){
        if(big % small == 0)
            break;
        nameji = big % small;
        big = small;
        small = nameji;
    }
    return num1/small*num2;
}
int main(){
    int n,a,b;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d%d",&a,&b);
        printf("%d\n",calculate(a,b));
    }
    return 0;
}