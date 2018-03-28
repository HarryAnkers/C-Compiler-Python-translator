#ifndef ast_hpp
#define ast_hpp

#include <vector>
#include <string>

#include "ast/ast_ASTNode.hpp"
#include "ast/ast_Top_List.hpp"
#include "ast/ast_Dec_Function.hpp"
#include "ast/ast_Future_Func.hpp"
#include "ast/ast_Dec_Var_List.hpp"
#include "ast/ast_Statement.hpp"
#include "ast/ast_Body.hpp"
#include "ast/ast_Argument.hpp"
#include "ast/ast_ArgumentNoType.hpp"
#include "ast/ast_Conditions.hpp"
#include "ast/ast_Primitives.hpp"
#include "ast/ast_Operator.hpp"

extern const ASTNode *parseAST();

#endif
