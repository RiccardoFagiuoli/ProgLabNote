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

void Collezioni::printNotes() const {
    cout << "Collection: " << name << endl;
    for (auto n : notes) {
        cout << "Note " << n << ": " << n->getTitle() << endl;
    }
}
void Collezioni::addNote(Note *n) {
    this->notes.push_back(n);
    notifyObserver();
}

void Collezioni::removeNote(Note *n) {
    if (notes.empty()) {
        cout << "Collection " << name << " is empty." << endl;
        return;
    }
    for (auto it = notes.begin(); it != notes.end(); it++) {
        if (*it == n) {
            notes.erase(it);
            n->setCollection(NULL);
            notifyObserver();
            return;
        }
        else {
            cout << "Note " << n->getTitle() << " not found in collection " << name << "." << endl;
            return;
        }
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