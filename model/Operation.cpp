//
// Created by danial on 7/6/15.
//

#include "Operation.h"



Operation::Operation()
{
}

int Operation::getFirstOperand()
{
    return operand[0];
}

int Operation::getSecondOperand()
{
    return operand[1];
}

OPERATION_MODE &Operation::getOperation_mode()
{
    return operation_mode;
}

int Operation::getResult()
{
    return result;
}

void Operation::setOperation_mode(const OPERATION_MODE &operation_mode)
{
    Operation::operation_mode = operation_mode;
}

void Operation::setResult(int result)
{
    Operation::result = result;
}

void Operation::setFirstOperand(int number)
{
    operand[0] = number;
}

void Operation::setSecondOperand(int number)
{
    operand[1] = number;
}

void Operation::calculate_result()
{
    switch (operation_mode)
    {
        case OPERATION_MODE::ADD:
            result = operand[0] + operand[1];
            break;
        case OPERATION_MODE::SUB:
            result = operand[0] - operand[1];
            break;
        case OPERATION_MODE::MULTIPLY:
            result = operand[0] * operand[1];
            break;
        case OPERATION_MODE::DIVIDE:
            result = operand[0] / operand[1];
            break;
    }

}
