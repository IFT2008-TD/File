# IFT-2008 Travaux dirigés

## Travail dirigé numéro 4: la file

### Instructions

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

