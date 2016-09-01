#include "Card.h"

bool Card::CompareValue(const Card& left, const Card& right) {
	if(left.GetValue().compare(right.GetValue()) == 0) 
		return true;
return false;
}

bool Card::CompareSuit(const Card& left, const Card& right){
	if(left.GetSuit().compare(right.GetSuit()) == 0) 
		return true;
return false;
}

bool operator==(const Card& left, const Card& right){
	if(Card::CompareValue(left, right) && Card::CompareSuit(left, right)) {
		return true;
	}
	return false;
}

std::ostream& operator<<(std::ostream& out, const Card& card){
	out << card.GetValue()<< card.GetSuit()<< " ";
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



