#include <stdio.h>

int main(){
	int a;
  	scanf("%d", &a);
  	if(a % 3 == 2 && a % 7 == 5 && a % 11 == 7) printf("YES");
  	else printf("NO");
}
