#include <iostream>

template<typename Type>
Type findMax(const Type array[], int size) {
    Type max = array[0];
    while(size > 0){
        for(int i = 1; i < size; i++) {
            if(max < array[i]) {
                max = array[i];
            }
        }
    }
    return max;
}

int main() {
    int intArray[5] = {1, 5, 3, 9, 2};
    int maxInt = findMax(intArray, 5);
    std::cout << "Le plus grand élément dans le tableau d'entiers est: " << maxInt << std::endl;


    // Tableau de doubles
    double doubleArray[5] = {1.1, 5.5, 3.3, 9.9, 2.2};
    double maxDouble = findMax(doubleArray, 5);
    std::cout << "Le plus grand élément dans le tableau de doubles est: " << maxDouble << std::endl;
    return 0;
}