//
// Created by Riccardo on 20/02/2025.
//

#ifndef NOTE_H
#define NOTE_H

#include <string>

#include "Collezioni.h"

using namespace std;
class Collezioni;
class Importanti;

class Note{
    private:
    string title;
    string text;
    bool locked;
    Collezioni* collection;
    bool important;

    public:
    static Importanti* impPtr;
    Note(const string& tl, const string& txt, Collezioni* c = nullptr, bool lck=false, bool i=false);
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
    bool getImportance() const {
        return important;
    }
    bool getLocked() const {
        return locked;
    }
    Collezioni* getCollection() {
        return collection;
    }

    void setTitle(const string& tl);
    void setText(const string& txt);
    void setLocked(bool lck);
    void setCollection(Collezioni* c);
    void setImportance(bool i);
    void changeCollection(Collezioni*  c);

    void delNote();

    void printNote() const;
};

#endif //NOTE_H
