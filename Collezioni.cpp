//
// Created by Riccardo on 20/02/2025.
//

#include "Collezioni.h"
#include "Note.h"
#include <iostream>
#include "ConcreteObserver.h"

using namespace std;

Collezioni::Collezioni(const string& n): name(n) {
    this->addObserver(new ConcreteObserver());
};
Collezioni::~Collezioni() {};

void Collezioni::addNote(Note *n) {
    notes.push_back(n);
    notifyObserver(true, name);
}

void Collezioni::removeNote(Note *n) {
    if (notes.empty()) {
        cout << "La collezione " << name << " e' vuota." << endl;
    }
    else {
        for (auto it = notes.begin(); it != notes.end(); it++) {
            if (*it == n) {
                notes.erase(it);
                n->setCollection(NULL);
                notifyObserver(false,name);
                return;
            }
            if (it == notes.end()) {
                cout << "la nota " << n->getTitle() << " non e' presente nella collezione " << name << "." << endl;
                return;
            }
        }
    }
}

void Collezioni::printCollezione() const {
    if (getNumNotes() == 0) {
        cout << "La collezione " << name << " e' vuota" << endl;
    }
    else {
        cout << "Collezione: " << name << endl;
        int i=1;
        for (auto n : notes) {
            cout << "Nota " << i++ << ": " << n->getTitle() << endl;
        }
    }
}

void Collezioni::addObserver(Observer *o) {
    observers.push_back(o);
}
void Collezioni::removeObserver(Observer *o) {
    observers.remove(o);
}
void Collezioni::notifyObserver(bool a,const string& n) {
    for (auto o : observers) {
        o->update(a,n);
    }
}