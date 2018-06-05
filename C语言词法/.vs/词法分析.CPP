#include<stdio.h>
#include<stdlib.h>
#include<string.h>


FILE *input,*output;//文件指针
char character;//字符变量,存放最新读入的源程序字符。
char token[20];//字符数组,存放构成单词符号的字符串。
int n;//n是token数组的下标。
int line;//当前行号
int c;//代表保留字的种别编码


//该函数能判断character中的字符是否为字母的布尔函数,若是则返回true,否则返回false。
bool letter()
{
	if((character>='a')&&(character<='z')||(character>='A')&&(character<='Z'))
		return true;
	else
		return false;
}
//该函数能判断character中的字符是否为数字的布尔函数,若是则返回true,否则返回false。
bool digit()
{
	if((character>='0')&&(character<='9'))
		return true;
	else
		return false;
}
//该函数能把下一个输入字符读到character中，读入源程序字符的指针前移一个字符。
/*void getChar()
{

	character=fgetc(input);
}*/
//该函数能滤除空格，若character中字符为空,则调用getchar(),直至character为非空。
void getbe()
{
	while(character==' '||character=='	'||character=='\n')
	{
		character = fgetc(input);
	}
}
//该函数能将token中的字符串与character中的字符连接，作为token中的新的字符串。
void concatenation()
{
	token[n]=character;
	n++;
	token[n]='\0';//字符串结束标志
}
//该函数能扫描指针回退一个字符,同时将character置为空白。
void retract()
{
	fseek(input,-1,1);
}
//该函数能进行出错处理。
void error()
{
	printf("输入有误\n");
}
//按token中的字符串查找保留字表，若是保留字，返回它的编码，否则返回0。
int reserve()
{
	if(strcmp(token,"if")==1)//strcmp(char*s1,char*s2);当s1=s2时，返回值=0
		return 1;
	else if(strcmp(token,"int")==1)
		return 1;
	else if(strcmp(token,"for")==1)
		return 1;
	else if(strcmp(token,"while")==1)
		return 1;
	else if(strcmp(token,"do")==1)
		return 1;
	else if(strcmp(token,"return")==1)
		return 1;
	else if(strcmp(token,"break")==1)
		return 1;
	else if(strcmp(token,"continue")==1)
		return 1;
	else if(strcmp(token,"void")==1)
		return 1;
	else
		return 0;
}

int buildlist1()
{
	int i;
	char x[]="abcdefghijklmnopqrstuvwxyz";
	for(i=0;x[i]!='\0';i++)
	{
	if(*token==x[i])
		return 1;
	else
		return 0;
	}
}
void main()
{
	input=fopen("E:\\1.txt","r");//“r”，为输入打开一个文本文件。
	output=fopen("E:\\output.txt","w");//“w”，为输出打开一个文本文件。
	token[0]=' ';//初始化token数组
	while(character!='#')//EOF一般用在文本文件中作为文件的结尾符号。
	{
		n=0;//每循环一次字符串完，n要置0
		character = fgetc(input);
		getbe();//滤除空格。
		switch(character)
	{
		case'a':
		case'b':
		case'c':
		case'd':
		case'e':
		case'f':
		case'g':
		case'h':
		case'i':
		case'j':
		case'k':
		case'l':
		case'm':
		case'n':
		case'o':
		case'p':
		case'q':
		case'r':
		case's':
		case't':
		case'u':
		case'v':
		case'w':
		case'x':
		case'y':
		case'z':
			{
				while(letter()||digit())//当读入的是字母或数字。
				{
					concatenation();//将当前读入的字符送入token数组
					character = fgetc(input);
				}
				retract();//扫描指针回退一个字符。
				c=reserve();//则获取字符串的种别编码。
				if(c==0)//c==0表示token数组中存有保留字。
				{
					c=buildlist1();
					if (c==1)
					fprintf(output,"(%d,“%s”)\n",6,token);
				}
				else
				{
					fprintf(output,"(%d,“%s”)\n",1,token);
				}
				break;
			}
		case'0':
		case'1':
		case'2':
		case'3':
		case'4':
		case'5':
		case'6':
		case'7':
		case'8':
		case'9':
			{
				while(digit())
				{
					concatenation();//将当前读入的字符送入token数组/
					character = fgetc(input);
				}
					retract();
					fprintf(output,"(%d,“%s”)\n",7,token);//将结果写入文件。
					break;
				}
		case'+':
			fprintf(output,"(%d,“%s”)\n",8,"+");
			break;
		case'-':
			fprintf(output,"(%d,“%s”)\n",9,"-");
			break;
		case'*':
			fprintf(output,"(%d,“%s”)\n",10,"*");
			break;
		case'(':
			fprintf(output,"(%d,“%s”)\n",0,"(");
			break;
		case')':
			fprintf(output,"(%d,“%s”)\n",0,")");
			break;
		case'{':
			fprintf(output,"(%d,“%s”)\n",0,"{");
			break;
		case'}':
			fprintf(output,"(%d,“%s”)\n",0,"}");
			break;
		case',':
			fprintf(output,"(%d,“%s”)\n",0,",");
			break;
		case'<':
			character = fgetc(input);
			if(character=='=')
			{
				fprintf(output,"(%d,“%s”)\n",11,"<=");
			}
			else
			{
				fprintf(output,"(%d,“%s”)\n",11,"<");
				retract();
			}
			break;
		case'>':
			character = fgetc(input);
			if(character=='=')
			{
				fprintf(output,"(%d,“%s”)\n",11,">=");
			}
			else
			{
				fprintf(output,"(%d,“%s”)\n",11,">");
				retract();
			}
			break;
		case'=':
			character = fgetc(input);
			if(character=='=')
			{
				fprintf(output,"(%d,“%s”)\n",11,"==");
			}
			else
			{
				fprintf(output,"(%d,“%s”)\n",12,"=");
				retract();
			}
			break;
		case';':
			{
				fprintf(output,"(%d,“%s”)\n",13,";");
			}
			break;
		case'#':
			printf("success!\n");
			break;
		default:
			error();
		}
		}
		fclose(output);
		fclose(input);
		system("pause");
}
