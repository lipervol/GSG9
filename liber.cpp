#include<stdio.h>
#include<string.h>
#include <stdlib.h>
#include<windows.h>
#include<conio.h>
#include <time.h>
#define N 1000
static char localuser[100];
static char localday[100];
typedef struct Logs
{
	char name[100];
	char book1[100];
	char time1[100];
	char book2[100];
	char time2[100];
	char book3[100];
	char time3[100];
}Log;
typedef struct Users
	{
		char name[100];
		char passwd[100];
		char num[100];
		char tel[100]; 
	}User;
//ʱ�亯�� 
void data()
{
	char year[100],mon[100],day[100],data[100];
	time_t t; 
	struct tm * lt;
	time (&t);                  
	lt = localtime (&t);
	int y=lt->tm_year+1900,m=lt->tm_mon+1,d=lt->tm_mday;
	if(m==13) m=1;         
    itoa(y,year,10);
    itoa(m,mon,10);
    itoa(d,day,10);
    strcpy(data,year);
	strcat(data,"/");
	strcat(data,mon);
	strcat(data,"/");
	strcat(data,day);
	strcpy(localday,data);
}
//�������� 
int linenum()
{
	char s[100];
    FILE *fp;
    int lines=0;
    fp=fopen("liberary.txt", "r");
    while((fgets(s,100,fp))!=NULL)
        if(s[strlen(s)-1]=='\n'&&strlen(s)>1) lines++;
    fclose(fp);
    return lines+1;
}
//���������������У� 
int lineall()
{
	char s[100];
    FILE *fp;
    int lines=0;
    fp=fopen("liberary.txt", "r");
    while((fgets(s,100,fp))!=NULL)
        if(s[strlen(s)-1]=='\n') lines++;
    fclose(fp);
    return lines;
}
int linelog()
{
	char s[100];
    FILE *fp;
    int lines=0;
    fp=fopen("log.txt", "r");
    while((fgets(s,100,fp))!=NULL)
        if(s[strlen(s)-1]=='\n') lines++;
    fclose(fp);
    return lines;
}
//ˢ�º��� 
void renew()
{
	typedef struct Books
    {
    	int num;
        char name[100];
        char author[100];
        float price;
        char borr[100];
       	char user[100]; 
       	char time[100];
    }Book;
    Book book[N];
    FILE *fp=fopen("liberary.txt","r+");
    int i,n;
    n=lineall();
    for(i=0;i<n;i++) fscanf(fp,"%d\t%s\t\t%s\t\t%f\t\t%s\t%s\t%s",&book[i].num,book[i].name,book[i].author,&book[i].price,book[i].borr,book[i].user,book[i].time);
    fclose(fp);
    FILE *fp1=fopen("liberary.txt","w");
    fclose(fp1);
    for(i=0;i<n;i++) 
	{
		FILE *fp2=fopen("liberary.txt","a");
		if(book[i].num!=0)
		fprintf(fp,"%d\t%s\t\t%s\t\t%.2f\t\t%s\t%s\t%s\n",linenum(),book[i].name,book[i].author,book[i].price,book[i].borr,book[i].user,book[i].time);
		fclose(fp2);
	}
}
//���麯�� 
void storebooks()
{
    typedef struct Books
    {
        char name[100];
        char author[100];
        float price;
    }Book;
    Book book[N];
    int n,i;
    printf("\t\t\t\t    root$>>������Ҫ������������:");
    scanf("%d",&n);
    printf("\t\t\t\t    root$>>�������������������ߡ��۸�:\n\t\t\t\t    ���� BOOK1 Tom 10.00\n");
    for(i=0;i<n;i++) 
	{
	printf("\t\t\t\t    ");
	scanf("%s %s %f",book[i].name,book[i].author,&book[i].price);
	} 
    for(i=0;i<n;i++) 
	{
		FILE *fp=fopen("liberary.txt","a");
		fprintf(fp,"%d\t%s\t\t%s\t\t%.2f\t\t�ڼ�\t��\t�޼�¼\n",linenum(),book[i].name,book[i].author,book[i].price);
		fclose(fp);
	}
} 
//�������� 
void search()
{pos1:
	typedef struct Books
    {
    	int num;
        char name[100];
        char author[100];
        float price;
        char borr[100];
       	char user[100]; 
       	char time[100];
    }Book;
    Book book[N];
    FILE *fp=fopen("liberary.txt","r+");
    int i,n;
    n=lineall();
    for(i=0;i<n;i++) fscanf(fp,"%d\t%s\t\t%s\t\t%f\t\t%s\t%s\t%s",&book[i].num,book[i].name,book[i].author,&book[i].price,book[i].borr,book[i].user,book[i].time);
    fclose(fp);
	printf("\t\t\t\t    <%s>#>>��ѡ��Ҫ���ҵ�����:[1]����[2]����[3]ȫ����Ϣ",localuser);
	char m;
	m=getch();
	printf("\n");
	if(m=='1'){
	printf("\t\t\t\t    <%s>#>>��������:",localuser);
	char a[100];
	scanf("%s",a);
	printf("\t\t\t  ID\t|����\t\t|����\t\t|�۸�\t\t|�ܷ����\n");
	printf("\t\t\t------------------------------------------------------------------------\n");
	for(i=0;i<n;i++)
	if(!strcmp(a,book[i].name)) printf("\t\t\t  %d\t|%s\t\t|%s\t\t|%.2f\t\t|%s\n",book[i].num,book[i].name,book[i].author,book[i].price,book[i].borr);
	printf("\t\t\t------------------------------------------------------------------------\n");
	}
	else if(m=='2'){
	printf("\t\t\t\t    <%s>#>>��������:",localuser);
	char b[100];
	scanf("%s",b);
	printf("\t\t\t  ID\t|����\t\t|����\t\t|�۸�\t\t|�ܷ����\n");
	printf("\t\t\t------------------------------------------------------------------------\n");
	for(i=0;i<n;i++)
	if(!strcmp(b,book[i].author)) printf("\t\t\t  %d\t|%s\t\t|%s\t\t|%.2f\t\t|%s\n",book[i].num,book[i].name,book[i].author,book[i].price,book[i].borr);
	printf("\t\t\t------------------------------------------------------------------------\n");
	}
	else if(m=='3'){
	printf("\t\t\t  ID\t|����\t\t|����\t\t|�۸�\t\t|�ܷ����\n");
	printf("\t\t\t------------------------------------------------------------------------\n");
	for(i=0;i<n;i++)
	printf("\t\t\t  %d\t|%s\t\t|%s\t\t|%.2f\t\t|%s\n",book[i].num,book[i].name,book[i].author,book[i].price,book[i].borr);	
	printf("\t\t\t------------------------------------------------------------------------\n");
	} 
	else
	printf("\t\t\t\t    <%s>#>>������1��2��3��",localuser); 
	printf("\t\t\t\t    <%s>$>>�Ƿ������ѯ��[1]��[2]��",localuser);
	char gsg;
	printf("\n");
	pos2:
	gsg=getch();
	if(gsg=='1') goto pos1;
	else if(gsg=='2');
	else goto pos2;
}
//ɾ������ 
void delbook()
{pos1:
	typedef struct Books
    {
    	int num;
        char name[100];
        char author[100];
        float price;
        char borr[100];
       	char user[100]; 
       	char time[100];
    }Book;
    Book book[N];
    FILE *fp=fopen("liberary.txt","r+");
    int i,n;
    n=lineall();
    for(i=0;i<n;i++) fscanf(fp,"%d\t%s\t\t%s\t\t%f\t\t%s\t%s\t%s",&book[i].num,book[i].name,book[i].author,&book[i].price,book[i].borr,book[i].user,book[i].time);
    fclose(fp);
    Log log[N];
    FILE *fp0=fopen("log.txt","r+");
    int nl,il;
	nl=linelog();
    for(il=0;il<nl;il++) fscanf(fp0,"%s\t%s\t%s\t%s\t%s\t%s\t%s",log[il].name,log[il].book1,log[il].time1,log[il].book2,log[il].time2,log[il].book3,log[il].time3);
    fclose(fp0);
    int m;
    printf("\t\t\t\t    root$>>������Ҫɾ�����ID(��������0):");
    scanf("%d",&m);
    if(m<=0||m>=linenum()) printf("\t\t\t\t    root$>>���鲻����\n");
    if(strcmp(book[m-1].time,"�޼�¼")) 
		printf("\t\t\t\t    root$>>�������˽��ģ��޷�ɾ����\n");
    if(!strcmp(book[m-1].time,"�޼�¼"))
    {
    for(i=0;i<n;i++)
	if(book[i].num==m) {
	printf("\t\t\t\t    root$>>ȷ�ϸ�����Ϣ��\n");
	printf("\t\t\t  ID\t|����\t\t|����\t\t|�۸�\t\t|�ܷ����\n");
	printf("\t\t\t------------------------------------------------------------------------\n");
	printf("\t\t\t  %d\t|%s\t\t|%s\t\t|%.2f\t\t|%s\n",book[i].num,book[i].name,book[i].author,book[i].price,book[i].borr);	
	printf("\t\t\t------------------------------------------------------------------------\n");
	printf("\t\t\t\t    root$>>�Ƿ�ɾ��[1]��[2]��\n");
	char t;
	pos_1: 
	t=getch();
	if(t=='1')
	{book[i].num=0; 
	printf("\t\t\t\t    root$>>ɾ�����\n");}
	else if(t=='2');
	else goto pos_1; 
	} 
	}
	FILE *fp1=fopen("liberary.txt","w");
    fclose(fp1);
    for(i=0;i<n;i++) 
	{
		FILE *fp2=fopen("liberary.txt","a");
		if(book[i].num!=0)
		fprintf(fp,"%d\t%s\t\t%s\t\t%.2f\t\t%s\t%s\t%s\n",linenum(),book[i].name,book[i].author,book[i].price,book[i].borr,book[i].user,book[i].time);
		fclose(fp2);
	}
	printf("\t\t\t\t    root$>>�Ƿ����ɾ����[1]��[2]��");
	char gsg;
	printf("\n");
	pos2:
	gsg=getch();
	if(gsg=='1') goto pos1;
	else if(gsg=='2');
	else goto pos2;
}
//���ĺ��� 
void borrow()
{
	data();
	typedef struct Books
    {
    	int num;
        char name[100];
        char author[100];
        float price;
        char borr[100];
       	char user[100]; 
       	char time[100];
    }Book;
    Book book[N];
    FILE *fp=fopen("liberary.txt","r+");
    int i,n;
    n=lineall();
    for(i=0;i<n;i++) fscanf(fp,"%d\t%s\t\t%s\t\t%f\t\t%s\t%s\t%s",&book[i].num,book[i].name,book[i].author,&book[i].price,book[i].borr,book[i].user,book[i].time);
    fclose(fp);
    Log log[N];
    FILE *fp0=fopen("log.txt","r+");
    int nl,il;
	nl=linelog();
    for(il=0;il<nl;il++) fscanf(fp0,"%s\t%s\t%s\t%s\t%s\t%s\t%s",log[il].name,log[il].book1,log[il].time1,log[il].book2,log[il].time2,log[il].book3,log[il].time3);
    for(il=0;il<nl;il++) if(!strcmp(log[il].name,localuser)) break;
    fclose(fp0);
    int signlog=0;
    if(!strcmp(log[il].time1,"�޼�¼")&&signlog==0) signlog=1;
	else if(!strcmp(log[il].time2,"�޼�¼")&&signlog==0) signlog=2;
	else if(!strcmp(log[il].time3,"�޼�¼")&&signlog==0) signlog=3;
	int m;
    printf("\t\t\t\t    <%s>#>>������Ҫ���ĵ����ID:",localuser);
    scanf("%d",&m);
    if(m>=linenum()||m<=0) printf("\t\t\t\t    <%s>#>>���鲻����\n",localuser);
    if(m<linenum()&&m>0&&signlog==0) printf("\t\t\t\t    <%s>#>>ֻ��������������\n",localuser); 
    for(i=0;i<n;i++)
	if(book[i].num==m&&signlog!=0)
	{
		if(!strcmp(book[i].borr,"�ڼ�"))
			{
			strcpy(book[i].borr,"�ѽ��");
			strcpy(book[i].user,localuser);
			strcpy(book[i].time,localday);
			if(signlog==1) {strcpy(log[il].book1,book[i].name);strcpy(log[il].time1,localday);}
			else if(signlog==2) {strcpy(log[il].book2,book[i].name);strcpy(log[il].time2,localday);}
			else {strcpy(log[il].book3,book[i].name);strcpy(log[il].time3,localday);}
			printf("\t\t\t\t    <%s>#>>���ĳɹ�\n",localuser);
			}
		else printf("\t\t\t\t    <%s>#>>�����ѽ��\n",localuser);
	}
	FILE *fp1=fopen("liberary.txt","w");
    fclose(fp1);
    for(i=0;i<n;i++) 
	{
		FILE *fp2=fopen("liberary.txt","a");
		if(book[i].num!=0)
		fprintf(fp2,"%d\t%s\t\t%s\t\t%.2f\t\t%s\t%s\t%s\n",linenum(),book[i].name,book[i].author,book[i].price,book[i].borr,book[i].user,book[i].time);
		fclose(fp2);
	}
	FILE *fp3=fopen("log.txt","w");
    fclose(fp3);
    FILE *fp4=fopen("log.txt","a");
    for(il=0;il<nl;il++) 
	fprintf(fp4,"%s\t%s\t%s\t%s\t%s\t%s\t%s\n",log[il].name,log[il].book1,log[il].time1,log[il].book2,log[il].time2,log[il].book3,log[il].time3);
	fclose(fp4);
	printf("\t\t\t\t    <%s>#>>�����������",localuser);
	getch(); 
}
//���麯�� 
void retu()
{
	typedef struct Books
    {
    	int num;
        char name[100];
        char author[100];
        float price;
        char borr[100];
       	char user[100]; 
       	char time[100];
    }Book;
    Book book[N];
    FILE *fp=fopen("liberary.txt","r+");
    int i,n;
    n=lineall();
    for(i=0;i<n;i++) fscanf(fp,"%d\t%s\t\t%s\t\t%f\t\t%s\t%s\t%s",&book[i].num,book[i].name,book[i].author,&book[i].price,book[i].borr,book[i].user,book[i].time);
    fclose(fp);
    Log log[N];
    FILE *fp0=fopen("log.txt","r+");
    int nl,il;
	nl=linelog();
    for(il=0;il<nl;il++) fscanf(fp0,"%s\t%s\t%s\t%s\t%s\t%s\t%s",log[il].name,log[il].book1,log[il].time1,log[il].book2,log[il].time2,log[il].book3,log[il].time3);
    for(il=0;il<nl;il++) if(!strcmp(log[il].name,localuser)) break;
    fclose(fp0);
    int m;
    printf("\t\t\t\t    <%s>#>>������Ҫ�黹�����ID:",localuser);
    scanf("%d",&m);
    int signlog=0;
    if(m>linenum()||m<=0) printf("\t\t\t\t    <%s>#>>���鲻����\n",localuser);
    if(!strcmp(book[m-1].borr,"�ڼ�")&&m>0&&m<=linenum()) printf("\t\t\t\t    <%s>#>>����δ�����\n",localuser);
    if(m>0&&m<=linenum()&&strcmp(book[m-1].user,localuser)) printf("\t\t\t\t    <%s>��δ���Ĵ��飡\n",localuser);
    if(m<=linenum()&&m>0)
    {
    	if(!strcmp(log[il].book1,book[m-1].name)&&signlog==0) signlog=1;
    	if(!strcmp(log[il].book2,book[m-1].name)&&signlog==0) signlog=2;
    	if(!strcmp(log[il].book3,book[m-1].name)&&signlog==0) signlog=3;
	}
    for(i=0;i<n;i++)
	if(book[i].num==m&&signlog!=0)
	{
		if(!strcmp(book[i].borr,"�ѽ��")&&!strcmp(book[i].user,localuser))
			{
			if(signlog==1) {strcpy(log[il].book1,"�޼�¼");strcpy(log[il].time1,"�޼�¼");}
			if(signlog==2) {strcpy(log[il].book2,"�޼�¼");strcpy(log[il].time2,"�޼�¼");}
			if(signlog==3) {strcpy(log[il].book3,"�޼�¼");strcpy(log[il].time3,"�޼�¼");}
			strcpy(book[i].borr,"�ڼ�");
			strcpy(book[i].user,"��");
			strcpy(book[i].time,"�޼�¼");
			printf("\t\t\t\t    <%s>#>>�黹�ɹ�\n",localuser);
			}
	}	
	FILE *fp1=fopen("liberary.txt","w");
    fclose(fp1);
    for(i=0;i<n;i++) 
	{
		FILE *fp2=fopen("liberary.txt","a");
		if(book[i].num!=0)
		fprintf(fp2,"%d\t%s\t\t%s\t\t%.2f\t\t%s\t%s\t%s\n",linenum(),book[i].name,book[i].author,book[i].price,book[i].borr,book[i].user,book[i].time);
		fclose(fp2);
	}
	FILE *fp3=fopen("log.txt","w");
    fclose(fp3);
    FILE *fp4=fopen("log.txt","a");
    for(il=0;il<nl;il++) 
	fprintf(fp4,"%s\t%s\t%s\t%s\t%s\t%s\t%s\n",log[il].name,log[il].book1,log[il].time1,log[il].book2,log[il].time2,log[il].book3,log[il].time3);
	fclose(fp4);
	printf("\t\t\t\t    <%s>#>>�����������",localuser);
	getch(); 
}
// user��������
int userall()
{
	char s[100];
    FILE *fp;
    int lines=0;
    fp=fopen("users.txt", "r");
    while((fgets(s,100,fp))!=NULL)
        if(s[strlen(s)-1]=='\n') lines++;
    fclose(fp);
    return lines;
}
void passwd(char p[])
{
	int i;
	for(i=0;i<100;i++)
	{
		p[i]=getch();
		if(p[i]=='\r')
		break;
		printf("*");
	}
	p[i]='\0';
}
// ע�ắ�� 
void logon()
{
	User user[N];
	FILE *fp=fopen("users.txt","r");
	int l=userall(),i;
	for(i=0;i<l;i++)
		fscanf(fp,"%s\t%s\t%s\t%s",user[i].name,user[i].passwd,user[i].num,user[i].tel);	
	fclose(fp);
	while(1)
	{
	system("cls");
	char n[100],p1[100],p2[100];
	printf("\t\t\t\t    ************************************\n");
	printf("\t\t\t\t                 ע    ��               \n");
	printf("\t\t\t\t    ************************************\n");
	printf("\t\t\t\t    #>>�����û�����"); 
	scanf("%s",n);
	int sign=0;
	for(i=0;i<l;i++)
		if(!strcmp(user[i].name,n)) sign=1;
		else if(!strcmp(n,"��")) sign=2;
	if(sign) 
	{
	char exit;
	if(sign==1)
	printf("\t\t\t\t    #>>���û���ע�ᣡ[1]����ע��[2]�˳�\n");
	else if(sign==2)
	printf("\t\t\t\t    #>>������Ϸ����û�����[1]����ע��[2]�˳�\n"); 
	exit=getch();
	if(exit=='1') continue;
	else break;
	}
	char m[100];
	int signs=0;
	printf("\t\t\t\t    #>>������ѧ�ţ�");
	scanf("%s",m); 
	for(i=0;i<l;i++)
		if(!strcmp(user[i].num,m)) signs=1;
		if(strlen(m)!=10) signs=2; 
	if(signs) 
	{
	char exit;
	if(signs==1)
	printf("\t\t\t\t    #>>��ѧ����ע�ᣡ[1]����ע��[2]�˳�\n");
	if(signs==2)
	printf("\t\t\t\t    #>>��������ȷ��ѧ�ţ�[1]����ע��[2]�˳�\n");
	exit=getch();
	if(exit=='1') continue;
	else break;
	}
	char g[100];
	int signss=0;
	printf("\t\t\t\t    #>>�������ֻ��ţ�");
	scanf("%s",g); 
	for(i=0;i<l;i++)
		if(!strcmp(user[i].tel,g)) signss=1;
		if(strlen(g)!=11) signss=2; 
	if(signss) 
	{
	char exit;
	if(signss==1)
	printf("\t\t\t\t    #>>���ֻ�����ע�ᣡ[1]����ע��[2]�˳�\n");
	if(signss==2)
	printf("\t\t\t\t    #>>��������ȷ���ֻ��ţ�[1]����ע��[2]�˳�\n");
	exit=getch();
	if(exit=='1') continue;
	else break;
	}
	printf("\t\t\t\t    #>>��������:");
	passwd(p1);
	printf("\n");
	printf("\t\t\t\t    #>>��������һ�Σ�");
	passwd(p2); 
	printf("\n");
	if(!strcmp(p1,p2))
	{
	printf("\t\t\t\t    #>>ע����ɣ�\n\t\t\t\t    #>>�������ȷ��\n");
	getch();
	FILE *fp1=fopen("users.txt","a");
	fprintf(fp1,"%s\t%s\t%s\t%s\n",n,p1,m,g);
	fclose(fp1);
	FILE *fp2=fopen("log.txt","a");
	fprintf(fp2,"%s\t�޼�¼\t�޼�¼\t�޼�¼\t�޼�¼\t�޼�¼\t�޼�¼\t\n",n);
	fclose(fp2);
	break;
	}
	else 
	{
	char exit;
	printf("\t\t\t\t    #>>���벻һ�£�������ע�ᣡ[1]����ע��[2]�˳�\n");
	exit=getch();
	if(exit=='1') continue;
	else break; 
	}
	}
}
//�޸ĺ��� 
void revise()
{pos1:
	typedef struct Books
    {
    	int num;
        char name[100];
        char author[100];
        float price;
        char borr[100];
       	char user[100]; 
       	char time[100];
    }Book;
    Book book[N];
    FILE *fp=fopen("liberary.txt","r+");
    int i,n;
    n=lineall();
    for(i=0;i<n;i++) fscanf(fp,"%d\t%s\t\t%s\t\t%f\t\t%s\t%s\t%s",&book[i].num,book[i].name,book[i].author,&book[i].price,book[i].borr,book[i].user,book[i].time);
    fclose(fp);
	int a;
	printf("\t\t\t\t    root$>>������Ҫ�޸ĵ����ID:");
	scanf("%d",&a);
	if(strcmp(book[a-1].time,"�޼�¼")&&a>0&&a<=n) printf("\t\t\t\t    root$>>�����ѽ�����޷��޸ģ�\n");
	if(a<=0||a>n) printf("\t\t\t\t    root$>>��ID�����ڣ�\n");
	char b;
	pos2:
	if(!strcmp(book[a-1].time,"�޼�¼")&&a>0&&a<=n)
	{
	    printf("\t\t\t\t    root$>>������Ҫ�޸ĵ����ݣ�[1]����[2]����[3]�۸�[4]���ع��ܲ˵�");
	    printf("\n");
	    pos0:
	    b=getch();
		if(b=='1')
		{
			char c[100];
			printf("\t\t\t\t    root$>>��������Ϊ��");
			scanf("%s",c);
			strcpy(book[a-1].name,c);
		}
		else if(b=='2')
		{
			char c[100];
			printf("\t\t\t\t    root$>>�����߸�Ϊ��");
			scanf("%s",c);
			strcpy(book[a-1].author,c);
		}
		else if(b=='3')
		{
			float c;
			printf("\t\t\t\t    root$>>���۸��Ϊ��");
			scanf("%f",&c);
			book[a-1].price=c;
		}
		if(b=='1'||b=='2'||b=='3') 
		{
		printf("\t\t\t\t    root$>>�Ƿ�����Ը����޸ģ�[1]��[2]��");
		char d;
		printf("\n");
		pos3:
		d=getch();
		if(d=='1') goto pos2;
		else if(d=='2');
		else goto pos3;
		}
		else if(b=='4');
		else goto pos0;
	}
	FILE *fp1=fopen("liberary.txt","w");
    fclose(fp1);
    for(i=0;i<n;i++) 
	{
		FILE *fp2=fopen("liberary.txt","a");
		if(book[i].num!=0)
		fprintf(fp2,"%d\t%s\t\t%s\t\t%.2f\t\t%s\t%s\t%s\n",linenum(),book[i].name,book[i].author,book[i].price,book[i].borr,book[i].user,book[i].time);
		fclose(fp2);
	}
	if(b!='4')
	{
	printf("\t\t\t\t    root$>>�Ƿ�����޸ģ�[1]��[2]��");
	char gsg;
	printf("\n");
	pos4:
	gsg=getch();
	if(gsg=='1') goto pos1;
	else if(gsg=='2');
	else goto pos4;
	}
}
//�߼����� 
void rootsearch()
{pos1: 
	typedef struct Books
    {
    	int num;
        char name[100];
        char author[100];
        float price;
        char borr[100];
       	char user[100]; 
       	char time[100];
    }Book;
    Book book[N];
    FILE *fp=fopen("liberary.txt","r+");
    int i,n;
    n=lineall();
    for(i=0;i<n;i++) fscanf(fp,"%d\t%s\t\t%s\t\t%f\t\t%s\t%s\t%s",&book[i].num,book[i].name,book[i].author,&book[i].price,book[i].borr,book[i].user,book[i].time);
    fclose(fp);
	printf("\t\t\t\t    root$>>��ѡ��Ҫ���ҵ�����:[1]����[2]����[3]ȫ����Ϣ[4]�ѽ���鼮");
	char m;
	m=getch();
	printf("\n");
	if(m=='1'){
	printf("\t\t\t\t    root$>>��������:");
	char a[100];
	scanf("%s",a);
	printf("\t  ID\t|����\t\t|����\t\t|�۸�\t\t|�ܷ����\t|�����û�\t|����ʱ��\n");
	printf("\t------------------------------------------------------------------------------------------------------\n");
	for(i=0;i<n;i++)
	if(!strcmp(a,book[i].name)) printf("\t  %d\t|%s\t\t|%s\t\t|%.2f\t\t|%s\t\t|%s\t\t|%s\n",book[i].num,book[i].name,book[i].author,book[i].price,book[i].borr,book[i].user,book[i].time);
	printf("\t------------------------------------------------------------------------------------------------------\n");
	}
	else if(m=='2'){
	printf("\t\t\t\t    root$>>��������:",localuser);
	char b[100];
	scanf("%s",b);
	printf("\t  ID\t|����\t\t|����\t\t|�۸�\t\t|�ܷ����\t|�����û�\t|����ʱ��\n");
	printf("\t------------------------------------------------------------------------------------------------------\n");
	for(i=0;i<n;i++)
	if(!strcmp(b,book[i].author)) printf("\t  %d\t|%s\t\t|%s\t\t|%.2f\t\t|%s\t\t|%s\t\t|%s\n",book[i].num,book[i].name,book[i].author,book[i].price,book[i].borr,book[i].user,book[i].time);
	printf("\t------------------------------------------------------------------------------------------------------\n");
	}
	else if(m=='3'){
	printf("\t  ID\t|����\t\t|����\t\t|�۸�\t\t|�ܷ����\t|�����û�\t|����ʱ��\n");
	printf("\t------------------------------------------------------------------------------------------------------\n");
	for(i=0;i<n;i++)
	printf("\t  %d\t|%s\t\t|%s\t\t|%.2f\t\t|%s\t\t|%s\t\t|%s\n",book[i].num,book[i].name,book[i].author,book[i].price,book[i].borr,book[i].user,book[i].time);
	printf("\t------------------------------------------------------------------------------------------------------\n");
	} 
	else if(m=='4'){
	printf("\t  ID\t|����\t\t|����\t\t|�۸�\t\t|�ܷ����\t|�����û�\t|����ʱ��\n");
	printf("\t------------------------------------------------------------------------------------------------------\n");
	for(i=0;i<n;i++)
	if(strcmp(book[i].time,"�޼�¼"))
	printf("\t  %d\t|%s\t\t|%s\t\t|%.2f\t\t|%s\t\t|%s\t\t|%s\n",book[i].num,book[i].name,book[i].author,book[i].price,book[i].borr,book[i].user,book[i].time);
	printf("\t------------------------------------------------------------------------------------------------------\n");
	} 
	else
	printf("\t\t\t\t    root$>>������1��2��3��\n"); 
	printf("\t\t\t\t    root$>>�Ƿ������ѯ��[1]��[2]��");
	char gsg;
	printf("\n");
	pos2:
	gsg=getch();
	if(gsg=='1') goto pos1;
	else if(gsg=='2');
	else goto pos2;
}
//��¼���� 
void note()
{
	Log log[N];
    FILE *fp0=fopen("log.txt","r+");
    int nl,il;
	nl=linelog();
    for(il=0;il<nl;il++) fscanf(fp0,"%s\t%s\t%s\t%s\t%s\t%s\t%s",log[il].name,log[il].book1,log[il].time1,log[il].book2,log[il].time2,log[il].book3,log[il].time3);
    for(il=0;il<nl;il++) if(!strcmp(log[il].name,localuser)) break;
    fclose(fp0);
    printf("\t\t\t\t    ----------------------------------------\n");
    printf("\t\t\t\t               �û�����%s                  \n",localuser);
    printf("\t\t\t\t    ----------------------------------------\n");
    printf("\t\t\t\t    |�ѽ��鼮  \t\t|��������            \n");
    printf("\t\t\t\t    ----------------------------------------\n");
    printf("\t\t\t\t    |%s  \t\t|%s              \n",log[il].book1,log[il].time1);
    printf("\t\t\t\t    ----------------------------------------\n");
    printf("\t\t\t\t    |%s  \t\t|%s              \n",log[il].book2,log[il].time2);
    printf("\t\t\t\t    ----------------------------------------\n");
    printf("\t\t\t\t    |%s  \t\t|%s              \n",log[il].book3,log[il].time3);
    printf("\t\t\t\t    ----------------------------------------\n");
    printf("\t\t\t\t    ע�⣺ÿ��ֻ��ͬʱ���������飬�뼰ʱ�黹��\n");
    printf("\t\t\t\t    <%s>#>>�����������\n",localuser);
    getch();
} 
//�޸�����
void repasswd()
{
	pos3:
	User user[N];
	FILE *fp=fopen("users.txt","r");
	int l=userall(),i;
	for(i=0;i<l;i++)
		fscanf(fp,"%s\t%s\t%s\t%s",user[i].name,user[i].passwd,user[i].num,user[i].tel);	
	fclose(fp);
	for(i=0;i<l;i++)
	if(!strcmp(user[i].name,localuser)) break;
	char p1[100],p2[100],p3[100];
	printf("\t\t\t\t    <%s>#>>������ԭ���룺",localuser);
	passwd(p1);
	printf("\n");
	int sign=0;
	if(!strcmp(user[i].passwd,p1))
	{
		pos1:
		printf("\t\t\t\t    <%s>#>>�����������룺",localuser);
		passwd(p2);printf("\n");
		printf("\t\t\t\t    <%s>#>>���ظ������룺",localuser);
		passwd(p3);printf("\n");
		if(!strcmp(p2,p3)) 
		{
			strcpy(user[i].passwd,p2);
			printf("\t\t\t\t    <%s>#>>�޸���ɣ�\n",localuser);
			sign=1;	
		}
		else
		{
			printf("\t\t\t\t    <%s>#>>�������벻һ�£�\n",localuser);
			printf("\t\t\t\t    <%s>#>>�Ƿ�����޸�[1]��[2]��\n",localuser);
			char a;
			printf("\n");
			pos2:
			a=getch();
			if(a=='1') goto pos1;
			else if(a=='2');
			else goto pos2;
		}
	} 
	else 
	{
		printf("\t\t\t\t    <%s>#>>��������Ƿ����[1]��[2]��\n",localuser); 
		char a;
		printf("\n");
		pos4:
		a=getch();
		if(a=='1') goto pos3;
		else if(a=='2');
		else goto pos4;
	}
	FILE *fp1=fopen("users.txt","w");
	fclose(fp1);
	FILE *fp2=fopen("users.txt","a");
	for(i=0;i<l;i++)
	fprintf(fp,"%s\t%s\t%s\t%s\n",user[i].name,user[i].passwd,user[i].num,user[i].tel);
	fclose(fp2);
	if(sign==1)
	{
	printf("\t\t\t\t    <%s>#>>�����������\n",localuser); 
	getch();
	}
} 
//ģ����ѯ(ROOT) 
void rootfuzzy()
{
	pos0:
	printf("\n");
	printf("\n");
	printf("\t\t\t\t    ****************************************\n");
	printf("\t\t\t\t                  ģ �� �� ѯ               \n");
	printf("\t\t\t\t    ****************************************\n");
	typedef struct Books
    {
    	int num;
        char name[100];
        char author[100];
        float price;
        char borr[100];
       	char user[100]; 
       	char time[100];
    }Book;
    Book book[N];
    FILE *fp=fopen("liberary.txt","r+");
    int i,n;
    n=lineall();
    for(i=0;i<n;i++) fscanf(fp,"%d\t%s\t\t%s\t\t%f\t\t%s\t%s\t%s",&book[i].num,book[i].name,book[i].author,&book[i].price,book[i].borr,book[i].user,book[i].time);
    fclose(fp);
    char a[100];
    printf("\t\t\t\t    root$>>��ѡ��Ҫ����������[1]����[2]����[3]�۸�����[4]�˳�\n");
    char b;
    pos_1:
	b=getch(); 
	pos1:
	if(b=='1')
	{
	printf("\t\t\t\t    root$>>�����ؼ���(Ӣ�����ִ�Сд)��");
	scanf("%s",a);
	printf("\t  ID\t|����\t\t|����\t\t|�۸�\t\t|�ܷ����\t|�����û�\t|����ʱ��\n");
	printf("\t------------------------------------------------------------------------------------------------------\n");
	char *p;
	for(i=0;i<n;i++)
	{ 
	p=strstr(book[i].name,a);
	if(p&&book[i].num!=0)
	printf("\t  %d\t|%s\t\t|%s\t\t|%.2f\t\t|%s\t\t|%s\t\t|%s\n",book[i].num,book[i].name,book[i].author,book[i].price,book[i].borr,book[i].user,book[i].time);
	else book[i].num=0;
	}
	printf("\t------------------------------------------------------------------------------------------------------\n");
	}
	else if(b=='2')
	{
	printf("\t\t\t\t    root$>>���߹ؼ���(Ӣ�����ִ�Сд)��");
	scanf("%s",a);
	char *p;
	printf("\t  ID\t|����\t\t|����\t\t|�۸�\t\t|�ܷ����\t|�����û�\t|����ʱ��\n");
	printf("\t------------------------------------------------------------------------------------------------------\n");
	for(i=0;i<n;i++)
	{ 
	p=strstr(book[i].author,a);
	if(p&&book[i].num!=0)
	printf("\t  %d\t|%s\t\t|%s\t\t|%.2f\t\t|%s\t\t|%s\t\t|%s\n",book[i].num,book[i].name,book[i].author,book[i].price,book[i].borr,book[i].user,book[i].time);
	else book[i].num=0;
	}
	printf("\t------------------------------------------------------------------------------------------------------\n");
	}
	else if(b=='3')
	{
	float c,d;
	printf("\t\t\t\t    root$>>�۸�����(����10 20):");
	scanf("%f %f",&c,&d);
	printf("\t  ID\t|����\t\t|����\t\t|�۸�\t\t|�ܷ����\t|�����û�\t|����ʱ��\n");
	printf("\t------------------------------------------------------------------------------------------------------\n");
	for(i=0;i<n;i++)
	{
	if(c<=book[i].price&&book[i].price<=d&&book[i].num!=0) 
	printf("\t  %d\t|%s\t\t|%s\t\t|%.2f\t\t|%s\t\t|%s\t\t|%s\n",book[i].num,book[i].name,book[i].author,book[i].price,book[i].borr,book[i].user,book[i].time);
	else book[i].num=0;
	}
	printf("\t------------------------------------------------------------------------------------------------------\n");
	}
	else if(b=='4');
	else goto pos_1;
	if(b!='4')
	{
	printf("\t\t\t\t    root$>>[1]��������[2]���²���[3]�˳�\n");
	char c;
	pos_2: 
	c=getch();
	if(c=='1') 
	{
	printf("\t\t\t\t    root$>>��ѡ��������ҵ�����[1]����[2]����[3]�۸�����\n");
	char d;
	pos_3: 
	d=getch();
	if(d=='1')
	{
	b='1';
	goto pos1;	
	}
	else if(d=='2')
	{
	b='2';
	goto pos1;	
	}
	else if(d=='3')
	{
	b='3';
	goto pos1; 
	} 
	else goto pos_3;
	}
	else if(c=='2') 
	{
	system("cls");
	goto pos0;
	} 
	else if(c=='3');
	else goto pos_2;
}}
//ģ������(��ͨ) 
void fuzzy()
{
	pos0:
	printf("\t\t\t\t    ****************************************\n");
	printf("\t\t\t\t                  ģ �� �� ѯ               \n");
	printf("\t\t\t\t    ****************************************\n");
	typedef struct Books
    {
    	int num;
        char name[100];
        char author[100];
        float price;
        char borr[100];
       	char user[100]; 
       	char time[100];
    }Book;
    Book book[N];
    FILE *fp=fopen("liberary.txt","r+");
    int i,n;
    n=lineall();
    for(i=0;i<n;i++) fscanf(fp,"%d\t%s\t\t%s\t\t%f\t\t%s\t%s\t%s",&book[i].num,book[i].name,book[i].author,&book[i].price,book[i].borr,book[i].user,book[i].time);
    fclose(fp);
    char a[100];
    printf("\t\t\t\t    <%s>#>>��ѡ��Ҫ����������[1]����[2]����[3]�۸�����[4]�˳�\n",localuser);
    char b;
    pos_1:
	b=getch(); 
	pos1:
	if(b=='1')
	{
	printf("\t\t\t\t    <%s>#>>�����ؼ���(Ӣ�����ִ�Сд)��",localuser);
	scanf("%s",a);
	printf("\t\t\t  ID\t|����\t\t|����\t\t|�۸�\t\t|�ܷ����\n");
	printf("\t\t\t------------------------------------------------------------------------\n");
	char *p;
	for(i=0;i<n;i++)
	{ 
	p=strstr(book[i].name,a);
	if(p&&book[i].num!=0)
	printf("\t\t\t  %d\t|%s\t\t|%s\t\t|%.2f\t\t|%s\n",book[i].num,book[i].name,book[i].author,book[i].price,book[i].borr);
	else book[i].num=0;
	}
	printf("\t\t\t------------------------------------------------------------------------\n");
	}
	else if(b=='2')
	{
	printf("\t\t\t\t    <%s>#>>���߹ؼ���(Ӣ�����ִ�Сд)��",localuser);
	scanf("%s",a);
	char *p;
	printf("\t\t\t  ID\t|����\t\t|����\t\t|�۸�\t\t|�ܷ����\n");
	printf("\t\t\t------------------------------------------------------------------------\n");
	for(i=0;i<n;i++)
	{ 
	p=strstr(book[i].author,a);
	if(p&&book[i].num!=0)
	printf("\t\t\t  %d\t|%s\t\t|%s\t\t|%.2f\t\t|%s\n",book[i].num,book[i].name,book[i].author,book[i].price,book[i].borr);
	else book[i].num=0;
	}
	printf("\t\t\t------------------------------------------------------------------------\n");
	}
	else if(b=='3')
	{
	float c,d;
	printf("\t\t\t\t    <%s>#>>�۸�����(����10 20):",localuser);
	scanf("%f %f",&c,&d);
	printf("\t\t\t  ID\t|����\t\t|����\t\t|�۸�\t\t|�ܷ����\n");
	printf("\t\t\t------------------------------------------------------------------------\n");
	for(i=0;i<n;i++)
	{
	if(c<=book[i].price&&book[i].price<=d&&book[i].num!=0) 
	printf("\t\t\t  %d\t|%s\t\t|%s\t\t|%.2f\t\t|%s\n",book[i].num,book[i].name,book[i].author,book[i].price,book[i].borr);
	else book[i].num=0;
	}
	printf("\t\t\t------------------------------------------------------------------------\n");
	}
	else if(b=='4');
	else goto pos_1;
	if(b!='4')
	{
	printf("\t\t\t\t    <%s>#>>[1]��������[2]���²���[3]�˳�\n",localuser);
	char c;
	pos_2: 
	c=getch();
	if(c=='1') 
	{
	printf("\t\t\t\t    <%s>#>>��ѡ��������ҵ�����[1]����[2]����[3]�۸�����\n",localuser);
	char d;
	pos_3: 
	d=getch();
	if(d=='1')
	{
	b='1';
	goto pos1;	
	}
	else if(d=='2')
	{
	b='2';
	goto pos1;	
	}
	else if(d=='3')
	{
	b='3';
	goto pos1; 
	} 
	else goto pos_3;
	}
	else if(c=='2') 
	{
	system("cls");
	goto pos0;
	} 
	else if(c=='3');
	else goto pos_2;
}}
void color()
{
	printf("\t\t\t\t    root$>>��ѡ�񱳾���ɫԤ��:\n");
	printf("\t\t\t\t    root$>>[1]��[2]��[3]��[4]��[5]��[6]��[7]��[8]��\n");
	char a,c[100];
	pos1:
	a=getch();
	if(a=='1') strcpy(c,"0");
	else if(a=='2') strcpy(c,"7");
	else if(a=='3') strcpy(c,"8");
	else if(a=='4') strcpy(c,"a");
	else if(a=='5') strcpy(c,"4");
	else if(a=='6') strcpy(c,"6");	
	else if(a=='7') strcpy(c,"5");
	else if(a=='8') strcpy(c,"3");
	else goto pos1;
	printf("\t\t\t\t    root$>>��ѡ��������ɫԤ��:\n");
	printf("\t\t\t\t    root$>>[1]��[2]��[3]��[4]��[5]��[6]��[7]��[8]��\n");
	char d[100];
	pos2:
	a=getch();
	if(a=='1') strcpy(d,"0");
	else if(a=='2') strcpy(d,"7");
	else if(a=='3') strcpy(d,"8");
	else if(a=='4') strcpy(d,"a");
	else if(a=='5') strcpy(d,"4");
	else if(a=='6') strcpy(d,"6");	
	else if(a=='7') strcpy(d,"5");
	else if(a=='8') strcpy(d,"3");
	else goto pos2;
	char b[100];
	strcpy(b,"color");
	strcat(b," ");
	strcat(b,c);
	strcat(b,d);
	system(b);
	printf("\t\t\t\t    root$>>�޸���ɫ�ɹ���\n");
	printf("\t\t\t\t    root$>>��������˳�\n");
	getch(); 
}
// ��¼���� 
int login()
{
	User user[N];
	FILE *fp=fopen("users.txt","r");
	int l=userall(),i;
	for(i=0;i<l;i++)
		fscanf(fp,"%s\t%s\t%s\t%s",user[i].name,user[i].passwd,user[i].num,user[i].tel);	
	fclose(fp);
	int sign=0;
	while(1)
	{
	system("cls");
	printf("\t\t\t\t   ************************************\n");
	printf("\t\t\t\t               ѧ �� �� ½             \n");
	printf("\t\t\t\t   ************************************\n");
	char n[100],p[100];
	printf("\t\t\t\t   #>>�û�����");
	scanf("%s",n);
	printf("\t\t\t\t   #>>���룺");
	passwd(p); 
	printf("\n");
	for(i=0;i<l;i++)
		if(!strcmp(user[i].name,n)&&!strcmp(user[i].passwd,p)) 
		{
			sign=1;
			strcpy(localuser,user[i].name);
			break;
		}
	if(sign==0) 
	{
		printf("\t\t\t\t   #>>�˺Ż��������[1]������¼[2]�˳�\n");
		char exit;
		exit=getch();
		if(exit=='1') continue;
		else break; 
	}
	if(sign==1) 
	{
		printf("\t\t\t\t   #>>����ɹ���\n");
		break;
	}
	}
return sign;
}
void refind()
{pos1:
	system("cls");
	printf("\t\t\t\t   ************************************\n");
	printf("\t\t\t\t               �� �� �� ��             \n");
	printf("\t\t\t\t   ************************************\n");
	User user[N];
	FILE *fp=fopen("users.txt","r");
	int l=userall(),i;
	for(i=0;i<l;i++)
		fscanf(fp,"%s\t%s\t%s\t%s",user[i].name,user[i].passwd,user[i].num,user[i].tel);	
	fclose(fp);
	char n[100];
	printf("\t\t\t\t   #>>������Ҫ�һ�������˺ţ�");
	scanf("%s",n);
	int sign=0;
	for(i=0;i<l;i++)
		if(!strcmp(user[i].name,n)) 
		{sign=1;break;} 
	if(sign)
	{
		char u[100],t[100];
		printf("\t\t\t\t   #>>�������Ӧ��ѧ�ţ�");
		scanf("%s",u);
		printf("\t\t\t\t   #>>�������Ӧ���ֻ��ţ�");
		scanf("%s",t);
		if(!strcmp(u,user[i].num)&&!strcmp(t,user[i].tel))
		{
			printf("\t\t\t\t   #>>�һسɹ���\n");
			printf("\t\t\t\t   #>>����Ϊ %s\n",user[i].passwd);
			printf("\t\t\t\t   #>>��������˳�\n");
			getch();
		}
		else 
		{
		printf("\t\t\t\t   #>>ѧ�Ż��ֻ��Ŵ����Ƿ�����һ�[1]��[2]��");
		char a;
		pos_1:
		a=getch();
		if(a=='1') goto pos1;
		else if(a=='2');
		else goto pos_1; 
		}
	}
	else
	{
		printf("\t\t\t\t   #>>���˺�δע�ᣡ�Ƿ����[1]��[2]��");
		char a;
		pos_2:
		a=getch();
		if(a=='1') goto pos1;
		else if(a=='2');
		else goto pos_2;
	}
}
//������ 
int main()
{
system("mode con cols=120 lines=30");
pos1:
system("cls");
printf("\n");
printf("\n");  
printf("\t\t            @@@@@@@@                    @@@@@@@@@                @@@@@@@@             \n");
printf("\t\t          @@@                         @@@                      @@@                    \n");
printf("\t\t         @@                          @@                       @@                      \n");
printf("\t\t        @@                          @@                       @@                       \n");
printf("\t\t       @@                           @@                      @@                        \n");
printf("\t\t       @@                            @@                     @@                        \n");
printf("\t\t       @@        @@@@@@               @@@@@@@@@             @@        @@@@@@          \n");
printf("\t\t       @@        @@@@@@                       @@@           @@        @@@@@@          \n");
printf("\t\t       @@            @@                        @@           @@            @@          \n");
printf("\t\t       @@            @@                        @@           @@            @@          \n");
printf("\t\t        @@           @@                        @@            @@           @@          \n");
printf("\t\t         @@@         @@                       @@              @@@         @@          \n");
printf("\t\t          @@@@@@@@@@@@@             @@@@@@@@@@@                @@@@@@@@@@@@@          \n");
printf("\t\t**************************************************************************************\n");
printf("\n"); 
printf("\t\t\t\t\t    ��ӭʹ��GSG9����ͼ�����ϵͳ\n");
printf("\n"); 
printf("\t\t\t\t\t           [1]����Ա���        \n");
printf("\n"); 
printf("\t\t\t\t\t           [2]ѧ�����          \n");
printf("\n");
printf("\t\t\t\t\t           [3]�˳�ϵͳ          \n");
char a;
a=getch();
system("cls");
if(a=='1')
{
	pos2:
	char n[100],p[100];
	printf("\n");
    printf("\n"); 
	printf("\t\t\t\t    ****************************************\n");
	printf("\t\t\t\t                 �� �� Ա �� ½             \n"); 
	printf("\t\t\t\t    ****************************************\n");
	printf("\t\t\t\t    �û�����");
	scanf("%s",n);
	printf("\t\t\t\t    ���룺");
	passwd(p);
	int sign1=0; 
	if(!strcmp(n,"root")&&!strcmp(p,"toor"))  sign1=1;
	else 
	{
	int n;
	printf("\n");
	printf("\t\t\t\t    �������[1]��������[2]����\n");
	n=getch();
	system("cls");
	if(n=='1') goto pos2;
	else goto pos1;
	}
	if(sign1==1) 
	{
		pos3:
		system("cls");
		printf("\n");
        printf("\n");
	    printf("\t\t\t\t    ****************************************\n");
		printf("\t\t\t\t                  ѡ �� �� ��               \n");
	    printf("\t\t\t\t    ****************************************\n");
	    printf("\n");
		printf("\t\t\t\t                  [1]��������               \n");
		printf("\n");
		printf("\t\t\t\t                  [2]ɾ������               \n");
		printf("\n");
		printf("\t\t\t\t                  [3]��ȷ��ѯ               \n");
		printf("\n");
		printf("\t\t\t\t                  [4]ģ����ѯ               \n");
		printf("\n");
		printf("\t\t\t\t                  [5]�޸�����               \n");
		printf("\n");
		printf("\t\t\t\t                  [6]��ɫ�޸�               \n");
		printf("\n");
		printf("\t\t\t\t                  [7]ˢ������               \n");
		printf("\n");
		printf("\t\t\t\t                  [8]�˳���½               \n");
		char b;
		b=getch();
		system("cls");
		if(b=='1') 
		{
		printf("\n");
        printf("\n");
		printf("\t\t\t\t    ****************************************\n");
		printf("\t\t\t\t                  �� �� �� ��               \n");
	    printf("\t\t\t\t    ****************************************\n");
		storebooks();
		goto pos3;
		} 
		else if(b=='2') 
		{
		printf("\n");
        printf("\n");
		printf("\t\t\t\t    ****************************************\n");
		printf("\t\t\t\t                  ɾ �� �� ��               \n");
	    printf("\t\t\t\t    ****************************************\n");
		delbook();
		goto pos3;
		} 
		else if(b=='3') 
		{
		printf("\n");
        printf("\n");
		printf("\t\t\t\t    ****************************************\n");
		printf("\t\t\t\t                  �� ȷ �� ѯ               \n");
	    printf("\t\t\t\t    ****************************************\n");
		rootsearch();
		goto pos3;
		} 
		else if(b=='4') 
		{
		rootfuzzy();
		goto pos3;
		} 
		else if(b=='5') 
		{
		printf("\n");
        printf("\n");
		printf("\t\t\t\t    ****************************************\n");
		printf("\t\t\t\t                  �� �� �� ��               \n");
	    printf("\t\t\t\t    ****************************************\n");
		revise();
		goto pos3;
		}
		else if(b=='6') 
		{
		printf("\n");
        printf("\n");
		printf("\t\t\t\t    ****************************************\n");
		printf("\t\t\t\t                  �� ɫ �� ��               \n");
	    printf("\t\t\t\t    ****************************************\n");
		color();
		goto pos3;
		}
		else if(b=='7') 
		{
		renew();
		goto pos3;
		}
		else if(b=='8') goto pos1;
		else goto pos3;
	}
}
else if(a=='2')
{
	pos5:
	system("cls");
	printf("\n");
    printf("\n");
	printf("\t\t\t\t    ****************************************\n");
	printf("\t\t\t\t                  ѡ �� �� ��               \n");
	printf("\t\t\t\t    ****************************************\n");
	printf("\n");
	printf("\t\t\t\t                  [1]ѧ����½               \n");
	printf("\n");
	printf("\t\t\t\t                  [2]�û�ע��               \n");
	printf("\n");
	printf("\t\t\t\t                  [3]�����һ�               \n");
	printf("\n");
	printf("\t\t\t\t                  [4]�������˵�             \n");
	char a;
	printf("\n");
	pos4:
	a=getch();
	if(a=='1')
	{
		int sign;
		sign=login();
		if(sign==1)
		{
			pos6:
			system("cls");
			printf("\t\t\t\t    ****************************************\n");
			printf("\t\t\t\t                  �� ӭ �� ��               \n");
			printf("\t\t\t\t                  %s                        \n",localuser);
			printf("\t\t\t\t    ****************************************\n");
			printf("\n");
			printf("\t\t\t\t                  [1]�����鼮               \n");
			printf("\n");
			printf("\t\t\t\t                  [2]�黹�鼮               \n");
			printf("\n");
			printf("\t\t\t\t                  [3]��ȷ��ѯ               \n");
			printf("\n");
			printf("\t\t\t\t                  [4]ģ����ѯ               \n");
			printf("\n");
			printf("\t\t\t\t                  [5]���ļ�¼               \n");
			printf("\n");
			printf("\t\t\t\t                  [6]�޸�����               \n");
			printf("\n");
			printf("\t\t\t\t                  [7]�˳���½               \n");
			char b;
			printf("\n");
			pos7:
			b=getch();
			if(b=='1') 
			{
				system("cls");
				printf("\t\t\t\t    ****************************************\n");
				printf("\t\t\t\t                  �� �� �� ��               \n");
				printf("\t\t\t\t    ****************************************\n");
				borrow();
				goto pos6;
			}
			else if(b=='2')
			{
				system("cls");
				printf("\t\t\t\t    ****************************************\n");
				printf("\t\t\t\t                  �� �� �� ��               \n");
				printf("\t\t\t\t    ****************************************\n");
				retu();
				goto pos6;
			}
			else if(b=='3')
			{
				system("cls");
				printf("\t\t\t\t    ****************************************\n");
				printf("\t\t\t\t                  �� ѯ �� ��               \n");
				printf("\t\t\t\t    ****************************************\n");
				search();
				goto pos6;
			}
			else if(b=='4')
			{
				system("cls");
				fuzzy(); 
				goto pos6;
			}
			else if(b=='5')
			{
				system("cls");
				printf("\t\t\t\t    ****************************************\n");
				printf("\t\t\t\t                  �� �� �� ¼               \n");
				printf("\t\t\t\t    ****************************************\n");
				note();
				goto pos6;
			}
			else if(b=='6')
			{
				system("cls");
				printf("\t\t\t\t    ****************************************\n");
				printf("\t\t\t\t                  �� �� �� ��               \n");
				printf("\t\t\t\t    ****************************************\n");
				repasswd();
				goto pos6;
			}
			else if(b=='7') goto pos5;
			else goto pos7;
		} 
		if(sign==0) goto pos5;
	}
	else if(a=='2') 
	{
		logon();
		goto pos5;
	}
	else if(a=='3') 
	{
		refind();
		goto pos5;
	}
	else if(a=='4') goto pos1;
	else goto pos4;
}
else if(a=='3');
else goto pos1;
}
