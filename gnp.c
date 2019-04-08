#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    char value;
    int score;
    struct Node *left;
    struct Node *right;
    struct Node *newer;
}node;

void insertNode(node *root,char value,int score){
    node *tmp = root;
    while(tmp -> newer != NULL){
        tmp = tmp -> newer;
    }
    node *newNode = (node *)malloc(sizeof(node));
    newNode -> value = value;
    newNode -> left = NULL;
    newNode -> right = NULL;
    newNode -> score = score;
    newNode -> newer = NULL;
    tmp -> newer = newNode;
}

void listNodes(node *root){
    node *tmp = root;
    printf("\nvalue:\tscore:");
    while(tmp != NULL){
        printf("\n%c\t%d",tmp -> value, tmp -> score);
        tmp = tmp -> newer;
    }
}

void setPosition(node *root,char preOrder[],int n){
    node *tmp = root;
    node *next = tmp;

    char actualCh;
    char nextCh;
    for (int i = 0;i < n;i++){
        actualCh = preOrder[i];
        nextCh = next -> value;
        while(tmp -> value != actualCh){
            tmp = tmp -> newer;
        }
        while (nextCh != (preOrder[i + 1])){
            next = next -> newer;
        }
        if (tmp -> score > next -> score){
            tmp -> left = next;
        }
        else {
            tmp -> right = next;
        }
        tmp = root;
        next = tmp;
    }

}

int main(void){
    node *root = (node *)malloc(sizeof(node));
    root -> value = '\0';
    root -> score = 0;
    root -> left = NULL;
    root -> right = NULL;
    root -> newer = NULL;

    int c,actualN;

    scanf("%d",&c);

    for(int i = 0;i < c;i++){
        scanf("%d",&actualN);
        char preOderV[actualN];
        char inOrderV[actualN];

        scanf("%s",preOderV);
        scanf("%s",inOrderV);

        for(int j = 0;j<actualN;j++){
            insertNode(root,inOrderV[j],j + 1);
        }
        setPosition(root,preOderV,actualN);
    }


    // insertNode(root,'a',1);
    listNodes(root);

    return 0;
}