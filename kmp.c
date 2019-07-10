#include<stdio.h>
#include<string.h>
voidfail(char*pat,intfailure[])

{
inti,j,n=strlen(pat);
failure[0]=-1;
for(j=1;j<n;j++)
{
i=failure[j-1];
while((pat[j]!=pat[i+1])&&(i>=0))
i=failure[i];
if(pat[j]==pat[i+1])
failure[j]=i+1;

else

failure[j]=-1;

}
}
intpmatch(char*string,char*pat,intfailure[])
{
inti=0,j=0;
intlens=strlen(string);
intlenp=strlen(pat);
while(i<lens&&j<lenp)
{
if(string[i]==pat[j])
{
i++;
j++;
}
elseif(j==0)
i++;
else
j=failure[j-1]+1;

}
return((j==lenp)?(i-lenp):-1);
}
intmain()
{
charstring[50],pat[50];
intch,i;
intfailure[100];
printf("enterthestring\n");
scanf("%s",string);
printf("enterpattern\n");
scanf("%s",pat);
fail(pat,failure);
printf("%s\n",pat);
for(i=0;i<strlen(pat);i++)
printf("%d",failure[i]);
printf("\n");
printf("posofmatchis%d\n",pmatch(string,pat,failure)+1);
}
