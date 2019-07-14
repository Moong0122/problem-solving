#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

char** word;
int arr[26];

int main(){
    int n, minus = 0;
    scanf("%d",&n);

    word = (char**)malloc(sizeof(char*)*n);
    for(int i=0;i<n;i++){
        word[i] = (char*)malloc(sizeof(char)*100);
    }

    for(int i=0;i<n;i++){ //3번진행!
        scanf("%s",word[i]); //happy입력받고
        for(int j=0;j<strlen(word[i]);i++){
            arr[atoi(word[i])-97] = j+1; //알파벳 순서를 입력하라 1부터~알파벳 길이만큼
            if(arr[atoi(word[i])-97] != 0 && (j+1) - arr[atoi(word[i])-97] >= 2){
                minus++;
                break;
            }
            memset(arr,0,sizeof(arr));
        }   
    }
    printf("%d\n", n-minus);
    free(word);
    return 0;
}

