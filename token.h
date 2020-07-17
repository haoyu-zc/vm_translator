#pragma once
#include <unordered_map>
#include <string>

class Token
{
private:
    static const std::unordered_map<std::string, int> kwMap;

public:
    enum
    {
        // Command types begin
        A_COMMAND,
        C_COMMAND,
        L_COMMAND,
        C_ARITHMETIC,
        C_PUSH,
        C_POP,
        C_LABEL,
        C_GOTO,
        C_IF,
        C_FUNCTION,
        C_RETURN,
        C_CALL,
        // Command types end


        // Memory segments begin
        LOCAL,
        ARGUMENT,
        THIS,
        THAT,
        CONSTANT,
        STATIC,
        POINTER,
        TEMP,
        // Memory segments end


        // Opetaions begin
        ADD,
        SUB,
        NEG,
        EQ,
        GT,
        LT,
        AND,
        OR,
        NOT
        // Operations end
    };
    Token(/* args */);
    ~Token();
};

Token::Token(/* args */)
{
}

Token::~Token()
{
}
