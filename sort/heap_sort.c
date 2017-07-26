#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define ARRAY_MAX 25 /* Maximum array elements */


int left(int parent)
{
	return (2 * parent) + 1;
}

int right(int parent)
{
	return (2 * parent) + 2;
}
 
void array_shuffle(int arr[])
{
    int i, j, temp;

    srand(getpid());
    for (i = ARRAY_MAX - 1; i > 0; i--) {
         j = rand()%(i + 1);
         temp = arr[i];
         arr[i] = arr[j];
         arr[j] = temp;
    }
}

void  max_heapify(int a[], int i, int heapsize)
{
    int tmp, largest;
    int l = left(i);
    int r = right(i);

    if ((l <= heapsize) && (a[l] > a[i]))
         largest = l;
    else
         largest = i;

    if ((r <= heapsize) && (a[r] > a[largest]))
         largest = r ;

    if (largest != i) {
         tmp = a[i];
         a[i] = a[largest];
         a[largest] = tmp;
         max_heapify(a, largest, heapsize);
    }
}

void  build_max_heap(int a[], int heapsize)
{
    int i;
    for (i = heapsize/2; i >= 0; i--)
         max_heapify(a, i, heapsize);
}

void heap_sort(int a[], int heapsize)
{
    int i, tmp;
    build_max_heap(a, heapsize);
    for (i = heapsize; i > 0; i--) 
    {
        tmp = a[i];
        a[i] = a[0];
        a[0] = tmp;
        heapsize--;
        max_heapify(a, 0, heapsize);
    }
}

int main(void)
{
    int i;
	int heapsize;
    int *a;

	a = malloc(sizeof(int) * ARRAY_MAX);
	if (!a) {
		perror("malloc");
		return -1;
	}

    for (i = 0; i < ARRAY_MAX; i++)
        a[i] = i;
    heapsize = ARRAY_MAX - 1;
    array_shuffle(a);

    for (i = 0; i < ARRAY_MAX; i++)
        printf("%d ", a[i]);
    printf("\n");

    heap_sort(a, heapsize);

    for (i = 0; i < ARRAY_MAX; i++)
        printf("%d ", a[i]);
    
	printf("\n");

	free(a);
    return 0;
}
