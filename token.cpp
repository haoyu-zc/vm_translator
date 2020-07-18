#include "token.h"
#include <string>
#include <unordered_map>

const std::unordered_map<std::string, int> Token::kwMap {
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
        {"not", Token::NOT}
};