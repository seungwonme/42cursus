#include <iostream>
#include "HumanA.hpp"

HumanA::HumanA(const std::string& name, const Weapon& weapon)
{
	mName = name;
	mWeapon = &weapon;
}

void	HumanA::attack(void) const
{
	std::cout << mName << " attacks with their " << mWeapon->getType() << std::endl;
}
