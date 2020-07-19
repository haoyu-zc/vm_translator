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
    {"not", Token::NOT}};

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
    {Token::NOT, "not"}};

const std::unordered_map<int, int> Token::cmdTypeMap{
    {Token::ADD, Token::COMMAND_TYPE::C_ARITHMETIC},
    {Token::SUB, Token::COMMAND_TYPE::C_ARITHMETIC},
    {Token::NEG, Token::COMMAND_TYPE::C_ARITHMETIC},
    {Token::EQ, Token::COMMAND_TYPE::C_ARITHMETIC},
    {Token::GT, Token::COMMAND_TYPE::C_ARITHMETIC},
    {Token::LT, Token::COMMAND_TYPE::C_ARITHMETIC},
    {Token::AND, Token::COMMAND_TYPE::C_ARITHMETIC},
    {Token::OR, Token::COMMAND_TYPE::C_ARITHMETIC},
    {Token::NOT, Token::COMMAND_TYPE::C_ARITHMETIC},

    {Token::PUSH, Token::COMMAND_TYPE::C_PUSH},
    {Token::POP, Token::COMMAND_TYPE::C_POP}};

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