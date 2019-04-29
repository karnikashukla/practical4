#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX 100
#define SIZE 100

int top = -1;
//int stack[MAX];

isempty()
{
	if(top==-1)
	{
		printf("\nEmpty stack");
		return;
	}
}

void push(int *stack,int item)
{
	
        top = top + 1;
		stack[top] =item;
}

int pop(int *stack)
{
	if(top == -1)
		printf("Stack Underflow\n");
	else
		return stack[top--];
}

int peek(int *stack)
{
	return stack[top];
}

void sortedinsert(int *stack,int val)
{
	if(isempty(stack) ||  val > peek(stack))
	{
		push(stack,val);
		return;
	}
	
	int temp=pop(stack);
	sortedinsert(stack,val);
	push(stack,temp);
}

void sort(int *stack)
{
	if(!isempty(stack))
	{
		int x=pop(stack);
		sort(stack);
		sortedinsert(stack,x);
	}
}

char *sortstring(char *str)
{
	int *stack= (int *)calloc(strlen(str),sizeof(int));
	int i;
	for(i=0;i<strlen(str);i++)
	{
		push(stack, (int)str[i]);
	}
	
	sort(stack);
	
	for(i=top;i>=0;i--)
	{
		str[i]= (int)pop(stack);
	}
	return str;
}

int main()
{
	char *str= (char *)calloc(1024,sizeof(char));
	int *arr= (int *)calloc(5,sizeof(int));
	printf("Enter the string : " );
	scanf("%s",str);
	
	str= sortstring(str);
	
	printf("\nSorted string : %s ",str);
	return 0;

}
//hello395world216
