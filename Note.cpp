//
// Created by Riccardo on 20/02/2025.
//

#include "Note.h"
#include "Collezioni.h"
#include <iostream>

Note::Note(const string& tl, const string& txt, bool lck, bool i): title(tl), text(txt), locked(lck), important(i) {}
Note::~Note() {}


void Note::printNote() const {
    cout << "Title: " << title << endl;
    cout << "Text: " << text << endl;
    cout << "Locked: " << locked << endl;
    cout << "Important: " << important << endl;
}
