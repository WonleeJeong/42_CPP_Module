#include "Weapon.hpp"

class HumanB
{
	private:
		std::string name;
		Weapon *Weapon_name;
	public:
		void	attack();
		void	setWeapon(Weapon &w_name);
		HumanB(std::string nm);
		~HumanB(void);
};