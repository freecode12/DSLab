#include<stdio.h>

typedef struct node* treepointer;
struct node{
 int key;
 treepointer leftChild;
 treepointer rightChild;
};

void display(treepointer);
int* search(treepointer, int);
void insert(treepointer*, int);

void main()
{
 int choice,e, x = 0;
 int *ptr;
 treepointer root=NULL;
 while(x != -1){
 printf("1) Insert\n");
 printf("2) Search\n");
 printf("3) Display\n");
 printf("4) Exit\n");
 printf("Enter choice\n");
 scanf("%d",&choice);
 switch(choice){
 case 1: printf("Enter element to be inserted\n");
 scanf("%d",&e);
 insert(&root,e);
 break;
 case 2: printf("Enter element to be searched\n");
 scanf("%d",&e);
 ptr = search(root,e);
 if(ptr == NULL ){
 printf("Not found\n");
 }
 else{
 printf("%d found\n",*ptr);
 }
 break;
 case 3: printf("\nBST is: \n");
         display(root);
 printf("\n");
 break;
 case 4: x = -1;
 break;
 }
 }
}

void display(treepointer root){
 if(root){
 display(root->leftChild);
 printf("%d\n",root->key);
 display(root->rightChild);
 }
}

int* search(treepointer root,int k){
 if(root == NULL){
 return NULL;
 }
 if(k==root->key){
 return &(root->key);
 }
 else if(k>root->key){
 return search(root->rightChild,k);
 }
 else if(k<root->key){
 return search(root->leftChild,k);
 }
}
void insert(treepointer* root,int k){
 treepointer temp,cur,prev;
 temp=(treepointer)malloc(sizeof(struct node));
 temp->key=k;
 temp->rightChild=NULL;
 temp->leftChild=NULL;
 cur=(*root);
 prev=NULL;
 if((*root)==NULL){
 (*root)=temp;
 return;
 }
 while(cur){
 prev=cur;
 if(k>cur->key){
 cur=cur->rightChild;
 }
 else{
 cur=cur->leftChild;
 }
 }
 if(k>prev->key){
 prev->rightChild=temp;
 }
 else{
 prev->leftChild=temp;
 }
 return;
}
