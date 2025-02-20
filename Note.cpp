//
// Created by Riccardo on 20/02/2025.
//
#include "Note.h"
#include <iostream>

Note::Note(string tl, string txt, string c, bool lck, bool i): title(tl), text(txt), collection(c), locked(lck), important(i) {}
Note::~Note() {}

string Note::getTitle() const {
    return title;
}
string Note::getText() const {
    return text;
}
bool Note::isLocked() const {
    return locked;
}
string Note::getCollection() const {
    return collection;
}
bool Note::isImportant() const {
    return important;
}

void Note::setTitle(string tl) {
    title = tl;
}
void Note::setText(string txt) {
    text = txt;
}
void Note::setLocked(bool lck) {
    locked = lck;
}
void Note::setCollection(string c) {
    collection = c;
}
void Note::setImportant(bool i) {
    important = i;
}

void Note::printNote() const {
    cout << "Title: " << title << endl;
    cout << "Text: " << text << endl;
    cout << "Collection: " << collection << endl;
    cout << "Locked: " << locked << endl;
    cout << "Important: " << important << endl;
}

void Note::addObserver(Observer *o) {
    observers.push_back(o);
}
void Note::removeObserver(Observer *o) {
    observers.remove(o);
}
void Note::notifyObserver() {
    for (auto o : observers) {
        o->update();
    }
}

