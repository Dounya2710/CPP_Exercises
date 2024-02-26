#include <iostream>
#include <vector>

int main() {
    int i;
    4 // r-value -> variable littérale
    4 + i // r-value -> expression arithmétique, va être évaluée
    i // l-value -> on peut assigner une valeur à la variable i
    i = 4 //  l-value -> une variable qui reçoit une valeur
    i == 4 // r-value -> expression conditionnelle (vraie ou fausse), impossible d'assigner une valeur

    std::vector<char> vec;
    vec[5] // l-value -> on peut modifier un élément
    vec // l-value -> affecter ou modifier le vecteur
    vec.pop_back() // r-value -> retire le dernier élément mais ne retourne pas un référence à cet élément
    std::vector { 'a', 'b', 'c' } // r-value -> crée un nouveau vecteur, mais impossible de le modifier ou d'y accéder directement
    vec.push_back('d') // r-value -> modification du vecteur sans retourner une référence
    std::move(vec) // r-value -> modification de vec

    int *ptr;
    ptr + 3 // l-value -> déplacement du pointeur
    *(ptr + 3) // l-value -> déréférence le pointeur après avoir ajouté 3 à sa valeur
    *ptr + 3 // r-value -> déréférence le pointeur et ajoute 3 à sa valeur

    std::string str;
    std::string { "aaaa" } // r-value -> crée une string temporaire initialisé avec la chaine "aaaa"
    str // l-value -> variable existante, donc accès à celle-ci
    str + "aaaa" // r-value -> création et concaténation d'une nouvelle chaine
    str += "aaaa" // l-value -> ajout de "aaaa" à la fin de la chaine
    "aaaa"// r-value -> chaine constante non modifiable

    /* Dans le cas où on a une instruction Class inst { expr };:

    Pour le constructeur de copie :
        Si expr est une l-value, le constructeur de copie sera appelé car une copie de expr sera effectuée pour initialiser inst.

    Pour le constructeur de déplacement :
        Si expr est une r-value, le constructeur de déplacement sera appelé car expr est une ressource temporaire pouvant être déplacée dans inst */
    
    return 0;
}