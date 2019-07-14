#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
    int arr[6] = {500,100,50,10,5,1};
    int n, mok, nameji, money, answer = 0;
    scanf("%d",&n);
    money = 1000-n;
    for(int i=0;i<6;i++){
        mok = money / arr[i];
        nameji = money % arr[i];
        money = nameji;
        answer+= mok;

        if(nameji == 0)
            break;
    }
    printf("%d\n",answer);
    return 0;
}