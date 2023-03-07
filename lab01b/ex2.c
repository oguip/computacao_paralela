#include <stdio.h>

int main() {
	float ma, n1, n2, n3, me;
	printf("Digite a nota N1: ");
	scanf("%f", &n1);
	printf("\nDigite a nota N2: ");
	scanf("%f", &n2);
	printf("\nDigite a nota N3: ");
	scanf("%f", &n3);
	me = (n1+n2+n3)/3;
	ma = (n1 + (n2*2) + (n3*3) + me)/7;
	printf("\nME: %f MA: %f", me, ma); 
	if(ma >= 9) printf("\nNota A");
	else if (ma >= 7.5) printf("\nNota B");
	else if (ma >= 6) printf("\nNota C");
	else if (ma >= 4) printf("\nNota D");
	else printf("\nNota E");
}
