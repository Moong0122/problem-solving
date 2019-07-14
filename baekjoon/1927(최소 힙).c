#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct HeapStruct{
    int Size;
    int *Elements;
}Heap;

Heap* CreateHeap(int heapsize);
void InsertMin(int X, Heap* H);
int DeleteMin(Heap* H);

int main()
{
    Heap *maxheap;
    int n,key,answer;
    scanf("%d",&n);
    maxheap = CreateHeap(n);

    for(int i=0;i<n;i++){
        scanf("%d",&key);
        if(key > 0)
            InsertMin(key, maxheap);
        else{
            answer = DeleteMin(maxheap);
            printf("%d\n", answer);
        }
    }
    return 0;
}
Heap* CreateHeap(int heapsize){
    Heap *h;
    h = (Heap*)malloc(sizeof(struct HeapStruct));
    h->Elements = (int*)malloc(sizeof(int)*(heapsize+1));
    h->Size = 0;

    return h;
}
void InsertMin(int X, Heap* H){
    int i;
    for(i = ++H->Size; i/2>0 && H->Elements[i/2]>X; i/=2){
        H->Elements[i] = H->Elements[i/2];
    }
    H->Elements[i] = X;
}
int DeleteMin(Heap* H){
    int i, child;
    int minElement, LastElement;

    if(H->Size == 0){
        return 0;
    }
    minElement = H->Elements[1];
    LastElement = H->Elements[H->Size--];

    for(i = 1; i*2<=H->Size;i=child){
        child = i*2;
        if(H->Elements[child+1] < H->Elements[child])
            child++;
        if(H->Elements[child] < LastElement)
            H->Elements[i] = H->Elements[child];
        else
            break;
    }
    H->Elements[i] = LastElement;
    return minElement;
}