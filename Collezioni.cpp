//
// Created by Riccardo on 20/02/2025.
//

#include "Collezioni.h"
#include "Note.h"
#include <iostream>

using namespace std;

Collezioni::Collezioni(const string& n): name(n) {};
Collezioni::~Collezioni() {
    for (auto n : notes) {
        notes.remove(n);
        delete n;
    }
};

void Collezioni::addNote(Note *n) {
    this->notes.push_back(n);
    notifyObserver();
}

void Collezioni::removeNote(Note *n) {
    if (this->notes.empty()) {
        cout << "La collezione " << name << " e' vuota." << endl;
    }
    else {
        for (auto it = notes.begin(); it != notes.end(); it++) {
            if (*it == n) {
                this->notes.erase(it);
                n->setCollection(NULL);
                notifyObserver();
            }
            else if (it == notes.end()) {
                cout << "la nota " << n->getTitle() << " non e' presente nella collezione " << name << "." << endl;
            }
            else if (this->notes.empty()) {
                break;
            }
        }
    }
}

void Collezioni::printCollezione() const {
    if (this->getNumNotes() == 0) {
        cout << "La collezione " << name << " e' vuota" << endl;
    }
    else {
        cout << "Collezione: " << name << endl;
        for (auto n : notes) {
            cout << "Nota " << n << ": " << n->getTitle() << endl;
        }
    }
}

void Collezioni::addImportant(Note *n) {
    importantNotes.push_back(n);
    notifyObserver();
}

void Collezioni::removeImportant(Note *n) {
    for (auto it = importantNotes.begin(); it != importantNotes.end(); it++) {
        if (*it == n) {
            importantNotes.erase(it);
            notifyObserver();
            return;
        }
    }
}

void Collezioni::printImportantNotes() const {
    for (auto n : importantNotes) {
        cout << "Nota importante: " << n->getTitle() << endl;
    }
}

void Collezioni::addObserver(Observer *o) {
    observers.push_back(o);
}
void Collezioni::removeObserver(Observer *o) {
    observers.remove(o);
}

void Collezioni::notifyObserver() {
    if (this->getNotes().front() != NULL) {
        this->getNotes().front()->update();
    }
    else {
        cout << "Collection " << name << " is empty." << endl;
    }
}