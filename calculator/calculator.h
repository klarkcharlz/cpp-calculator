#pragma once

enum class Operation {
    Plus,
    Minus,
    Multiply,
    Divide,
    Quit,
    Pow,
    Set,
    Clear,
    Print,
    Save,
    Load
};

using Number = double;

bool ReadNumber(Number& number);
bool ReadOperation(Operation& operation);
bool RunCalculatorCycle();
