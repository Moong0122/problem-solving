#include<stdio.h>

int GCD(int num1, int num2){
    int big, small;
    if(num1 > num2){
        big = num1;
        small = num2;
    }else{
        big = num2;
        small = num1;
    }
    return small ? GCD(small, big%small) : big;
}
int main(){
    int a,b,x,y;
    int n,m,result,result_two;
    scanf("%d%d",&a,&b);
    scanf("%d%d",&x,&y);

    result = GCD(b,y);
    result_two = GCD(a*y/result + x*b/result,b*y/result);
    printf("%d %d\n",(a*y/result + x*b/result)/result_two,b*y/result/result_two);
    return 0;
}