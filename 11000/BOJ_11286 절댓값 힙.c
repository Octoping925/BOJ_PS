// https://www.acmicpc.net/problem/11286
#include <stdio.h>

int heap[200010];
int n, size = 0;

void swap(int *x, int *y) {
    int tmp = *x;
    *x = *y;
    *y = tmp;
}

int abs(int x) {
    return x > 0 ? x : -x;
}

int compare(int x, int y) {
    if(abs(x) != abs(y)) return abs(x) < abs(y) ? -1 : 1;
    if(abs(x) == abs(y)) return x - y;
}

void upify(int x)
{
    while(compare(heap[x / 2], heap[x]) > 0)
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
            if(compare(heap[x], heap[left]) < 0) return;
            swap(&heap[x], &heap[left]);
            x = left;
        }
        else if(compare(heap[x], heap[left]) > 0 && compare(heap[left], heap[right]) <= 0) {
            swap(&heap[x], &heap[left]);
            x = left;
        }
        else if(compare(heap[x], heap[right]) > 0 && compare(heap[right], heap[left]) <= 0) {
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