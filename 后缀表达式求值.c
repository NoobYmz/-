#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 100

typedef int Elmetype;

typedef struct stack{	
	Elmetype data[MAXSIZE];
	int top;
}Stack; 

typedef enum{
	LEFT_PARE,RIGHT_PARE,
	ADD,SUB,MUL,DIV,MOD,
	EOS,NUM
}contentType; 

char string[] = "88+2/2+56*-";


//初始化
Stack* InitiStack(){
	Stack* p;
	p = (Stack*)malloc(sizeof(Stack));
	
	p->top = -1;
	
	return p;
}

//入栈
void push(Stack* q, Elmetype e){
	if ( q->top >= MAXSIZE ){
		printf("栈满了\n");
		return;
	}
	
	q->data[++q->top] = e;
}

//出栈
Elmetype pop(Stack* s){
	if ( s->top == -1 ){
		printf("该栈目前还没有元素\n");
		return -1;
	}
	
	Elmetype e;
	
	e = s->data[s->top--];
	
	return e;
} 

//获取栈顶元素
Elmetype GetHead(Stack* s){
	if ( s->top == -1 ){
		printf("该栈目前还没有元素\n");
		return -1; 
	}
	
	return s->data[s->top];
}

contentType GetToken(char* s, int* n){
	*s = string[*n];
	*n = *n + 1;
	switch(*s){
		case '+':
			return ADD;
		case '-':
			return SUB;
		case '*':
			return MUL;
		case '/':
			return DIV;
		case '%':
			return MOD;
		case '\0':
			return EOS;
		default:
			return NUM;
	}
	
	
}

void Eval(Stack* s){
	char symbol;
	Elmetype op1,op2;
	int index = 0;
	contentType token;
	
	Elmetype result;
	
	token = GetToken(&symbol, &index);
	while ( token != EOS ){
		
		if ( token == NUM ) {
			push(s, symbol - '0');
		}
		else{
			op2 = pop(s);
			op1 = pop(s); 
			switch(token){
				case 2:
					push(s, op1 + op2 );
					break;
				case 3:
					push(s, op1 - op2 );
					break;
				case 4:
					push(s, op1 * op2 );
					break;
				case 5:
					push(s, op1 / op2 );
					break;
				case 6:
					push(s, op1 % op2 );
					break;
			}
		}
		token = GetToken(&symbol, &index);
	}
	result = pop(s);
	printf("结果为%d\n",result);
}

int main(){
	
	Stack* list;
	list = InitiStack();
	
	Eval(list); 
	free(list);
	return 0;
} 
