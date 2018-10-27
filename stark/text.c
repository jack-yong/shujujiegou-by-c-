#include "Stark.h"

int Precede(char c1,char c2);

char left2right(char ch);

void transform(char String[],struct Stark* NStark); //ÖÐÐò×ªºóÐò 

int PiPei(char String[],struct Stark* NStark); //À¨ºÅÆ¥Åä 0Îª²»Æ¥Åä 1ÎªÆ¥Åä 

void main()
{
	int i = 0;
	struct Stark* OStark = StarkInit();
	struct Stark* NStark1 = StarkInit();
	struct Stark* NStark2 = StarkInit();
	char* String1 = "(3+4)*5+6*(7-8)";
	char* String2 = "(3+4)*5+6*7-8[]{}";
	printf("%s\n",String2);
	printf("%d\n",PiPei(String2,NStark2));
	printf("%s\n",String1);
	transform(String1,NStark1);
	Destory(NStark1);
	Destory(NStark2);
}

int Precede(char c1,char c2)
{
	if(c1 == '*' || c1 == '/')
	{
		if(c1 == c2)return 0;
		else if(c2 == '+' || c2 == '-')
			return 1;
	}
	else if(c1 == '+' || c1 == '-')
	{
		if(c1 == c2)return 0;
		else if(c2 == '*' || c2 == '/') 
			return -1;
	}
	return 	NULL;
}

char left2right(char ch)
{
	if(ch == '(')return ')';
	if(ch == '[')return ']';
	if(ch == '{')return '}';
	if(ch == ')')return '(';
	if(ch == ']')return '[';
	if(ch == '}')return '{';
	return NULL;
}
void transform(char String[],struct Stark* NStark)
{
	int i = 0;
	while(String[i])
	{
		if(String[i] >= '0' && String[i] <= '9') 
		{
			printf("%c",String[i]);
			i++;
			continue;
		}
		if(String[i] == '(')
		{
			Push(NStark,(int)String[i]);
			i++;
			continue;
		}
		while(String[i] == ')')
		{
			if(Gettop(NStark) == '(')
			{
				Pop(NStark);
				break;
			}
			printf("%c",(char)Pop(NStark));
		} 
		char ch = String[i];
		while(ch == '+' || ch == '-' || ch == '*' || ch == '/' )
		{
			
			if(Gettop(NStark) == '(' || isEmpty(NStark))
			{
				Push(NStark,(int)String[i]);
				break;
			}
			if(Precede((char)Gettop(NStark),String[i]) == -1)
			{
				Push(NStark,(int)String[i]);
				break;
			}
			printf("%c",(char)Pop(NStark));
		}
		//Push(NStark,(int)String[i]);
		i++;
	} 
	/*do
	{
		if(ch >= '0' && ch <= '9') 
			printf("%c",ch);
			break;
		if(ch == '(')
			Push(NStark,ch);
			break;
		if(ch == ')'&& Gettop(NStark) != '(')
		{
			printf("%c",Pop(NStark));
			break;	
		}
		if(Gettop(NStark) != '('|| !isEmpty(NStark))
		{
			switch(Precede((char)Gettop(NStark),(char)ch))
			{
				case '<':
					Push(NStark,ch);
					ch = getchar();
					break;
				case '=':
				case '>':
					printf("%c",Pop(NStark));
					ch = getchar();
					break;
			}
		}
		ch = getchar();
	}while(ch != '(' && ch != '\n');*/
	while(!isEmpty(NStark)) printf("%c",Pop(NStark));
}

int PiPei(char String[],struct Stark* NStark)
{
	int i = 0;
	while(String[i])
	{
		if(String[i] == '(' || String[i] == '[' || String[i] == '{')
		{
			Push(NStark,(int)String[i]);
			i++;
			continue;
		}
		if(String[i] == ')' || String[i] == ']' || String[i] == '}' )
		{
			if(String[i] == left2right(Gettop(NStark)))
			{
				Pop(NStark);
				i++;
				continue;
			}
			else return 0;
		}
		i++;
		
	} 
	if(!isEmpty(NStark))
	{
		return 0;
	}
	return 1;
} 
