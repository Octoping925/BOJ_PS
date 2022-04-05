// https://www.acmicpc.net/problem/1756
// #include <stdio.h>

int oven[300010];
int summarize[300010][2];
size_t d, n;

int main()
{
    scanf("%d %d", &d, &n);

    scanf("%d", &oven[d]);
    for(int i = d-1; i >= 1; i--) {
        scanf("%d", &oven[i]);

        if(oven[i+1] < oven[i]) oven[i] = oven[i+1];
    }

    int idx = 1;
    summarize[1][0] = oven[1];
    summarize[1][1] = 1;
    for(int i = 2; i <= d; ++i) {
        if(oven[i] == oven[i-1]) {
            summarize[idx][0]++;
        }
        else {
            idx++;
            summarize[idx][0] = oven[i];
            summarize[idx][1] = 1;
        }
    }

    int pidx = 1;
    int pizzadepth = 0;
    for(int p = 1; p <= n; ++p) {
        int pizza;
        scanf("%d", &pizza);
        for(int i = pidx; i <= idx; ++i) {
            if(pizza <= summarize[i][0]) {
                summarize[i][1]--;
                if(!summarize[i][1]) {
                    pidx++;
                }
                break;
            }
            else {
                pizzadepth += summarize[i][1];
            }
        }
    }

}


// 미완성