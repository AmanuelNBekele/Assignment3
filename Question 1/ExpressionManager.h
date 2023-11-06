#ifndef EXPRESSIONMANAGER_H
#define EXPRESSIONMANAGER_H

#include <string>

class ExpressionManager {
public:
  
  bool isOperator(char c); // Checks if a character is an operator
  int getOperatorPrecedence(char op); // Gets the precedence of an operator 
  bool isBalanced(const std::string &expression); //Checks if an expression is balanced 
  std::string infixToPostfix(const std::string &expression);// COnversts an infix expression to a postfix expression
};

#endif
