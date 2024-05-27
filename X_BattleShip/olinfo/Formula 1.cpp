#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#define MAXN 100

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int N, i;
    int H[MAXN], V[MAXN];

    assert(1 == scanf("%d", &N));
    for (i = 0; i < N; i++)
        assert(1 == scanf("%d", &H[i]));
    for (i = 0; i < N; i++)
        assert(1 == scanf("%d", &V[i]));

    int hamilton = 0, verstappen = 0;
    int fastest_hamilton = H[0], fastest_verstappen = V[0];
    for (i = 0; i < N; i++)
    {
        if (H[i] < fastest_hamilton)
        {
            fastest_hamilton = H[i];
        }
        if (V[i] < fastest_verstappen)
        {
            fastest_verstappen = V[i];
        }
        hamilton += H[i];
        verstappen += V[i];
    }
    if (hamilton < verstappen)
    {
        printf("Hamilton\n");
    }
    else
    {
        printf("Verstappen\n");
    }
    if (fastest_hamilton < fastest_verstappen)
    {
        printf("Hamilton\n");
    }
    else
    {
        printf("Verstappen\n");
    }

    return 0;
}