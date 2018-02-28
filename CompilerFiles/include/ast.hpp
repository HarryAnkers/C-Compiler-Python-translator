#ifndef ast_hpp
#define ast_hpp

#include "ast/ast_ASTNode.hpp"
#include "ast/ast_Function_List.hpp"
#include "ast/ast_Dec_Function.hpp"
#include "ast/ast_Statement.hpp"
#include "ast/ast_Body.hpp"
#include "ast/ast_Argument.hpp"
#include "ast/ast_ArgumentNoType.hpp"
#include "ast/ast_IfElseList.hpp"
#include "ast/ast_Conditions.hpp"
#include "ast/ast_Primitives.hpp"
#include "ast/ast_Operator.hpp"

extern const ASTNode *parseAST();

#endif
