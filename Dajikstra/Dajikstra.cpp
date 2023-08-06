#include <stdio.h>

#define duongvocung 2147483647

void XoaPhanTu(int* A, int n, int pt);
void thuattoan_Dijkstra(int A[10][10], int n, int dd, int dc);
int main()
{
	int A[10][10];
	int n; // ma tran vuong cap n
	FILE* fp;  // con tro tap tin
	fopen_s(&fp, "D:\\DATATRR\\Dijkstra.txt", "r");
	if (fp == NULL)
	{
		printf("ERROR!");
		return -1;
	}
	fscanf(fp, "%d", &n);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			fscanf(fp, "%d", &A[i][j]);
		}
	}
	fclose(fp);
	printf("Ma tran trong so: \n");
	for (int x = 0; x < n; x++)
	{
		for (int y = 0; y < n; y++)
		{
			printf("%7d", A[x][y]);
		}
		printf("\n");
	}
	thuattoan_Dijkstra(A, n, 0, 3);
	return 0;
}

void thuattoan_Dijkstra(int A[10][10], int n, int dd, int dc)
{
	int d[10];
	int p[10];
	int T[10];
	int u;
	for (int v = 0; v < n; v++)
	{
		d[v] = duongvocung;
	}
	d[dd] = 0;
	p[dd] = -1;
	for (int i = 0; i < n; i++)
	{
		T[i] = i;
	}
	int length;
	while ((length = sizeof(T) / sizeof(int)) != 0)
	{
		int min = d[T[0]];
		u = T[0];
		for (int i1 = 0; i1 < length; i1++)
		{
			if (d[T[i1]] < min)
			{
				u = T[i1];
			}
		}
		XoaPhanTu(T, length, u);
		for (int i2 = 0; i2 < length; i2++)
		{
			int v = T[i2];
			if ((A[u][v] != 0) && (A[u][v] != -1))
			{
				if (d[v] > d[u] + A[u][v])
				{
					d[v] = d[u] + A[u][v];
					p[v] = u;
				}
			}
		}
	}
	int B[10];
	B[0] = dc;
	int dem = 1;
	int x = p[dc];
	while (x != -1)
	{
		B[dem++] = x;
		x = p[x];
	}
	int length3 = sizeof(B) / sizeof(int);
	for (int i3 = length3 - 1; i3 >= 0; i3--)
	{
		printf("%d -> ", B[i3]);
		printf("END\n");
	}
}

void XoaPhanTu(int* A, int n, int pt)
{
	int vt;
	for (int i = 0; i < n; i++)
	{
		if (A[i] == pt)
		{
			vt = i;
			break;
		}
	}
	for (int j = vt; j < n; j++)
	{
		A[j] = A[j + 1];
	}
	n--;
}
