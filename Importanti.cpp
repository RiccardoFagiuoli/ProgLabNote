//
// Created by Riccardo on 24/02/2025.
//
#include<iostream>
#include "Importanti.h"
#include "Note.h"

using namespace std;

Importanti::Importanti(const string& n):Collezioni(n){};

Importanti* impNote = new Importanti("Importanti");

Importanti* Importanti::getImportant() {
    return impNote;
}


void Importanti::addImportant(Note *n) {
    importantNotes.push_back(n);
}

void Importanti::removeImportant(Note *n) {
    if (!importantNotes.empty()) {
        for (auto it = importantNotes.begin(); it != importantNotes.end(); it++) {
            if (*it == n) {
                importantNotes.erase(it);
                return;
            }
        }
    }
    else {
        cout << "Non ci sono note importanti impossibile rimuovere"  << endl;
    }
}

void Importanti::printImportantNotes() const {
    if (importantNotes.empty()) {
        cout << "Non ci sono note importanti" << "." << endl;
    }
    else {
        int i=1;
        for (auto n : importantNotes) {
            cout << "Nota importante " << i++ <<": " << n->getTitle() << endl;
        }
    }
}