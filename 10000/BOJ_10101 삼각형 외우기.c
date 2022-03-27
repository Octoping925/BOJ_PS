// https://www.acmicpc.net/problem/10101
main(x,y,z) {
    scanf("%d\n%d\n%d", &x, &y, &z);
    puts(x+y+z-180?"Error":x==y&&y==z?"Equilateral":x==y||x==z||y==z?"Isosceles":"Scalene");
}