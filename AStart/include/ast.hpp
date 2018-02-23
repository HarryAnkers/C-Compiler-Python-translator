#ifndef ast_hpp
#define ast_hpp

#include "ast/ast_Expression.hpp"
#include "ast/ast_Primitives.hpp"
#include "ast/ast_Operator.hpp"
#include "ast/ast_Function_maths.hpp"

#include "ast/ast_MainBody.hpp"
#include "ast/ast_Function.hpp"
#include "ast/ast_Function_List.hpp"
#include "ast/ast_Statement.hpp"
#include "ast/ast_Body.hpp"

extern const MainBody *parseAST();

#endif
