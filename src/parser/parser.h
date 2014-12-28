#ifndef PARSER_H_
#define PARSER_H_ 1

/*

// non-terminals
<command>           ::= <instruction> <eol>

<instruction>       ::= <c-instruction> | <a-instruction> | <l-instruction>
<l-instruction>     ::= <l-paren> <symbol> <r-paren>
<c-instruction>     ::= <dest> <comp-mnemonic> <jump>
<a-instruction>     ::= <at> <symbol> | <at> <constant>

<dest>              ::= <dest-mnemonic> <equal> | <empty>
<jump>              ::= <semicolon> <jump-mnemonic> | <empty>

// terminals
<semicolon>         ::= ";"
<equal>
<l-paren>           ::= "("
<r-paren>           ::= ")"
<at>                ::= "@"
<empty>             ::= ""

<constant>          ::= "[\d]+"
<symbol>            ::= "[A-Za-z_.$:][\w_.$:]*"

<comp-mnemonic>     ::=
    "0" | "1" | "-1" | "D" | "A" | "!D" | "!A" | "-D" | "-A" |
    "D+1" | "A+1" | "D-1" | "A-1" | "D+A" | "D-A" | "A-D" |
    "D&A" | "D|A" | "M" | "!M" | "-M" | "M+1" | "M-1" | "D+M" |
    "D-M" | "M-D" | "D&M" | "D|M"

<jump-mnemonic>     ::=
    "JGT" | "JEQ" | "JGE" | "JLT" | "JNE" | "JLE" | "JMP"

<dest-mnemonic>     ::=
    "M" | "D" | "MD" | "A" | "AM" | "AD" | "AMD"

*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

enum state {
    START,
    END
};

enum state transition(enum state current_state, char c);

#endif // PARSER_H_
