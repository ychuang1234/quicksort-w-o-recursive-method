#ifndef _STACK_H
#define _STACK_H

struct stack{
	int top;
	int record[50];
};
typedef struct stack stack;
void setstack(stack* s);
void pop(stack* s,int* i);
void push(stack* s,int i);
int empty(stack* s);


#endif