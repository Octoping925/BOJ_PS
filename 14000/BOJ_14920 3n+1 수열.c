// https://www.acmicpc.net/problem/14920
main(n,cnt){cnt=1;scanf("%d",&n);while(n>1){n=n&1?3*n+1:n/2;++cnt;}printf("%d",cnt);}