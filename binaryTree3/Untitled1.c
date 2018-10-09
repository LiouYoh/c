#include<stdio.h>
#include<stdlib.h>

typedef struct treeNode{
    int data;
    struct treeNode *left;
    struct treeNode *right;
}treeNode;

treeNode *Insert(treeNode *node,int data){
    if(node==NULL){
        treeNode *temp;
        temp = (treeNode *)malloc(sizeof(treeNode));
        temp -> data = data;
        temp -> left = temp -> right = NULL;
        return temp;
    }
    if(data >(node->data)){
        node->right = Insert(node->right,data);
    }
    else if(data < (node->data)){
        node->left = Insert(node->left,data);
    }
}

void PrintInorder(treeNode *node){
    if(node==NULL){
        return;
    }
    PrintInorder(node->left);
    printf("%d ",node->data);
    PrintInorder(node->right);
}

int main(){
    treeNode *root = NULL;
    root = Insert(root, 5);
    root = Insert(root, -1);
    root = Insert(root, 3);
    root = Insert(root, -14);
    root = Insert(root, 8);
    root = Insert(root, 10);
    root = Insert(root, 9);
    root = Insert(root, 6);
    PrintInorder(root);
}
