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
    std::string input_filename;
    std::string currentCmdLine;
    int command_type;
    int cmd = -1;
    int arg1 = -1;
    int arg2 = -1;

    // Load the assembly file in commnad line argument
    Parser(std::string asmFile, Token &token);

    // Parse command into seperate fields.
    void parse();

    // Is there more commands in the asm file?
    bool hasMoreCommands();

    // Load next command and set it as "current" command.
    void advance();

    // Return the type of the current command, including
    // A_COMMAND, C_COMMAND, and L_COMMAND.
    int commandType();

    void closeFstream();
};
