#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int n;
    scanf("%d",&n);
    
    int arr[n][2];
    int rank[n];
    
    for(int i=0;i<n;i++){
        rank[i] = 1;
        scanf("%d%d",&arr[i][0],&arr[i][1]);
    }
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(arr[i][0] > arr[j][0] && arr[i][1] > arr[j][1])
            rank[j]++;
        }
    }
    for(int i = 0; i<n; i++){
        printf("%d ", rank[i]);
    }
    
    return 0;
}
