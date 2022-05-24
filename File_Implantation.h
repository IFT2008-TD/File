//
// Created by etudiant on 22-05-20.
//

#ifndef FILE_EXEC_FILE_IMPLANTATION_H
#define FILE_EXEC_FILE_IMPLANTATION_H

#include "File.h"

namespace td4 {
/**
 * Crée une file d'attente vide, de capacité maximale capacite.
 * @tparam T
 * @param capacite Nombre maximal d'élément dans la file.  Par défaut, sera cap_defaut
 * @except std::invalid_argument si capacite dépasse cap_maximal
 */
    template<typename T>
    File<T>::File(size_t capacite) : capacite(capacite), cardinal(0), tete(0), vecteur(capacite) {
        if (capacite > cap_maximum) throw std::invalid_argument("constructeur par défaut: Capacité excessive.") ;
    }

/**
 * Crée une file d'attente à-partir d'une liste d'initialisation.  Adapte automatiquement la capacité à celle de la liste.  Échoue
 * si la capacité de la liste est supérieure à la capacité maximum.
 * NB: La capacité sera le double de la longueur de la liste d'initialisation.
 * @tparam T
 * @param l Liste d'initialisation.
 * @except std::runtime_error si la liste d'initialisation est plus grande que la capacité maximum.
 */
    template<typename T>
    File<T>::File(std::initializer_list<T> l) : capacite(2 * l.size()), cardinal(l.size()), tete(0), vecteur(l) {
       if (capacite > cap_maximum) throw std::invalid_argument("constructeur liste: Capacité excessive.") ;
       vecteur.resize(capacite) ;
    }

/**
 * Ajoute un élément en QUEUE de file.
 * @tparam T
 * @param e Élément à insérer dans la file.
 * @except std::runtime_error si la file est pleine.
 */
    template<typename T>
    void File<T>::enfiler(const T &e) {
        if (estPleine()) throw std::runtime_error("enfile: file pleine") ;
        vecteur.at(queue()) = e ;
        ++cardinal ;

    }

/**
 * Retire l'élément en TÊTE de file.  Ne retourne RIEN.
 * @tparam T
 * @except std::runtime_error si la file est vide.
 */
    template<typename T>
    void File<T>::defiler() {
        if (estVide()) throw std::runtime_error("defiler: file vide") ;
        tete = (tete + 1) % capacite ;
        --cardinal ;

    }

/**
 * Retourne l'élément en TÊTE de file (le prochain à sortir)
 * @tparam T
 * @return Élément en tête
 * @except std::runtime_error si la file est vide.
 */
    template<typename T>
    const T &File<T>::premier() const {
        if (estVide()) throw std::runtime_error("premier: file vide") ;
        return vecteur.at(tete);
    }

/**
 * MÉTHODE PRIVÉE: Localise le dernier élément de la file.
 * @tparam T
 * @return Index de la position du dernier élément ajouté, plus 1.
 */
    template<typename T>
    size_t File<T>::queue() const {
        return (tete + cardinal) % capacite ;
    }

/**
 * Efface toutes les données de la file.  Celle-ci est vide après l'opération.  Ne change PAS la capacité de la file.
 * N'a aucun effet si la file est déjà vide.
 * @tparam T
 */
    template<typename T>
    void File<T>::vider() {
        tete = 0 ;
        cardinal = 0 ;
    }

/**
 * Modifie la capacité de la file.  Si celle-ci avait une capacité de n, agrandir(x) donnera une file de capacité
 * finale x.  Si x est plus grand que n, les données seront inchangées.  Si x est plus petit que n, le comportement
 * est non défini.  Il est donc préférable, pour réduire une file, de l'effacer au préalable.
 * @tparam T
 */
    template<typename T>
    void File<T>::agrandir(size_t x) {
        vecteur.resize(x) ;
        capacite = x ;

    }

/**
 * Vérifie si la file est vide.
 * @tparam T
 * @return true si la file est vide.
 */
    template<typename T>
    bool File<T>::estVide() const {
        return (cardinal == 0);
    }

/**
 * Vérifie si la file est remplie.
 * @tparam T
 * @return true si la file est remplie.
 */
    template<typename T>
    bool File<T>::estPleine() const {
        return (disponible() == 0);
    }

/**
 * Vérifie la réserve de la file.  Si disponible retourne n, alors on peut encore enfile n éléments dans la file.
 * @tparam T
 * @return Le nombre d'éléments que l'on peut enfiler.
 */
    template<typename T>
    size_t File<T>::disponible() const {
        return (capacite - cardinal);
    }

}

#endif //FILE_EXEC_FILE_IMPLANTATION_H
