//error 
#include<stdio.h> 
#include<conio.h> 
typedef struct 
{int sno; 
char name[25];int m1,m2,m3; 
}STD; 
void display(FILE *); 
int search(FILE *); 
main() 
{int i,n,sno_key,opn; 
FILE *fp;  
printf("How many records ?"); 
scanf("%d",&n); 
fp=fopen("stud.dat","w"); 
for(i=0;i<n;i++) 
{printf("Enter the student information : %d(sno,Name,M1,M2,M3):",i+1); 
scanf("%d%s%d%d%d",&s.sno,s.name,&s.m1,&s.m2,&s.m3); 
fwrite(&s,sizeof(s),1,fp); 
} 
fclose(fp); 
fp=fopen("stdu.dat","r"); 
 do
 {printf("1-DISPLAY\n2.SEARCH\n 3.EXIT\n YOUR OPTION: "); 
scanf("%d",&open); 
switch(opn) 
{ 
case 1: 
printf("\n Student Records in the file \n"); 
display(fp); 
break; 
case 2: 
printf("Read sno of the student to be searched :"); 
scanf("%d",&sno_key); 
if(search(fp,sno_key)){ 
printf("success!! Record found in the file\n"); 
printf("%d\t%s\t%d\t%d\t%d\n", s.sno,s.name,s.m1,s.m2,s.m3); 
} 
else 
printf("Failure!! Record %d not found\n",sno_key); 
break; 
case 3: 
printf("Exit !! press key"); 
getch(); 
break; 
default: 
printf("Invalid option!!! Try again!!\n"); 
break; 
} 
}while(opn!=3); 
fclose(fp); 
} 
Void display(FILE *fp) 
{rewind(fp); 
while(fread(&s,sizeof(s),1,fp)) 
printf("%d\t%s\t%d\t%d\t%d\n",s.sno,s.name,s.m1,s.m2,s.m3); 
} 
int search(FILE *fp,int sno_key) 
{rewind(fp); 
while(fread(&s,sizeof(s),1,fp)) 
If(s.sno==sno_key) 
return 1; 
return 0; 
}
