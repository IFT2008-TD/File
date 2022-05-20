//
// Created by etudiant on 22-05-20.
//

#ifndef FILE_FILE_H
#define FILE_FILE_H

#include <vector>
#include <cstddef>
#include <initializer_list>

namespace td4 {

    template<typename T>
    class File {
    public:

        static const size_t cap_maximum = 1000;
        static const size_t cap_defaut = 7;

        explicit File(size_t = cap_defaut);

        explicit File(std::initializer_list<T>);

        void enfiler(const T &);

        void defiler();

        const T &premier() const;

        void vider();

        void agrandir(size_t);

        bool estVide() const;

        bool estPleine() const;

        size_t disponible() const;

    private:
        size_t capacite;
        size_t cardinal;
        size_t tete;
        std::vector<T> vecteur;

    private:

        size_t queue() const;


    };

}


#include "File_Implantation.h"

#endif //FILE_FILE_H
