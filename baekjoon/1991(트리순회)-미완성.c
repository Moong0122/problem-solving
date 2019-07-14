#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

typedef struct TreeNode* SearchTree;
typedef struct TreeNode* Node;
typedef int ElementType

typedef struct TreeNode{
    ElementType Element;
    SearchTree Left;
    SearchTree Right;
}Tree;

Node Find(ElementType X, SearchTree T);
SearchTree Insert(ElementType X, SearchTree T);
void printInorder(Tree* root);
void printPreorder(Tree* root);
void printPostorder(Tree* root);

int main(){
    Tree* root = NULL;
    int n;
    scanf("%d",&n);

    for(int i=0;i<n;i++){
        char element, left, rihgt;
        scanf("%c %c %c",&element, &left, &rihgt);
    }


    return 0;
}
void printInorder(Tree* root){
    if(root){
        printInorder(root->Left);
        printf("%d " , root->Element);
        printInorder(root->Right);
    }
}
void printPreorder(Tree* root){
    if(root){
        printf("%d ", root->Element);
        printPreorder(root->Left);
        printPreorder(root->Right);
    }
}
void printPostorder(Tree* root){
    if(root){
        printPostorder(root->Left);
        printPostorder(root->Right);
        printf("%d ", root->Element);
    }
}