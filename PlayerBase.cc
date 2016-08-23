#include "PlayerBase.h"
#include <iostream>


void PlayerBase::AddCard(const Card& card){
	cards.push_back(card);
	}

void PlayerBase::SeeCards() const {
	for(int i = 0; i < cards.size(); ++i){
		std::cout << cards[i] << " ";
	}
	std::cout << std::endl;
}

bool  PlayerBase::FindCard(const Card& card) const{
	/*if(cards.find(card) != cards.end()){
		return true;
	}
	else {
		return false;
	}*/
}

bool PlayerBase::Empty()const{
	return cards.size() == 0;
}
	
