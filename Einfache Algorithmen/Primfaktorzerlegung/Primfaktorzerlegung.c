#include <stdio.h>
#include <stdbool.h>

bool IstPrime(long int Zahl)
{
    long int i, l;
    bool prim = true;
    if ((Zahl%2)==0) { return false; } //schauen ob es sich um eine gerade oder ungerade Zahl handelt
    for (i=3; i<Zahl; i+=2)
    {
        if ((Zahl%i)==0) { prim = false; break; } //brute force Methode um heraus zu finden ob Primzahl oder nicht
    }
    return prim;
}

void Primfaktoren(long int Zahl)
{
    bool prim = true;
    long int Teiler = 2;
    long int Alt = Zahl;
    while (Teiler<Alt)
    {
        while ((Zahl%Teiler)==0) //Immer wenn es bei der Division keinen Rest gibt wird die Zahl ausgegeben
        {
            Zahl=Zahl/Teiler;
            printf("%ld",Teiler);
            if (Zahl>1) { printf("*"); }
            prim = false;
        }
        Teiler++;
        while (IstPrime(Teiler)==false) { Teiler++; }
    }
    if (prim==true) { printf("%ld ist eine Primzahl.\n",Alt);}
    else { printf("\n"); }
}

int main(void) {
    long int Zahl;
    printf("Primteiler berechnet die Primfaktorzerlegung einer Zahl\n");
    printf("Zahl:"); scanf("%ld",&Zahl);
    printf("Primfaktoren von %ld ...\n",Zahl);
    Primfaktoren(Zahl);
    return 0;
}
