//
// Created by Riccardo on 24/02/2025.
//
#include<iostream>
#include "Importanti.h"
#include "Note.h"
#include <algorithm>

using namespace std;

Importanti::Importanti(const string& n):Collezioni(n){};

void Importanti::addNote(Note *n) {
    auto it = std::find(importantNotes.begin(), importantNotes.end(), n);
    if (it == importantNotes.end()) {
        importantNotes.push_back(n);
        n->setImportance(true);
        notifyObserver(true, name);
    }
}
/*
void Importanti::removeNote(Note *n) {
    if (!importantNotes.empty()) {
        for (auto it = importantNotes.begin(); it != importantNotes.end(); it++) {
            if (*it == n) {
                importantNotes.erase(it);
                n->setImportance(false);
                notifyObserver(false ,name);
                return;
            }
            if (it == importantNotes.end()) {
                cout << "La nota non e' presente tra quelle importanti"  << endl;
            }
        }
    }
}*/

void Importanti::removeNote(Note* n) {
    auto it = std::find(importantNotes.begin(), importantNotes.end(), n);
    if (it != importantNotes.end()) {
        importantNotes.erase(it);
        n->setImportance(false);
        notifyObserver(false, name);
    } else {
        std::cout << "La nota " << n->getTitle() << " non e' presente tra quelle importanti."  << std::endl;
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
