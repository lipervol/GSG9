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
//时间函数 
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
//行数函数 
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
//行数函数（含空行） 
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
//刷新函数 
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
//存书函数 
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
    printf("\t\t\t\t    root$>>请输入要存入的书的数量:");
    scanf("%d",&n);
    printf("\t\t\t\t    root$>>请输入存入的书名、作者、价格:\n\t\t\t\t    例如 BOOK1 Tom 10.00\n");
    for(i=0;i<n;i++) 
	{
	printf("\t\t\t\t    ");
	scanf("%s %s %f",book[i].name,book[i].author,&book[i].price);
	} 
    for(i=0;i<n;i++) 
	{
		FILE *fp=fopen("liberary.txt","a");
		fprintf(fp,"%d\t%s\t\t%s\t\t%.2f\t\t在架\t无\t无记录\n",linenum(),book[i].name,book[i].author,book[i].price);
		fclose(fp);
	}
} 
//搜索函数 
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
	printf("\t\t\t\t    <%s>#>>请选择要查找的内容:[1]书名[2]作者[3]全部信息",localuser);
	char m;
	m=getch();
	printf("\n");
	if(m=='1'){
	printf("\t\t\t\t    <%s>#>>输入书名:",localuser);
	char a[100];
	scanf("%s",a);
	printf("\t\t\t  ID\t|书名\t\t|作者\t\t|价格\t\t|能否借阅\n");
	printf("\t\t\t------------------------------------------------------------------------\n");
	for(i=0;i<n;i++)
	if(!strcmp(a,book[i].name)) printf("\t\t\t  %d\t|%s\t\t|%s\t\t|%.2f\t\t|%s\n",book[i].num,book[i].name,book[i].author,book[i].price,book[i].borr);
	printf("\t\t\t------------------------------------------------------------------------\n");
	}
	else if(m=='2'){
	printf("\t\t\t\t    <%s>#>>输入作者:",localuser);
	char b[100];
	scanf("%s",b);
	printf("\t\t\t  ID\t|书名\t\t|作者\t\t|价格\t\t|能否借阅\n");
	printf("\t\t\t------------------------------------------------------------------------\n");
	for(i=0;i<n;i++)
	if(!strcmp(b,book[i].author)) printf("\t\t\t  %d\t|%s\t\t|%s\t\t|%.2f\t\t|%s\n",book[i].num,book[i].name,book[i].author,book[i].price,book[i].borr);
	printf("\t\t\t------------------------------------------------------------------------\n");
	}
	else if(m=='3'){
	printf("\t\t\t  ID\t|书名\t\t|作者\t\t|价格\t\t|能否借阅\n");
	printf("\t\t\t------------------------------------------------------------------------\n");
	for(i=0;i<n;i++)
	printf("\t\t\t  %d\t|%s\t\t|%s\t\t|%.2f\t\t|%s\n",book[i].num,book[i].name,book[i].author,book[i].price,book[i].borr);	
	printf("\t\t\t------------------------------------------------------------------------\n");
	} 
	else
	printf("\t\t\t\t    <%s>#>>请输入1、2或3！",localuser); 
	printf("\t\t\t\t    <%s>$>>是否继续查询：[1]是[2]否",localuser);
	char gsg;
	printf("\n");
	pos2:
	gsg=getch();
	if(gsg=='1') goto pos1;
	else if(gsg=='2');
	else goto pos2;
}
//删除函数 
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
    printf("\t\t\t\t    root$>>请输入要删除书的ID(返回输入0):");
    scanf("%d",&m);
    if(m<=0||m>=linenum()) printf("\t\t\t\t    root$>>该书不存在\n");
    if(strcmp(book[m-1].time,"无记录")) 
		printf("\t\t\t\t    root$>>该书有人借阅，无法删除！\n");
    if(!strcmp(book[m-1].time,"无记录"))
    {
    for(i=0;i<n;i++)
	if(book[i].num==m) {
	printf("\t\t\t\t    root$>>确认该书信息：\n");
	printf("\t\t\t  ID\t|书名\t\t|作者\t\t|价格\t\t|能否借阅\n");
	printf("\t\t\t------------------------------------------------------------------------\n");
	printf("\t\t\t  %d\t|%s\t\t|%s\t\t|%.2f\t\t|%s\n",book[i].num,book[i].name,book[i].author,book[i].price,book[i].borr);	
	printf("\t\t\t------------------------------------------------------------------------\n");
	printf("\t\t\t\t    root$>>是否删除[1]是[2]否\n");
	char t;
	pos_1: 
	t=getch();
	if(t=='1')
	{book[i].num=0; 
	printf("\t\t\t\t    root$>>删除完成\n");}
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
	printf("\t\t\t\t    root$>>是否继续删除：[1]是[2]否");
	char gsg;
	printf("\n");
	pos2:
	gsg=getch();
	if(gsg=='1') goto pos1;
	else if(gsg=='2');
	else goto pos2;
}
//借阅函数 
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
    if(!strcmp(log[il].time1,"无记录")&&signlog==0) signlog=1;
	else if(!strcmp(log[il].time2,"无记录")&&signlog==0) signlog=2;
	else if(!strcmp(log[il].time3,"无记录")&&signlog==0) signlog=3;
	int m;
    printf("\t\t\t\t    <%s>#>>请输入要借阅的书的ID:",localuser);
    scanf("%d",&m);
    if(m>=linenum()||m<=0) printf("\t\t\t\t    <%s>#>>该书不存在\n",localuser);
    if(m<linenum()&&m>0&&signlog==0) printf("\t\t\t\t    <%s>#>>只能最多借阅三本！\n",localuser); 
    for(i=0;i<n;i++)
	if(book[i].num==m&&signlog!=0)
	{
		if(!strcmp(book[i].borr,"在架"))
			{
			strcpy(book[i].borr,"已借出");
			strcpy(book[i].user,localuser);
			strcpy(book[i].time,localday);
			if(signlog==1) {strcpy(log[il].book1,book[i].name);strcpy(log[il].time1,localday);}
			else if(signlog==2) {strcpy(log[il].book2,book[i].name);strcpy(log[il].time2,localday);}
			else {strcpy(log[il].book3,book[i].name);strcpy(log[il].time3,localday);}
			printf("\t\t\t\t    <%s>#>>借阅成功\n",localuser);
			}
		else printf("\t\t\t\t    <%s>#>>该书已借出\n",localuser);
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
	printf("\t\t\t\t    <%s>#>>按任意键返回",localuser);
	getch(); 
}
//还书函数 
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
    printf("\t\t\t\t    <%s>#>>请输入要归还的书的ID:",localuser);
    scanf("%d",&m);
    int signlog=0;
    if(m>linenum()||m<=0) printf("\t\t\t\t    <%s>#>>该书不存在\n",localuser);
    if(!strcmp(book[m-1].borr,"在架")&&m>0&&m<=linenum()) printf("\t\t\t\t    <%s>#>>该书未借出！\n",localuser);
    if(m>0&&m<=linenum()&&strcmp(book[m-1].user,localuser)) printf("\t\t\t\t    <%s>您未借阅此书！\n",localuser);
    if(m<=linenum()&&m>0)
    {
    	if(!strcmp(log[il].book1,book[m-1].name)&&signlog==0) signlog=1;
    	if(!strcmp(log[il].book2,book[m-1].name)&&signlog==0) signlog=2;
    	if(!strcmp(log[il].book3,book[m-1].name)&&signlog==0) signlog=3;
	}
    for(i=0;i<n;i++)
	if(book[i].num==m&&signlog!=0)
	{
		if(!strcmp(book[i].borr,"已借出")&&!strcmp(book[i].user,localuser))
			{
			if(signlog==1) {strcpy(log[il].book1,"无记录");strcpy(log[il].time1,"无记录");}
			if(signlog==2) {strcpy(log[il].book2,"无记录");strcpy(log[il].time2,"无记录");}
			if(signlog==3) {strcpy(log[il].book3,"无记录");strcpy(log[il].time3,"无记录");}
			strcpy(book[i].borr,"在架");
			strcpy(book[i].user,"无");
			strcpy(book[i].time,"无记录");
			printf("\t\t\t\t    <%s>#>>归还成功\n",localuser);
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
	printf("\t\t\t\t    <%s>#>>按任意键返回",localuser);
	getch(); 
}
// user行数函数
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
// 注册函数 
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
	printf("\t\t\t\t                 注    册               \n");
	printf("\t\t\t\t    ************************************\n");
	printf("\t\t\t\t    #>>输入用户名："); 
	scanf("%s",n);
	int sign=0;
	for(i=0;i<l;i++)
		if(!strcmp(user[i].name,n)) sign=1;
		else if(!strcmp(n,"无")) sign=2;
	if(sign) 
	{
	char exit;
	if(sign==1)
	printf("\t\t\t\t    #>>该用户已注册！[1]继续注册[2]退出\n");
	else if(sign==2)
	printf("\t\t\t\t    #>>请输入合法的用户名！[1]继续注册[2]退出\n"); 
	exit=getch();
	if(exit=='1') continue;
	else break;
	}
	char m[100];
	int signs=0;
	printf("\t\t\t\t    #>>请输入学号：");
	scanf("%s",m); 
	for(i=0;i<l;i++)
		if(!strcmp(user[i].num,m)) signs=1;
		if(strlen(m)!=10) signs=2; 
	if(signs) 
	{
	char exit;
	if(signs==1)
	printf("\t\t\t\t    #>>该学号已注册！[1]继续注册[2]退出\n");
	if(signs==2)
	printf("\t\t\t\t    #>>请输入正确的学号！[1]继续注册[2]退出\n");
	exit=getch();
	if(exit=='1') continue;
	else break;
	}
	char g[100];
	int signss=0;
	printf("\t\t\t\t    #>>请输入手机号：");
	scanf("%s",g); 
	for(i=0;i<l;i++)
		if(!strcmp(user[i].tel,g)) signss=1;
		if(strlen(g)!=11) signss=2; 
	if(signss) 
	{
	char exit;
	if(signss==1)
	printf("\t\t\t\t    #>>该手机号已注册！[1]继续注册[2]退出\n");
	if(signss==2)
	printf("\t\t\t\t    #>>请输入正确的手机号！[1]继续注册[2]退出\n");
	exit=getch();
	if(exit=='1') continue;
	else break;
	}
	printf("\t\t\t\t    #>>输入密码:");
	passwd(p1);
	printf("\n");
	printf("\t\t\t\t    #>>请再输入一次：");
	passwd(p2); 
	printf("\n");
	if(!strcmp(p1,p2))
	{
	printf("\t\t\t\t    #>>注册完成！\n\t\t\t\t    #>>按任意键确定\n");
	getch();
	FILE *fp1=fopen("users.txt","a");
	fprintf(fp1,"%s\t%s\t%s\t%s\n",n,p1,m,g);
	fclose(fp1);
	FILE *fp2=fopen("log.txt","a");
	fprintf(fp2,"%s\t无记录\t无记录\t无记录\t无记录\t无记录\t无记录\t\n",n);
	fclose(fp2);
	break;
	}
	else 
	{
	char exit;
	printf("\t\t\t\t    #>>密码不一致，请重新注册！[1]继续注册[2]退出\n");
	exit=getch();
	if(exit=='1') continue;
	else break; 
	}
	}
}
//修改函数 
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
	printf("\t\t\t\t    root$>>请输入要修改的书的ID:");
	scanf("%d",&a);
	if(strcmp(book[a-1].time,"无记录")&&a>0&&a<=n) printf("\t\t\t\t    root$>>该书已借出，无法修改！\n");
	if(a<=0||a>n) printf("\t\t\t\t    root$>>该ID不存在！\n");
	char b;
	pos2:
	if(!strcmp(book[a-1].time,"无记录")&&a>0&&a<=n)
	{
	    printf("\t\t\t\t    root$>>请输入要修改的内容：[1]书名[2]作者[3]价格[4]返回功能菜单");
	    printf("\n");
	    pos0:
	    b=getch();
		if(b=='1')
		{
			char c[100];
			printf("\t\t\t\t    root$>>将书名改为：");
			scanf("%s",c);
			strcpy(book[a-1].name,c);
		}
		else if(b=='2')
		{
			char c[100];
			printf("\t\t\t\t    root$>>将作者改为：");
			scanf("%s",c);
			strcpy(book[a-1].author,c);
		}
		else if(b=='3')
		{
			float c;
			printf("\t\t\t\t    root$>>将价格改为：");
			scanf("%f",&c);
			book[a-1].price=c;
		}
		if(b=='1'||b=='2'||b=='3') 
		{
		printf("\t\t\t\t    root$>>是否继续对该书修改：[1]是[2]否");
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
	printf("\t\t\t\t    root$>>是否继续修改：[1]是[2]否");
	char gsg;
	printf("\n");
	pos4:
	gsg=getch();
	if(gsg=='1') goto pos1;
	else if(gsg=='2');
	else goto pos4;
	}
}
//高级查找 
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
	printf("\t\t\t\t    root$>>请选择要查找的内容:[1]书名[2]作者[3]全部信息[4]已借出书籍");
	char m;
	m=getch();
	printf("\n");
	if(m=='1'){
	printf("\t\t\t\t    root$>>输入书名:");
	char a[100];
	scanf("%s",a);
	printf("\t  ID\t|书名\t\t|作者\t\t|价格\t\t|能否借阅\t|借阅用户\t|借阅时间\n");
	printf("\t------------------------------------------------------------------------------------------------------\n");
	for(i=0;i<n;i++)
	if(!strcmp(a,book[i].name)) printf("\t  %d\t|%s\t\t|%s\t\t|%.2f\t\t|%s\t\t|%s\t\t|%s\n",book[i].num,book[i].name,book[i].author,book[i].price,book[i].borr,book[i].user,book[i].time);
	printf("\t------------------------------------------------------------------------------------------------------\n");
	}
	else if(m=='2'){
	printf("\t\t\t\t    root$>>输入作者:",localuser);
	char b[100];
	scanf("%s",b);
	printf("\t  ID\t|书名\t\t|作者\t\t|价格\t\t|能否借阅\t|借阅用户\t|借阅时间\n");
	printf("\t------------------------------------------------------------------------------------------------------\n");
	for(i=0;i<n;i++)
	if(!strcmp(b,book[i].author)) printf("\t  %d\t|%s\t\t|%s\t\t|%.2f\t\t|%s\t\t|%s\t\t|%s\n",book[i].num,book[i].name,book[i].author,book[i].price,book[i].borr,book[i].user,book[i].time);
	printf("\t------------------------------------------------------------------------------------------------------\n");
	}
	else if(m=='3'){
	printf("\t  ID\t|书名\t\t|作者\t\t|价格\t\t|能否借阅\t|借阅用户\t|借阅时间\n");
	printf("\t------------------------------------------------------------------------------------------------------\n");
	for(i=0;i<n;i++)
	printf("\t  %d\t|%s\t\t|%s\t\t|%.2f\t\t|%s\t\t|%s\t\t|%s\n",book[i].num,book[i].name,book[i].author,book[i].price,book[i].borr,book[i].user,book[i].time);
	printf("\t------------------------------------------------------------------------------------------------------\n");
	} 
	else if(m=='4'){
	printf("\t  ID\t|书名\t\t|作者\t\t|价格\t\t|能否借阅\t|借阅用户\t|借阅时间\n");
	printf("\t------------------------------------------------------------------------------------------------------\n");
	for(i=0;i<n;i++)
	if(strcmp(book[i].time,"无记录"))
	printf("\t  %d\t|%s\t\t|%s\t\t|%.2f\t\t|%s\t\t|%s\t\t|%s\n",book[i].num,book[i].name,book[i].author,book[i].price,book[i].borr,book[i].user,book[i].time);
	printf("\t------------------------------------------------------------------------------------------------------\n");
	} 
	else
	printf("\t\t\t\t    root$>>请输入1、2或3！\n"); 
	printf("\t\t\t\t    root$>>是否继续查询：[1]是[2]否");
	char gsg;
	printf("\n");
	pos2:
	gsg=getch();
	if(gsg=='1') goto pos1;
	else if(gsg=='2');
	else goto pos2;
}
//记录函数 
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
    printf("\t\t\t\t               用户名：%s                  \n",localuser);
    printf("\t\t\t\t    ----------------------------------------\n");
    printf("\t\t\t\t    |已借书籍  \t\t|借阅日期            \n");
    printf("\t\t\t\t    ----------------------------------------\n");
    printf("\t\t\t\t    |%s  \t\t|%s              \n",log[il].book1,log[il].time1);
    printf("\t\t\t\t    ----------------------------------------\n");
    printf("\t\t\t\t    |%s  \t\t|%s              \n",log[il].book2,log[il].time2);
    printf("\t\t\t\t    ----------------------------------------\n");
    printf("\t\t\t\t    |%s  \t\t|%s              \n",log[il].book3,log[il].time3);
    printf("\t\t\t\t    ----------------------------------------\n");
    printf("\t\t\t\t    注意：每人只能同时借阅三本书，请及时归还！\n");
    printf("\t\t\t\t    <%s>#>>按任意键返回\n",localuser);
    getch();
} 
//修改密码
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
	printf("\t\t\t\t    <%s>#>>请输入原密码：",localuser);
	passwd(p1);
	printf("\n");
	int sign=0;
	if(!strcmp(user[i].passwd,p1))
	{
		pos1:
		printf("\t\t\t\t    <%s>#>>请输入新密码：",localuser);
		passwd(p2);printf("\n");
		printf("\t\t\t\t    <%s>#>>请重复新密码：",localuser);
		passwd(p3);printf("\n");
		if(!strcmp(p2,p3)) 
		{
			strcpy(user[i].passwd,p2);
			printf("\t\t\t\t    <%s>#>>修改完成！\n",localuser);
			sign=1;	
		}
		else
		{
			printf("\t\t\t\t    <%s>#>>两次密码不一致！\n",localuser);
			printf("\t\t\t\t    <%s>#>>是否继续修改[1]是[2]否\n",localuser);
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
		printf("\t\t\t\t    <%s>#>>密码错误，是否继续[1]是[2]否\n",localuser); 
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
	printf("\t\t\t\t    <%s>#>>按任意键返回\n",localuser); 
	getch();
	}
} 
//模糊查询(ROOT) 
void rootfuzzy()
{
	pos0:
	printf("\n");
	printf("\n");
	printf("\t\t\t\t    ****************************************\n");
	printf("\t\t\t\t                  模 糊 查 询               \n");
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
    printf("\t\t\t\t    root$>>请选择要搜索的内容[1]书名[2]作者[3]价格区间[4]退出\n");
    char b;
    pos_1:
	b=getch(); 
	pos1:
	if(b=='1')
	{
	printf("\t\t\t\t    root$>>书名关键字(英文区分大小写)：");
	scanf("%s",a);
	printf("\t  ID\t|书名\t\t|作者\t\t|价格\t\t|能否借阅\t|借阅用户\t|借阅时间\n");
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
	printf("\t\t\t\t    root$>>作者关键字(英文区分大小写)：");
	scanf("%s",a);
	char *p;
	printf("\t  ID\t|书名\t\t|作者\t\t|价格\t\t|能否借阅\t|借阅用户\t|借阅时间\n");
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
	printf("\t\t\t\t    root$>>价格区间(例如10 20):");
	scanf("%f %f",&c,&d);
	printf("\t  ID\t|书名\t\t|作者\t\t|价格\t\t|能否借阅\t|借阅用户\t|借阅时间\n");
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
	printf("\t\t\t\t    root$>>[1]继续查找[2]重新查找[3]退出\n");
	char c;
	pos_2: 
	c=getch();
	if(c=='1') 
	{
	printf("\t\t\t\t    root$>>请选择继续查找的内容[1]书名[2]作者[3]价格区间\n");
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
//模糊查找(普通) 
void fuzzy()
{
	pos0:
	printf("\t\t\t\t    ****************************************\n");
	printf("\t\t\t\t                  模 糊 查 询               \n");
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
    printf("\t\t\t\t    <%s>#>>请选择要搜索的内容[1]书名[2]作者[3]价格区间[4]退出\n",localuser);
    char b;
    pos_1:
	b=getch(); 
	pos1:
	if(b=='1')
	{
	printf("\t\t\t\t    <%s>#>>书名关键字(英文区分大小写)：",localuser);
	scanf("%s",a);
	printf("\t\t\t  ID\t|书名\t\t|作者\t\t|价格\t\t|能否借阅\n");
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
	printf("\t\t\t\t    <%s>#>>作者关键字(英文区分大小写)：",localuser);
	scanf("%s",a);
	char *p;
	printf("\t\t\t  ID\t|书名\t\t|作者\t\t|价格\t\t|能否借阅\n");
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
	printf("\t\t\t\t    <%s>#>>价格区间(例如10 20):",localuser);
	scanf("%f %f",&c,&d);
	printf("\t\t\t  ID\t|书名\t\t|作者\t\t|价格\t\t|能否借阅\n");
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
	printf("\t\t\t\t    <%s>#>>[1]继续查找[2]重新查找[3]退出\n",localuser);
	char c;
	pos_2: 
	c=getch();
	if(c=='1') 
	{
	printf("\t\t\t\t    <%s>#>>请选择继续查找的内容[1]书名[2]作者[3]价格区间\n",localuser);
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
	printf("\t\t\t\t    root$>>请选择背景颜色预设:\n");
	printf("\t\t\t\t    root$>>[1]黑[2]白[3]灰[4]绿[5]红[6]黄[7]紫[8]蓝\n");
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
	printf("\t\t\t\t    root$>>请选择字体颜色预设:\n");
	printf("\t\t\t\t    root$>>[1]黑[2]白[3]灰[4]绿[5]红[6]黄[7]紫[8]蓝\n");
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
	printf("\t\t\t\t    root$>>修改颜色成功！\n");
	printf("\t\t\t\t    root$>>按任意键退出\n");
	getch(); 
}
// 登录函数 
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
	printf("\t\t\t\t               学 生 登 陆             \n");
	printf("\t\t\t\t   ************************************\n");
	char n[100],p[100];
	printf("\t\t\t\t   #>>用户名：");
	scanf("%s",n);
	printf("\t\t\t\t   #>>密码：");
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
		printf("\t\t\t\t   #>>账号或密码错误！[1]继续登录[2]退出\n");
		char exit;
		exit=getch();
		if(exit=='1') continue;
		else break; 
	}
	if(sign==1) 
	{
		printf("\t\t\t\t   #>>登入成功！\n");
		break;
	}
	}
return sign;
}
void refind()
{pos1:
	system("cls");
	printf("\t\t\t\t   ************************************\n");
	printf("\t\t\t\t               密 码 找 回             \n");
	printf("\t\t\t\t   ************************************\n");
	User user[N];
	FILE *fp=fopen("users.txt","r");
	int l=userall(),i;
	for(i=0;i<l;i++)
		fscanf(fp,"%s\t%s\t%s\t%s",user[i].name,user[i].passwd,user[i].num,user[i].tel);	
	fclose(fp);
	char n[100];
	printf("\t\t\t\t   #>>请输入要找回密码的账号：");
	scanf("%s",n);
	int sign=0;
	for(i=0;i<l;i++)
		if(!strcmp(user[i].name,n)) 
		{sign=1;break;} 
	if(sign)
	{
		char u[100],t[100];
		printf("\t\t\t\t   #>>请输入对应的学号：");
		scanf("%s",u);
		printf("\t\t\t\t   #>>请输入对应的手机号：");
		scanf("%s",t);
		if(!strcmp(u,user[i].num)&&!strcmp(t,user[i].tel))
		{
			printf("\t\t\t\t   #>>找回成功！\n");
			printf("\t\t\t\t   #>>密码为 %s\n",user[i].passwd);
			printf("\t\t\t\t   #>>按任意键退出\n");
			getch();
		}
		else 
		{
		printf("\t\t\t\t   #>>学号或手机号错误！是否继续找回[1]是[2]否");
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
		printf("\t\t\t\t   #>>该账号未注册！是否继续[1]是[2]否");
		char a;
		pos_2:
		a=getch();
		if(a=='1') goto pos1;
		else if(a=='2');
		else goto pos_2;
	}
}
//主函数 
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
printf("\t\t\t\t\t    欢迎使用GSG9数字图书管理系统\n");
printf("\n"); 
printf("\t\t\t\t\t           [1]管理员入口        \n");
printf("\n"); 
printf("\t\t\t\t\t           [2]学生入口          \n");
printf("\n");
printf("\t\t\t\t\t           [3]退出系统          \n");
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
	printf("\t\t\t\t                 管 理 员 登 陆             \n"); 
	printf("\t\t\t\t    ****************************************\n");
	printf("\t\t\t\t    用户名：");
	scanf("%s",n);
	printf("\t\t\t\t    密码：");
	passwd(p);
	int sign1=0; 
	if(!strcmp(n,"root")&&!strcmp(p,"toor"))  sign1=1;
	else 
	{
	int n;
	printf("\n");
	printf("\t\t\t\t    密码错误！[1]重新输入[2]返回\n");
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
		printf("\t\t\t\t                  选 择 功 能               \n");
	    printf("\t\t\t\t    ****************************************\n");
	    printf("\n");
		printf("\t\t\t\t                  [1]存入数据               \n");
		printf("\n");
		printf("\t\t\t\t                  [2]删除数据               \n");
		printf("\n");
		printf("\t\t\t\t                  [3]精确查询               \n");
		printf("\n");
		printf("\t\t\t\t                  [4]模糊查询               \n");
		printf("\n");
		printf("\t\t\t\t                  [5]修改数据               \n");
		printf("\n");
		printf("\t\t\t\t                  [6]颜色修改               \n");
		printf("\n");
		printf("\t\t\t\t                  [7]刷新数据               \n");
		printf("\n");
		printf("\t\t\t\t                  [8]退出登陆               \n");
		char b;
		b=getch();
		system("cls");
		if(b=='1') 
		{
		printf("\n");
        printf("\n");
		printf("\t\t\t\t    ****************************************\n");
		printf("\t\t\t\t                  存 入 数 据               \n");
	    printf("\t\t\t\t    ****************************************\n");
		storebooks();
		goto pos3;
		} 
		else if(b=='2') 
		{
		printf("\n");
        printf("\n");
		printf("\t\t\t\t    ****************************************\n");
		printf("\t\t\t\t                  删 除 数 据               \n");
	    printf("\t\t\t\t    ****************************************\n");
		delbook();
		goto pos3;
		} 
		else if(b=='3') 
		{
		printf("\n");
        printf("\n");
		printf("\t\t\t\t    ****************************************\n");
		printf("\t\t\t\t                  精 确 查 询               \n");
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
		printf("\t\t\t\t                  修 改 数 据               \n");
	    printf("\t\t\t\t    ****************************************\n");
		revise();
		goto pos3;
		}
		else if(b=='6') 
		{
		printf("\n");
        printf("\n");
		printf("\t\t\t\t    ****************************************\n");
		printf("\t\t\t\t                  颜 色 修 改               \n");
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
	printf("\t\t\t\t                  选 择 功 能               \n");
	printf("\t\t\t\t    ****************************************\n");
	printf("\n");
	printf("\t\t\t\t                  [1]学生登陆               \n");
	printf("\n");
	printf("\t\t\t\t                  [2]用户注册               \n");
	printf("\n");
	printf("\t\t\t\t                  [3]密码找回               \n");
	printf("\n");
	printf("\t\t\t\t                  [4]返回主菜单             \n");
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
			printf("\t\t\t\t                  欢 迎 您 ！               \n");
			printf("\t\t\t\t                  %s                        \n",localuser);
			printf("\t\t\t\t    ****************************************\n");
			printf("\n");
			printf("\t\t\t\t                  [1]借阅书籍               \n");
			printf("\n");
			printf("\t\t\t\t                  [2]归还书籍               \n");
			printf("\n");
			printf("\t\t\t\t                  [3]精确查询               \n");
			printf("\n");
			printf("\t\t\t\t                  [4]模糊查询               \n");
			printf("\n");
			printf("\t\t\t\t                  [5]借阅记录               \n");
			printf("\n");
			printf("\t\t\t\t                  [6]修改密码               \n");
			printf("\n");
			printf("\t\t\t\t                  [7]退出登陆               \n");
			char b;
			printf("\n");
			pos7:
			b=getch();
			if(b=='1') 
			{
				system("cls");
				printf("\t\t\t\t    ****************************************\n");
				printf("\t\t\t\t                  借 阅 书 籍               \n");
				printf("\t\t\t\t    ****************************************\n");
				borrow();
				goto pos6;
			}
			else if(b=='2')
			{
				system("cls");
				printf("\t\t\t\t    ****************************************\n");
				printf("\t\t\t\t                  归 还 书 籍               \n");
				printf("\t\t\t\t    ****************************************\n");
				retu();
				goto pos6;
			}
			else if(b=='3')
			{
				system("cls");
				printf("\t\t\t\t    ****************************************\n");
				printf("\t\t\t\t                  查 询 书 籍               \n");
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
				printf("\t\t\t\t                  借 阅 记 录               \n");
				printf("\t\t\t\t    ****************************************\n");
				note();
				goto pos6;
			}
			else if(b=='6')
			{
				system("cls");
				printf("\t\t\t\t    ****************************************\n");
				printf("\t\t\t\t                  修 改 密 码               \n");
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
