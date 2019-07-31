#include<stdio.h>

int arr[11][11];
int calculate(int num1, int num2){
    if(arr[num1][num2] > 0)
        return arr[num1][num2];
    if(num2 == 0 || num1 == num2)
        return arr[num1][num2] = 1;
    if(num2 > 0 && num2 < num1)
        return arr[num1][num2] = calculate(num1-1,num2-1) + calculate(num1-1, num2);
    else
        return 0;
}
int main(){
    int n,k;
    scanf("%d%d",&n,&k);
    printf("%d\n",calculate(n,k));
    return 0;
}