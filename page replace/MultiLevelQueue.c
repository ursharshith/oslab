#include <stdio.h>
#include <limits.h>
#define MAX 100

void swap(int *x, int *y);
int find(int n, int p[], int at[], int v[], int *t);
int minI(int n, int at[], int *t);
void enque(int k, int f, int r, int Q[]);
int deque(int f, int r, int Q[]);
int srtf_find(int n, int at[], int rbt[], int v[], int *t);

void fcfs(int n, int p[], int at[], int bt[], int *c, int *t, int G[]);
void sjf(int n, int p[], int at[], int bt[], int *c, int *t, int G[]);
void npprty(int n, int p[], int at[], int bt[], int *c, int *t, int G[]);
void roundRobin(int n, int p[], int at[], int bt[], int *c, int *t, int G[]);
void srtf(int n, int p[], int at[], int bt[], int *c, int *t, int G[]);
void premptivePriority(int n, int p[], int at[], int bt[], int *c, int *t, int G[]);

struct queue
{
	int size;
	int prty;
	int p[MAX];
	int at[MAX];
	int bt[MAX];
	int Qprty[MAX];
	int sa;
	int v;
};

void main()
{
	int G[MAX], t = 0, c = 0;
	int nq;
	printf("Enter number of Queues: ");
	scanf("%d", &nq);
	struct queue Q[nq];
	for (int i = 0; i < nq; i++)
	{
		printf("Enter priority of Q%d:", i + 1);
		scanf("%d", &Q[i].prty);
		printf("Enter size of Q%d:", i + 1);
		scanf("%d", &Q[i].size);
		printf("Enter P,AT,BT of Q%d: ", i + 1);
		for (int j = 0; j < Q[i].size; j++)
		{
			scanf("%d %d %d", &Q[i].p[j], &Q[i].at[j], &Q[i].bt[j]);
		}
		printf("Enter:\n1 - FCFS\n2 - SJF\n3 - Non-Preemptive Priority\n4 - RoundRobin\n5 - SRTF\n6 - Preemptive Priority\n");
		scanf("%d", &Q[i].sa);
		Q[i].v = -1;
		printf("executed\n");
	}
	printf("Execution initialised");
	int min, tempI;
	for (int i = 0; i < nq; i++)
	{
		min = INT_MAX;
		printf("Execution started");
		for (int j = 0; j < nq; j++)
		{
			if (Q[j].prty < min && Q[j].v == -1)
			{
				min = Q[j].prty;
				tempI = j;
			}
		}
		printf("Minimum found");
		Q[tempI].v = 1;
		switch (Q[tempI].sa)
		{
		case 1:
			fcfs(Q[tempI].size, Q[tempI].p, Q[tempI].at, Q[tempI].bt, &c, &t, G);
			break;
		case 2:
			// sjf(Q[tempI].size,Q[tempI].p,Q[tempI].at,Q[tempI].bt,*c,*t,G);
			break;
		case 3:
			npprty(Q[tempI].size, Q[tempI].p, Q[tempI].at, Q[tempI].bt, &c, &t, G);
			break;
		case 4:
			roundRobin(Q[tempI].size, Q[tempI].p, Q[tempI].at, Q[tempI].bt, &c, &t, G);
			break;
		case 5:
			srtf(Q[tempI].size, Q[tempI].p, Q[tempI].at, Q[tempI].bt, &c, &t, G);
			break;
		case 6:
			premptivePriority(Q[tempI].size, Q[tempI].p, Q[tempI].at, Q[tempI].bt, &c, &t, G);
			break;
		}
	}
	printf("Process executed:\n");
	for (int i = 0; i < c; i++)
	{
		if (G[i] == -1)
		{
			printf("Idle ");
		}
		else
		{
			printf(" P%d", G[i]);
		}
	}
}

void fcfs(int n, int p[], int at[], int bt[], int *c, int *t, int G[])
{
	printf("FCFS started");
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n - 1; j++)
		{
			if (at[j] > at[j + 1])
			{
				swap(&p[j], &p[j + 1]);
				swap(&at[j], &at[j + 1]);
				swap(&bt[j], &bt[j + 1]);
			}
		}
	}
	int v[n];
	for (int i = 0; i < n; i++)
	{
		v[i] = -1;
	}
	for (int i = 0; i < n;)
	{
		int j = find(n, p, at, v, *t);
		if (j == -1)
		{
			G[*c++] = -1;
			*t = at[minI(n, at, *t)];
		}
		else
		{
			G[*c++] = p[j];
			*t += bt[j];
			i++;
		}
	}
	printf("FCFS ended");
}

void swap(int *x, int *y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}

int find(int n, int p[], int at[], int v[], int *t)
{
	for (int i = 0; i < n; i++)
	{
		if (at[i] <= *t && v[i] == -1)
		{
			v[i] = 1;
			return i;
		}
	}
	return -1;
}

int minI(int n, int at[], int *t)
{
	int min = INT_MAX, temp;
	for (int i = 0; i < n; i++)
	{
		if (at[i] > *t && min > at[i])
		{
			min = at[i];
			temp = i;
		}
	}
	return temp;
}

// SJF
void sjf(int n, int p[], int at[], int bt[], int *c, int *t, int G[])
{
	printf("SJF started");
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n - 1; j++)
		{
			if (bt[j] > bt[j + 1])
			{
				swap(&p[j], &p[j + 1]);
				swap(&at[j], &at[j + 1]);
				swap(&bt[j], &bt[j + 1]);
			}
			else if (bt[j] == bt[j + 1])
			{
				if (at[j] > at[j + 1])
				{
					swap(&p[j], &p[j + 1]);
					swap(&at[j], &at[j + 1]);
					swap(&bt[j], &bt[j + 1]);
				}
			}
		}
	}
	int v[n];
	for (int i = 0; i < n; i++)
	{
		v[i] = -1;
	}
	for (int i = 0; i < n;)
	{
		int j = find(n, at, bt, v, *t);
		if (j == -1)
		{
			// GC[gcc++] = -1;
			G[*c++] = -1;
			*t = at[minI(n, at, *t)];
		}
		else
		{
			G[*c++] = p[j];
			*t += bt[j];
			i++;
		}
	}
	printf("SJF ended");
}

// NonPreemptive Priority
void npprty(int n, int p[], int at[], int bt[], int *c, int *t, int G[])
{
	printf("Enter priorities of processes: ");
	int pr[n];
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &pr[i]);
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n - 1; j++)
		{
			if (pr[j] > pr[j + 1])
			{
				swap(&p[j], &p[j + 1]);
				swap(&at[j], &at[j + 1]);
				swap(&bt[j], &bt[j + 1]);
				swap(&pr[j], &pr[j + 1]);
			}
			else if (pr[j] == pr[j + 1])
			{
				if (at[j] > at[j + 1])
				{
					swap(&p[j], &p[j + 1]);
					swap(&at[j], &at[j + 1]);
					swap(&bt[j], &bt[j + 1]);
					swap(&pr[j], &pr[j + 1]);
				}
			}
		}
	}
	int v[n];
	for (int i = 0; i < n; i++)
	{
		v[i] = -1;
	}
	for (int i = 0; i < n;)
	{
		int j = find(n, at, pr, v, *t);
		if (j == -1)
		{
			G[*c++] = -1;
			t = at[minI(n, at, *t)];
		}
		else
		{
			G[*c++] = p[j];
			*t += bt[j];
			i++;
		}
	}
}

// RoundRobin
void enque(int k, int f, int r, int Q[])
{
	if (f == -1 && r == -1)
	{
		f++;
		r++;
	}
	else if (r == 100)
	{
		printf("OVERFLOW");
	}
	Q[r++] = k;
}

int deque(int f, int r, int Q[])
{
	if (f > r || f == -1)
	{
		printf("UNDERFLOW");
	}
	else
	{
		return Q[f++];
	}
}

void roundRobin(int n, int p[], int at[], int bt[], int *c, int *t, int G[])
{
	int Q[100];
	int f = -1, r = -1;
	int q;
	printf("Enter Time Quantum: ");
	scanf("%d", &q);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n - 1; j++)
		{
			if (at[j] > at[j + 1])
			{
				swap(&p[j + 1], &p[j]);
				swap(&at[j + 1], &at[j]);
				swap(&bt[j + 1], &bt[j]);
			}
			else if (at[j] == at[j + 1])
			{
				if (p[j] > p[j + 1])
				{
					swap(&p[j + 1], &p[j]);
					swap(&at[j + 1], &at[j]);
					swap(&bt[j + 1], &bt[j]);
				}
			}
		}
	}
	int v[n], rbt[n], k;
	for (int i = 0; i < n; i++)
	{
		v[i] = -1;
		rbt[i] = bt[i];
	}
	for (int i = 0; i < n;)
	{
		for (int j = 0; j < n; j++)
		{
			if (at[j] <= t && v[j] == -1)
			{
				enque(j, f, r, Q);
				v[j] = 1;
			}
		}
		int fl = 0;
		if (f > r || f == -1)
		{
			fl = 1;
		}
		if (fl == 1)
		{
			G[*c++] = -1;
			*t++;
		}
		else
		{
			k = deque(f, r, Q);
			G[*c++] = p[k];
			if (rbt[k] <= q)
			{
				*t += rbt[k];
				rbt[k] = 0;
				i++;
			}
			else
			{
				rbt[k] -= q;
				*t += q;
				for (int j = 0; j < n; j++)
				{
					if (at[j] <= t && v[j] == -1)
					{
						enque(j, f, r, Q);
						v[j] = 1;
					}
				}
				enque(k, f, r, Q);
			}
		}
	}
}

// SRTF
void srtf(int n, int p[], int at[], int bt[], int *c, int *t, int G[])
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n - 1; j++)
		{
			if (bt[j] > bt[j + 1])
			{
				swap(&p[j], &p[j + 1]);
				swap(&at[j], &at[j + 1]);
				swap(&bt[j], &bt[j + 1]);
			}
			else if (bt[j] == bt[j + 1])
			{
				if (at[j] > at[j + 1])
				{
					swap(&p[j], &p[j + 1]);
					swap(&at[j], &at[j + 1]);
					swap(&bt[j], &bt[j + 1]);
				}
			}
		}
	}
	int v[n], rbt[n], ct[n], tat[n], wt[n];
	for (int i = 0; i < n; i++)
	{
		v[i] = -1;
		rbt[i] = bt[i];
	}
	for (int i = 0; i < n;)
	{
		int j = srtf_find(n, at, rbt, v, *t);
		if (j == -1)
		{
			G[*c++] = -1;
			t = at[minI(n, at, *t)];
		}
		else
		{
			int x = minI(n, at, *t);
			if (x == INT_MAX)
			{
				x = *t + rbt[j];
			}
			if (rbt[j] < (x - *t))
			{
				G[*c++] = p[j];
				*t += rbt[j];
				rbt[j] = 0;
				v[j] = 1;
				i++;
			}
			else
			{
				G[*c++] = p[j];
				rbt[j] = rbt[j] - (x - *t);
				*t = x;
				if (rbt[j] == 0)
				{
					v[j] = 1;
					ct[j] = *t;
					i++;
				}
			}
		}
	}
}

int srtf_find(int n, int at[], int rbt[], int v[], int *t)
{
	int min = INT_MAX, temp = -1;
	for (int i = 0; i < n; i++)
	{
		if (at[i] <= *t && min >= rbt[i] && v[i] == -1)
		{
			if (rbt[i] == min)
			{
				if (at[i] < at[temp])
				{
					min = rbt[i];
					temp = i;
				}
			}
			else
			{
				min = rbt[i];
				temp = i;
			}
		}
	}
	return temp;
}

// Pre-emptive Priority
void premptivePriority(int n, int p[], int at[], int bt[], int *c, int *t, int G[])
{
	int prty[n];
	printf("Enter priorities of processes: ");
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &prty[i]);
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n - 1; j++)
		{
			if (bt[j] > bt[j + 1])
			{
				swap(&p[j], &p[j + 1]);
				swap(&at[j], &at[j + 1]);
				swap(&bt[j], &bt[j + 1]);
				swap(&prty[j], &prty[j + 1]);
			}
			else if (bt[j] == bt[j + 1])
			{
				if (at[j] > at[j + 1])
				{
					swap(&p[j], &p[j + 1]);
					swap(&at[j], &at[j + 1]);
					swap(&bt[j], &bt[j + 1]);
					swap(&prty[j], &prty[j + 1]);
				}
			}
		}
	}
	int v[n], rbt[n];
	for (int i = 0; i < n; i++)
	{
		v[i] = -1;
		rbt[i] = bt[i];
	}
	for (int i = 0; i < n;)
	{
		int j = srtf_find(n, at, prty, v, t);
		if (j == -1)
		{
			G[*c++] = -1;
			t = minI(n, at, *t);
		}
		else
		{
			int x = minI(n, at, *t);
			if (x == INT_MAX)
			{
				x = *t + rbt[j];
			}
			if (rbt[j] < (x - *t))
			{
				G[*c++] = p[j];
				*t += rbt[j];
				rbt[j] = 0;
				v[j] = 1;
				i++;
			}
			else
			{
				G[*c++] = p[j];
				rbt[j] = rbt[j] - (x - *t);
				*t = x;
				if (rbt[j] == 0)
				{
					v[j] = 1;
					i++;
				}
			}
		}
	}
}