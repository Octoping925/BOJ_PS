#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int n, m, min, chk[1010][1010][2];
char map[1010][1010];



int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; ++i) scanf("%s", map[i] + 1);

	min = n * m + 1;

    for(int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            if(map[i][j] == '0') {
                chk[i][j][0] = min(chk[i-1][j][0], chk[i][j-1][0]
            }
            else {

            }
        }
        
    }


	if (min == n * m + 1) printf("-1");
	else printf("%d", min);

	return 0;
}