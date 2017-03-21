/*
 * bst.h : binary search tree interface declaration.
 */

#ifndef __BST__
#define __BST__

#define NSUBTREES	2
#define BST_MAX_HEIGHT	32

typedef int (bst_cmp_t)(const void *a, const void *b, void *bst_cmp_param);

struct bst_node {
	void *data;
	struct bst_node *bst_link[NSUBTREES];
};

struct bst_table {
	int bst_count;
	struct bst_root *root;
	void *bst_cmp_param;
	struct bst_cmp_t *bst_cmp;	
};

struct bst_table * bst_init(void);
struct bst_node * bst_get_node(void *data);
void bst_node_free(struct bst_node **node);
void bst_free(struct bst_table **bst);

#endif /* __BST__ */
