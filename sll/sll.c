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

void sll_delete_node(struct node **sl, struct node *d)
{
	struct node *t;

	if (*sl == NULL)
		return;

	if ((*sl)->next == NULL) {
		if (*sl == d) {
			free(*sl);
			*sl = NULL;
			return;
		}
	}

	if (*sl == d) {
		*sl = (*sl)->next;
		free(d);
		return;
	}

	for (t = *sl; t && t->next != d; t = t->next)
		;

	if (t && t->next && t->next == d) {
		t->next = d->next;
		free(d);
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

void sll_alternate_split(struct node **sl, struct node **a, struct node **b)
{
	struct node *l;
	struct node *h;

	if (*sl == NULL)
		return;

	if ((*sl)->next == NULL) {
		*a = *sl;
		*b = NULL;
		*sl = NULL;
		return;
	}

	*a = *sl;
	*b = (*sl)->next;

	for (l = *a, h = *b; h && h->next;) {
		l->next = h->next;
		l = l->next;

		if (h->next) {
			h->next = h->next->next;
			h = h->next;
		}
	}

    if (l->next)
		l->next = NULL;
	*sl = NULL;
}

/* move all occurences of the data to the end */
void sll_move_end(struct node **sl, int data)
{



}

/* detect the loop in the linked list */
void sll_find_loop(struct node *sl)
{
	struct node *l;
	struct node *h;

    if (sl == NULL)
		return;

	l = sl;
	h = l->next;
	while (h && h->next) {
		if (l == h) {
			printf("Loop Detected\n");
			break;
		}

		l = l->next;
        h = h->next->next;
	}
}

/* find thye middle of the linked list */
void sll_find_middle(struct node **sl)
{
	struct node *l;
	struct node *h;

    if (*sl == NULL)
		return;

	l = *sl;
	h = l->next;
	while (h && h->next) {
		l = l->next;
        h = h->next->next;
	}

	printf("%d ", l->data);

	if (h)
		printf("%d", h->data);

	putchar('\n');
}

/* find and pring nth node from the end of the linked list */
int sll_find_nth_from_end(struct node *sl, int n)
{
	int cnt;

	if (sl == NULL)
		return  n;

	cnt = sll_find_nth_from_end(sl->next, n);

	if (cnt == 0)
		printf("%d from the end %d\n", n, sl->data);

	return cnt - 1;
}

/* reverse linked list recursively */
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

/* removes duplicates from unsorted array */
void sll_delete_duplicates(struct node **sl)
{
	struct node *i;
	struct node *j;
	struct node *d;

	if (*sl == NULL || (*sl)->next == NULL)
		return;

	for (i = *sl; i; i = i->next) {
		for (j = i; j->next;) {
			if (i->data == j->next->data) {
				d = j->next;
				j->next = j->next->next;
				free(d);
			} else
				j = j->next;
		}
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

/* print alternate node of the linked list */
void sll_print_alternate(struct node *sl)
{
	if (sl == NULL)
		return;

	while (sl && sl->next) {
		printf("%d ", sl->data);
		sl = sl->next->next;
	}

	if (sl)
		printf("%d \n", sl->data);

	putchar('\n');
}

/* print alternate_mirror of the linked list */
void sll_print_alternate_mirror(struct node *sl)
{
	if (sl == NULL)
		return;

    printf("%d ", sl->data);
	if (sl->next)
		sll_print_alternate_mirror(sl->next->next);
    printf("%d ", sl->data);
}
