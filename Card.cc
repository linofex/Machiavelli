#include "Card.h"


bool Card::CompareValue(const Card& left, const Card& right) {
	if(left.GetValue() == right.GetValue()) {
		return true;
	}
	return false;
}

bool Card::CompareSuit(const Card& left, const Card& right){
	if(left.GetSuit() == right.GetSuit()) { 
		return true;
	}
	return false;
}

bool operator==(const Card& left, const Card& right){
	if(Card::CompareValue(left, right) && Card::CompareSuit(left, right)) {
		return true;
	}
	return false;
}

std::ostream& operator<<(std::ostream& out, const Card& card){
	std::string utf8;
	if(card.GetSuit() == "f"){ utf8 = "\u2663";}
	else if(card.GetSuit() == "p") {utf8 = "\u2660";}
	else if(card.GetSuit() == "c") {utf8 = "\u2665";}
	else if(card.GetSuit() == "q"){utf8 = "\u2666";}
	else {utf8 = card.GetSuit();}
	out << card.GetValue() << utf8 << " ";
	return out;
}


bool operator<(const Card& left, const Card& right){
	if(left.GetIntValue() == right.GetIntValue()){
		return (left.GetSuit() < right.GetSuit());
	}
	else{
		return left.GetIntValue() < right.GetIntValue();
	}
}



