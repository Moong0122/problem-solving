#include<stdio.h>
#include<string.h>

char sentence[102];
int stack[102];
int sp = 0,check = 0;
int main(){
	fgets(sentence,sizeof(sentence),stdin); 
	while(sentence[0] != '.'){
		int len = strlen(sentence);
		for(int i=0;i<len;i++){
			if(sentence[i] == '['){
				stack[sp] = 1;
				sp++;
			}else if(sentence[i] == '('){
				stack[sp] = 2;
				sp++;
			}else if(sentence[i] == ')'){
				if(i-1>=0 && stack[sp-1] == 2)
					sp--;
				else{
					check = 1;
					break;
				}
			}else if(sentence[i] == ']'){
				if(i-1>=0 && stack[sp-1] == 1)
					sp--;
				else{
					check = 1;
					break;
				}
			}
			if(check == 1)
				break;
		}
		if(sp == 0 && check == 0)
			printf("yes\n");
		else
			printf("no\n");
		sp = 0;
		check = 0
		sentence[0] = '\0';
		fgets(sentence,sizeof(sentence),stdin);
	}
	return 0;
}