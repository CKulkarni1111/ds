/*
 * dll.h : doubly linked list interface declaration.
 */

#ifndef __DLL__
#define __DLL__

struct node {
	int data;
	struct node *next;
	struct node *prev;
};

void dll_append(struct node **sl, int data);
void dll_delete(struct node **sl);
void dll_delete_rec(struct node *sl);
void dll_append_list(struct node **a, struct node **b);
void dll_insert_nth(struct node **sl, int pos, int data);
void dll_delete_nth(struct node **sl, int pos);
int  dll_count(struct node *sl);
void dll_print(struct node *sl);
#endif /* __DLL__ */
