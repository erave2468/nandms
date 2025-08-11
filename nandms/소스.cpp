#pragma warning(disable:4996)
#include <stdio.h>

void print_num(int* visit, int m)
{
    int i;

    i = 1;
    while (i <= m)
    {
        printf("%d", visit[i]);
        if (i != m)
            printf(" ");
        i++;
    }
    printf("\n");
}

int check(int* visit, int i) 
{
    int j;

    j = 0;
    while (j < i)
    {
        //���� ����� ���ؼ� ������ ���� ������ false��
        if (visit[j] == visit[i])
        {
            return (0);
        }
        j++;
    }
    return (1);
}

void DFS(int* visit, int n, int m, int i) // i: ���� ���õ� ���� �ε���
{
	int j; // j: ���� ���õ� ��

	if (i > m) // m���� ��� ����������
    {
        print_num(visit, m);
        return;
    }
    j = 1;
    while (j <= n)
    {
        //backtracking
        visit[i] = j;
        if (check(visit, i))
            DFS(visit, n, m, i + 1);
        j++;
    }
}

int main()
{
	int visit[10] = { 0 }; // visit[i]: i��°�� ���õ� ��
    int n, m;
	printf("Enter n and m: ");
	scanf("%d %d", &n, &m); // n: 1~n������ ��, m: m���� �̴� ����
    DFS(visit, n, m, 1);

    return (0);
}