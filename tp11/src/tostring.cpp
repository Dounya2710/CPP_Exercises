#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <array>
#include <type_traits>

template <typename T>
auto to_string(const T& data) -> typename std::enable_if<!std::is_same<T, std::string>::value && !std::is_same<T, const char*>::value, std::string>::type {
    std::stringstream ss;
    ss << "<" << typeid(data).name() << ": " << &data << ">";
    return ss.str();
}

template <>
std::string to_string(const std::string& str) {
    return str;
}

template <>
std::string to_string(const char* str) {
    return str;
}

std::string to_string(int data) {
    return std::to_string(data);
}

template <typename T>
struct has_to_string {
    template <typename U>
    static auto test(U* ptr) -> decltype(std::to_string(*ptr), std::true_type());

    template <typename>
    static auto test(...) -> std::false_type;

    static constexpr bool value = decltype(test<T>(nullptr))::value;
};

template <typename T>
auto to_string(const T& data) -> decltype(std::declval<std::ostream&>() << data, std::string()) {
    std::stringstream ss;
    ss << data;
    return ss.str();
}

template <typename T>
auto to_string(const std::vector<T>& vec) -> std::string {
    std::stringstream ss;
    ss << "[";
    for (size_t i = 0; i < vec.size(); ++i) {
        if (i > 0) ss << ", ";
        ss << to_string(vec[i]);
    }
    ss << "]";
    return ss.str();
}

template <typename T, size_t N>
auto to_string(const std::array<T, N>& arr) -> std::string {
    std::stringstream ss;
    ss << "[";
    for (size_t i = 0; i < arr.size(); ++i) {
        if (i > 0) ss << ", ";
        ss << to_string(arr[i]);
    }
    ss << "]";
    return ss.str();
}

template <typename T>
auto to_string(const T& container) -> typename std::enable_if<!has_to_string<T>::value && !std::is_same<T, std::string>::value && !std::is_same<T, const char*>::value, std::string>::type {
    std::stringstream ss;
    ss << "{";
    auto it = std::begin(container);
    if (it != std::end(container)) {
        ss << to_string(*it);
        ++it;
    }
    for (; it != std::end(container); ++it) {
        ss << ", " << to_string(*it);
    }
    ss << "}";
    return ss.str();
}

class Empty {};

class Convertible {
public:
    std::string to_string() const {
        return "Convertible";
    }
};

std::ostream& operator<<(std::ostream& out, const Convertible& c) {
    out << c.to_string();
    return out;
}

class Streamable {
public:
    friend std::ostream& operator<<(std::ostream& out, const Streamable& s) {
        return out << "Streamable";
    }
};

class Both : public Streamable, public Convertible {};

std::string to_string(const Streamable& s) {
    std::stringstream ss;
    ss << s;
    return ss.str();
}

std::string to_string(const Both& b) {
    return b.Convertible::to_string();
}

std::string to_string(const Convertible& data) {
    return data.to_string();
}

int main()
{
    // De base on a l'adresse des objets
    std::cout << "Vide" << std::endl << " -> " << to_string(Empty {}) << std::endl;

    // Q1: on veut gérer les chaines de caractères
    std::cout << "std::string" << std::endl << " -> " << to_string(std::string { "Machin" }) << std::endl;
    std::cout << "char*" << std::endl << " -> " << to_string("Bidule") << std::endl;

    // Q2: Puis les conversions simples fournies par la fonction std::to_string
    std::cout << "int" << std::endl << " -> " << to_string(3) << std::endl;

    // Q4: On s'attaque maintenant aux conteneurs
    std::cout << "std::vector<int>" << std::endl
              << " -> " << to_string(std::vector<int> { 1, 2, 3, 4 }) << std::endl;
    std::cout << "std::vector<std::vector<int>>" << std::endl
              << " -> "
              << to_string(std::vector<std::vector<int>> { std::vector<int> { 0, 1, 2, 3 },
                                                           std::vector<int> { 4, 5, 6, 7 } })
              << std::endl;
    // Q4b: avec une spécialisation pour les std::array
    std::cout << "std::array<int, 4>" << std::endl
              << " -> " << to_string(std::array<int, 4> { 1, 2, 3, 4 }) << std::endl;

    // Q5: Si un objet présente une fonction de conversion, on l'utilise
    std::cout << "Convertible" << std::endl << " -> " << to_string(Convertible {}) << std::endl;

    // Q6: S'il est streamable (en implémentant l'opérateur << sur ostream), idem
    std::cout << "Streamable" << std::endl << " -> " << to_string(Streamable {}) << std::endl;

    // Commenter cette ligne si elle bloque la compilation trop tot dans le TP
    //std::cout << "Both" << std::endl << " -> " << to_string(Both {}) << std::endl;
    return 0;
}