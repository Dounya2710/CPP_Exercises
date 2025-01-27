# TP3 - Exercice 1:

## Cas A - Copie VS Référence

1. `first_wheel` fait référence à `wheels[0]` alors que `last_wheel` est juste une copie de `wheels[3]`.

## Cas B - Pointeurs observants

1. Une référence est une flèche en pointillé (point d'un objet à un autre), un pointeur fait référence à `nullptr`.
2. Le pointeur nul est représenté en symbole nul.
3. Un pointeur-observant est réassignalble, il peut être vide mais n'own pas la donnée pointée. -> ```const Worker* manager = nullptr;```
Une référence fait toujours référence à la même donnée. -> ```cto.manager = &boss;```

## Cas C - Insertions dans un `std::vector`

1. cf Brouillon
2. Dans le graphe, si on ajoute un nouvel objet qui own un autre après la désinstancication de la référence (`first_products`) cela crée une dangling-reference.

3. 
```cpp
#include <memory>
#include <vector>

struct Product
{};

struct Client
{
    std::vector<std::unique_ptr<Product>> products;
};

int main()
{
    auto client = Client {};

    client.products.push_back(std::make_unique<Product>{});
    client.products.push_back(std::make_unique<Product>{});

    auto& first_product = client.products.front(); // Toujours valide
    client.products.push_back(std::make_unique<Product>{});
    return 0;
}
```
4. cf Brouillon

5. Non. Avec des std::unique_ptr, le graphe d'ownership reste cohérent, car les adresses des objets Product ne changent pas. La réallocation du conteneur n'a aucun effet sur les pointeurs ownants ou les objets qu'ils possèdent.
