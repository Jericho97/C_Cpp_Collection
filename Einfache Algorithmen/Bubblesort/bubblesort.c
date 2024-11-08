#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

typedef enum{false,true} bool;

void tausche(int *A, int Pos1, int Pos2) // Array�bergabe als Pointer
{
    int temp=A[Pos1];
    A[Pos1]=A[Pos2];
    A[Pos2]=temp;
}

void BubbleSort(int *A, long int n, bool Testausgabe)
{
    bool getauscht;
    int i;
    do
    {
        getauscht=false; // Initialisierung
        for (i=0; i<n-1; i++)
        {
            if (A[i]>A[i+1])
            {
                tausche(A,i,i+1);
                getauscht=true; // Wird wahr, sobald getauscht wurde
            }
        }
        if (Testausgabe==true) // Die Testausgabe gibt das gesamte Zahlenarray aus
        {
            for (i=0; i<n; i++) { printf("%d ",A[i]); }
            printf("\n");
        }
    }
    while (getauscht==true); // Noch Vertauschungen aufgetreten? In diesem Falls neuen Durchlauf starten
}

int main(void)
{
    int i;
    int Zahlen[20];
    char Auswahl[20];
    printf("Ausgabe der Sortierschritte (j/n)?");
    scanf("%s",&Auswahl);
    srand(clock());
    printf("Erzeuge 20 Zufallsahlen zwischen 1 und 100...");
    for (i=0; i<20; i++) { Zahlen[i]=rand()%100+1; }
    printf("\nAusgabe des Zahlen-Arrays:\n");
    for (i=0; i<20; i++) { printf("%d ",Zahlen[i]); }
    printf("\nSortiere Zahlen mit Bubble Sort...\n");
    if (strcmp(Auswahl,"j")==0) { BubbleSort(Zahlen,20,true); }
    if (strcmp(Auswahl,"n")==0) { BubbleSort(Zahlen,20,false); }
    for (i=0; i<20; i++) { printf("%d ",Zahlen[i]); }
    printf("\n");
    return 0;
}
