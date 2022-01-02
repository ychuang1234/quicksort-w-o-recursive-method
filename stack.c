#include "stack.h"
void setstack(stack*s){
	s->top = 0;
}
void push(stack*s,int i){
	s->record[++s->top] = i;
}
void pop(stack*s,int* i){
	*i = s->record[s->top--];
}
int empty(stack*s){
	return (s->top==0);
}
