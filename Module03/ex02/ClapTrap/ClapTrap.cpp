#include "../include/ClapTrap.hpp"
 
ClapTrap::ClapTrap(std::string name) : _name(name)
{
    std::cout << "Default constructor called with name: " << name << std::endl;
}

ClapTrap::~ClapTrap()
{
    std::cout << "Destructor called with name: " << _name << std::endl;
}

void ClapTrap::attack(std::string const &target)
{
    if(_hitpoints == 0)
        std::cout << "ClapTrap " << _name << " is dead and cannot attack" << std::endl;
    else if(_energyPoints <= 0)
        std::cout << "ClapTrap " << _name << " is out of energy and cannot attack" << std::endl;
    else
    {
        std::cout << "ClapTrap " << _name << " attacks " << target << ", dealing ";
        std::cout << _attackDamage << " points of damage!" << std::endl;
        _energyPoints -= 1;
    }
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if(_hitpoints == 0)
        std::cout << "ClapTrap " << _name << " is already dead" << std::endl;
    else if (amount >= _hitpoints)
    {
        if(amount > _hitpoints)
            amount = _hitpoints;
        _hitpoints = 0;
        std::cout << "ClapTrap " << _name << " took " << amount << " points of damage and died" << std::endl;
    }
    else 
    {
        _hitpoints -= amount;
        std::cout << "ClapTrap " << _name << " took " << amount << " points of damage!" << std::endl;
    }
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if(_hitpoints == 0)
        std::cout << "ClapTrap " << _name << " is dead and cannot be repaired" << std::endl;
    else if (_energyPoints == 0)
        std::cout << "ClapTrap " << _name << " is out of energy and cannot repair itself" << std::endl;
    else
    {
        _hitpoints += amount;
        std::cout << "ClapTrap " << _name << " was repaired for " << amount << " hit points!" << std::endl;
        _energyPoints -= 1;
    }
}
ClapTrap::ClapTrap(const ClapTrap &claptrap)
{
    _name = claptrap._name;
    _hitpoints = claptrap._hitpoints;
    _energyPoints = claptrap._energyPoints;
    _attackDamage = claptrap._attackDamage;
}

ClapTrap &ClapTrap::operator = (const ClapTrap &claptrap)
{
    _name = claptrap._name;
    _hitpoints = claptrap._hitpoints;
    _energyPoints = claptrap._energyPoints;
    _attackDamage = claptrap._attackDamage;
    return (*this);
}

