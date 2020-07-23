// Cleaner representation of ifndef...
#pragma once
#include <string>
#include <fstream>
#include <vector>
#include "token.h"


class Parser
{
private:
    std::ifstream fin;
    std::string removeSpaces(std::string str);
    Token tk;
    std::vector<std::string> str_frags;

public:
    std::string currentCmdLine;
    Token::COMMAND_TYPE command_type;
    int cmd;
    int arg1;
    int arg2;

    // Load the assembly file in commnad line argument
    Parser(std::string asmFile, Token &token);

    // Output a trimed file(no empty lines and comments).
    void trim();

    // Parse command into seperate fields.
    void parse();

    // Is there more commands in the asm file?
    bool hasMoreCommands();

    // Load next command and set it as "current" command.
    void advance();

    // Return the type of the current command, including
    // A_COMMAND, C_COMMAND, and L_COMMAND.
    int commandType();

    // Return the symbol or decimal Xxx of the current command @Xxx or (Xxx).
    // Should be called only when command_type is A_COMMAND or L_COMMAND.
    std::string symbol();

    // Return the comp mnemonic in the current C-command (28 possibilities).
    // Should be called only when command_type is C_COMMAND.
    std::string comp();

    // Return the dest mnemonic in the current C-command (8 possibilities).
    // Should be called only when command_type is C_COMMAND.
    std::string dest();

    // Return the jump mnemonic in the current C-command (8 possibilities).
    // Should be called only when command_type is C_COMMAND.
    std::string jump();

    void closeFstream();
};
