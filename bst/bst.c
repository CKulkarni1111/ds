#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#include "bst.h"

/* allocate and initialize the node */
struct bst_node *bst_get_node(void *data)
{
	struct bst_node *n;

	n = malloc(sizeof (struct bst_node *));
	
	if (!n) {
		fprintf(stderr, "ERROR : malloc : %s\n", strerror(errno));
		return NULL;
	}
	n->data = data;
	n->bst_link[0] = NULL;
	n->bst_link[1] = NULL;

	return n;
}

/* allocate and initialize the bst_table */
struct bst_table * bst_init(void)
{
	struct bst_table *bst;
	
	bst = malloc(sizeof(struct bst_table));
	
	if (!bst) {
		fprintf(stderr, "ERROR : malloc : %s\n", strerror(errno));
		return NULL;
	}
	bst->bst_count = 0;
	bst->bst_cmp_param = NULL;
	bst->bst_cmp = NULL;
	bst->root = NULL;

	return bst;
}

void bst_node_free(struct bst_node **node)
{
	if (*node)
		free((*node)->data);
	free(*node);
	*node = NULL;			
}

/* free bst_table */
void bst_free(struct bst_table **bst)
{
	if (! (*bst))
		return;

	if ((*bst)->root) {
		fprintf(stderr, "ERROR : bst is not empty !!!\n");
		return;
	}
	free(*bst);
	*bst = NULL;
}
