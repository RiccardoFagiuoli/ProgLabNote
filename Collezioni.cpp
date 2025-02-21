//
// Created by Riccardo on 20/02/2025.
//

#include "Collezioni.h"
#include "Note.h"
#include <iostream>


using namespace std;

Collezioni::Collezioni(const string& n): name(n) {
    addObserver(new NumNote);
};
Collezioni::~Collezioni() {
    for (auto o : observers) {
        delete o;
    }
};

void Collezioni::printNotes() const {
    cout << "Collection: " << name << endl;
    for (auto n : notes) {
        cout << "Note " << n << ": " << n->getTitle() << endl;
    }
}
