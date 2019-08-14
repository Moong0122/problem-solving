#include<stdio.h>
#include<stdlib.h>

int arr[500001];
int compare(const void *a, const void *b);
//int binarySearch(int target, int size);
int binarySearch(int left, int right, int target);
int main(){
    int n,m,a;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    qsort(arr,n,sizeof(int),compare);
    scanf("%d",&m);
    for(int i=0;i<m;i++){
        scanf("%d",&a);
        printf("%d ",binarySearch(0,n-1,a));
    }
    printf("\n");
    return 0;
}
int compare(const void *a, const void *b){
    if(*(int*)a < *(int*)b)
        return -1;
    if(*(int*)a > *(int*)b)
        return 1;
    else
        return 0;
}
int binarySearch(int left, int right, int target){
    int mid;
    
    if(left > right)
        return 0;
    mid = (left+right)/2;
    
    if(target == arr[mid])
        return 1;
    else if(target > arr[mid])
        return binarySearch(mid+1,right,target);
    else
        return binarySearch(left,mid-1,target);
}

// int binarySearch(int target, int size){
//     int l,r,mid;
//     l = 0;
//     r = size-1;
//     if(target < arr[l] || target > arr[r])
//         return 0;
//
//     while(l<=r){
//         mid = (l+r)/2;
//         if(target == arr[mid])
//             return 1;
//         if(target > arr[mid])
//             l = mid+1;
//         if(target < arr[mid])
//             r = mid-1;
//     }
//     return 0;
// }
