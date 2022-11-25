#include "List.h"
#include <stdio.h>

int main(){
	List lt1=listCreate(sizeof(int));
	int n=10;
	listAdd(lt1, &n);
	n=20;
	listAdd(lt1, &n);
	n=30;
	listAdd(lt1, &n);
	n=40;
	listAdd(lt1, &n);
	printf("Size: %d \n", listSize(lt1));

	int *dato;
	dato=listGet(lt1,0);
	printf("%d \n", *dato);

	return 0;
}
