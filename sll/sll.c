/*
 * sll.c : singely linked list implementation.
 */
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include "sll.h"

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

void sll_delete(struct node **sl)
{
	struct node *t;

	while (*sl) {
		t = *sl;
		*sl = (*sl)->next;
		free(t);
	}
}

void sll_append_list(struct node **a, struct node **b)
{
	struct node *t;

	if ((*a == NULL && *b == NULL) || (*a != NULL && *b == NULL))
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
