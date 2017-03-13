/*
 * sll.c : singely linked list implementation.
 */
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include "sll.h"

/* allocate and initialize node */
static struct node * get_node(int data)
{
	struct node *n;

	n = (struct node *) malloc(sizeof (struct node));
	if (n == NULL) {
		fprintf(stderr, "error : malloc : %s\n", strerror(errno));
		exit(EXIT_FAILURE);
	}
	n->data = data;
	n->next = NULL;
	return n;
}

/* create and append the node at the end of the list */
void sll_append(struct node **sl, int data)
{
	struct node *n;
	struct node *t;

	n = get_node(data);

	if (*sl == NULL) {
		*sl = n;
	} else {
		for (t = *sl; t->next != NULL; t = t->next)
			;
		t->next = n;
	}
}

/* insert node before the position */
void sll_insert_before(struct node **sl, int pos, int data)
{

}

/* insert node after the position */
void sll_insert_after(struct node **sl, int pos, int data)
{

}

/* delete node before the position */
void sll_delete_before(struct node **sl, int pos)
{

}

/* delete node after the position */
void sll_delete_after(struct node **sl, int pos)
{

}

/* delete entire linked list iteratively */
void sll_delete(struct node **sl)
{
	struct node *t;

	while (*sl) {
		t = *sl;
		*sl = (*sl)->next;
		free(t);
	}
}

/* append list b at the end of list a */
void sll_append_list(struct node **a, struct node **b)
{
	struct node *t;

	if (*a == NULL && *b == NULL)
		return;

	if (*a != NULL && *b == NULL)
		return;

	if (*a == NULL) {
		*a = *b;
		*b = NULL;
	}

	for (t = *a; t->next != NULL; t = t->next)
		;
	t->next = *b;
	*b = NULL;
}

void sll_print(struct node *sl)
{
	while (sl) {
		printf("%4d -> ", sl->data);
		sl = sl->next;
	}
	puts(" NULL");
}
