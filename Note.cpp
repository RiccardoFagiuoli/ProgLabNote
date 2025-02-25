//
// Created by Riccardo on 20/02/2025.
//
#include <iostream>
#include "Note.h"

#include <mutex>

#include "Collezioni.h"


Note::Note(const string& tl, const string& txt, Collezioni* c, bool lck, bool i): title(tl), text(txt), collection(c), locked(lck), important(i) {
    c->addNote(this);
}
Note::~Note(){};

void Note::setTitle(const string& tl) {
    if (!locked) {
        title = tl;
    }
    else {
        cout << "Nota bloccata" << endl;
    }
}
void Note::setText(const string& txt) {
    if (!locked) {
        text = txt;
    }
    else {
        cout << "Nota bloccata" << endl;
    }
}
void Note::setLocked(bool lck) {
        locked = lck;
}
void Note::setCollection(Collezioni* c) {
    if (!locked) {
        if (collection != NULL) {
            collection->removeNote(this);
        }
        if (c != NULL) {
            c->addNote(this);
        }
        collection = c;
    }
    else {
        cout << "Nota bloccata" << endl;
    }
}
void Note::setImportance(bool i) {
    important = i;
}

void Note::delNote() {
    if (!locked) {
        string n= title;
        if (collection != NULL) {
            collection->removeNote(this);
        }
        /*
        if (important) {
            important = false;
            ImportantNotes->removeNote(this);
        }*/
        delete this;
        cout << "Nota " << n << " eliminata" << endl;
    }
    else {
        cout << "Nota bloccata" << endl;
    }
}

void Note::printNote() const {
    string c;
    if (collection == NULL) {
        c="nessuna";
    }
    else {
        c = collection->getName();
    }
    cout << "Titolo: " << title << endl;
    cout << "Testo: " << text << endl;
    cout << "Bloccata: " << locked << endl;
    cout << "Importante: " << important << endl;
    cout << "Collezione: " << c << endl;
}