#include<stdio.h>

typedef enum {false, true} bool;;

int Textsuche(char *Text, char *P)
{
    bool gefunden;
    int TextPos,PatternPos,temp;
    TextPos=0; gefunden=false;
    while ((gefunden==false)&&(Text[TextPos]!=0))
    {
        while ((Text[TextPos]!=P[0])&&(Text[TextPos]!=0))
        {
            TextPos++;
        }
        PatternPos=0; temp=TextPos; // Z�hler zur�cksetzen
        while ((Text[TextPos]==P[PatternPos])&&(P[PatternPos]!=0))
        {
            TextPos++; PatternPos++; // Immer ein Zeichen weiter
        }
        if (P[PatternPos]==0) // Die Suche war erfolgreich
        {
            gefunden=true;
        }
    }
    if (gefunden==true) { return temp; }
    else { return -1; }
}

int main(void)
{
    int Pos;
    char P[100];
    char *Text="Ich bin ein einfacher Text. Suche bitte in mir nach einem Wort.";
    printf("Text:%s\n",Text);
    printf("Zu suchendes Wort:"); scanf("%s",&P);
    Pos=Textsuche(Text,P);
    if (Pos>=0) { printf("Das Wort '%s' wurde an Position %d gefunden.\n",P,Pos); }
    else { printf("Das zu suchende Wort wurde nicht gefunden.\n"); }
    return 0;
}
