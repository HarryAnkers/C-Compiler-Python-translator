#ifndef ast_hpp
#define ast_hpp

#include "ast/ast_expression.hpp"
#include "ast/ast_primitives.hpp"
#include "ast/ast_operators.hpp"
#include "ast/ast_functions.hpp"

#include "ast/ast_MainBody.hpp"
#include "ast/ast_Function.hpp"
#include "ast/ast_Statement.hpp"
#include "ast/ast_Body.hpp"

extern const MainBody *parseAST();
//extern const Expression *parseAST();

#endif
