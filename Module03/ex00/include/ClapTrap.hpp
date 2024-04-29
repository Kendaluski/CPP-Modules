#ifndef CLAPTRAP_HPP
 # define CLAPTRAP_HPP

# include <iostream>

class ClapTrap
{
    private:
        std::string _name;
        unsigned int _hitpoints = 10;
        unsigned int _energyPoints = 10;
        unsigned int _attackDamage = 10;
    public:
        ClapTrap(std::string name);
        void attack(std::string const & target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
        ~ClapTrap();
};
 
#endif