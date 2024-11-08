#include <stdio.h>
#include<string.h>

void Ringtausch(int *a, int *b)
{
    int *temp=a;
    a=b; b=temp;
}

void Ringtausch_st(char **a, char **b)
{
    char *temp=*a;
    *a=*b;
    *b=temp;
}

typedef struct
{
    char Anrede[5];
    char Vorname[50];
    char Nachname[50];
    int Alter;
} Person_t;

void Ringtausch_struct(Person_t *a, Person_t *b)
{
    Person_t temp=*a;
    *a=*b;
    *b=temp;
}

int main(void)
{
    //Ringtausch ganze Zahlen
    int a=47, b=11;
    Ringtausch(&a,&b);
    printf("a=%d,b=%d\n");

    // Ringtausch Strings
    char *a_str="Hallo";
    char *b_str="Welt";
    printf("%s %s\n",a_str,b_str);
    Ringtausch(&a_str,&b_str);
    printf("%s %s\n",a_str,b_str);

    // Ringtausch Strukturen
    Person_t a_struct,b_struct;
    strcpy(a_struct.Anrede,"Herr");
    strcpy(a_struct.Vorname,"Herbert");
    strcpy(a_struct.Nachname,"Meyer");
    a_struct.Alter=42;
    strcpy(b_struct.Anrede,"Frau");
    strcpy(b_struct.Vorname,"Erika");
    strcpy(b_struct.Nachname,"Mustermann");
    b_struct.Alter=46;
    Ringtausch_struct(&a_struct,&b_struct);
    printf("Person 1:\n");
    printf("Name:%s %s %s\n",a_struct.Anrede,a_struct.Vorname,a_struct.Nachname);
    printf("Alter:%d\n",a_struct.Alter);
    printf("Person 2:\n");
    printf("Name:%s %s %s\n",b_struct.Anrede,b_struct.Vorname,b_struct.Nachname);
    printf("Alter:%d\n",b_struct.Alter);
    return 0;
}
