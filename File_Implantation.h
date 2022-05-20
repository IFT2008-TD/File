//
// Created by etudiant on 22-05-20.
//

#ifndef FILE_EXEC_FILE_IMPLANTATION_H
#define FILE_EXEC_FILE_IMPLANTATION_H

#include "File.h"

template<typename T>
File<T>::File() {

}

template<typename T>
File<T>::File(std::vector<T>) {

}

template<typename T>
void File<T>::enfiler(const T &) {

}

template<typename T>
void File<T>::defiler() {

}

template<typename T>
const T &File<T>::premier() const {
    T t ;
    return t ;
}

template<typename T>
size_t File<T>::queue() const {
    return 0;
}

template<typename T>
void File<T>::vider() {

}

template<typename T>
void File<T>::agrandir(size_t) {

}

template<typename T>
bool File<T>::estVide() const {
    return false;
}

template<typename T>
bool File<T>::estPleine() const {
    return false;
}

template<typename T>
size_t File<T>::disponible() const {
    return 0;
}

#endif //FILE_EXEC_FILE_IMPLANTATION_H
