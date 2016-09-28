#include<vector>
#include<algorithm>
#include "Card.h"

class TestCard {
	public:
		TestCard() {
		std::cout << "ciso "; 
			std::vector<Card> cards;
			cards.push_back(Card("A", "c"));
			cards.push_back(Card("8", "c"));
			cards.push_back(Card("50", "f"));
			cards.push_back(Card("K", "p"));
			cards.push_back(Card("8", "g"));
			cards.push_back(Card("8", "f"));
			
			std::vector<Card>::iterator iter = cards.begin();
			for (; iter != cards.end(); ++iter) {
				if (iter->Exist()) {
					std::cout << "La carta " << (*iter)
					<< " esiste." << std::endl;
				}
				else {
					std::cout << "La carta "<< (*iter) <<
					" non esiste. Il suo valore e` " <<
					iter->GetIntValue() << std::endl;
				}
			}
			
			if(Card::CompareValue(cards[0], cards[4])) {
				std::cout << "Le carte " << cards[0] << 
				" e " << cards[4] << " hanno lo stesso" 
				" valore." << std::endl;
			}
			
			else{
				std::cout << "Le carte " << cards[0] << 
				" e " << cards[4] << " NON shanno lo stesso"
				" valore." << std::endl;
				}
			
			if(Card::CompareSuit(cards[0], cards[1])) {
				std::cout << "Le carte " << cards[0] << 
				" e " << cards[1] << " hanno lo stesso"
				" seme." << std::endl;
			}
			else {
				std::cout << "Le carte " << cards[0] << 
				" e " << cards[1] << " NON shanno lo stesso"
				" seme." << std::endl;}
			
			if(cards[0] == cards[1]) {
				std::cout << cards[0] << " = " << cards[1] <<
				std::endl;
			}
			else {
				std::cout << cards[0] << " != " << cards[1] <<
				std::endl;
			}
			
			std::sort(cards.begin(), cards.end());
			
			std::vector<Card>::iterator iter1 = cards.begin();
			std::cout << "Carte ordinate:\n" << std::endl;
			for (; iter1 != cards.end(); ++iter1) {
				std::cout << (*iter1) <<	std::endl;
			}
		}
};

int main() {
	TestCard testCard;
	return 0;
}
			
