///////////////////////////////////////////////////////////////////////////////////////
//
// Choisissez les types les plus appropriés pour que les fonctions puissent faire leur travail de la manière
// la plus sécurisée et optimisée possible.
// Attention donc aux copies inutiles sur les types coûteux à copier et à si la fonction est censée modifier
// le paramètre ou pas.
//
// Exemple
// get_char retourne un caractère
//  ANSWER_EX get_char();
#define ANSWER_EX char
//                ^^^^ -> indiquez votre réponse ici
//
///////////////////////////////////////////////////////////////////////////////////////

// Question 1
// stringify_integer convertit un entier en chaîne de caractères
//
// Rappel: ANSWER_1A stringify_integer(ANSWER_1B integer);
#define ANSWER_1A const std::string
#define ANSWER_1B int

// Question 2
// count_nb_elements permet de retourner le nombre d'éléments présents dans un tableau
// dynamique d'entiers
//
// Rappel:  ANSWER_2A count_nb_elements(ANSWER_2B elements);
#define ANSWER_2A int
#define ANSWER_2B const std::vector<int>&

// Question 3
// WrappedString permet de stocker une chaîne et d'encapsuler ses accès en lecture et en écriture
// Pour le constructeur, vous devez indiquer le type du paramètre qui permettra d'intialiser _content:
//
// Rappel: WrappedString(ANSWER_3A initial_content)
#define ANSWER_3A const std::string&

// La fonction get_readonly_content() doit donner un accès en lecture seule à _content
//
// Rappel: ANSWER_3B get_readonly_content() ANSWER_3C { return _content; }
#define ANSWER_3B const std::string&
#define ANSWER_3C const

// La fonction get_readonly_content() doit donner un accès en lecture et écriture à _content
//
// Rappel: ANSWER_3D get_modifiable_content() ANSWER_3E { return _content; }
#define ANSWER_3D std::string
#define ANSWER_3E                   
