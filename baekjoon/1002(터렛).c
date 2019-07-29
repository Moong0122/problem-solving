#include<stdio.h>
#include<math.h>

int calculate(float x,float y, float r, float a,float b, float R){
    float big, small;
    if(r > R){
        big = r;
        small = R;
    }else{
        small = r;
        big = R;
    }
    float dis = sqrt(pow(x-a,2) + pow(y-b,2));
    if(x==a && y==b && r==R)
        return -1;
    else if(dis + small == big || dis == small + big)
        return 1;
    else if(dis < small+big && dis+small > big)
        return 2;
    else
        return 0;
}
int main(){
    int n;
    float x_one, y_one, r_one, x_two, y_two, r_two;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%f%f%f%f%f%f",&x_one, &y_one, &r_one, &x_two, &y_two, &r_two);
        printf("%d\n",calculate(x_one, y_one, r_one, x_two, y_two, r_two));
    }
    return 0;
}
