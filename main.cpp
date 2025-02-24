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
#include "Note.h"
#include "Collezioni.h"

int main() {
    //esempio di main
    Collezioni c0("Collezione0");
    Note n0("Nota0", "Testo0", &c0);
    c0.removeNote(&n0);

    cout << endl;

    Collezioni c("Collezione1");
    Note n1("Nota1", "Testo1", &c);
    Note n2("Nota2", "Testo2", &c);
    Note n3("Nota3", "Testo3", &c);
    Note n4("Nota4", "Testo4", &c);

    cout << endl;

    Collezioni c2("Collezione2");
    Note n5("Nota5", "Testo5", &c2);
    Note n6("Nota6", "Testo6", &c2);
    Note n7("Nota7", "Testo7", &c2);
    Note n8("Nota8", "Testo8", &c2);

    cout << endl;
    //rimozione di una nota
    n1.printNote();
    c.removeNote(&n1);
    c.removeNote(&n5);

    cout << endl;
    //print note 1 e 5
    n1.printNote();
    n2.printNote();
    n3.printNote();
    n4.printNote();

    cout << endl;
    cout << endl;
    c0.printCollezione();
    cout << endl;
    c.printCollezione();
    cout << endl;
    c2.printCollezione();

    cout << endl;
    //aggiungo note a importanti
    c.addImportant(&n1);
    c.addImportant(&n2);
    c2.addImportant(&n5);

    cout << endl;
    //stampo note importanti
    c.printImportantNotes();

    cout << endl;
    //rimuovo note importanti
    c.removeImportant(&n1);

    return 0;
}