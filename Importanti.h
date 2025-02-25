//
// Created by Riccardo on 24/02/2025.
//

#ifndef IMPORTANTI_H
#define IMPORTANTI_H
#include "Collezioni.h"


class Importanti: public Collezioni{
    private:
    list<Note*> importantNotes;
    public:
    Importanti(const string& n);
    ~Importanti() {};
    //getter e setter
    list<Note*> getImportant() const {
        return importantNotes;
    }
    void addNote(Note *n) override;
    void removeNote(Note *n) override;
    void printImportantNotes() const;
};
#endif //IMPORTANTI_H
