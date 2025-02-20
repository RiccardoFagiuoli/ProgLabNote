//
// Created by Riccardo on 20/02/2025.
//

#ifndef COLLEZIONI_H
#define COLLEZIONI_H
#include <list>
#include <string>
#include "Observer.h"
#include "Note.h"

using namespace std;
class Note;

class Collezioni: public Observer {
    private:
    string name;
    list<Note*> notes;
    public:
    Collezioni(const string& n);
    ~Collezioni();

    string getName() const {
        return name;
    }
    void addNote(Note *n) {
        notes.push_back(n);
        n->addObserver(this);
    }
    void removeNote(Note *n) {
        notes.remove(n);
        n->removeObserver(this);
    }

    void printNotes() const;
    int getNumNotes() const {
        return notes.size();
    }

    void update() override;


};

#endif //COLLEZIONI_H
