# Examen de C++

### Niveau : Master 1 Informatique
### Durée : 3 heures
### Instructions :

    Répondez aux questions sur des feuilles séparées.
    Commentez votre code pour expliquer vos choix et votre raisonnement.
    Toute tentative de tricherie entraînera l'annulation de votre copie.

### Partie 1 : Classes et Gestion de la Mémoire (60 points)

#### Question 1 (20 points)

On vous demande de créer une classe Person qui représente une personne avec les attributs suivants :

    Nom (chaîne de caractères)
    Âge (entier)

La classe doit inclure :

    Un constructeur par défaut.
    Un constructeur paramétré.
    Un destructeur.
    Une méthode display() pour afficher les informations de la personne.

Écrivez la déclaration de la classe et son implémentation.

#### Question 2 (20 points)

Ajoutez une classe Student qui hérite de la classe Person avec un attribut supplémentaire :

    Note moyenne (flottant)

La classe Student doit inclure :

    Un constructeur paramétré qui appelle le constructeur de la classe de base.
    Une méthode display() qui surcharge celle de la classe de base pour afficher également la note moyenne.

Écrivez la déclaration de la classe et son implémentation.

#### Question 3 (20 points)

On vous demande d'implémenter une gestion dynamique de la mémoire pour un tableau de Person dans une classe PersonArray. Cette classe doit inclure :

    Un pointeur vers un tableau dynamique de Person.
    La taille du tableau.

La classe doit fournir :

    Un constructeur qui alloue dynamiquement de la mémoire pour un tableau de Person de taille donnée.
    Un destructeur qui libère la mémoire allouée.
    Une méthode addPerson(const Person& p, int index) pour ajouter une Person à un indice donné.
    Une méthode displayAll() pour afficher les informations de toutes les personnes dans le tableau.

Écrivez la déclaration de la classe et son implémentation.

### Partie 2 : Templates (40 points)

#### Question 4 (20 points)

Créez une classe template Stack qui implémente une pile (LIFO) avec les opérations suivantes :

    void push(const T& element) : ajoute un élément au sommet de la pile.
    T pop() : retire et renvoie l'élément au sommet de la pile.
    bool isEmpty() const : renvoie vrai si la pile est vide, faux sinon.

Écrivez la déclaration de la classe et son implémentation.

#### Question 5 (20 points)

Créez une fonction template findMax qui prend en entrée un tableau et sa taille, et renvoie le plus grand élément du tableau.

Utilisez cette fonction pour trouver le plus grand élément dans un tableau de int et un tableau de double. Écrivez le code de test approprié dans la fonction main.