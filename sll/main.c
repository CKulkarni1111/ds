#include <stdio.h>

#include "sll.h"

struct node* make_sll(unsigned int n);
void test_sll_delete_data(void);
void test_sll_split(void);
void test_sll_alternate_split(void);
void test_sll_reverse_rec(void);

struct node* make_sll(unsigned int n)
{
    int i;

	struct node *sl = NULL;

    for (i = 0; i < n; i++)
		sll_append(&sl, i);

	return sl;
}

void test_sll_delete_data(void)
{
	struct node *sl = NULL;

	sll_append(&sl, 0);
	sll_print(sl);
	sll_delete_data(&sl, 1);
	sll_print(sl);

	sll_delete_data(&sl, 0);
	sll_print(sl);

	sll_append(&sl, 0);
	sll_append(&sl, 0);
	sll_print(sl);
	sll_delete_data(&sl, 0);
	sll_print(sl);

	sll_append(&sl, 0);
	sll_append(&sl, 0);
	sll_append(&sl, 0);
	sll_append(&sl, 0);
	sll_append(&sl, 0);
	sll_append(&sl, 1);
	sll_append(&sl, 0);
	sll_append(&sl, 0);
	sll_print(sl);
	sll_delete_data(&sl, 0);
	sll_print(sl);
	sll_delete_rec(sl);
}


void test_sll_split(void)
{
	struct node *sl = NULL;
	struct node *a = NULL;
	struct node *b = NULL;

	printf("Split empty list:- \n");
	sll_split(&sl, &a, &b);
	sll_print(sl);

	printf("add one node and split:-\n");
    sl = make_sll(1);
	sll_print(sl);
	sll_split(&sl, &a, &b);
	sll_print(sl);
	sll_print(a);
	sll_print(b);
	sll_delete_rec(sl);
	sll_delete_rec(a);
	sll_delete_rec(b);
	printf("add two nodes and split:-\n");
	sl = make_sll(2);
	sll_print(sl);
	sll_split(&sl, &a, &b);
	sll_print(sl);
	sll_print(a);
	sll_print(b);
	sll_delete_rec(sl);
	sll_delete_rec(a);
	sll_delete_rec(b);
	printf("add three nodes and split:-\n");
	sl = make_sll(3);
	sll_print(sl);
	sll_split(&sl, &a, &b);
	sll_print(sl);
	sll_print(a);
	sll_print(b);
	sll_delete_rec(sl);
	sll_delete_rec(a);
	sll_delete_rec(b);
	printf("add four nodes and split:-\n");
	sl = make_sll(4);
	sll_print(sl);
	sll_split(&sl, &a, &b);
	sll_print(sl);
	sll_print(a);
	sll_print(b);
	sll_delete_rec(sl);
	sll_delete_rec(a);
	sll_delete_rec(b);

	printf("add five nodes and split:-\n");
	sl = make_sll(5);
	sll_print(sl);
	sll_split(&sl, &a, &b);
	sll_print(sl);
	sll_print(a);
	sll_print(b);
	sll_delete_rec(sl);
	sll_delete_rec(a);
	sll_delete_rec(b);
	
}

void test_sll_alternate_split(void)
{
	struct node *sl = NULL;
	struct node *a = NULL;
	struct node *b = NULL;

	printf("Split empty list:- \n");
	sll_alternate_split(&sl, &a, &b);
	sll_print(sl);

	printf("add one node and split:-\n");
    sl = make_sll(1);
	sll_print(sl);
	sll_alternate_split(&sl, &a, &b);
	sll_print(sl);
	sll_print(a);
	sll_print(b);
	sll_delete_rec(sl);
	sll_delete_rec(a);
	sll_delete_rec(b);
	printf("add two nodes and split:-\n");
	sl = make_sll(2);
	sll_print(sl);
	sll_alternate_split(&sl, &a, &b);
	sll_print(sl);
	sll_print(a);
	sll_print(b);
	sll_delete_rec(sl);
	sll_delete_rec(a);
	sll_delete_rec(b);

	printf("add three nodes and split:-\n");
	sl = make_sll(3);
	sll_print(sl);
	sll_alternate_split(&sl, &a, &b);
	sll_print(sl);
	sll_print(a);
	sll_print(b);
	sll_delete_rec(sl);
	sll_delete_rec(a);
	sll_delete_rec(b);

	printf("add four nodes and split:-\n");
	sl = make_sll(4);
	sll_print(sl);
	sll_alternate_split(&sl, &a, &b);
	sll_print(sl);
	sll_print(a);
	sll_print(b);
	sll_delete_rec(sl);
	sll_delete_rec(a);
	sll_delete_rec(b);

	printf("add five nodes and split:-\n");
	sl = make_sll(5);
	sll_print(sl);
	sll_alternate_split(&sl, &a, &b);
	sll_print(sl);
	sll_print(a);
	sll_print(b);
	sll_delete_rec(sl);
	sll_delete_rec(a);
	sll_delete_rec(b);

	printf("add six nodes and split:-\n");
	sl = make_sll(6);
	sll_print(sl);
	sll_alternate_split(&sl, &a, &b);
	sll_print(sl);
	sll_print(a);
	sll_print(b);
	sll_delete_rec(sl);
	sll_delete_rec(a);
	sll_delete_rec(b);
}

void test_sll_reverse_rec(void)
{
	struct node *sl = NULL;

	printf("add four nodes and split:-\n");
	sl = make_sll(5);
	sll_print(sl);
	sll_reverse_rec(&sl);
	sll_print(sl);
	sll_delete_rec(sl);
}

int main(int argc, char *argv[])
{


	/*test_sll_delete_data();*/
	/*test_sll_split();*/
	test_sll_alternate_split();
	/*test_sll_reverse_rec();*/
#if 0
	int i;
	struct node *sl = NULL;

	for (i = 0; i < 10; i++) {
		sll_sorted_insert(&sl,  i * 10);
		sll_print(sl);
	}

	printf("---\n");

	for (i = 0; i < 10; i++) {
		sll_sorted_insert(&sl,  i * 5);
		sll_print(sl);
	}

	for (i = 0; i < 10; i++)
		sll_append(&sl, i * 10);

	sll_print(sl);
	sll_delete_nth(&sl, 1);
	sll_print(sl);
	sll_delete_nth(&sl, 9);
	sll_print(sl);
	sll_delete_nth(&sl, 5);
	sll_print(sl);
	sll_insert_nth(&sl, 1, 1111);
	sll_print(sl);

	for (i = 0; i < 10; i++)
		sll_append(&sl, i * 10);

	sll_print(sl);
    sll_insert_nth(&sl, 13, 55);
	sll_print(sl);
	sll_delete_rec(sl);
#endif
	return 0;
}
