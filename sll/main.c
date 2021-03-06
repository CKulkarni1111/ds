#include <stdio.h>

#include "sll.h"

struct node* make_sll(unsigned int n);
void test_sll_delete_data(void);
void test_sll_split(void);
void test_sll_alternate_split(void);
void test_sll_reverse_rec(void);
void test_sll_find_middle(void);
void test_sll_find_loop(void);
void test_sll_rotate(void);
void test_sll_find_nth_from_end(void);
void test_sll_print_alternate(void);
void test_sll_print_alternate_mirror(void);
void test_sll_delete_duplicates(void);
void test_sll_delete_node(void);

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

void test_sll_find_middle(void)
{
	struct node *sl = NULL;

	printf("find_middle empty list:- \n");
	sll_find_middle(&sl);
	sll_print(sl);

	printf("add one node and find_middle:-\n");
    sl = make_sll(1);
	sll_print(sl);
	sll_find_middle(&sl);
	sll_print(sl);
	sll_delete_rec(sl);
	printf("add two nodes and find_middle:-\n");
	sl = make_sll(2);
	sll_print(sl);
	sll_find_middle(&sl);
	sll_print(sl);
	sll_delete_rec(sl);
	printf("add three nodes and find_middle:-\n");
	sl = make_sll(3);
	sll_print(sl);
	sll_find_middle(&sl);
	sll_print(sl);
	sll_delete_rec(sl);
	printf("add four nodes and find_middle:-\n");
	sl = make_sll(4);
	sll_print(sl);
	sll_find_middle(&sl);
	sll_print(sl);
	sll_delete_rec(sl);

	printf("add five nodes and find_middle:-\n");
	sl = make_sll(5);
	sll_print(sl);
	sll_find_middle(&sl);
	sll_print(sl);
	sll_delete_rec(sl);
}

void test_sll_find_loop(void)
{
	struct node *sl = NULL;

	printf("find_middle empty list:- \n");
	sll_find_middle(&sl);
	sll_print(sl);

	printf("add one node and find_loop:-\n");
    sl = make_sll(1);
	sll_print(sl);
	sl->next = sl;
	sll_find_loop(sl);

	printf("add two nodes and find_loop:-\n");
	sl = make_sll(2);
	sll_print(sl);
	sl->next->next = sl;
	sll_find_loop(sl);
	sl = make_sll(2);
	sl->next->next = sl->next;
	sll_find_loop(sl);

	printf("add three nodes and find_loop:-\n");
	sl = make_sll(3);
	sll_print(sl);
	sl->next->next->next = sl->next->next;
	sll_find_loop(sl);
	sl->next->next->next = sl->next;
	sll_find_loop(sl);
	sl->next->next->next = sl;
	sll_find_loop(sl);

	printf("add four nodes and find_loop:-\n");
	sl = make_sll(4);
	sll_print(sl);
	sl->next->next->next->next = sl->next->next->next;
	sll_find_loop(sl);
	sl->next->next->next->next = sl->next->next;
	sll_find_loop(sl);
	sl->next->next->next->next = sl->next;
	sll_find_loop(sl);
	sl->next->next->next->next = sl;
	sll_find_loop(sl);

	printf("add five nodes and find_middle:-\n");
	sl = make_sll(5);
	sll_print(sl);
	sl->next->next->next->next->next = sl->next->next->next->next;
	sll_find_loop(sl);
	sl->next->next->next->next->next = sl->next->next->next;
	sll_find_loop(sl);
	sl->next->next->next->next->next = sl->next->next;
	sll_find_loop(sl);
	sl->next->next->next->next->next = sl->next;
	sll_find_loop(sl);
	sl->next->next->next->next->next = sl;
	sll_find_loop(sl);
}

void test_sll_rotate(void)
{
	struct node *sl = NULL;

	sll_rotate(&sl, 0);
	sll_print(sl);

	sll_append(&sl, 1);
	sll_print(sl);
	sll_rotate(&sl, 2);
	sll_print(sl);

	sll_append(&sl, 2);
	sll_print(sl);
	sll_rotate(&sl, 1);
	sll_print(sl);
	sll_rotate(&sl, 1);
	sll_print(sl);

	sll_append(&sl, 3);
	sll_print(sl);
	sll_rotate(&sl, 4);
	sll_print(sl);

	sll_append(&sl, 4);
	sll_print(sl);
	sll_rotate(&sl, 1);
	sll_print(sl);

	sll_rotate(&sl, 2);
	sll_print(sl);

	sll_rotate(&sl, 3);
	sll_print(sl);

	sll_rotate(&sl, 4);
	sll_print(sl);
}

void test_sll_find_nth_from_end(void)
{
	struct node *sl = NULL;

	printf("test find nth from end:-\n");
	sl = make_sll(5);
	sll_print(sl);
	sll_find_nth_from_end(sl, 0);
	sll_find_nth_from_end(sl, 1);
	sll_find_nth_from_end(sl, 2);
	sll_find_nth_from_end(sl, 3);
	sll_find_nth_from_end(sl, 4);
	sll_find_nth_from_end(sl, 5);
	sll_print(sl);
	sll_delete_rec(sl);
}

void test_sll_print_alternate(void)
{
	struct node *sl = NULL;

	printf("print_alternate empty list:- \n");
	sll_print_alternate(sl);
	sll_print(sl);

	printf("add one node and print_alternate:-\n");
    sl = make_sll(1);
	sll_print(sl);
	sll_print_alternate(sl);
	sll_delete_rec(sl);
	printf("add two nodes and print_alternate:-\n");
	sl = make_sll(2);
	sll_print(sl);
	sll_print_alternate(sl);
	sll_delete_rec(sl);
	printf("add three nodes and print_alternate:-\n");
	sl = make_sll(3);
	sll_print(sl);
	sll_print_alternate(sl);
	sll_delete_rec(sl);
	printf("add four nodes and print_alternate:-\n");
	sl = make_sll(4);
	sll_print(sl);
	sll_print_alternate(sl);
	sll_delete_rec(sl);

	printf("add five nodes and print_alternate:-\n");
	sl = make_sll(5);
	sll_print(sl);
	sll_print_alternate(sl);
	sll_delete_rec(sl);

	printf("add five nodes and print_alternate:-\n");
	sl = make_sll(10);
	sll_print(sl);
	sll_print_alternate(sl);
	sll_delete_rec(sl);
}

void test_sll_print_alternate_mirror(void)
{
	struct node *sl = NULL;

	printf("print_alternate_mirror empty list:- \n");
	sll_print_alternate_mirror(sl);
	sll_print(sl);

	printf("add one node and print_alternate_mirror:-\n");
    sl = make_sll(1);
	sll_print(sl);
	sll_print_alternate_mirror(sl);
	sll_delete_rec(sl);
	printf("add two nodes and print_alternate_mirror:-\n");
	sl = make_sll(2);
	sll_print(sl);
	sll_print_alternate_mirror(sl);
	sll_delete_rec(sl);
	printf("add three nodes and print_alternate_mirror:-\n");
	sl = make_sll(3);
	sll_print(sl);
	sll_print_alternate_mirror(sl);
	sll_delete_rec(sl);
	printf("add four nodes and print_alternate_mirror:-\n");
	sl = make_sll(4);
	sll_print(sl);
	sll_print_alternate_mirror(sl);
	sll_delete_rec(sl);

	printf("add five nodes and print_alternate_mirror:-\n");
	sl = make_sll(5);
	sll_print(sl);
	sll_print_alternate_mirror(sl);
	sll_delete_rec(sl);
	
	printf("add five nodes and print_alternate_mirror:-\n");
	sl = make_sll(10);
	sll_print(sl);
	sll_print_alternate_mirror(sl);
	sll_delete_rec(sl);
}

void test_sll_delete_duplicates(void)
{
	struct node *sl = NULL;

	sll_append(&sl, 1);
	sll_print(sl);
	sll_delete_duplicates(&sl);
	sll_print(sl);

	sll_append(&sl, 1);
	sll_print(sl);
	sll_delete_duplicates(&sl);
	sll_print(sl);
	sll_delete_rec(sl);
	sl = NULL;

	sll_append(&sl, 1);
	sll_append(&sl, 1);
	sll_append(&sl, 1);
	sll_append(&sl, 1);
	sll_append(&sl, 1);
	sll_append(&sl, 1);
	sll_append(&sl, 1);
	sll_append(&sl, 1);
	sll_append(&sl, 1);
	sll_print(sl);
	sll_delete_duplicates(&sl);
	sll_print(sl);
	sll_delete_rec(sl);
	sl = NULL;

	sll_append(&sl, 1);
	sll_append(&sl, 2);
	sll_append(&sl, 1);
	sll_append(&sl, 2);
	sll_append(&sl, 1);
	sll_append(&sl, 2);
	sll_append(&sl, 1);
	sll_append(&sl, 2);
	sll_append(&sl, 1);
	sll_print(sl);
	sll_delete_duplicates(&sl);
	sll_print(sl);
	sll_delete_rec(sl);
	sl = NULL;

	sll_append(&sl, 1);
	sll_append(&sl, 2);
	sll_append(&sl, 2);
	sll_append(&sl, 3);
	sll_append(&sl, 3);
	sll_append(&sl, 3);
	sll_append(&sl, 3);
	sll_append(&sl, 4);
	sll_append(&sl, 5);
	sll_print(sl);
	sll_delete_duplicates(&sl);
	sll_print(sl);
	sll_delete_rec(sl);
	sl = NULL;



}

void test_sll_delete_node(void)
{
	int i;
	struct node *sl = NULL;
	struct node *t = NULL;

	for (i = 0; i < 10; i++)
		sll_append(&sl, i);

	sll_print(sl);
	sll_delete_node(&sl, sl->next->next);
	sll_print(sl);
	sll_delete_node(&sl, sl);
	sll_print(sl);

	for (i = 0, t = sl; t && i < 5; i++, t = t->next)
		;

	sll_delete_node(&sl, t);
	sll_print(sl);

	for (i = 0, t = sl; t && i < 4; i++, t = t->next)
		;

	sll_delete_node(&sl, t);
	sll_print(sl);
    for (i = 0; i < 6; i++) {
		sll_delete_node(&sl, sl);
		sll_print(sl);
    }

	sll_delete_rec(sl);
	sl = NULL;
}

int main(int argc, char *argv[])
{


	/*test_sll_delete_data();*/
	/*test_sll_split();*/
	/*test_sll_alternate_split();*/
	/*test_sll_find_middle();*/
	/*test_sll_find_loop();*/
	/*test_sll_print_alternate_mirror();*/
	/*test_sll_delete_duplicates();*/
	/*test_sll_find_nth_from_end();*/
	 /*test_sll_reverse_rec();*/
	/* test_sll_delete_node();*/
	test_sll_rotate();
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
