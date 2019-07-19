#include<stdio.h>
#include<stdlib.h>
#include<string.h>
// malloc 사용 -> 메모리 사용 : 1116KB
unsigned long long *arr;
unsigned long long wave(int num){
    if(num == 0)
        return 0;
    if(num == 1 || num == 2 || num == 3)
        return 1;
    if(num == 4 || num == 5)
        return 2;
    
    if(arr[num] != -1)
        return arr[num];

    return arr[num] = wave(num-1) + wave(num-5);
}

int main(){
    int n,a;
    arr = (unsigned long long*)malloc(sizeof(unsigned long long)*101);
    memset(arr,-1,sizeof(unsigned long long)*101);
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&a);
        printf("%llu\n",wave(a));
    }
    free(arr);
    return 0;
}

/*
 그냥 배열 사용 -> 메모리 사용 : 1116KB
 #include<stdio.h>
 #include<stdlib.h>
 #include<string.h>
 
 unsigned long long arr[101];
 unsigned long long wave(int num){
 if(num == 0)
 return 0;
 if(num == 1 || num == 2 || num == 3)
 return 1;
 if(num == 4 || num == 5)
 return 2;
 
 if(arr[num] != -1)
 return arr[num];
 
 return arr[num] = wave(num-1) + wave(num-5);
 }
 
 int main(){
 int n,a;
 memset(arr,-1,sizeof(unsigned long long)*101);
 scanf("%d",&n);
 for(int i=0;i<n;i++){
 scanf("%d",&a);
 printf("%llu\n",wave(a));
 }
 return 0;
 }
 */
