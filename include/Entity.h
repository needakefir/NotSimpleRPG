#pragma once
#include <string>
class Entity {
	public:
		Entity(int hp,std::string& name);
		int getHP() const;
		void setHP(int hp);
		bool getDefeated();
		void setName(std::string& name) ;
		std::string& getName();
		friend std::ostream& operator<<(std::ostream& out, Entity& e);
	protected:	
		int Entity_HP;
		std::string E_Name;
};