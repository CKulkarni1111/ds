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

/* insert node at nth position */
void sll_insert_nth(struct node **sl, int pos, int data)
{
    int i;
	struct node *t;
	struct node *nn;

	/* check for null list and start pos */
	if (*sl == NULL && pos != 1) {
		fprintf(stderr, "ERROR : empty list position out of bounds.\n");
		return;
	}

	if (*sl == NULL && pos == 1) {
		*sl =get_node(data);
	} else if (*sl != NULL && pos == 1) {
		/* head insertion */
		nn = get_node(data);
		nn->next = *sl;
		*sl = nn;
	} else if (*sl != NULL && pos > 1) {
		for (i = 1, t = *sl; t && i < pos; i++, t = t->next) {
			if (i == (pos - 1)) {
				nn = get_node(data);
				nn->next = t->next;
				t->next = nn;
				break;
			}
		}
	}
}

/* delete the nth node */
void sll_delete_nth(struct node **sl, int pos)
{
	int i;
	struct node *d;
	struct node *t;

	if (*sl == NULL)
		return;

	if (pos == 1) {
		d = *sl;
		*sl = (*sl)->next;
		free(d);
	} else if (pos > 1) {
		for (i = 1, t = *sl; t->next && i < pos; i++, t = t->next) {
			if ((pos - 1) == i) {
				d = t->next;
				t->next = d->next;
				free(d);
				return;
			}
		}
	}
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

/* delete entire linked list recursively */
void sll_delete_rec(struct node *sl)
{
	if (sl == NULL)
		return;

	sll_delete_rec(sl->next);
	free(sl);
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
