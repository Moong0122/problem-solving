#include<stdio.h>

int arr[1001][11];
int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=10;i++){
		arr[0][i] = 1;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=10;j++){
			arr[i][j] = ((arr[i][j-1]%10007) + (arr[i-1][j]%10007))%10007;
		}
	}
	printf("%d\n", arr[n][10]);
	return 0;
}
/*
0	1	2	3	4	5	6	7	8	9	10
------------------------------------------
0	1	1	1	1	1	1	1	1	1	1	[0]
0	1	2	3	4	5	6	7	8	9	10	[1]
0	1	3	6	10	15	21	28	36	45	55	[2]
*/
