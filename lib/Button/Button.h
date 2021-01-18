#ifndef BUTTON
#define BUTTON
#include <Arduino.h>

class Button
{
    int pin;
    int cpt;
    int lastval=0;
    unsigned long int j;


public:
    Button(int);

    // Méthodes
    void check();
    int getNumber();
};


#endif