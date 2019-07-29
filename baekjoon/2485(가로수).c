#include<stdio.h>

int gcd(int num1, int num2){
    int big, small,tmp;
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
        tmp = big % small;
        big = small;
        small = tmp;
    }
    return small;
}
/*
int gcd(int num1, int num2){
    int big, small,tmp;
    if(num1 > num2){
        big = num1;
        small = num2;
    }else{
        big = num2;
        small = num1;
    }
    return small ? gcd(small,big%small): big;
}
 */
int main(){
    int n,a,b,temp,sum = 0;
    scanf("%d",&n);
    int arr[n]; //4를 입력받았지만 공간은 3개가 나오므로
    scanf("%d",&a); // 제일 첫번째 수
    for(int i=1;i<=n-1;i++){
        scanf("%d",&b);
        arr[i] = b-a;
        a = b;
    }
    temp = gcd(arr[1],arr[2]);
    for(int i=3;i<=n-1;i++){
        temp = gcd(temp,arr[i]);
    }
    for(int i=1;i<=n-1;i++){
        sum += (arr[i] / temp -1);
    }
    printf("%d\n", sum);
}
