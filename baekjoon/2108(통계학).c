#include<stdio.h>
#include<stdlib.h>

int number[8002]; // 최빈값 구할 때 사용

int compare(const void *a, const void *b){
    int num1 = *(int*)a;
    int num2 = *(int*)b;
    if(num1 < num2)
        return -1;
    if(num1 > num2)
        return 1;
    else
        return 0;
}
int main(){
    int n, max = -1;
    double first = 0.0;
    int ck = 0,third;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
        first += arr[i]; // 산술평균에 쓸 합 구하기
        number[arr[i]+4000]++; //0부터 8002까지
        if(number[arr[i]+4000] > max)
            max = number[arr[i]+4000]; //최댓값을 바로 구해준다
    }
    for(int i=0;i<8002;i++){
        if(number[i] == max){
            third = i-4000;
            ck++;
            if(ck == 2)
                break;
        }
    }
    qsort(arr,n,sizeof(int),compare); // 중앙값, 범위 완성
    printf("%.lf\n",first/n);
    printf("%d\n", arr[(n-1)/2]);
    printf("%d\n", third);
    printf("%d\n", arr[n-1] - arr[0]);
    return 0;
}
