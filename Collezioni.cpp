//
// Created by Riccardo on 20/02/2025.
//

#include "Collezioni.h"
#include "Note.h"
#include <iostream>
#include "ConcreteObserver.h"
#include <algorithm>

using namespace std;

Collezioni::Collezioni(const string& n): name(n) {
    this->addObserver(new ConcreteObserver());
};
Collezioni::~Collezioni() {};

void Collezioni::addNote(Note *n) {
    notes.push_back(n);
    notifyObserver(true, name);
}

void Collezioni::removeNote(Note* n) {
    auto it = std::find(notes.begin(), notes.end(), n);
    if (it != notes.end()) {
        n->setCollection(nullptr);
        notes.erase(it);
        notifyObserver(false, name);
    } else {
        std::cout << "La nota " << n->getTitle() << " non e' presente nella collezione " << name << "." << std::endl;
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