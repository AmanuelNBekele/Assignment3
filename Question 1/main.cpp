#include "ExpressionManager.h"
#include <iostream>
#include <string>

int main() {
  ExpressionManager manager; // Create an instance of the ExpressionManager class.
  std::string expression; // Declare a string variable to store the input expression.

  std::cout << "Enter an infix expression: "; // Prompt the user to enter an infix expression.
  std::cin >> expression;
// Check if the input expression has balanced parentheses.
  if (manager.isBalanced(expression)) {
    std::string postfix = manager.infixToPostfix(expression);
    std::cout << "Balanced Parentheses: Yes" << std::endl;
    std::cout << "Postfix Expression: " << postfix << std::endl;
  } else {
    std::cout << "Balanced Parentheses: No (Invalid Expression)" << std::endl;
  }

  return 0;
}
