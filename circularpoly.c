#include<stdio.h>
#include<stdlib.h>
typedef struct polyNode *polyptr;
typedef struct polyNode{
 int coef;
 int expo;
 polyptr link;
};
polyptr cadd(polyptr,polyptr);
int compare(int a,int b);
void attach(int ,int ,polyptr*);
void main(){
 int no,i,coef,expo;
 polyptr a,b,a1,b1;
 a=(polyptr)malloc(sizeof(struct polyNode));
 a->expo=-1;
 a1=a;
 b=(polyptr)malloc(sizeof(struct polyNode));
 b->expo=-1;
 b1=b;
 printf("Enter number of terms of first polynomial\n");
 scanf("%d",&no);
 for(i=0;i<no;i++){
 printf("Enter coefficient and exponent\n");
 scanf("%d %d",&coef,&expo);
 attach(coef,expo,&a1);
 }
 printf("Enter number of terms of second polynomial\n");
 scanf("%d",&no);
 for(i=0;i<no;i++){
 printf("Enter coefficient and exponent\n");
 scanf("%d %d",&coef,&expo);
 attach(coef,expo,&b1);
 }
 a1->link=a;
 b1->link=b;
 polyptr c;
 c=cadd(a,b);
 printf("After addition\n");
 for(c=c->link;c->expo!=-1;c=c->link){
 printf("%dx^%d+",c->coef,c->expo);
 }
 printf("\b \b");
}
void attach(int coef,int expo,polyptr *a){
 polyptr temp=(polyptr)malloc(sizeof(struct polyNode));
 temp->coef=coef;
 temp->expo=expo;
 temp->link=NULL;
 (*a)->link=temp;
 (*a)=temp;
}
polyptr cadd(polyptr a,polyptr b){
 polyptr startA=a;
 int co,done=0;
 a=a->link;
 b=b->link;
 polyptr c,endC;
 c=(polyptr)malloc(sizeof(struct polyNode));
 c->expo=-1;
 endC=c;
 do{
 switch(compare(a->expo,b->expo)){
 case 1: attach(a->coef,a->expo,&endC);
 a=a->link;
break;
 case -1: attach(b->coef,b->expo,&endC);
 b=b->link;
 break;
 case 0: if(a==startA){
 done=1;
 }
else{
 co=a->coef+b->coef;
 if(co){
 attach(co,a->expo,&endC);
 }
 }
b=b->link;
a=a->link;
break;
 }
 }while(!done);
 endC->link=c;
 return c;
}
int compare(int a,int b){
 if(a==b){
 return 0;
 }
 else if(a>b){
 return 1;
 }
 else{
 return -1;
 }
}
