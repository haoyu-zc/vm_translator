// Cleaner representation of ifndef...
#pragma once
#include <string>
#include <fstream>

using std::endl;
using std::ifstream;
using std::string;

// Or use constexpr int A_COMMAND = 1; ? 
static const int A_COMMAND = 1;
static const int C_COMMAND = 2;
static const int L_COMMAND = 3;

class Parser
{
private:
    ifstream fin;
    string removeSpaces(string str);

public:
    string currentCmd;

    // Load the assembly file in commnad line argument
    Parser(string asmFile);

    // Output a trimed file(no empty lines and comments).
    void trim();

    // Is there more commands in the asm file?
    bool hasMoreCommands();

    // Load next command and set it as "current" command.
    void advance();

    // Return the type of the current command, including
    // A_COMMAND, C_COMMAND, and L_COMMAND.
    int commandType();

    // Return the symbol or decimal Xxx of the current command @Xxx or (Xxx).
    // Should be called only when command_type is A_COMMAND or L_COMMAND.
    string symbol();

    // Return the comp mnemonic in the current C-command (28 possibilities).
    // Should be called only when command_type is C_COMMAND.
    string comp();

    // Return the dest mnemonic in the current C-command (8 possibilities).
    // Should be called only when command_type is C_COMMAND.
    string dest();

    // Return the jump mnemonic in the current C-command (8 possibilities).
    // Should be called only when command_type is C_COMMAND.
    string jump();
};
