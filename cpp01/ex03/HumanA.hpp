#include "Weapon.hpp"

class HumanA
{
	private:
		std::string name;
		Weapon &Weapon_name;
	public:
		void	attack(void);
		void	setWeapon(Weapon w_name);
		HumanA(std::string nm, Weapon &w_name);
		~HumanA(void);
};