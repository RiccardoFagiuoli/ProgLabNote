//
// Created by Riccardo on 20/02/2025.
//

#ifndef NOTE_H
#define NOTE_H

#include <string>

using namespace std;

class Note{
    private:
    string title;
    string text;
    bool locked;
    bool important;

    public:
    Note(const string& tl, const string& txt, bool lck=false, bool i=false);
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
    bool isImportant() const {
        return important;
    }

    void setTitle(string tl) {
        title = tl;
    }
    void setText(string txt) {
        if (!locked) {
            text = txt;
        }
    }
    void setLocked(bool lck) {
        locked = lck;
    }
    void setImportant(bool i) {
        if (!locked) {
            important = i;
        }
    }
    void delNote() {
        if (!locked) {
            delete this;
        }
    }

    void printNote() const;
};

#endif //NOTE_H
