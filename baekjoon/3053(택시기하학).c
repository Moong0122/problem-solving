#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int main(){
    int r;
    scanf("%d",&r);
    double answer_u, answer_t;
    answer_u = M_PI * r * r;
    answer_t = 2 * r * r;
    printf("%6lf\n%6lf\n",answer_u,answer_t);
    return 0;
}
