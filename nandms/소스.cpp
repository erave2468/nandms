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
        //전의 값들과 비교해서 동일한 값이 있으면 false로
        if (visit[j] == visit[i])
        {
            return (0);
        }
        j++;
    }
    return (1);
}

void DFS(int* visit, int n, int m, int i) // i: 현재 선택된 수의 인덱스
{
	int j; // j: 현재 선택된 수

	if (i > m) // m개를 모두 선택했으면
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
	int visit[10] = { 0 }; // visit[i]: i번째에 선택된 수
    int n, m;
	printf("Enter n and m: ");
	scanf("%d %d", &n, &m); // n: 1~n까지의 수, m: m개를 뽑는 조합
    DFS(visit, n, m, 1);

    return (0);
}