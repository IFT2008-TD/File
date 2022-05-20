# IFT-2008 Travaux dirigés

## Travail dirigé numéro 4: la file

### Instructions

- Cloner le dépôt git ```git clone https://github.com/IFT2008-TD/File.git``` et créez le projet dans CLion.
- Si votre version de git est à jour sur la VM (voir contribution de Pascal Johnson dans le forum du cours), vous pouvez tout simplement cliquer "get from vcs"
dans la fenêtre des nouveaux projets de CLion, et dans le champ URL, vous saisissez l'adresse du 
dépôt: "https://github.com/IFT2008-TD/File.git" et cliquer sur "clone".  CLion va créer le projet automatiquement.
- Créer votre propre branche, que vous nommez comme vous voulez ```git branch mabranche```
- Basculer sur cette branche ```git checkout mabranche```
- Lire ce README, et la documentation de la classe et des méthodes
- COMPLÉTER LES TESTS
- Implanter la classe et s'assurer de passer tous les tests

### Description de la classe et du modèle d'implantation

Une file est le pendant FIFO d'une pile: les données sont placées les unes à la suite des autres
en file indienne, mais à la différence de la pile, c'est le premier élément inséré qui
est retiré.  La file doit donc implanter au minimum les opérations suivantes:

- enfiler(): insérer un élément en dernier dans la file.
- defiler(): retirer le premier élément de la file.
- premier(): lire le premier élément de la file.

On remarquera qu'ici, nous avons fait le choix de découpler les deux opérations defiler()
et premier().  Ceci est cohérent avec les standards de la STL.

Les contraintes de mémoire vont nous obliger à implanter des opérations supplémentaires pour
tenir compte du fait que la file a une capacité finie.

Notez donc la présence de deux attributs statiques:

- cap_maximum: il ne sera pas possible de construire une file dont la capacité, en éléments, dépasse ce nombre. 
- cap_defaut: ce sera la capacité de la file si les constructeur est appelé sans paramètre.

Les données seront conservées dans un objet vector, de sorte que nous n'aurons pas besoin
d'implanter les méthodes de la règle des 5 de Coplien, tous ces détails sont déjà pris en 
charge par la classe vector.

La capacité de la file sera donc la taille du vector, et nous utiliserons deux attributs de
type size_t pour garder la trace des éléments de la file:

- cardinal: le nombre d'éléments contenus dans la file
- premier: l'index de l'élément de tête de la file (le prochain élément à être retiré)

Nous utiliserons donc une méthode privée pour calculer dernier, qui est l'index de la position 
qui suit immédiatement le dernier élément de la file.  Il existe une relation mathématique simple
entre les attributs numériques de la file.  En-effet, à tout moment, la relation suivante
doit être respectée:

dernier = (premier + cardinal) mod capacite

Cette relation mathématique est l'invariant de notre classe file.  Donc, nous nous assurerons 
que l'invariant soit toujours respecté en calculant l'index dernier lorsque nous en avons 
besoin.

Donc, par-exemple, voici une file de capacité 10, stockée dans un vector dont les
indices vont de 0 à 9 inclusivement.  Il y a 5 éléments: e1, e2, ..., e5 dans la file,donc
le cardinal est 5.  Le prochain élément à sortir est e1.  Le dernier élément inséré est
e5.  On a donc premier = 2 et dernier = (2 + 5) mod 10 = 7.
```

_________________________________________________________________________
_______|_______|__e1___|__e2___|__e3___|__e4___|__e5___|_____|_____|_____|
                premier                                 dernier

```
Donc, si on fait l'opération defiler(), premier devient 3 et cardinal devient 4, et on a bien que dernier = (3+4) mod 10 = 7:
```

_________________________________________________________________________
_______|_______|_______|__e2___|__e3___|__e4___|__e5___|_____|_____|_____|
                        premier                         dernier

```
Et si maintenant on enfile(e6), cardinal devient 5 et on a: dernier = (3+5) mod 10 = 8
```

_________________________________________________________________________
_______|_______|_______|__e2___|__e3___|__e4___|__e5___|_e6__|_____|_____|
                        premier                               dernier

```

Que faut-il faire si dernier et premier atteignent le dernier indice du vecteur?  Doit-on 
lancer une exception, ou y a-t-il moyen de continuer?
