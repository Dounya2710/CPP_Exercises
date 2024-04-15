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

template <typename T>
void print_test(std::string type, T&& value) {
    std::cout << type << std::endl;
    std::cout << "** Error: value is not a std::string" << std::endl;
}

void print_test(std::string type, std::string value)
{
    std::cout << type << std::endl;
    std::cout << " -> " << value << std::endl;
}

int main()
{
    // De base on a l'adresse des objets
    print_test("Vide", to_string(Empty {}));

    // Q1: on veut gérer les chaines de caractères
    print_test("std::string", to_string(std::string { "Machin" }));
    print_test("char*", to_string("Bidule"));

    // Q2: Puis les conversions simples fournies par la fonction std::to_string
    print_test("int", to_string(3));

    // Q4: On s'attaque maintenant aux conteneurs
    print_test("std::vector<int>", to_string(std::vector<int> { 1, 2, 3, 4 }));
    print_test("std::vector<std::vector<int>>",
               to_string(std::vector<std::vector<int>> { std::vector<int> { 0, 1, 2, 3 },
                                                         std::vector<int> { 4, 5, 6, 7 } }));
    // Q4b: avec une spécialisation pour les std::array
    print_test("std::array<int, 4>", to_string(std::array<int, 4> { 1, 2, 3, 4 }));

    // Q5: Si un objet présente une fonction de conversion, on l'utilise
    print_test("Convertible", to_string(Convertible {}));

    // Q6: S'il est streamable (en implémentant l'opérateur << sur ostream), idem
    print_test("Streamable", to_string(Streamable {}));

    // Commenter cette ligne si elle bloque la compilation trop tot dans le TP
<<<<<<< HEAD
    //std::cout << "Both" << std::endl << " -> " << to_string(Both {}) << std::endl;
=======
    print_test("Both", to_string(Both {}));
>>>>>>> upstream/master
    return 0;
}
