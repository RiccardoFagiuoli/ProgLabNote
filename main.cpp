/*
 *Classi che rappresentano note (es. Bear / Evernote). Ogni nota è composta da titolo e testo,
 *può essere bloccata per evitarne cancellazione/modifica e fa parte di una collezione specificata con nome.
 *Può anche far parte di una collezione di note importanti oltre che di una collezione specifica.
 *Usare Observer per indicare quante note stanno in una collezione.
 *
 *Note: titolo, testo, bloccata, collezione, importante
 *Collezioni: nome, lista di note
 *Observer: numero di note in una collezione
*/

#include <iostream>
#include "Collezioni.h"

int main() {
    //esempio di main
    Note n1("Nota1", "Testo nota 1", "Collezione1", false, true);
    Note n2("Nota2", "Testo nota 2", "Collezione1", false, false);
    Note n3("Nota3", "Testo nota 3", "Collezione2", true, false);
    Note n4("Nota4", "Testo nota 4", "Collezione2", false, true);
    Note n5("Nota5", "Testo nota 5", "Collezione2", true, true);

    return 0;
}