#include <iostream>
#include <fstream>
#include <string>
#include "parser.h"
#include <regex>
#include <algorithm>
#include "utils.h"
#include "token.h"

using namespace std;

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
        if (commandType() == Token::A_COMMAND)
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

void Parser::parse(Token &token)
{
    this->tk = token;
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
    string line;
    getline(fin, line);
    line = removeComments(line);
    line = trimOuterSpaces(line);
    // Skip empty line(s) after removing comments and triming.
    while (line.empty())
    {
        getline(fin, line);
        line = removeComments(line);
        line = trimOuterSpaces(line);
    }
    currentCmd = line;
}

int Parser::commandType()
{
    istringstream line(currentCmd);
    string first_word;
    line >> first_word;
    if (!tk.hasKey(first_word))
        return -1;
    else
    {
        int token = tk.getToken(first_word);
        cout << tk.getType(token) << endl;
        return tk.getType(token);
    }
}

string Parser::symbol()
{
    string pattern = "\\(([^)]+)\\)";
    regex r(pattern);
    smatch result;
    if (commandType() == Token::A_COMMAND)
        return currentCmd.substr(1);
    else if (commandType() == Token::L_COMMAND)
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
    if (commandType() != tk.C_COMMAND)
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
    if (commandType() != Token::C_COMMAND)
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
