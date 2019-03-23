#include <iostream>

int main(int argc, const char * argv[]) {
    
    // Blocks (compund statements)
    
    /* A block of statements, also alled a compud statement, is a group of statements that is treated by the compiler as
     if it were a single statement. Blocks begin with a { symbol and end with a } symbol, and the statements to be
     executed are placed in between. Blocks can be used any place where a single statement is allowed. no semicolon
     is needed at the end of a block.
     
     Blocks are used when writing functions like the main function.
     
     Blocks can be nested inside of other blocks. as you've seen, the if statement executes a single statement if the
     condition is true, however, because blocks can be used anywhere a single statement can, we can instead use a nested
     block of statements to make the if statement excetue multiplte statements of the condition is true.
     
     It is even possible to put blocks inside of blocks inside of blocks:
  
     int main()
     { // block level 1
     std::cout << "Enter an integer: ";
     int value;
     std::cin >> value;
     
     if (value >  0)
     { // block level 2
     if ((value % 2) == 0)
     { // block level 3
     std::cout << value << " is positive and even" << std::endl;
     }
     else
     {
     std::cout << value << " is positive and odd" << std::endl;
     }
     }
     
     return 0;
     }
     
     There is no practical limit to how many nested blocks you can have. However it is generally a good idea to try to
     keep the nimber of nested blocks to at most 3 ( maybe 4) blocks deep. if your function has a need for more, its
     probably time to break your function into multiple smaller functions!
    
     */
    
    return 0;
}
