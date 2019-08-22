
#include<stdio.h>
#include<string.h>

char str1[1001];
char str2[1001];
int dp[1002][1002];
int checkDP(int x, int y);
int Max(int x, int y);
int main(){
	fgets(str1,sizeof(str1),stdin);
	fgets(str2,sizeof(str2),stdin);
	int len1 = strlen(str1);
	int len2 = strlen(str2);
	for(int i=0;i<len1-1;i++){
		for(int j=0;j<len2-1;j++){
			if(str1[i] == str2[j])
				dp[i][j] = checkDP(i-1,j-1)+1;
			else{
				dp[i][j] = Max(checkDP(i-1,j),checkDP(i,j-1));
			}
		}
	}
	printf("%d\n", dp[len1-2][len2-2])
	return 0;
}
int checkDP(int x, int y){
	if(x < 0 || y < 0)
		return 0;
	return dp[x][y];
}
int Max(int x, int y){
	return x>y ? x : y;
}
