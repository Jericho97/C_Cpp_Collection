# Primfaktorzerlegung

Primzahlen kennen Sie wahrscheinlich noch aus Ihrer Schulzeit, aber diese kommen auch
im Informatikstudium sehr oft vor. Primzahlen sind sämtliche natürlichen Zahlen, die nur
durch 1 und sich selbst teilbar sind. In diesem Abschnitt geht es darum, eine Zahl in ihre
Primfaktoren zu zerlegen. Eine Primfaktorzerlegung durchzuführen, heißt, eine natürliche
Zahl als Produkt einer oder mehrerer Primzahlen darzustellen. Dabei können Faktoren
auch doppelt auftreten. Beispielsweise kann die Zahl 12 als 2* 2* 3 geschrieben werden, 2
und 3 sind beides Primzahlen. Verschlüsselungs Algorithmen bestehen oft daraus große Zahlen in ihre
Primzahlen zu zerlegen.

## Wann ist eine Zahl ein Primzahl

Kann über den Modulo Operator heraus gefunden werden, welcher den Rest einer Division von zwei
Zahlen liefert. Wenn der Modulo Operator bei einer Division den Rest 0 liefert dann handelt es sich bei der
Zahl um keine Primzahl. Folgender Code kann dafür verwendet werden um eine Primzahl zu suchen
```c++
 long int Zahl=17;
 bool prim=true; // Erst einmal annehmen, Zahl sei prim
 long int i; // Schleifenzähler
 for (i=2; i<Zahl; i++) // Teiler zwischen 2 und Zahl-1 prüfen
 {
    if ((Zahl%i)==0) { prim=false; break; }
 }
```

