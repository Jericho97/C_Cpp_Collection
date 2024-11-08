#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef enum { false, true } bool;

long int Suchen(char *Text, char *P)
{
	bool gefunden;
	long int TextPos,PatternPos,temp;
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

void Entfernen(char *Text, long int StartPos, long int Anzahl)
{
	long int i,L;
	L=strlen(Text);
	for (i=StartPos; i<L; i++)
	{
		Text[i]=Text[Anzahl+i];
	}
}

void Einfuegen(char *Text, long int StartPos, long int Anzahl)
{
	long int i=0,L=strlen(Text);
	for (i=L; i>=StartPos; i--)
	{
		Text[Anzahl+i]=Text[i];
	}
}

void Ueberschreiben(char *Text, char *P, long int StartPos, long int L)
{
	long int i=0;
	for (i=0; i<L; i++)
	{
		Text[StartPos+i]=P[i];
	}
}

void Ersetzen(char *Text, char *Wort1, char *Wort2, long int Pos)
{
	Entfernen(Text,Pos,strlen(Wort1));
	Einfuegen(Text,Pos,strlen(Wort2));
	Ueberschreiben(Text,Wort2,Pos,strlen(Wort2));
}

int main(void)
{
	long int Pos;
	char Puffer[100];
	char *Text,*Wort1,*Wort2;
	printf("Text:"); fgets(Puffer,100,stdin);
	Text=(char*)malloc(strlen(Puffer)+1);
	Puffer[strlen(Puffer)-1]=0; strcpy(Text,Puffer); // newline entfernen
	printf("Wort:"); fgets(Puffer,100,stdin);
	Wort1=(char*)malloc(strlen(Puffer)+1);
	Puffer[strlen(Puffer)-1]=0; strcpy(Wort1,Puffer); // newline entfernen
	printf("Ersetzen durch:"); fgets(Puffer,100,stdin);
	Wort2=(char*)malloc(strlen(Puffer)+1);
	Puffer[strlen(Puffer)-1]=0; strcpy(Wort2,Puffer); // newline entfernen
	Pos=Suchen(Text,Wort1);
	if (Pos!=-1)
	{
		Ersetzen(Text,Wort1,Wort2,Pos);
		printf("%s\n",Text);
	}
	else
	{
		printf("Das gesuchte Wort kann nicht gefunden werden.\n");
	}
	return 0;
}
