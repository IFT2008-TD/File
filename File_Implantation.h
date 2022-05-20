//
// Created by etudiant on 22-05-20.
//

#ifndef FILE_EXEC_FILE_IMPLANTATION_H
#define FILE_EXEC_FILE_IMPLANTATION_H

#include "File.h"

/**
 * Crée une file d'attente vide.
 * @tparam T
 */
template<typename T>
File<T>::File() {

}

/**
 * Crée une file d'attente à-partir d'un objet vector.  Adapte automatiquement la capacité à celle du vector.  Échoue
 * si la capacité de l'objet vector est supérieure à la capacité maximale.
 * @tparam T
 * @except std::runtime_error si l'objet vector est plus grand que la capacité maximale.
 */
template<typename T>
File<T>::File(const std::vector<T>& v) {

}

/**
 * Ajoute un élément en QUEUE de file.
 * @tparam T
 * @except std::runtime_error si la file est pleine.
 */
template<typename T>
void File<T>::enfiler(const T &) {

}

/**
 * Retire l'élément en TÊTE de file.  Ne retourne RIEN.
 * @tparam T
 * @except std::runtime_error si la file est vide.
 */
template<typename T>
void File<T>::defiler() {

}

/**
 * Retourne l'élément en TÊTE de file (le prochain à sortir)
 * @tparam T
 * @return Élément en tête
 * @except std::runtime_error si la file est vide.
 */
template<typename T>
const T &File<T>::premier() const {
    T t ;
    return t ;
}

/**
 * MÉTHODE PRIVÉE: Localise le dernier élément de la file.
 * @tparam T
 * @return Index de la position du dernier élément ajouté, plus 1.
 */
template<typename T>
size_t File<T>::queue() const {
    return 0;
}

/**
 * Efface toutes les données de la file.  Celle-ci est vide après l'opération.  Ne change PAS la capacité de la file.
 * N'a aucun effet si la file est déjà vide.
 * @tparam T
 */
template<typename T>
void File<T>::vider() {

}

/**
 * Modifie la capacité de la file.  Si celle-ci avait une capacité de n, agrandir(x) donnera une file de capacité
 * finale x.  Si x est plus grand que n, les données seront inchangées.  Si x est plus petit que n, le comportement
 * est non défini.  Il est donc préférable, pour réduire une file, de l'effacer au préalable.
 * @tparam T
 */
template<typename T>
void File<T>::agrandir(size_t) {

}

/**
 * Vérifie si la file est vide.
 * @tparam T
 * @return true si la file est vide.
 */
template<typename T>
bool File<T>::estVide() const {
    return false;
}

/**
 * Vérifie si la file est remplie.
 * @tparam T
 * @return true si la file est remplie.
 */
template<typename T>
bool File<T>::estPleine() const {
    return false;
}

/**
 * Vérifie la réserve de la file.  Si disponible retourne n, alors on peut encore enfile n éléments dans la file.
 * @tparam T
 * @return Le nombre d'éléments que l'on peut enfiler.
 */
template<typename T>
size_t File<T>::disponible() const {
    return 0;
}

#endif //FILE_EXEC_FILE_IMPLANTATION_H
