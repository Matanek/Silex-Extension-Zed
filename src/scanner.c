#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <tree_sitter/parser.h>

enum TokenType {
    AUTOMATIC_SEMICOLON,
    TRY_ELSE_CONTINUATION,
};

static bool is_identifier_character(int32_t character) {
    return
        (character >= 'A' && character <= 'Z') ||
        (character >= 'a' && character <= 'z') ||
        (character >= '0' && character <= '9') ||
        character == '_';
}

static bool next_token_is_else(TSLexer* lexer) {
    const char keyword[] = "else";
    for (const char* character = keyword; *character != '\0'; character += 1) {
        if (lexer->lookahead != *character) return false;
        lexer->advance(lexer, false);
    }
    return !is_identifier_character(lexer->lookahead);
}

void* tree_sitter_silex_external_scanner_create(void) {
    return NULL;
}

void tree_sitter_silex_external_scanner_destroy(void* payload) {
    (void)payload;
}

unsigned tree_sitter_silex_external_scanner_serialize(void* payload, char* buffer) {
    (void)payload;
    (void)buffer;
    return 0;
}

void tree_sitter_silex_external_scanner_deserialize(
    void* payload,
    const char* buffer,
    unsigned length
) {
    (void)payload;
    (void)buffer;
    (void)length;
}

bool tree_sitter_silex_external_scanner_scan(
    void* payload,
    TSLexer* lexer,
    const bool* valid_symbols
) {
    (void)payload;
    if (
        !valid_symbols[AUTOMATIC_SEMICOLON] &&
        !valid_symbols[TRY_ELSE_CONTINUATION]
    ) return false;

    lexer->mark_end(lexer);
    while (lexer->lookahead == ' ' || lexer->lookahead == '\t' || lexer->lookahead == '\r') {
        lexer->advance(lexer, true);
    }

    if (lexer->lookahead == '\n') {
        do {
            lexer->advance(lexer, true);
        } while (
            lexer->lookahead == ' ' || lexer->lookahead == '\t' ||
            lexer->lookahead == '\r' || lexer->lookahead == '\n'
        );
        lexer->mark_end(lexer);
        if (
            valid_symbols[TRY_ELSE_CONTINUATION] &&
            lexer->lookahead == 'e' &&
            next_token_is_else(lexer)
        ) {
            lexer->result_symbol = TRY_ELSE_CONTINUATION;
            return true;
        }
        if (!valid_symbols[AUTOMATIC_SEMICOLON]) return false;
        if (lexer->lookahead == '.') {
            lexer->advance(lexer, false);
            if (lexer->lookahead == '.') return false;
        }
        lexer->result_symbol = AUTOMATIC_SEMICOLON;
        return true;
    }

    if (
        valid_symbols[AUTOMATIC_SEMICOLON] &&
        (lexer->lookahead == '}' || lexer->eof(lexer))
    ) {
        lexer->result_symbol = AUTOMATIC_SEMICOLON;
        return true;
    }

    return false;
}
