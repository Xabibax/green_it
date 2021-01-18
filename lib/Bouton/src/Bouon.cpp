#include <Bouton.h>

class Bouton
{
    Bouton::Bouton(int _press) {
        this->nbPress = _press;
    }
    // Méthodes
    int Bouton::getNumber()
    {
        int res = this->nbPress;
        this->nbPress = 0;
        return this->nbPress;
    }
    void Bouton::check()
    {
        this->nbPress++;
    }

    // Attributs
    int Bouton::nbPress = 0;    
};