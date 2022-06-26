#include<stdio.h>
#include<string.h>
#include<malloc.h>
struct std
{
	int admn,l,e,m,ss,so,total,cls;
	char sname[15],res[10],fname[15],dob[12];
	float avg;
};
void main()
{
	int ch,i;
	struct std n;
	FILE *fp;
	do
	{
    	printf("      Main Menu :- \n");
		printf("----------------------\n");
		printf("1. Add New Student\n2. Display List\n0. Exit\n\nEnter Your Choice : ");
		scanf("%d",&ch);
        switch(ch)
		{
			case 1:
				fp=fopen("std.dat","ab+");
				if(fp==NULL)
				{
					printf("File not Opened");
					exit(0);
				}
				printf("Admn : ");
				fflush(stdin);
				scanf("%d",&n.admn);
 			    printf("Student Name : ");
				fflush(stdin);
				scanf("%s",&n.sname);
				printf("Class(Only Numbers) : ");
				fflush(stdin);
				scanf("%d",&n.cls);
				printf("Father Name : ");
				fflush(stdin);
				scanf("%s",&n.fname);
				printf("Date Of birth : ");
				fflush(stdin);
				scanf("%s",&n.dob);
				printf("Language1 : ");
				fflush(stdin);
				scanf("%d",&n.l);
				printf("English : ");
				fflush(stdin);
				scanf("%d",&n.e);
				printf("Maths : ");
				fflush(stdin);
				scanf("%d",&n.m);
				printf("Science : ");
				fflush(stdin);
				scanf("%d",&n.ss);
				printf("Social : ");
				fflush(stdin);
				scanf("%d",&n.so);
				n.total=n.l+n.e+n.m+n.ss+n.so;
				n.avg=n.total/5.0;
				if(n.l<35||n.e<35||n.m<35||n.ss<35||n.so<35)
					strcpy(n.res,"FAIL");
				else if(n.avg>=90)
					strcpy(n.res,"DIST");
				else if(n.avg>=70)
					strcpy(n.res,"FIRST");
				else if(n.avg>=50)
					strcpy(n.res,"SECOND");
				else
					strcpy(n.res,"THIRD");
				printf("%d %s %s %s %d %d %d %d %d %d %d %.2f %s\n",n.admn,n.sname,n.fname,n.dob,n.cls,n.l,n.e,n.m,n.ss,n.so,n.total,n.avg,n.res);
				fwrite(&n,sizeof(n),1,fp);
				fclose(fp);
			break;
			case 2:
				fp=fopen("std.dat","rb+");
				if(fp==NULL)
				{
					printf("File not Opened");
					exit(0);
				}
				while(fread(&n,sizeof(n),1,fp)!=0)
				{
					printf("%d %s %s %s %d %d %d %d %d %d %d %.2f %s\n",n.admn,n.sname,n.fname,n.dob,n.cls,n.l,n.e,n.m,n.ss,n.so,n.total,n.avg,n.res);
				}
				fclose(fp);
			break;

			case 0:
				exit(0);
			break;
			default:
				printf("Invalid Choice try again...!");
		}
	}while(1);
}