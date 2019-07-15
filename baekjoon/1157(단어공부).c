#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<ctype.h>

int alphabet[26];
int main(){
    int max = -1, double_ck = 0, max_location;
    char* word;
    word = (char*)malloc(sizeof(char)*1000001);
    scanf("%s",word);
    int len = strlen(word);
    
    for(int i=0;i<len;i++){
        if(isupper(word[i])){
            word[i] = tolower(word[i]);
        }
        alphabet[word[i]-97] += 1;
        
    }
    for(int i=0;i<26;i++){
        if(alphabet[i]>max){
            max = alphabet[i];
            max_location = i;
        }
    }
    for(int i=0;i<26;i++){
        if(alphabet[i] == max)
            double_ck += 1;
    }
    printf("%c\n",double_ck>=2 ? '?' : max_location+65);
    free(word);
    return 0;
}
