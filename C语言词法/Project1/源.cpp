#include<stdio.h>
#include<string.h>
#include <stdlib.h>



FILE *input, *output;//�ļ�ָ��
char character;//�ַ�����,������¶����Դ�����ַ���
char token[20];//�ַ�����,��Ź��ɵ��ʷ��ŵ��ַ�����
int n;//n��token������±ꡣ
int line;//��ǰ�к�
int c;//�������ֵ��ֱ����
	  //char *kt[6] = { "if","else","do","while","case","switch" };


	  //�ж�character�е��ַ��Ƿ�Ϊ��ĸ�Ĳ�������,�����򷵻�true,���򷵻�false��
bool letter()
{
	if ((character >= 'a') && (character <= 'z') || (character >= 'A') && (character <= 'Z'))
		return true;
	else
		return false;
}
//�ж�character�е��ַ��Ƿ�Ϊ���ֵĲ�������,�����򷵻�true,���򷵻�false��
bool digit()
{
	if ((character >= '0') && (character <= '9'))
		return true;
	else
		return false;
}





//�������ַ�����character��
void getChar()
{
	character = fgetc(input);
}


//�˳��ո���character���ַ�Ϊ��,�����getchar(),ֱ��characterΪ�ǿա�

void getbe()
{
	while (character == ' ' || character == '	' || character == '\n')
	{
		getChar();
	}
}


//��token�е��ַ�����character�е��ַ����ӣ���Ϊtoken�е��µ��ַ�����
void concatenation()
{
	token[n] = character;
	n++;
	token[n] = '\0';//�ַ���������־
}

//�ú�����ɨ��ָ�����һ���ַ�,ͬʱ��character��Ϊ�հס�
void retract()
{
	fseek(input, -1, 1);
}


//�ú����ܽ��г�����
void error()
{
	printf("��������\n");
}


int buildlist1()  //��ʶ��
{
	int i;
	char x[] = "abcdefghijklmnopqrstuvwxyz";
	for (i = 0; x[i] != '\0'; i++)
	{
		if (*token == x[i])
			return 1;
		else
			return 0;
	}



	//���ұ�����
}int reserve()
{
	/*
	for (int  i = 0; i < 6; i++)

	if (strcmp(token, kt[i]) == 1)
	{
	return 1;
	break;
	}
	else
	return 0;*/

	if (strcmp(token, "if") == 1)//strcmp(char*s1,char*s2);��s1=s2ʱ������ֵ=0
		return 1;
	else if (strcmp(token, "int") == 1)
		return 1;
	else if (strcmp(token, "for") == 1)
		return 1;
	else if (strcmp(token, "while") == 1)
		return 1;
	else if (strcmp(token, "do") == 1)
		return 1;
	else if (strcmp(token, "return") == 1)
		return 1;
	else if (strcmp(token, "break") == 1)
		return 1;
	else if (strcmp(token, "continue") == 1)
		return 1;
	else if (strcmp(token, "void") == 1)
		return 1;
	else
		return 0;

}
void main()
{

	input = fopen("E://input.txt","r");//��r����Ϊ�����һ���ı��ļ���
	output = fopen("E://output.txt","w");//��w����Ϊ�����һ���ı��ļ���
	token[0] = ' ';//��ʼ��token����
	while (character != '#')//#һ�������ı��ļ�����Ϊ�ļ��Ľ�β���š�
	{
		n = 0;//ÿѭ��һ���ַ����꣬nҪ��0
		getChar();
		getbe();//�˳��ո�

		switch (character)
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
			while (letter() || digit())//�����������ĸ�����֡�
			{
				concatenation();//����ǰ������ַ�����token����
				getChar();
			}
			retract();//ɨ��ָ�����һ���ַ���
			c = reserve();//���ȡ�ַ������ֱ���롣
			if (c == 0)//c==0��ʾtoken�����д��б����֡�
			{
				c = buildlist1();
				if (c == 1)
					fprintf(output, "(%d,��%s��)\n", 6, token);
			}
			else
			{
				fprintf(output, "(%d,��%s��)\n", 1, token);
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
			while (digit())
			{
				concatenation();//����ǰ������ַ�����token����/
				getChar();
			}
			retract();
			fprintf(output, "(%d,��%s��)\n", 7, token);//�����д���ļ���
			break;
		}
		case'+':
			fprintf(output, "(%d,��%s��)\n", 8, "+");
			break;
		case'-':
			fprintf(output, "(%d,��%s��)\n", 9, "-");
			break;
		case'*':
			fprintf(output, "(%d,��%s��)\n", 10, "*");
			break;
		case'(':
			fprintf(output, "(%d,��%s��)\n", 0, "(");
			break;
		case')':
			fprintf(output, "(%d,��%s��)\n", 0, ")");
			break;
		case'{':
			fprintf(output, "(%d,��%s��)\n", 0, "{");
			break;
		case'}':
			fprintf(output, "(%d,��%s��)\n", 0, "}");
			break;
		case',':
			fprintf(output, "(%d,��%s��)\n", 0, ",");
			break;
		case'<':
			getChar();
			if (character == '=')
			{
				fprintf(output, "(%d,��%s��)\n", 11, "<=");
			}
			else
			{
				fprintf(output, "(%d,��%s��)\n", 11, "<");
				retract();
			}
			break;
		case'>':
			getChar();
			if (character == '=')
			{
				fprintf(output, "(%d,��%s��)\n", 11, ">=");
			}
			else
			{
				fprintf(output, "(%d,��%s��)\n", 11, ">");
				retract();
			}
			break;
		case'=':
			getChar();
			if (character == '=')
			{
				fprintf(output, "(%d,��%s��)\n", 11, "==");
			}
			else
			{
				fprintf(output, "(%d,��%s��)\n", 12, "=");
				retract();
			}
			break;
		case';':
		{
			fprintf(output, "(%d,��%s��)\n", 13, ";");
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



	/*
	char *kt[10] = { "if","else","do","while","case","switch" };
	char str[10];
	char token[30];
	char ch;
	int num = 1;
	int i;
	int l = 0;
	int j = 0;
	int length = 0;

	printf("please input a string (end with '#')");
	do
	{
	scanf_s("%c", &ch,2);
	str[length] = ch;
	length++;
	} while (ch != '#');
	printf("-----------------------------------------------\n");
	printf("\t�ַ�\t\t���\n");
	printf("-----------------------------------------------\n");

	ch = str[j];

	while (num != 0)
	{
	if (ch >= '0'&&ch <= '9')
	{
	while (ch >= '0'&&ch <= '9')
	{
	token[l] = ch;
	j++;
	l++;
	ch = str[j];
	}
	num = 7;
	out(l, token, num);
	l = 0;
	}//if ch between 0and 9
	else if ((ch >= 'a'&&ch <= 'z') || (ch <= 'A'&&ch <= 'Z'))
	{
	while ((ch >= 'a'&&ch <= 'z') || (ch <= 'A'&&ch <= 'Z'))
	{
	token[l] = ch;
	j++;
	l++;
	ch = str[j];
	}
	num = 8;
	for (i = 0; i < 6; i++)

	if (strcmp(token, kt[i]) == 0)
	{
	num = i + 1;
	break;
	}
	out(l, token, num);
	l = 0;
	}//if ch between a and z orA AND Z
	else if (ch == ' ')
	{
	while (ch == ' ')
	{
	j++;
	ch = str[j];
	}
	}//if ch is ' '

	else switch (ch)
	{
	case'+':
	token[l] = ch;
	l++;
	j++;
	ch = str[j];
	num = 9;
	out(l, token, num);
	break;
	case'-':
	token[l] = ch;
	l++;
	j++;
	ch = str[j];
	num = 10;
	out(l, token, num);
	l = 0;
	break;
	case'*':
	token[l] = ch;
	l++;
	j++;
	ch = str[j];
	num = 11;
	out(l, token, num);
	l = 0;
	break;
	case'/':
	token[l] = ch;
	l++;
	j++;
	ch = str[j];
	num = 12;
	out(l, token, num);
	l = 0;
	break;
	case'>':
	token[l] = ch;
	l++;
	j++;
	ch = str[j];
	if (ch == '=')
	{
	token[l] = ch;
	l++;
	j++;
	ch = str[j];
	num = 14;
	out(l, token, num);
	}
	else
	{
	num = 13;
	out(l, token, num);
	}
	l = 0;
	break;
	case'<':
	token[l] = ch;
	l++;
	j++;
	ch = str[j];
	if (ch == '=')
	{
	token[l] = ch;
	l++;
	j++;
	ch = str[j];
	num = 16;
	out(l, token, num);
	}
	else
	{
	num = 15;
	out(l, token, num);
	}
	l = 0;
	break;
	case'=':
	token[l] = ch;
	l++;
	j++;
	ch = str[j];
	if (ch == '=')
	{
	token[l] = ch;
	l++;
	j++;
	ch = str[j];
	num = 18;
	out(l, token, num);
	}
	else
	{
	num = 17;
	out(l, token, num);
	}
	l = 0;
	break;
	case',':
	token[l] = ch;
	l++;
	j++;
	ch = str[j];
	num = 19;
	out(l, token, num);
	l = 0;
	break;
	case';':
	token[l] = ch;
	l++;
	j++;
	ch = str[j];
	num = 20;
	out(l, token, num);
	l = 0;
	break;

	case':':
	token[l] = ch;
	l++;
	j++;
	ch = str[j];
	num = 21;
	out(l, token, num);
	l = 0;
	break;
	case'(':
	token[l] = ch;
	l++;
	j++;
	ch = str[j];
	num = 22;
	out(l, token, num);
	l = 0;
	break;
	case')':
	token[l] = ch;
	l++;
	j++;
	ch = str[j];
	num = 23;
	out(l, token, num);
	l = 0;
	break;
	case'{':
	token[l] = ch;
	l++;
	j++;
	ch = str[j];
	num = 24;
	out(l, token, num);
	l = 0;
	break;
	case'}':
	token[l] = ch;
	l++;
	j++;
	ch = str[j];
	num = 25;
	out(l, token, num);
	l = 0;
	break;
	case'#':
	token[l] = ch;
	l++;
	num = 0;
	out(l, token, num);
	break;
	default:
	j++;
	ch = str[j];
	break;
	}//swith
	}//while j<length
	*/
}


/*  int  print(int l, char token[], int num)
{
int i;
printf("\t");
for (i = 0; i < l; i++)
printf("%c", token[i]);
printf("\t\t\t%d\n", num);
}
*/