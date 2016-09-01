#include "PlayerBase.h"
#include <iostream>
#include <algorithm>

int PlayerBase::n_player =  0;

void PlayerBase::AddCard(const Card& card){
	cards.push_back(card);
	std::sort(cards.begin(), cards.end());
	}

void PlayerBase::SeeCards() const {
	for(int i = 0; i < cards.size(); ++i){
		std::cout << cards[i];
	}
	std::cout << std::endl;
}

bool  PlayerBase::FindCard(const Card& card) const{
	std::vector<Card>::const_iterator iter = cards.begin();
	for (; iter != cards.end(); ++iter){
		if(*iter == card){
			return true;
		}
	}
	return false;
}

bool PlayerBase::Empty()const{
	return cards.size() == 0;
}

std::string PlayerBase::GetName() const {
	return name;
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

void PlayerBase::SortCard(){
	sort(cards.begin(), cards.end());
}   


std::vector<Card> PlayerBase::GetCards() const{
	return cards;
}
