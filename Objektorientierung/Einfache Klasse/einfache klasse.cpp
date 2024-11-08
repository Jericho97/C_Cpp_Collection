#include <iostream>

using namespace std;

class Klasse {

    private:
        int meineZahl;

    public:
        //Klasse(int Zahl){meineZahl = Zahl;}
        Klasse(int Zahl);
        void eingabeZahl();
        void ausgabeZahl();
};

Klasse::Klasse(int Zahl)
{
    meineZahl = Zahl;
}

void Klasse::eingabeZahl()
{
    cout << "Zahl eingeben: ";
    cin >> meineZahl;
    cout << endl;
}

void Klasse::ausgabeZahl()
{
    cout << "Ausgabe meineZahl: " << meineZahl << endl;
}

int main() {
    int Zahl = 1000;
    Klasse klasse(Zahl);
    //klasse.eingabeZahl();
    klasse.ausgabeZahl();
    return 0;
}
