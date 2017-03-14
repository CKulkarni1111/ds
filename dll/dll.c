/*
 * dll.c : doubly linked list implementation.
 */
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include "dll.h"

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
	n->prev = NULL;
	return n;
}

/* create and append the node at the end of the list */
void dll_append(struct node **sl, int data)
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
		n->prev = t;
	}
}

/* insert node before the position */
void dll_insert_before(struct node **sl, int pos, int data)
{

}

/* insert node after the position */
void dll_insert_after(struct node **sl, int pos, int data)
{

}

/* delete node before the position */
void dll_delete_before(struct node **sl, int pos)
{

}

/* delete node after the position */
void dll_delete_after(struct node **sl, int pos)
{

}

/* append list a at the end of list b */
void dll_append_list(struct node **a, struct node **b)
{
	struct node *t;

	if (*a == NULL && *b == NULL)
		return;

	if (*a != NULL && *b == NULL)
		return;

	if (*a != NULL && *b != NULL) {
		for (t = *a; t->next != NULL; t = t->next)
			;
		t->next = *b;
		(*b)->prev = t;
	}
	*b = NULL;
}

/* delete entire linked list iteratively */
void dll_delete(struct node **sl)
{
	struct node *t;

	while (*sl) {
		t = *sl;
		*sl = (*sl)->next;
		free(t);
	}
}

/* delete entire linked list recursively */
void dll_delete_rec(struct node *sl)
{
	if (sl == NULL)
		return;

	dll_delete_rec(sl->next);
	free(sl);
}

void dll_print(struct node *sl)
{
	while (sl) {
		printf("%4d %c-%c ", sl->data,
				sl->prev != NULL ? '<' : 'X',
				sl->next != NULL ? '>' : 'X');
		sl = sl->next;
	}
	puts(" NULL");
}
