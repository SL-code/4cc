
// TOP

#ifndef FCPP_LEXER_TYPES_INC
#define FCPP_LEXER_TYPES_INC

#ifndef ENUM
#define ENUM(type,name) typedef type name; enum name##_
#endif

/* DOC(A Cpp_Token_Type classifies a token to make parsing easier. Some types are not
actually output by the lexer, but exist because parsers will also make use of token
types in their own output.) */
ENUM(uint32_t, Cpp_Token_Type){
	CPP_TOKEN_JUNK,
	CPP_TOKEN_COMMENT,
    
	CPP_PP_INCLUDE,
	CPP_PP_DEFINE,
	CPP_PP_UNDEF,
	CPP_PP_IF,
	CPP_PP_IFDEF,
	CPP_PP_IFNDEF,
	CPP_PP_ELSE,
	CPP_PP_ELIF,
	CPP_PP_ENDIF,
	CPP_PP_ERROR,
	CPP_PP_IMPORT,
	CPP_PP_USING,
	CPP_PP_LINE,
	CPP_PP_PRAGMA,
	CPP_PP_STRINGIFY,
	CPP_PP_CONCAT,
	CPP_PP_UNKNOWN,
    
	CPP_TOKEN_KEY_TYPE,
	CPP_TOKEN_KEY_MODIFIER,
	CPP_TOKEN_KEY_QUALIFIER,
    /* DOC(This type is not stored in token output from the lexer.) */
	CPP_TOKEN_KEY_OPERATOR,
	CPP_TOKEN_KEY_CONTROL_FLOW,
    CPP_TOKEN_KEY_CAST,
	CPP_TOKEN_KEY_TYPE_DECLARATION,
	CPP_TOKEN_KEY_ACCESS,
	CPP_TOKEN_KEY_LINKAGE,
	CPP_TOKEN_KEY_OTHER,
    
	CPP_TOKEN_IDENTIFIER,
	CPP_TOKEN_INTEGER_CONSTANT,
	CPP_TOKEN_CHARACTER_CONSTANT,
	CPP_TOKEN_FLOATING_CONSTANT,
	CPP_TOKEN_STRING_CONSTANT,
	CPP_TOKEN_BOOLEAN_CONSTANT,
    
    CPP_TOKEN_STATIC_ASSERT,
    
	CPP_TOKEN_BRACKET_OPEN,
	CPP_TOKEN_BRACKET_CLOSE,
	CPP_TOKEN_PARENTHESE_OPEN,
	CPP_TOKEN_PARENTHESE_CLOSE,
	CPP_TOKEN_BRACE_OPEN,
	CPP_TOKEN_BRACE_CLOSE,
    CPP_TOKEN_SEMICOLON,
    CPP_TOKEN_ELLIPSIS,
    
    /* DOC(This is an 'ambiguous' token type because it requires
    parsing to determine the full nature of the token.) */
	CPP_TOKEN_STAR,
    
    /* DOC(This is an 'ambiguous' token type because it requires
    parsing to determine the full nature of the token.) */
	CPP_TOKEN_AMPERSAND,
    
    /* DOC(This is an 'ambiguous' token type because it requires
    parsing to determine the full nature of the token.) */
	CPP_TOKEN_TILDE,
    
    /* DOC(This is an 'ambiguous' token type because it requires
    parsing to determine the full nature of the token.) */
	CPP_TOKEN_PLUS,
    
    /* DOC(This is an 'ambiguous' token type because it requires
    parsing to determine the full nature of the token.) */
	CPP_TOKEN_MINUS,
    
    /* DOC(This is an 'ambiguous' token type because it requires
    parsing to determine the full nature of the token.) */
	CPP_TOKEN_INCREMENT,
    
    /* DOC(This is an 'ambiguous' token type because it requires
    parsing to determine the full nature of the token.) */
	CPP_TOKEN_DECREMENT,
    
    // NOTE(allen): Precedence 1, LtoR
	CPP_TOKEN_SCOPE,
    
    // NOTE(allen): Precedence 2, LtoR
    /* DOC(This type is for parser use, it is not output by the lexer.) */
    CPP_TOKEN_POSTINC,
    /* DOC(This type is for parser use, it is not output by the lexer.) */
    CPP_TOKEN_POSTDEC,
    /* DOC(This type is for parser use, it is not output by the lexer.) */
    CPP_TOKEN_FUNC_STYLE_CAST,
    CPP_TOKEN_CPP_STYLE_CAST,
    /* DOC(This type is for parser use, it is not output by the lexer.) */
    CPP_TOKEN_CALL,
    /* DOC(This type is for parser use, it is not output by the lexer.) */
    CPP_TOKEN_INDEX,
	CPP_TOKEN_DOT,
	CPP_TOKEN_ARROW,
    
    // NOTE(allen): Precedence 3, RtoL
    
    /* DOC(This token is for parser use, it is not output by the lexer.) */
    CPP_TOKEN_PREINC,
    /* DOC(This token is for parser use, it is not output by the lexer.) */
    CPP_TOKEN_PREDEC,
    /* DOC(This token is for parser use, it is not output by the lexer.) */
    CPP_TOKEN_POSITIVE,
    /* DOC(This token is for parser use, it is not output by the lexer.) */
    CPP_TOKEN_NEGAITVE,
	CPP_TOKEN_NOT,
    
    /* DOC(This type is for parser use, it is not output by the lexer.) */
    CPP_TOKEN_BIT_NOT,
    
    /* DOC(This type is for parser use, it is not output by the lexer.) */
    CPP_TOKEN_CAST,
    /* DOC(This type is for parser use, it is not output by the lexer.) */
    CPP_TOKEN_DEREF,
    /* DOC(This type is for parser use, it is not output by the lexer.) */
    CPP_TOKEN_TYPE_PTR,
    /* DOC(This type is for parser use, it is not output by the lexer.) */
    CPP_TOKEN_ADDRESS,
    /* DOC(This type is for parser use, it is not output by the lexer.) */
    CPP_TOKEN_TYPE_REF,
    CPP_TOKEN_SIZEOF,
    CPP_TOKEN_ALIGNOF,
    CPP_TOKEN_DECLTYPE,
    CPP_TOKEN_TYPEID,
    CPP_TOKEN_NEW,
    CPP_TOKEN_DELETE,
    /* DOC(This type is for parser use, it is not output by the lexer.) */
    CPP_TOKEN_NEW_ARRAY,
    /* DOC(This type is for parser use, it is not output by the lexer.) */
    CPP_TOKEN_DELETE_ARRAY,
    
    // NOTE(allen): Precedence 4, LtoR
	CPP_TOKEN_PTRDOT,
	CPP_TOKEN_PTRARROW,
    
    // NOTE(allen): Precedence 5, LtoR
    
    /* DOC(This type is for parser use, it is not output by the lexer.) */
	CPP_TOKEN_MUL,
	CPP_TOKEN_DIV,
	CPP_TOKEN_MOD,
    
    // NOTE(allen): Precedence 6, LtoR
    
    /* DOC(This type is for parser use, it is not output by the lexer.) */
    CPP_TOKEN_ADD,
    
    /* DOC(This type is for parser use, it is not output by the lexer.) */
    CPP_TOKEN_SUB,
    
    // NOTE(allen): Precedence 7, LtoR
	CPP_TOKEN_LSHIFT,
	CPP_TOKEN_RSHIFT,
    
    // NOTE(allen): Precedence 8, LtoR
	CPP_TOKEN_LESS,
	CPP_TOKEN_GRTR,
	CPP_TOKEN_GRTREQ,
	CPP_TOKEN_LESSEQ,
    
    // NOTE(allen): Precedence 9, LtoR
    CPP_TOKEN_EQEQ,
    CPP_TOKEN_NOTEQ,
    
    // NOTE(allen): Precedence 10, LtoR
    
    /* DOC(This type is for parser use, it is not output by the lexer.) */
	CPP_TOKEN_BIT_AND,
    
    // NOTE(allen): Precedence 11, LtoR
	CPP_TOKEN_BIT_XOR,
    
    // NOTE(allen): Precedence 12, LtoR
	CPP_TOKEN_BIT_OR,
    
    // NOTE(allen): Precedence 13, LtoR
	CPP_TOKEN_AND,
    
    // NOTE(allen): Precedence 14, LtoR
	CPP_TOKEN_OR,
    
    // NOTE(allen): Precedence 15, RtoL
    CPP_TOKEN_TERNARY_QMARK,
	CPP_TOKEN_COLON,
    CPP_TOKEN_THROW,
	CPP_TOKEN_EQ,
	CPP_TOKEN_ADDEQ,
	CPP_TOKEN_SUBEQ,
	CPP_TOKEN_MULEQ,
	CPP_TOKEN_DIVEQ,
	CPP_TOKEN_MODEQ,
	CPP_TOKEN_LSHIFTEQ,
	CPP_TOKEN_RSHIFTEQ,
	CPP_TOKEN_ANDEQ,
	CPP_TOKEN_OREQ,
	CPP_TOKEN_XOREQ,
    
    // NOTE(allen): Precedence 16, LtoR
	CPP_TOKEN_COMMA,
    
    CPP_TOKEN_DEFINED,
	CPP_TOKEN_INCLUDE_FILE,
    CPP_TOKEN_ERROR_MESSAGE,
    
    /* DOC(This type is for parser use, it is not output by the lexer.) */
    CPP_TOKEN_EOF,
    
    CPP_TOKEN_TYPE_COUNT
};

struct Cpp_Token{
	Cpp_Token_Type type;
    int32_t start, size;
    uint16_t state_flags;
    uint16_t flags;
};

ENUM(uint16_t, Cpp_Token_Flag){
	CPP_TFLAG_IGNORE = 0x1,
	CPP_TFLAG_PP_DIRECTIVE = 0x2,
	CPP_TFLAG_PP_BODY = 0x4,
	CPP_TFLAG_BAD_ENDING = 0x8,
	CPP_TFLAG_MULTILINE = 0x10,
    CPP_TFLAG_PARAMETERIZED = 0x20,
    CPP_TFLAG_IS_OPERATOR = 0x40,
    CPP_TFLAG_IS_KEYWORD = 0x80
};

ENUM(uint16_t, Cpp_Preprocessor_State){
	CPP_LEX_PP_DEFAULT,
	CPP_LEX_PP_IDENTIFIER,
	CPP_LEX_PP_MACRO_IDENTIFIER,
	CPP_LEX_PP_INCLUDE,
	CPP_LEX_PP_BODY,
	CPP_LEX_PP_BODY_IF,
	CPP_LEX_PP_NUMBER,
    CPP_LEX_PP_ERROR,
	CPP_LEX_PP_JUNK,
	CPP_LEX_PP_COUNT
};

struct Cpp_Token_Stack{
	Cpp_Token *tokens;
	int32_t count, max_count;
};
static Cpp_Token_Stack null_cpp_token_stack = {0};

struct Cpp_Get_Token_Result{
	int32_t token_index;
	int32_t in_whitespace;
};

struct Cpp_Relex_State{
    char *data;
    int32_t size;
    
    Cpp_Token_Stack *stack;
    int32_t start, end, amount;
    int32_t start_token_i;
    int32_t end_token_i;
    int32_t relex_start;
    int32_t tolerance;
    int32_t space_request;
};

#endif

// BOTTOM
