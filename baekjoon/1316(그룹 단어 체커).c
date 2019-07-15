#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

char word[101];
int arr[26];
int main(){
    
    int n, total = 0,num;
    scanf("%d",&n);
    num = n;
    while(n--){
        scanf("%s",word);
        for(int i=0;i<strlen(word);i++){
            if(arr[word[i]-97] != 0 && (i+1) - arr[word[i]-97] >= 2){
                total += 1;
                break;
            }
            arr[word[i]-97] = i+1;
        }
        memset(word,0,sizeof(word));
        memset(arr, 0, sizeof(arr));
    }
    printf("%d\n",num-total);
    
    return 0;
}
