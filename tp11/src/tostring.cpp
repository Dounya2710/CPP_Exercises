#include <array>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <tuple>
#include <type_traits>
#include <typeinfo>

template <typename T, typename = void>
struct is_streamable : std::false_type {};

template <typename T>
struct is_streamable<T, std::void_t<decltype(std::declval<std::ostream&>() << std::declval<T>())>>
    : std::true_type {};

template <typename T, typename = void>
struct has_to_string_method : std::false_type {};

template <typename T>
struct has_to_string_method<T, std::void_t<decltype(std::declval<T>().to_string())>>
    : std::true_type {};


template <typename T, typename = void>
struct is_iterable : std::false_type {};

template <typename T>
struct is_iterable<T, std::void_t<
    decltype(std::begin(std::declval<T>())),
    decltype(std::end(std::declval<T>()))
>> : std::true_type {};

template <typename T>
struct is_tuple : std::false_type {};

template <typename... Args>
struct is_tuple<std::tuple<Args...>> : std::true_type {};

template <typename Tuple, std::size_t... Is>
std::string tuple_to_string(const Tuple& t, std::index_sequence<Is...>) {
    std::ostringstream oss;
    oss << "{";
    ((oss << (Is == 0 ? "" : ", ") << to_string(std::get<Is>(t))), ...);
    oss << "}";
    return oss.str();
}

template <typename T>
std::string to_string(const T& value) {
    if constexpr (std::is_same_v<T, std::string>) {
        return value;
    } else if constexpr (std::is_same_v<T, const char*> || std::is_same_v<T, char*>) {
        return std::string(value);
    } else if constexpr (std::is_arithmetic_v<T>) {
        return std::to_string(value);
    } else if constexpr (has_to_string_method<T>::value) {
        return value.to_string();
    } else if constexpr (is_iterable<T>::value && !std::is_same_v<T, std::string>) {
        std::ostringstream oss;
        oss << "{";
        auto it = std::begin(value);
        auto end = std::end(value);
        while (it != end) {
            oss << to_string(*it);
            if (++it != end) oss << ", ";
        }
        oss << "}";
        return oss.str();
    } else if constexpr (is_tuple<T>::value) {
        return tuple_to_string(value, std::make_index_sequence<std::tuple_size_v<T>>{});
    } else if constexpr (is_streamable<T>::value) {
        std::ostringstream oss;
        oss << value;
        return oss.str();
    } else {
        std::ostringstream oss;
        oss << "<" << typeid(T).name() << ": " << &value << ">";
        return oss.str();
    }
}

class Empty
{};

class Streamable
{
public:
    friend std::ostream& operator<<(std::ostream& out, const Streamable& s)
    {
        return out << "Streamable @" << &s;
    }
};

class Convertible
{
public:
    std::string to_string() const
    {
        std::stringstream ss;
        ss << "Convertible @" << this;
        return ss.str();
    }
};

class Both : public Streamable, public Convertible
{};

/*template <typename T>
void print_test(std::string type, T&& value) {
    std::cout << type << std::endl;
    std::cout << "** Error: value is not a std::string" << std::endl;
}*/

template <typename T>
void print_test(const std::string& label, T&& value) {
    std::cout << label << "\n -> " << to_string(std::forward<T>(value)) << "\n";
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
    print_test("Both", to_string(Both {}));
    return 0;
}
