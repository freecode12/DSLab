#include<stdio.h>
#include<stdlib.h>
typedefstructelement
{
intkey;
}element;
structstack
{
elementdata;
structstack*link;
};
typedefstructstack*stackpointer;

stackpointertop[10];
voidpush(elementitem,inti)
{
stackpointertemp;
temp=(stackpointer)malloc(sizeof(structstack));
temp->data=item;
temp->link=top[i];
top[i]=temp;
}
elementpop(inti)
{
stackpointertemp=top[i];
elementitem;
if(!temp)
{
item.key=-1;
returnitem;
}
item=top[i]->data;
top[i]=top[i]->link;
free(temp);
returnitem;
}
voiddisplay(inti)
{
stackpointertemp;
temp=top[i];
if(top[i]==NULL)
{
printf("stackisempty\n");
return;
}
printf("stack%dis\n",i+1);
for(;temp;temp=temp->link)
printf("%d\n",temp->data.key);
printf("\n");
}
intmain()
{
intstackno,choice;
elementitem;
while(1)
{
printf("Enter\n1.Push\n2.Pop\n3.Display\n4.Exit\n");
scanf("%d",&choice);
if(choice!=4)
{
printf("Enterstacknumberfrom1-10\n");
scanf("%d",&stackno);
}

switch(choice)
{
case1:printf("Enterdatatobeinserted:");
scanf("%d",&item.key);
push(item,stackno-1);
break;
case2:item=pop(stackno-1);
if(item.key==-1)
printf("Stackempty\n");
else
printf("Elementdeleted:%d\n",item.key);
break;
case3:display(stackno-1);
break;

case4:printf("OperationComplete\n");

exit(0);

}
}
}
