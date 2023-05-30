#include<stdio.h>
#define max 10000

void nhap(int* arr, int* n) {
	do
	{
		printf("import n > 0: ");
		scanf("%d", n);
	} while (n < 1);
	for (int i = 0; i < *n; i++) {
		printf("\narr[%d] = ", i);
		scanf("%d", &arr[i]);
	}
}

void swap(int* a, int* b)
{
	int c = *a;
	*a = *b;
	*b = c;
}

void demgiatri(int* arr, int n)
{
	int mark;
	int count;
	for (int i = 0; i < n; i++)
	{
		mark = arr[i];
		count = 1;
		for (int j = i + 1; j < n; j++)
		{
			if (mark == arr[j])
			{
				count++;
				swap(&arr[i + 1], &arr[j]);
				i++;
			}
		}
		(count == 1)? printf("%d appears 1 time\n", arr[i]) : printf("%d appears %d times\n", arr[i], count);
	}
}
int main()
{
	int arr[max], n = 0;
	nhap(arr, &n);
	demgiatri(arr, n);
    return 0;
}
