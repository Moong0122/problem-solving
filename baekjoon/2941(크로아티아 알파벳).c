#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
    char word[101];
    int cnt = 0;
    scanf("%s",word);
    
    int len=strlen(word);
    for(int i=0;i<len;i++){
        if(word[i] == 'c'){
            if(word[i+1] == '='|| word[i+1] == '-')
                i++;
        }else if(word[i] == 'd'){
            if(word[i+1] == 'z' && word[i+2] == '=')
                i+=2;
            else if(word[i+1] == '-')
                i++;
        }else if(word[i] == 'l' || word[i] == 'n'){
            if(word[i+1] == 'j')
                i++;
        }else if(word[i] == 's' || word[i] == 'z'){
            if(word[i+1] == '=')
                i++;
        }
        cnt++;
    }
    printf("%d\n",cnt);
    
    return 0;
}
