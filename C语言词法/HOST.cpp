#include<stdio.h>
#include<string.h>
int  print(int l, char token[], int num)
{
	int i;
	printf("\t");
	for (i = 0; i < l; i++)
		printf("%c", token[i]);
	printf("\t\t\t%d\n", num);
	return 0;
}
void main()
	{
	char *kt[6] = { "if","else","do","while","case","switch" };
	char str[10];
	char token[10];
	char ch;
	int num = 1;
	int i;
	int l = 0;
	int j = 0;
	int length = 0;

	printf("please input a string (end with '#')");
	do
	{
		scanf("%c", &ch);
		str[length] = ch;
		length++;
	} while (ch!='#');
	printf("-------------------------------------\n");
	printf("\tWordsymbol\t\tTypecode\n");
	printf("--------------------------------------\n");

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
			print(l,token,num);
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
			for(i=0;i<6;i++)
				if (strcmp(token, kt[i]) == 0)
				{
					num = i + 1;
					break;
				}
			print(l, token, num);
			l = 0;
		}//if ch between a and z orA AND Z
		else if (ch == ' ')
		{
			j++;
			ch = str[j];
		}
	}//if ch is ' '
	switch (ch)
	{
	case'+':
		token[l] = ch;
		l++;
		j++;
		ch = str[j];
		num = 9;
		print(l, token, num);
	case'-':
		token[l] = ch;
		l++;
		j++;
		ch = str[j];
		num = 10;
		print(l, token, num);
		l = 0;
		break;
	case'*':
		token[l] = ch;
		l++;
		j++;
		ch = str[j];
		num = 11;
		print(l, token, num);
		l = 0;
		break;
	case'/':
		token[l] = ch;
		l++;
		j++;
		ch = str[j];
		num = 12;
		print(l, token, num);
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
			print(l, token, num);
		}
		else
		{
			num = 13;
			print(l, token, num);
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
			print(l, token, num);
		}
		else
		{
			num = 15;
			print(l, token, num);
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
			print(l, token, num);
		}
		else
		{
			num = 17;
			print(l, token, num);
		}
		l = 0;
		break;
	case',':
		token[l] = ch;
		l++;
		j++;
		ch = str[j];
		num = 19;
		print(l, token, num);
		l = 0;
		break;
	case';':
		token[l] = ch;
		l++;
		j++;
		ch = str[j];
		num = 20;
		print(l, token, num);
		l = 0;
		break;

	case':':
		token[l] = ch;
		l++;
		j++;
		ch = str[j];
		num = 21;
		print(l, token, num);
		l = 0;
		break;
	case'(':
		token[l] = ch;
		l++;
		j++;
		ch = str[j];
		num = 22;
		print(l, token, num);
		l = 0;
		break;
	case')':
		token[l] = ch;
		l++;
		j++;
		ch = str[j];
		num = 23;
		print(l, token, num);
		l = 0;
		break;
	case'{':
		token[l] = ch;
		l++;
		j++;
		ch = str[j];
		num = 24;
		print(l, token, num);
		l = 0;
		break;
	case'}':
		token[l] = ch;
		l++;
		j++;
		ch = str[j];
		num = 25;
		print(l, token, num);
		l = 0;
		break;
	case'#':
		token[l] = ch;
		l++;
		j++;
		num = 0;
		print(l, token, num);
		break;
	default:
		j++;
		ch = str[j];
		break;
	     }//swith
	}//while j<length

