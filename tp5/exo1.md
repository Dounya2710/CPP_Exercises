# TP5: Copie et déplacement

## Exercice 1: L-Value et R-Value

1. 

a. 
```cpp
4 // R-Value, il s'agit d'une valeur qui n'a pas d'espace mémoire réservé
4 + i // R-Value, opération qui n'a pas d'espace mémoire
i // L-Value, il a un espace mémoire réservé
i = 4 // L-Value, c'est une affectation d'une valeur qui a un espace mémoire réservé
i == 4 // R-Value, l'opérateur == retourne un booléen temporaire
```

b.
```cpp
vec[5] // L-Value, possède déjà un emplacement dans la mémoire, donc l'accès à la valeur existe
vec // L-Value
vec.pop_back() // R-Value, la fonction pop_back() ne retourne rien et ne peut être utilisé comme valeur
std::vector { 'a', 'b', 'c' } // R-Value, crée un tableau temporaire
vec.emplace_back('d') // R-Value, insère un élément mais ne retourne rien
std::move(vec) // R-Value, convertit le vec en une R-Value castée en std::vector<char>&&
```

c. 
```cpp
ptr + 3 // R-Value, aucun espace réservé, variable temporaire
*(ptr + 3) // L-Value, accès au pointeur
*ptr + 3 // R-Value, aucun espace mémoire réservé
```

d. 
```cpp
std::string { "aaaa" } // R-Value, crée un std::string temporaire
str // L-Value, espace réservé
str + "aaaa" // R-Value, concaténation qui renvoie une variable temporaire
str += "aaaa" // L-Value, l'opératuer += retourne une référence à str
```

2. Le constructeur de copie est appelé si expr est une L-Value de type `Class` et que le constructeur de copie n'est pas supprimé.
Le constructeur de déplacement est appelé si expr est une R-Value de type `Class` et que le constructeur de déplacement n'est pas supprimé.
