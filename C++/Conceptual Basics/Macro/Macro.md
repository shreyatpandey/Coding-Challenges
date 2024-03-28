## What is Macro?
 * Textual replacement
 * Whenever the compiler encounters a macro in the program, it will replace it with macro value

# String Constant
 * "#" is used to convert string argument into string constant
 * "#" = stringization operator, converting into "quoted string"

## Pattern Matching
 * "##" is used for concatenation or merge tokens
 * It concatenates two strings when passed as an argument in Macro

## Why do we use Macro?
  * Increase in program efficiency
  * Specially used to define constant in program
  * Way of eliminating function call overhead because they are expanded in-line
  * Untill gcc C99 compiler, there was no inline keyword. So up till that point Macro allowed you to use "inline"
  * In C++, they do work function as template
 
