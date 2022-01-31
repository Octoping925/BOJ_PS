// https://www.acmicpc.net/problem/10809
#include <stdio.h>
#include <string.h>
char txt[105];
int alph[30];

int main() {
	for(int i = 0; i < 26; ++i) alph[i] = -1;
	
	scanf("%s", txt);
    for(int i = 0; i < strlen(txt); ++i) {
		if(alph[txt[i] - 'a'] == -1) {
			alph[txt[i] - 'a'] = i;
		}
	}

	for(int i = 0; i < 26; ++i) {
		printf("%d ", alph[i]);
	}
    return 0;
}
  