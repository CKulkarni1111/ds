#include <stdio.h>

#include "sll.h"

int main(int argc, char *argv[])
{
	int i;
	struct node *sla = NULL;
	struct node *slb = NULL;

	for (i = 0; i < 10; i++)
		sll_append(&sla, i * 10);

	for (i = 0; i < 10; i++)
		sll_append(&slb, i * 100);

	sll_print(sla);
	sll_print(slb);
	sll_append_list(&sla, &slb);

	sll_print(sla);
	sll_print(slb);
	sll_delete(&sla);
	return 0;
}
