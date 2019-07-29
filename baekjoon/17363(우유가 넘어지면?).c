#include<stdio.h>

int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    char arr[n][m];
    for(int i=0;i<n;i++){ // 7
        for(int j=0;j<m;j++){ // 6
            scanf(" %c",&arr[i][j]);
        }
    } // 그림 입력 완료
    for(int i=0;i<m;i++){ //6
        for(int j=0;j<n;j++){ //7
            if(arr[j][m-i-1] == '.')
                printf(".");
            else if(arr[j][m-i-1] == 'O')
                printf("O");
            else if(arr[j][m-i-1] == '-')
                printf("|");
            else if(arr[j][m-i-1] == '|')
                printf("-");                            
            else if(arr[j][m-i-1] == '/')
                printf("\\");
            else if(arr[j][m-i-1] == 92)
                printf("/");   
            else if(arr[j][m-i-1] == '^')
                printf("<"); 
            else if(arr[j][m-i-1] == '<')
                printf("v"); 
            else if(arr[j][m-i-1] == 'v')
                printf(">"); 
            else if(arr[j][m-i-1] == '>')
                printf("^");    
        }
        printf("\n");
    }
    return 0;
}
