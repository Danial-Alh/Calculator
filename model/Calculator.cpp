//
// Created by danial on 7/3/15.
//

#include "Calculator.h"

const int Calculator::NUMBER_OF_STATES = 5;
const int Calculator::NUMBER_OF_INPUT_TYPES = 5;

Calculator::Calculator()
{
    automata = new int*[NUMBER_OF_STATES];
    for( int i = 0; i < NUMBER_OF_STATES; i++ )
        automata[i] = new int[NUMBER_OF_INPUT_TYPES];
}
