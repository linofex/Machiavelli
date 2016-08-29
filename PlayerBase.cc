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
	std::vector<Card>::const_iterator iter = cards.begin();
	for (; iter != cards.end(); ++iter){
		if(*iter == card){
			return true;
		}
	return false;
}
}

bool PlayerBase::Empty()const{
	return cards.size() == 0;
}
	
void PlayerBase::RemoveCard(const Card& card){
	std::vector<Card>::iterator iter = cards.begin();
	for (; iter != cards.end(); ++iter){
		if(*iter == card){
			cards.erase(iter);
			return;
		}
	}
}

void PlayerBase::SetCards(const std::vector<Card>& cards_){
	cards = cards_;
}

std::vector<Card> PlayerBase::GetCards() const{
	return cards;
}
