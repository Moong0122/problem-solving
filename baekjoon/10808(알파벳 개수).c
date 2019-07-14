#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int number[26];

int main()
{
    char* word;
    word = (char*)malloc(sizeof(char)*101);
    
    scanf("%s",word);
    
    for(int i=0;i<strlen(word);i++){
        number[word[i]-97]++;
    }
    for(int i=0;i<26;i++){
        printf("%d ", number[i]);
    }
    printf("\n");
    return 0;
}
