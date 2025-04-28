#include<stdio.h>

int main(){
int a;

printf("escolha qual tabuada?");
scanf("%d", &a);	

    for (int i = 0; i <= 10; ++i){
    int multipl= a * i;
	    printf("%d x %d = %d\n", a, i, multipl);
    }
}