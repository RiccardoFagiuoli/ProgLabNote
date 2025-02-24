//
// Created by Riccardo on 20/02/2025.
//

#include "Note.h"
#include <iostream>
#include "Collezioni.h"
#include "Note.h"

Note::Note(const string& tl, const string& txt, Collezioni* c, bool lck, bool i): title(tl), text(txt), collection(c), locked(lck), important(i) {
    c->addObserver(this);
    c->addNote(this);
}

Note::~Note() {
    if (this->collection != NULL) {
        this->collection->removeObserver(this);
        this->collection->removeNote(this);
    }
}
void Note::setCollection(Collezioni* c) {
    if (!locked) {
        if (collection != NULL) {
            collection->removeObserver(this);
        }
        if (c != NULL) {
            c->addObserver(this);
        }
        collection = c;
    }
}

void Note::setImportant(bool i) {
    if (!locked) {
        if (i) {
            collection->addImportant(this);
            if (!important) {
                important = i;
            }
        }
        else {
            collection->removeImportant(this);
            if (important) {
                important = i;
            }
        }
    }
}

void Note::printNote() const {
    string coll;
    if (collection == NULL) {
        coll= "NULL";
    }
    else {
        coll= collection->getName();
    }
    cout << "Titolo: " << title << endl;
    cout << "Testo: " << text << endl;
    cout << "Collezione: " << coll << endl;
    cout << "Lucchetto: " << locked << endl;
    cout << "Importante: " << important << endl;
}

void Note::update() {
    int collSize= this->collection->getNumNotes();
    cout << "Collezione " << this->collection->getName() << " ha " << collSize << " note" << endl;
};

//TODO: Implementare il metodo Importantupdate
/*
void Note::Importantupdate() {
    int collSize= this->collection->getNumNotes();
    cout << "Collezione " << this->collection->getName() << " ha " << collSize << " note" << endl;
};*/