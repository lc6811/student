#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<stdlib.h>
typedef struct student{
	int id;
	char user_name[1024];
	char pass_word[1024];
	float score;
}Stu;
//函数功能：一级菜单
//函数入参：空参
void menu1();
void menu2();
void menu3();
//function:control
//argv:the address of class
void control(Stu* class);
void control_user(Stu* class);
int launch(Stu* class);
void control_gur(Stu* class);
void enter_wait();
//function:regist
//argv:class address
void regist(Stu* class);
//function:printf_all
//argv:class address
int search_username(Stu* class,char*serach_name);
int login(Stu* class);
void gur(Stu* class);
void update(Stu* class);
void modify(Stu* class);
void rank(Stu* class);
void printf_all(Stu* class);
int len = 0;//全局变量
int main()
{
	Stu class[3];
	Stu* p_class = class;
	memset(p_class,0,sizeof(class));
	control(p_class);
	return 0;
}

void control(Stu* class)
{
	int choose = 0;
	while(1)
	{
		sleep(1);
		system("clear");
		menu1();
		printf("请输入您的选择:");
		scanf("%d",&choose);
		if(getchar() != '\n')
		{
			printf("输入错误\n");
			continue;
		}
		switch(choose)
		{
			case 1:
				printf("到达用户注册函数\n");
				regist(class);
				break;
			case 2:
				printf("用户登录\n");
				if(login(class) == 1)
				{
					continue;
				}
				control_user(class);
				break;
			case 3:
				printf("管理员登录\n");
				if(lanuch(class) == 1)
				{
					continue;
				}
				control_gur(class);
				break;
			case 0:
				return;
			default:
				printf("输入错误！\n");
				break;
		}
	}
}
void control_user(Stu* class)
{
	int choose = 0;
	int position = 0;
	while(1)
	{
		sleep(1);
		system("clear");
		menu2();
		printf("请输入您的选择:");
		scanf("%d",&choose);
		if(getchar() != '\n')
		{
			printf("输入错误\n");
			continue;
		}
		switch(choose)
		{
			case 1:
				printf("查看排名\n");
				rank(class);
				break;
			case 2:
				printf("修改密码\n");
				update(class);
				break;
			case 3:
				printf("查看所有用户\n");
				printf_all(class);
				break;
			case 0:
				return;
			default:
				printf("输入错误!\n");
				break;
		}
	}
}
int lanuch(Stu* class)
{
	char user_name[1024] = "wuwei";
	char pass_word[1024] = "123";
	char input_username[1024] = "";
	printf("请输入用户名:");
	scanf("%s",input_username);
	if(strcmp(input_username,user_name) != 0)
	{
		printf("用户名不存在\n");
		return 1;
	}
	char input_password[1024] = "";
	printf("请输入密码\n");
	scanf("%s",input_password);
	if(strcmp(input_password,pass_word) != 0)
	{
		printf("密码错误\n");
		return 1;
	}

}


void control_gur(Stu* class)		
{
	int choose = 0;
	while(1)
	{
		sleep(1);
		system("clear");
		menu3();
		printf("请输入您的选择:");
		scanf("%d",&choose);
		if(getchar() != '\n')	
		{
			printf("输入错误！\n");
		}
		switch(choose)
		{
			case 1:
				printf("修改成绩\n");
				modify(class);
				break;
			case 2:
				printf("查看排名\n");
				rank(class);
				break;
			case 3:
				printf("查看所有用户\n");
				printf_all(class);
				break;
			case 0:
				return;
		 		default:
				printf("输入错误！\n");
				break;
			
		}
	}
}
void menu1()
{
	printf("1.注册账户\n");
	printf("2.用户登录\n");
	printf("3.管理员登录\n");
	printf("0.退出系统\n");
}

void menu2()
{
	printf("1.查看排名\n");
	printf("2.修改密码\n");
	printf("3.查看所有用户\n");
	printf("0.返回上一级\n");	
}

void menu3()
{
	printf("1.修改成绩\n");
	printf("2.查看排名\n");
	printf("3.查看所有用户\n");
	printf("0.返回上一级\n");
}




void regist(Stu* class)
{
	if(len == 3)
	{
		printf("数据库容量不允许\n");
	}
	Stu student;
	memset(&student,0,sizeof(student));
	char password_ensure[1024] = "";
	printf("请输入用户名:");
	scanf("%s",student.user_name);
	printf("请输入密码:");
	scanf("%s",student.pass_word);
	printf("请再次输入密码：");
	scanf("%s",password_ensure);
	if(strcmp(student.pass_word,password_ensure) == 0)
	{
		student.id = len+1;
		*(class + len) = student;
		len++;
		printf("注册成功!\n");
	}
	else
	{
		printf("两次密码不一致，注册失败\n");
	}
	getchar();
}


int search_username(Stu* class,char* search_username)
{
	int i = 0;
	for(i = 0;i < len;i++)
	{
		if (strcmp(search_username,class[i].user_name)  ==  0)
		{
			return i;
		}
	}
	return -1;
}
int login(Stu* class)
{
	char input_username[1024] = "";
	printf("请输入您的用户名:");
	scanf("%s",input_username);
	int index = search_username(class,input_username);
	if(index < 0)
	{
		printf("用户名不存在\n");
		return 1;
	}
	char input_password[1024] = "";
	printf("请输入密码:");
	scanf("%s",input_password);
	if(strcmp(input_password,class[index].pass_word) == 0)
	{
		printf("登录成功!\n");
		return 0;
	}
	else
	{
		printf("登录错误，登录失败!\n");
		return 1;
	}

}

void modify(Stu* class)
{
	char input_username[1024] = "";
	char input_password[1024] = "";
	printf("请输入用户名:");
	scanf("%s",input_username);
	int index = search_username(class,input_username);
	if(index < 0)
	{
		printf("用户名不存在\n");
	}
	else
	{
		float grade = 0;
		printf("请输入成绩:");
		scanf("%f",&grade);
		class[index].score = grade;
		printf("成绩修改完成\n");
	}
}


void rank(Stu* class)
{
	int i = 0;
	int j = 0;
	float temp = 0;
	for(i = 0;i < len - 1;i++)
	{
		for(j = 0;j < len - 1 - i;j++ )
		{
			if(class[j].score > class[j+1].score)
			{
				temp = class[j].score;
				class[j].score = class[j+1].score;
				class[j+1].score = temp;
			}
		}
	}
	printf("排序完成");
}



void update(Stu* class)
{
	char input_username[1024] = "";
    printf("请输入用户名:");
	scanf("%s",input_username);
	int index = search_username(class,input_username);
	if(index < 0)
	{
		printf("用户名不存在\n");
		return;
	}
	char input_password[1024] = "";
	printf("请输入密码:");
	scanf("%s",input_password);
	if(strcmp(class[index].pass_word,input_password) != 0)
	{
		printf("密码错误\n");
		return;
	}
	else
	{
	
		char update_password[1024] = "";
		printf("请输入新密码:");	
		scanf("%s",update_password);
		strcpy(class[index].pass_word,update_password);
		printf("密码修改成功\n");
	}
}


void printf_all(Stu* class)
{
	printf("ID\t用户名\t密码\t分数\n");
	int i = 0;
	for(i = 0;i < len;i++)
	{ 
		printf("%d\t%s\t%s\t%.2f\n",class[i].id,class[i].user_name,class[i].pass_word,class[i].score);
	}
}


void enter_wait()
{
	printf("按回车键以继续...\n");
	while(getchar() !='\n');
}
