//
// Created by Riccardo on 20/02/2025.
//

#include "Note.h"
#include <iostream>

#include "Collezioni.h"

Note::Note(const string& tl, const string& txt, Collezioni* c, bool lck, bool i): title(tl), text(txt), collection(c), locked(lck), important(i) {
    c->addObserver(this);
    c->addNote(this);
}

Note::~Note() {
    this->collection->removeObserver(this);
    this->collection->removeNote(this);
}


void Note::printNote() const {
    string coll;
    if (collection == NULL) {
        coll= "NULL";
    }
    else {
        coll= collection->getName();
    }
    cout << "Title: " << title << endl;
    cout << "Text: " << text << endl;
    cout << "Collection: " << coll << endl;
    cout << "Locked: " << locked << endl;
    cout << "Important: " << important << endl;
}

void Note::update() {
    int collSize= this->collection->getNumNotes();
    cout << "Collection " << this->collection->getName() << " has " << collSize << " notes." << endl;
};