/*
 * sll.h : singly linked list interface declaration.
 */

#ifndef __SLL__
#define __SLL__

struct node {
	int data;
	struct node *next;
};

void sll_append(struct node **sl, int data);
void sll_delete(struct node **sl);
void sll_append_list(struct node **a, struct node **b);
void sll_print(struct node *sl);
#endif /* __SLL__ */
