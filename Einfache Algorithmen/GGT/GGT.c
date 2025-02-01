#include <stdio.h>

long int GGT(long int a, long int b)
{
    long int Rest = 1, temp;
    if (a>b)
    {
        temp = a; a = b; b = temp; // Ringtausch bei a > b
        printf("a = %d",a);
        printf("b = %d",b);
    }
    while (Rest>0)
    {
        Rest = a%b;
        printf("Rest = %ld\n", Rest);
        if (Rest>0) { temp = Rest; }
        a = b; b = Rest;
    }
    return temp; // Der GTT ist in temp
}

int main(void) {
    long int a,b;
    printf("Berechnung des GGT zweier Zahlen\n");
    printf("Zahl a:"); scanf("%ld",&a);
    printf("Zahl b:"); scanf("%ld",&b);
    printf("Der GGT ist %ld\n", GGT(a,b));
    return 0;
}
