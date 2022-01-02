#include <stdlib.h>
#include <stdio.h>

#ifndef recursive
	#define FUNC quicksort	
	#include "stack.h"
#else
	#define FUNC quicksort_recursive
	
#endif

int partition(int*data, int i ,int j){
	int upper,lower;
	int pivot;
	upper = i;
	lower = j;
	pivot = data[i];
	while(upper!=lower){
		while(upper<lower && pivot>=data[lower]){
			lower--;
		}
		if (upper != lower){
			data[upper] = data[lower];
		}
		
		while(upper<lower && pivot<=data[upper]){
			upper++;
		}
		if (upper != lower){
			data[lower] = data[upper];
		}
	}
	data[upper] = pivot;
	return upper;
}
#ifndef recursive
void quicksort(int*data,int i,int j){
	printf("recursive!\n");
	int p, top, bottom;
	stack s;
	setstack(&s);
	push(&s,j);
	push(&s,i);
	while(!empty(&s)){
		pop(&s,&top);
		pop(&s,&bottom);
		while(top<bottom){
			p = partition(data,top,bottom);
			if ((p-top)>(bottom-p)){
				push(&s,p-1);
				push(&s,top);
				top = p+1;
			}else{
				push(&s,bottom);
				push(&s,p+1);
				bottom = p-1;
			}
		}
	}
}
#endif
void quicksort_recursive(int*data,int i,int j){
	printf("non recursive!\n");
	if (i<j){
		int p = partition(data,i,j);
		quicksort_recursive(data,i,p-1);
		quicksort_recursive(data,p+1,j);
	}
}
int main(){
	int i=0,j=0;
	int data[] = {6,4,9,4,7,2};
	FUNC(&data[0],0,5);
	for (i=0;i<6;i++) printf("%i ",data[i]);
	printf("\n");
	return 0;
}