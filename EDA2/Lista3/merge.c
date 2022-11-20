#include <stdio.h>
#include <stdlib.h>

void merge(int *v, int l, int h, int r)
{
	int i = l, j = h + 1, pos = 0, *k;
	k = (int *)calloc((r - l + 1), sizeof(int));

	while (i <= h && j <= r)
	{
		if (v[i] < v[j])
			k[pos++] = v[i++];
		else
			k[pos++] = v[j++];
	}

	while (i <= h)
		k[pos++] = v[i++];

	while (j <= r)
		k[pos++] = v[j++];

	// Merge
	pos = 0;
	for (int i = l; i <= r; ++i)
	{
		v[i] = k[pos++]; // k[i-esq]
	}
	free(k);
};

void mergesort(int *v, int l, int r)
{
	if (l >= r)
		return;

	int h = (l + r) / 2;

	mergesort(v, l, h);
	mergesort(v, h + 1, r);
	merge(v, l, h, r);
}

int main()
{
	// variaveis
	int v[100000], n;

	// entrada
	scanf("%d\n", &n);

	for (int i = 0; i < n; i++)
		scanf("%d", &v[i]);

	// ordenacao
	mergesort(v, 0, n - 1);

	int i = 0;
	for (; i < n - 1; i++)
		printf("%d ", v[i]);
	printf("%d\n",v[i]);
	return 0;
}
