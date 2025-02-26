//
// Created by Riccardo on 20/02/2025.
//
#include <iostream>
#include "Note.h"
#include "Collezioni.h"
#include "Importanti.h"

Importanti* Note::impPtr=nullptr;

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
        if (collection != nullptr) {
            collection->removeNote(this);
        }
        if (c != nullptr) {
            c->addNote(this);
        }
        collection = c;
    }
    else {
        cout << "Nota bloccata" << endl;
    }
}
void Note::changeCollection(Collezioni *c) {
    if (!locked) {
        string origin = "nessuna";
        string destination = "nessuna";
        if (collection != nullptr) {
            origin = collection->getName();

        }
        if (c != nullptr) {
            destination = c->getName();
        }
        cout << "Collezione della nota " << this->getTitle() << " cambiata: " << origin << "-->" << destination << endl;
        setCollection(c);
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
        cout << "Nota " << n << " eliminata" << endl;
        if (collection != nullptr) {
            collection->removeNote(this);
        }
        if (important) {
            impPtr->removeNote(this);
        }
        delete this;
    }
    else {
        cout << "Nota bloccata" << endl;
    }
}

void Note::printNote() const {
    string c;
    if (collection == nullptr) {
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