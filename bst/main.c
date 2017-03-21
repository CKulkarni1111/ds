#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#include "bst.h"

int main(int argc, char *argv[])
{
	struct bst_table *bst = NULL;
	
	bst = bst_init();
	bst_free(&bst);
	return 0;
}
