#ifndef DOG_HPP
 # define DOG_HPP

# include <iostream>
# include "Animal.hpp"

class Dog : public Animal
{
    private:
    public:
        Dog();
        Dog(const Dog &dog);
        virtual ~Dog();
        void makeSound() const;
        Dog & operator = (const Dog &dog);
};
 
std::ostream & operator << (std::ostream &out, const Dog &dog);
 
#endif