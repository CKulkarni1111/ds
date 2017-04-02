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

void sll_sorted_insert(struct node **sl, int data)
{
	struct node *l;
	struct node *h;
	struct node *nn;

	nn = get_node(data);
	if (*sl == NULL) {
		*sl = nn;
	} else if (*sl != NULL && (*sl)->data >= data) {
		nn->next = *sl;
		*sl = nn;
	} else {
		for (l = *sl, h = (*sl)->next; h; l = h, h = h->next) {
			if (l->data <= data && h->data >= data) {
				nn->next = h;
				l->next = nn;
				return;
			}
		}
		if (!h && l && !l->next) {
			l->next = nn;
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

/* delete all the nodes which matches data */
void sll_delete_data(struct node **sl, int data)
{
	struct node *l;
	struct node *h;
	struct node *t;

	if (*sl == NULL)
		return;
	else {
		while (*sl && (*sl)->data == data) {
			t = *sl;
			*sl = (*sl)->next;
			free(t);
		}
		if (*sl) {
			for (l = *sl, h = l->next; h; l = h, h = h->next) {
				while (h && h->data == data) {
					t = h;
					h = h->next;
					free(t);
				}
				l->next = h;
				if (!h)
					return;
			}
		}
	}
}

void sll_split(struct node **sl, struct node **a, struct node **b)
{
	struct node *l;
	struct node *h;

	if (*sl == NULL) {
		*a = NULL;
		*b = NULL;
		return;
	}

	if ((*sl)->next == NULL) {
		*a = *sl;
		*b = NULL;
		*sl = NULL;
		return;
	}

	for (l = *sl, h = l->next; h->next && h->next->next;
									l = h, h = h->next->next)
		;
	*a = *sl; 
	*b = l->next;
	l->next = NULL;
	*sl = NULL;
}

struct node* __sll_reverse_rec(struct node *sl, struct node *p)
{
	struct node *nsl = NULL;

	if (sl->next != NULL)
	   	nsl = __sll_reverse_rec(sl->next, sl);

	if (sl->next == NULL)
		nsl = sl;

	sl->next = p;
	
	return nsl;
}

void sll_reverse_rec(struct node **sl)
{
	*sl = __sll_reverse_rec(*sl, NULL);
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

/* get total number of nodes */
int sll_count(struct node *sl)
{
	int i;

	i = 0;
	while (sl) {
		i++;
		sl = sl->next;
	}

	return i;
}

void sll_print(struct node *sl)
{
	while (sl) {
		printf("%4d -> ", sl->data);
		sl = sl->next;
	}
	puts(" NULL");
}
