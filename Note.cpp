//
// Created by Riccardo on 20/02/2025.
//

#include "Note.h"
#include <iostream>

Note::Note(const string& tl, const string& txt, const string& c, bool lck, bool i): title(tl), text(txt), collection(c), locked(lck), important(i) {
    notifyObserver();
}
Note::~Note() {}


void Note::printNote() const {
    cout << "Title: " << title << endl;
    cout << "Text: " << text << endl;
    cout << "Collection: " << collection << endl;
    cout << "Locked: " << locked << endl;
    cout << "Important: " << important << endl;
}

void Note::addObserver(Observer *o) override{
    observers.push_back(o);
}
void Note::removeObserver(Observer *o) override {
    observers.remove(o);
}
void Note::notifyObserver() override {
    for (auto o : observers) {
        o->update();
    }
}
//come risolvo il warning?
