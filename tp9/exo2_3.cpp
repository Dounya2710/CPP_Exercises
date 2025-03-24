#include <iostream>
#include <string>
#include <vector>
#include <numeric>
#include <algorithm>

std::string to_upper_case(std::string words) {
    std::transform(words.begin(), words.end(), words.begin(),
                   [](unsigned char c){ return std::toupper(c); }
                  );
    return words;
}

std::string concat_in_caps(const std::vector<std::string>& words)
{
    const auto it = std::accumulate(words.begin() + 1, words.end(), to_upper_case(words[0]), [](auto str1, const auto& str2) { return std::move(str1) + ' ' + to_upper_case(str2);});
    return it;
}

int main()
{
    std::vector<std::string> words { "ARRETE", "De", "criEr", "steuplAIt" };
    std::cout << concat_in_caps(words) << std::endl;
    return 0;
}