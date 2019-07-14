#include <stdio.h>
#include <string.h>

int stack[51];
char g[50];

int main(){

    int n;
    //문자열을 입력받기 위해서는 입력받을 문자열의 길이만큼 배열을 만들어줘야 한다
    scanf("%d",&n);
    // ())(() 이 예제에서 걸린다 즉 stack을 인티저 변수말고 진짜 스택으로 만들어야 할 것 같다
    while(n--){
        int pointer = 0;
        scanf("%s",g);
        
        for(int i=0;i<50;i++){ //for문을 돌면서 stack을 계산해준다
            if(g[i] == '('){ //push 1을 해준다
                stack[pointer] = 1;
                pointer++;
            }
            if(g[i] == ')'){
                pointer--;
                if(pointer<0){
                    pointer += 50;
                    break;
                }
                stack[pointer] = 0;
            }
        }
        if (pointer == 0)
            printf("YES\n");
        else
            printf("NO\n");
        
        memset(g, 0, sizeof(g));
        memset(stack, 0, sizeof(stack));
    }
    
    return 0;
}

