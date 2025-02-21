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
#include "NumNote.h"



int main() {
    //esempio di main
    Collezioni casella("Casella");

    auto nota1 = make_shared<Note>("Nota 1", "Testo della nota 1");
    auto nota2 = make_shared<Note>("Nota 2", "Testo della nota 2");

    casella.addNote(nota1);
    casella.addNote(nota2);

    casella.setImportant(nota1);
    casella.removeNote(nota1);

    // Stampa le note importanti
    std::cout << "Note importanti:" << std::endl;
    for (const auto& nota : casella.getImportantNote()){
        std::cout << "- " << nota->getTitle() << std::endl;
    }

    // Rimuovi nota1 dalle note importanti
    casella.notImportant(nota1);

    // Stampa nuovamente le note importanti
    std::cout << "Note importanti dopo la rimozione:" << std::endl;
    for (const auto& nota : casella.getImportantNote()){
        std::cout << "- " << nota->getTitle() << std::endl;
    }

    Collezioni collezione2("Collezione 2");
    auto nota3 = std::make_shared<Note>("Nota 3", "Testo della nota 3");
    collezione2.addNote(nota3);

    nota1->setLocked(true);
    nota1->setText("Testo modificato");
    nota1->printNote();


    return 0;
}