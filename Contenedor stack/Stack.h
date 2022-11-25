#ifndef STACK_H_
#define STACK_H_

typedef void * Type;
typedef struct strStack * Stack;
typedef enum {FALSE=0, TRUE=1} Bool;
Stack stack_create();
int stack_size(Stack);
Bool stack_isEmpty(Stack);
void stack_push(Stack, Type);
Type stack_pop(Stack);
Type stack_top(Stack);
void stack_destroy(Stack);


#endif /* STACK_H_ */