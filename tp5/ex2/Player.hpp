#include "Card.hpp"

#include <string>
#include <vector>

class Player
{
private:
    std::string       _name;
    std::vector<Card> _cards;

public:
    Player(std::string);

    Card pop_back();
    void push_front(Card);

    const std::vector<Card>& cards() { return _cards; }
    const std::string&       name() { return _name; }

    static void deal_all_cards(Player&, Player&);
    static bool play(Player&, Player&, std::vector<Card> stake = {});

    inline static unsigned turn_number = 0;
};
