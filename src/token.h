#pragma once
#include <unordered_map>
#include <string>

class Token
{
private:
    static const std::unordered_map<std::string, int> kwMap;
    static const std::unordered_map<int, int> cmdTypeMap;
    static const std::unordered_map<int, const char*> nameMap;

public:
    Token(/* args */);
    bool hasKey(const std::string &s);
    int getToken(std::string &s);
    int getType(int token);
    std::string getName(int token);
    enum COMMAND_TYPE
    {
        C_ARITHMETIC,
        C_PUSH,
        C_POP,
        C_LABEL,
        C_GOTO,
        C_IF,
        C_FUNCTION,
        C_RETURN,
        C_CALL
    };

    enum
    {
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
        PUSH,
        POP,
        ADD,
        SUB,
        NEG,
        EQ,
        GT,
        LT,
        AND,
        OR,
        NOT,
        // Operations end

        // Program control begins
        LABEL,
        GOTO,
        IF,
        FUNCTION,
        RETURN,
        CALL
        // Program control ends
    };
};
