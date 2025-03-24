## Exercice 1 - Documentation

1. Consulter la documentation des conteneurs spécifiés afin de renseigner les complexités en temps de chacune des opérations :

| Conteneur     | Insertion (en tête / en fin) | Suppression (en tête / en fin) | Accès |
|---------------|--------------|--------------|--------------|
| array         |     N/A      |     N/A      |      O(1)    |
| vector        |     O(N)     | O(1) ou O(N) |      O(1)    |
| deque         |     O(1)     |     O(1)     |      O(1)    |
| forward_list  |     O(N)     |     O(N)     |      O(N)    |
| list          |     O(1)     |     O(1)     |      O(N)    |
| set           |     O(log(N))|     O(log(N))|     O(log(N))|
| unordered_set |     O(N)     |     O(N)     |      O(N)    |

2. Supposons que vous ayez récupéré un itérateur sur un élément d'un conteneur avec : `auto it = std::find(ctn.begin(), ctn.end(), element_to_find)`.  
En fonction du type de conteneur, quelles sont les opérations susceptibles d'invalider cet itérateur ? Essayez d'être précis dans vos réponses.  
Exemple : Si `ctn` est un `std::vector`, alors `it` peut être invalidé en cas de suppression d'un élément précédent `it` dans le conteneur.

Si `ctn` est un `std::vector`, alors `it` peut être invalidé en cas d'insertion d'un élément précédent `it` dans le conteneur.

3. Quelle est la différence entre les fonctions `push_back` et `emplace_back` de la classe-template `std::vector` ?

`push_back` copie (si L-Value) ou move (si R-Value) l'objet passé en paramètre pour construire l'élément. Il faut donc que le paramètre soit du même type que les éléments du std::vector. `emplace_back` forward ses paramètres au constructeur de l'élément. Il faut donc que les arguments passés à la fonction correspondent à la signature de l'un des constructeurs des éléments du std::vector.