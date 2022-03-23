// https://www.acmicpc.net/problem/24678
main(n,a,s,i){scanf("%d",&n);while(n--){for(i=0,s=0;i<3;++i){scanf("%d",&a);s+=a%2;}puts(s<2?"R":"B");}}