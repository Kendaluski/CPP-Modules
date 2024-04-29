#ifndef CLAPTRAP_HPP
 # define CLAPTRAP_HPP

# include <iostream>

class ClapTrap
{
    protected:
        std::string _name;
        unsigned int _hitpoints;
        unsigned int _energyPoints;
        unsigned int _attackDamage;
    public:
        ClapTrap(std::string name);
        void attack(std::string const & target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
        ClapTrap(const ClapTrap &claptrap);
        ~ClapTrap();
        ClapTrap & operator = (const ClapTrap &claptrap);
};
 
#endif