#include "token.h"
#include <string>
#include <unordered_map>

const std::unordered_map<std::string, int> Token::kwMap{
    // Memory segments begin
    {"local", Token::LOCAL},
    {"argument", Token::ARGUMENT},
    {"this", Token::THIS},
    {"that", Token::THAT},
    {"constant", Token::CONSTANT},
    {"static", Token::STATIC},
    {"pointer", Token::POINTER},
    {"temp", Token::TEMP},
    // Memory segments end

    // Opetaions begin
    {"push", Token::PUSH},
    {"pop", Token::POP},
    {"add", Token::ADD},
    {"sub", Token::SUB},
    {"neg", Token::NEG},
    {"eq", Token::EQ},
    {"gt", Token::GT},
    {"lt", Token::LT},
    {"and", Token::AND},
    {"or", Token::OR},
    {"not", Token::NOT},
    // Operations end

    // Program control starts
    {"label", Token::LABEL},
    {"goto", Token::GOTO},
    {"if-goto", Token::IF},
    {"function", Token::FUNCTION},
    {"return", Token::RETURN},
    {"call", Token::CALL}
    // Program control ends

};

const std::unordered_map<int, const char *> Token::nameMap{
    // Memory segments begin
    {Token::LOCAL, "local"},
    {Token::ARGUMENT, "argument"},
    {Token::THIS, "this"},
    {Token::THAT, "that"},
    {Token::CONSTANT, "constant"},
    {Token::STATIC, "static"},
    {Token::POINTER, "pointer"},
    {Token::TEMP, "temp"},
    // Memory segments end

    // Opetaions begin
    {Token::PUSH, "push"},
    {Token::POP, "pop"},
    {Token::ADD, "add"},
    {Token::SUB, "sub"},
    {Token::NEG, "neg"},
    {Token::EQ, "eq"},
    {Token::GT, "gt"},
    {Token::LT, "lt"},
    {Token::AND, "and"},
    {Token::OR, "or"},
    {Token::NOT, "not"},
    // Operations end

    // Program control starts
    {Token::LABEL, "label"},
    {Token::GOTO, "goto"},
    {Token::IF, "if-goto"},
    {Token::FUNCTION, "function"},
    {Token::RETURN, "return"},
    {Token::CALL, "call"}
    // Program control ends

};

const std::unordered_map<int, int> Token::cmdTypeMap{
    {Token::ADD, Token::C_ARITHMETIC},
    {Token::SUB, Token::C_ARITHMETIC},
    {Token::NEG, Token::C_ARITHMETIC},
    {Token::EQ, Token::C_ARITHMETIC},
    {Token::GT, Token::C_ARITHMETIC},
    {Token::LT, Token::C_ARITHMETIC},
    {Token::AND, Token::C_ARITHMETIC},
    {Token::OR, Token::C_ARITHMETIC},
    {Token::NOT, Token::C_ARITHMETIC},

    {Token::PUSH, Token::C_PUSH},
    {Token::POP, Token::C_POP},
    {Token::LABEL, Token::C_LABEL},

    {Token::LABEL, Token::C_LABEL},
    {Token::GOTO, Token::C_GOTO},
    {Token::IF, Token::C_IF},
    {Token::FUNCTION, Token::C_FUNCTION},
    {Token::RETURN, Token::C_RETURN},
    {Token::CALL, Token::C_CALL}

};

Token::Token()
{
}

bool Token::hasKey(const std::string &s)
{
    if (kwMap.find(s) == kwMap.end())
        return false;
    else
        return true;
}

int Token::getToken(std::string &s)
{
    return kwMap.at(s);
}

int Token::getType(int token)
{
    return cmdTypeMap.at(token);
}

std::string Token::getName(int token)
{
    return nameMap.at(token);
}