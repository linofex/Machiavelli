#include "PlayerBase.h"
#include <iostream>


void PlayerBase::AddCard(const std::string& card){
	cards.push_back(card);
	}

void PlayerBase::SeeCards(){
	for(int i = 0; i < cards.size(); ++i){
		std::cout << cards[i]<< ' ';
	}
	std::cout<<std::endl;
}

void PlayerBase::Move(){}

bool PlayerBase::Empty(){
	return cards.size() == 0;
}
	
