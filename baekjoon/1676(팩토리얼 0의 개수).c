#include<stdio.h>

int five = 0;
int check(int num){
    int number = num;
    if(num <= 4)
        return five;
    for(int i=2;i*i<=num;i++){
        if(num % i == 0){
            if(i == 5)
                five++;
            num /= i;
            i--;
        }
    }
    if(num == 5)
        five++;
    return check(number-1);
}
int main(){
    int n;
    scanf("%d",&n);
    printf("%d\n", check(n));
    return 0;
}