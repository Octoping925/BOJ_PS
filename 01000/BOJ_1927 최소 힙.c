// https://www.acmicpc.net/problem/1927
#include <stdio.h>

int heap[200010];
int n, size = 0;

void swap(int *x, int *y) {
    int tmp = *x;
    *x = *y;
    *y = tmp;
}

void upify(int x)
{
    while(heap[x / 2] > heap[x])
    {
        if(x == 1) return;
        swap(&heap[x], &heap[x / 2]);
        x /= 2;
    }
}

void downify(int x)
{
    while(1)
    {
        int left = x * 2, right = x * 2 + 1;
        if(left > size) return;
        if(right > size)
        {
            if(heap[x] < heap[left]) return;
            swap(&heap[x], &heap[left]);
            x = left;
        }
        else if(heap[x] > heap[left] && heap[left] <= heap[right]) {
            swap(&heap[x], &heap[left]);
            x = left;
        }
        else if(heap[x] > heap[right] && heap[right] <= heap[left]) {
            swap(&heap[x], &heap[right]);
            x = right;
        }
        else return;
    }
}

void addHeap(int x)
{
    heap[++size] = x;
    upify(size);
}

int pop()
{
    int minimum = heap[1];
    swap(&heap[1], &heap[size]);
    size--;
    downify(1);
    return minimum;
}

int print()
{
    if(size == 0) return 0;
    return pop();
}

int main()
{
    scanf("%d", &n);
    for(int i = 0; i < n; ++i) {
        int k;
        scanf("%d", &k);
        if(k != 0) {
            addHeap(k);
        }
        else {
            printf("%d\n", print());
        }
    }
}