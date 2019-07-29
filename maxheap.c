#include<stdio.h>

int n = 0;
heap[100];

void push(int item)
{
 int p, c;
 if(n == 100){
 printf("Heap full\n");
 }
 else{

 c = n++;
 p = (c-1)/2;
 while(c!=0&&item>heap[p]){
 heap[c]=heap[p];
 c = p;
 p = (c-1)/2;
 }
 heap[c]=item;
 }
}

int pop(){
 int parent,child;
 int item,temp,t;
 t =-1;
 if(n == 0){
 return t;
 }
 item=heap[0];
 temp=heap[n-1];
 n--;
 parent=0;
 child=1;
 while(child<n){
 if(heap[child]<heap[child+1]){
 child++;
 }
 if(temp>=heap[child]){
 break;
 }
 heap[parent]=heap[child];
 parent=child;
 child=(parent*2)+1;
 }
 heap[parent]=temp;
 return item;
}

void display(){
if(n == 0)printf("Heap empty\n");
for(int t=0;t<n;t++){
 printf("%d\n",heap[t]);
 }
 printf("\n");
}

int main()
{
int choice, x=0;
int got;
while(x != -1){
 printf("1)Push\n");
 printf("2)Pop\n");
 printf("3)Display\n");
 printf("4)Exit\n");
 scanf("%d",&choice);
 switch(choice){
 case 1:{ printf("Enter element to be entered\n");
 scanf("%d",&got);
push(got);}
break;
 case 2: {got=pop();
 if(got==-1){
 printf("Empty heap\n");
 }
else{
 printf("%d popped\n",got);
 }}
break;
 case 3: {printf("Heap is: \n\n");
display();}
break;
 case 4: {x = -1;}
 break;
 }
 }
 return 0;
}
