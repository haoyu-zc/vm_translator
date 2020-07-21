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
Parser::Parser(string vmfile, Token &token)
{
    //ifstream fin;
    fin.open(vmfile);
    tk = token;
}

void Parser::parse()
{
    istringstream line(currentCmd);
    tokens = {istream_iterator<string>{line},
              istream_iterator<string>{}};
    cmd = tokens[0];
    switch (command_type)
    {
    case Token::C_ARITHMETIC:
        arg1 = tokens[1];
        break;
    case Token::C_RETURN:
        cout << "error";
        break;
    case Token::C_PUSH || Token::C_POP || Token::C_FUNCTION || Token::C_CALL:
        arg1 = tokens[1];
        arg2 = tokens[2];
        break;
    default:
        break;
    }
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
    if (!tk.hasKey(cmd))
        return -1;
    else
    {
        int token = tk.getToken(cmd);
        cout << tk.getType(token) << " " << tk.getName(token) << endl;
        command_type = static_cast<Token::COMMAND_TYPE>(tk.getType(token));
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

void Parser::closeFstream()
{
    fin.close();
}
