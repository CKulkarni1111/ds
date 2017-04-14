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
void sll_insert_nth(struct node **sl, int pos, int data);
void sll_sorted_insert(struct node **sl, int data);
void sll_delete_rec(struct node *sl);
void sll_delete_nth(struct node **sl, int pos);
void sll_delete_data(struct node **sl, int data);
void sll_delete_duplicates(struct node **sl);
void sll_delete_node(struct node **sl, struct node *d);
void sll_split(struct node **sl, struct node **a, struct node **b);
void sll_alternate_split(struct node **sl, struct node **a, struct node **b);
void sll_move_end(struct node **sl, int data);
void sll_rotate(struct node **sl, int pos);
void sll_find_loop(struct node *sl);
void sll_find_middle(struct node **sl);
int sll_find_nth_from_end(struct node *sl, int n);
struct node* __sll_reverse_rec(struct node *sl, struct node *p);
void sll_reverse_rec(struct node **sl);
int  sll_count(struct node *sl);
void sll_print(struct node *sl);
void sll_print_alternate(struct node *sl);
void sll_print_alternate_mirror(struct node *sl);
#endif /* __SLL__ */
