#ifndef FRAGTRAP_HPP
 # define FRAGTRAP_HPP

# include <iostream>
#include "ScavTrap.hpp"

class FragTrap : public ClapTrap
{
    private:
    public:
        FragTrap(std::string name);
        ~FragTrap();
        void highFivesGuys(void);
};
 
 
#endif