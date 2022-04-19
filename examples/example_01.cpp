#include <iostream>
#include <assert.h>

#include "enprint.hpp"

class Card{
public:
	enum class Suit{Spades, Clubs, Hearts, Diamonds};
	enum class Rank{Ace, Deuce, Three, Four, Five, Six, Seven, Eight, Nine, Ten, Jack, Queen, King, _Size};
private:
	Suit _suit;
	Rank _rank;
public:

	Card(const uint32_t i){
		assert(i < 52);
		_rank = static_cast<Rank>(i%13);
		_suit = static_cast<Suit>(i/13);
	}

	friend inline std::ostream& operator<<(std::ostream& out, const Card& card);

};

inline std::ostream& operator<<(std::ostream& out, const Card::Suit& suit){
	return out << enprint::enum_as_string_view<4>(suit);
}

inline std::ostream& operator<<(std::ostream& out, const Card::Rank& rank){
	return out << enprint::enum_as_string_view(rank);
}

inline std::ostream& operator<<(std::ostream& out, const Card& card){
	return out << card._rank << " of " << card._suit;
}

int main(){
	for(uint32_t i=0;i<52;i++){
		std::cout << Card(i) << "\n";
	}
	return 0;
}
