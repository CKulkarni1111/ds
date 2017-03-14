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
void sll_delete_rec(struct node *sl);
void sll_append_list(struct node **a, struct node **b);
void sll_insert_before(struct node **sl, int pos, int data);
void sll_insert_after(struct node **sl, int pos, int data);
void sll_delete_before(struct node **sl, int pos);
void sll_delete_after(struct node **sl, int pos);
void sll_print(struct node *sl);
#endif /* __SLL__ */
