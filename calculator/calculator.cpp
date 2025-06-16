#include <iostream>
#include <string>
#include <cmath>

#include "calculator.h"


bool RunCalculatorCycle() {
    if (Number number = 0; !ReadNumber(number)) {
        return false;
    } else {
        Number result = 0;
        Number memory_cell = 0;
        bool memory_set = false; // флаг по которому будем определять была ли загрузка в ячейку памяти хоть раз
        Operation operation = Operation::Quit;
        result = number;

        while(true) {
            if (!ReadOperation(operation)) return false;

            switch(operation) {
                case Operation::Quit:
                    return true;
                case Operation::Plus:
                    if (ReadNumber(number)) result += number;
                    else return true;
                    break;
                case Operation::Minus:
                    if (ReadNumber(number)) result -= number;
                    else return false;
                    break;
                case Operation::Divide:
                    if (ReadNumber(number)) result /= number;
                    else return false;
                    break;
                case Operation::Pow:
                    if (ReadNumber(number)) result = std::pow(result, number);
                    else return false;
                    break;
                case Operation::Multiply:
                    if (ReadNumber(number)) result *= number;
                    else return false;
                    break;
                case Operation::Set:
                    if (ReadNumber(number)) result = number;
                    else return false;
                    break;
                case Operation::Print:
                    std::cout << result << std::endl;
                    break;
                case Operation::Clear:
                    result = 0;
                    break;
                case Operation::Save:
                    memory_cell = result;
                    memory_set = true;
                    break;
                case Operation::Load:
                    if (memory_set) result = memory_cell;
                    else {
                        std::cerr << "Error: Memory is empty" << std::endl;
                        return false;
                    }
                    break;
                default: break;
            }
        }
    }
}

bool ReadNumber(Number& number) {
    if (!(std::cin >> number)) {
        std::cerr << "Error: Numeric operand expected" << std::endl;
        return false;
    }
    return true;
}

bool ReadOperation(Operation& operation) {
    std::string op;
    std::cin >> op;
    if (op == "q") operation = Operation::Quit;
    else if (op == "+") operation = Operation::Plus;
    else if (op == "-") operation = Operation::Minus;
    else if (op == "*") operation = Operation::Multiply;
    else if (op == "/") operation = Operation::Divide;
    else if (op == "**") operation = Operation::Pow;
    else if (op == ":") operation = Operation::Set;
    else if (op == "c") operation = Operation::Clear;
    else if (op == "=") operation = Operation::Print;
    else if (op == "s") operation = Operation::Save;
    else if (op == "l") operation = Operation::Load;
    else {
        std::cerr << "Error: Unknown token " << op << std::endl;
        return false;
    }
    return true;
}