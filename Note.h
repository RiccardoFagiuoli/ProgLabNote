//
// Created by Riccardo on 20/02/2025.
//

#ifndef NOTE_H
#define NOTE_H

#include <list>
#include <string>

#include "Collezioni.h"
#include "Observer.h"

using namespace std;
class Collezioni;

class Note: public Observer{
    private:
    string title;
    string text;
    bool locked;
    Collezioni* collection;
    bool important;

    public:
    Note(const string& tl, const string& txt, Collezioni* c = NULL, bool lck=false, bool i=false);
    ~Note();

    string getTitle() const {
        return title;
    }
    string getText() const {
        return text;
    }
    bool isLocked() const {
        return locked;
    }
    Collezioni& getCollection() const {
        return *collection;
    }

    bool isImportant() const {
        return important;
    }

    void setTitle(string tl) {
        title = tl;
    }
    void changeText(string txt) {
        if (!locked) {
            text = txt;
        }
    }
    void setLocked(bool lck) {
        locked = lck;
    }
    void setCollection(Collezioni* c);

    void setImportant(bool i);

    void delNote() {
        if (!locked) {
            delete this;
        }
    }

    void printNote() const;

    void update() override;

    void getCollection();
};

#endif //NOTE_H
