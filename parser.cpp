#include <iostream>
#include <fstream>
#include <string>
#include "parser.h"
#include <regex>
#include <algorithm>

using namespace std;

// Function to remove all spaces from a given string
// string Parser::removeSpaces(string input)
// {
//     input.erase(std::remove(input.begin(), input.end(), ' '), input.end());
//     return input;
// }

// Private fuctions
void Parser::trim()
{
    ofstream fout;
    fout.open("trimedFile.asm");

    string command;

    while (hasMoreCommands())
    {
        advance();
        command = currentCmd;

        /* hasMoreCommarnd() test */
        cout << command + " has more commands? " << boolalpha << hasMoreCommands() << endl;
        cout << commandType() << endl;

        /* symbol() test */
        if (commandType() == A_COMMAND)
            cout << symbol() << endl;

        fout << command << endl;
    }
    fin.close();
    fout.close();
}

// Public functions
Parser::Parser(string vmfile)
{
    //ifstream fin;
    fin.open(vmfile);
}

bool Parser::hasMoreCommands()
{
    if (fin.peek() != EOF)
        return true;
    else
        return false;
}

// Variables for advance()
void Parser::advance()
{
    // Remove "//" comments and spaces in the front.
    string pattern_comt = "\\W*//.+";
    regex r_comt(pattern_comt);
    string fmt = "";
    string line;
    getline(fin, line);
    line = regex_replace(line, r_comt, fmt);
    // line = removeSpaces(line);
    // Skip empty lines after removing comments.
    while (line.empty())
    {
        getline(fin, line);
        line = regex_replace(line, r_comt, fmt);
        //line = removeSpaces(line);
    }
    currentCmd = line;
}

int Parser::commandType()
{
    istringstream line(currentCmd);
    string first_word;
    line >> first_word;
    if (first_word == "push")
        cout << first_word + ".type = push." << endl;
    return 1;
}

string Parser::symbol()
{
    string pattern = "\\(([^)]+)\\)";
    regex r(pattern);
    smatch result;
    if (commandType() == A_COMMAND)
        return currentCmd.substr(1);
    else if (commandType() == L_COMMAND)
    {
        regex_search(currentCmd, result, r);
        return result.str(1);
    }
    else
        throw runtime_error("Not a A or L command!");
}

string Parser::comp()
{
    // Judge whether the current command is a C-Command.
    if (commandType() != C_COMMAND)
        throw runtime_error("Not a C command!");
    else
    {
        // Return the comp field
        // Parse command such as "0;JEQ"
        int semiPos = currentCmd.find(';');
        if (semiPos != string::npos)
            // If there is a jump field, return the chars before ";" for comp field.
            return currentCmd.substr(0, semiPos);
        else
        {
            // Parse command such as "D=A"
            int eqPos = currentCmd.find('=');
            return currentCmd.substr(eqPos + 1);
        }
    }
}

string Parser::dest()
{
    // Check whether the current command is a C-Command.
    if (commandType() != C_COMMAND)
        throw runtime_error("Not a C command!");
    else
    {
        // Check whether there is a dest field.
        int eqPos = currentCmd.find("=");
        if (eqPos != string::npos)
            return currentCmd.substr(0, eqPos);
        else
            return "null";
    }
}

string Parser::jump()
{
    int semiPos = currentCmd.find(';');
    if (semiPos != string::npos)
        // If there is a jump field, return the chars before ";" for comp field.
        return currentCmd.substr(semiPos + 1);
    else
        return "null";
}
