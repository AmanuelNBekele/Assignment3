#include "ExpressionManager.h"
#include <iostream>
#include <stack>
using namespace std;
#include <map>

bool ExpressionManager::isOperator(char c) {
  return (c == '+' || c == '-' || c == '*' || c == '/' || c == '%');
}

int ExpressionManager::getOperatorPrecedence(char op) {
  if (op == '+' || op == '-')
    return 1;
  if (op == '*' || op == '/' || op == '%')
    return 2;
  return 0; // Non-operators
}

bool ExpressionManager::isBalanced(const string &expression) {
  std::stack<char> stack;

  for (char c : expression) {
    if (c == '(' || c == '{' || c == '[') {
      stack.push(c);
    } else if (c == ')' || c == '}' || c == ']') {
      if (stack.empty()) {
        return false; // Unbalanced
      }
      char top = stack.top();
      stack.pop();
      if ((c == ')' && top != '(') || (c == '}' && top != '{') ||
          (c == ']' && top != '[')) {
        return false; // Mismatched parentheses
      }
    }
  }

  return stack.empty(); // If the stack is empty, all parentheses are balanced.
}

string ExpressionManager::infixToPostfix(const string &expression) {
  std::stack<char> operators;
  std::string postfixExpression = "";

  for (char c : expression) {
    if (isalnum(c)) {
      postfixExpression += c; // Operand, add to output
    } else if (c == '(') {
      operators.push(c);
    } else if (c == ')') {
      while (!operators.empty() && operators.top() != '(') {
        postfixExpression += operators.top();
        operators.pop();
      }
      if (!operators.empty() && operators.top() == '(') {
        operators.pop(); // Pop the '('
      } else {
        // Unbalanced parentheses
        return "Invalid expression: Unbalanced parentheses";
      }
    } else if (isOperator(c)) {
      while (!operators.empty() && getOperatorPrecedence(operators.top()) >=
                                       getOperatorPrecedence(c)) {
        postfixExpression += operators.top();
        operators.pop();
      }
      operators.push(c);
    }
  }

  while (!operators.empty()) {
    if (operators.top() == '(' || operators.top() == ')') {
      // Unbalanced parentheses
      return "Invalid expression: Unbalanced parentheses";
    }
    postfixExpression += operators.top();
    operators.pop();
  }

  return postfixExpression;
}
