#include<stdio.h>
#include<stdlib.h>

typedef struct person{
    int age;
    char name[101];
}Person;

int compare(const void *a, const void *b){
    return ((Person*)a)->age > ((Person*)b)->age;
}
int main(){
    int n,j;
    scanf("%d",&n);
    Person p[n];
    for(int i=0;i<n;i++){
        scanf("%d %s",&p[i].age,p[i].name);
    }
    qsort(p,n,sizeof(Person),compare);

    for(int i=0;i<n;i++){
        printf("%d %s\n",p[i].age,p[i].name);
    }
    return 0;
}
