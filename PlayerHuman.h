#include "PlayerBase.h"

class PlayerHuman : public PlayerBase {
	public:
		PlayerHuman():PlayerBase(){}
		PlayerHuman(const std::string& name_):PlayerBase(name_){}
};
	
