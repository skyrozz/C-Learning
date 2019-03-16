

#include "pch.h"
#include <iostream>
#include <string>
#include <stdio.h>
using namespace std;


/*Lets do some forward declaration:
//A forward declaration allows us to tell the compiler about the existence of an identifier before actually defining the identifier.
//To write a forward declaration for a function, we use a declaration statement called a function prototype.
//The function prototype consists of the function’s return type, name, parameters, but no function body
(the curly braces and everything in between them), terminated with a semicolon.
*/

void add(int x, int y); // function prototype includes return type, name, parameters, and semicolon.  No function body!
// so now the program will compile without giving errors even if we call the function "add" before  we have defined what said function does.
//you dont have  to specify the names of the parameters when using a function prototype. the following prototype would work just as fine:
// int add(int, int);

int getValueFromUser() {

	// use void as the return type when you dont want the function to return anything.

	/* When you write a user-defined function, 
	you get to determine whether your function will return a value back to the caller or not. 
	*/
	
	cout << "Enter an integer: ";
	int input{ 0 };
	cin >> input;

	//we use a return statement to return a wanted value back to the caller function (main this time)	
	return input; 
}

void sum(int x, int y) {
	//This function simply sums up two numbers given to it
	cout << x << " + " << y << " = " << x + y << "\n";
}

int doubleNumber(int number) {
	//Here we can take an integer and double it.
	return number * 2;
}

void add(int x, int y) { // I just created this function so that my forward declaration example would work.
	cout << x << " + " << y << " = " << x + y << "\n";
}

bool isPrime (int x){
    bool prime { false };
    if (x == 2){
        prime = true;
    }
    else if (x == 3){
        prime = true;
    }
    else if (x == 5){
        prime = true;
    }
    else if (x == 7){
        prime = true;
    }
    else {
        prime = false;
    }
    return prime;
}

void printInteger(const int myValue){
    cout << myValue << "\n";
}

int main()
{
   /*
	cout << "Hello World!\n"; 
	cout << "bla bla bla" << endl ;
	 
	string name = "Juho" ;
	int age = 20;

	cout << "Hi my name is " << name << " and im " << age << " years old." << endl;

	for (int i = 0; i <= 3; i++) {
		cout << i << endl;
	}

	int a = 5; // copy initialization of value 5 into variable width
	int b(5); // direct initialization of value 5 into variable width
	/*
	   /* For simple data types (like integers), copy and direct initialization are essentially the same.
	   But for some advanced types, direct initialization can perform better than copy initialization. 
	   Prior to C++11, direct initialization was recommended over copy initialization in most cases because of the performance boost.
	   */
	  
	   // Prefer ‘\n’ over std::endl when outputting text to the console. (i think it uses less memory)

	// to read user input from console, use std::cin
	/*
	string input;
	cout << "Please type something:";
	cin >> input;	// note that when taking input you use >> instead of << !
	cout << "you typed: " << input << endl ; // for some reason this only saved a string untill i pressed space :/
	// getline(cin, str); seems to do what i want. */

	/*

	int numberToDouble;
	cout << "Enter a number: ";
	cin >> numberToDouble;
	numberToDouble = numberToDouble * 2;
	cout << "the number you entered times 2 is: " << numberToDouble << endl;

	// lets optimize the number doubling bit...

	int number{ 0 };

	cout << "Please enter an integer: ";
	cin >> number;
	cout << "Double that number is: " << number * 2 << "\n";

	

	int firstNumber{ 0 };
	int secondNumber{ 0 };

	cout << "enter an integer: ";
	cin >> firstNumber;
	cout << "enter a second integer: ";
	cin >> secondNumber;
	cout << firstNumber << " + " << secondNumber << " is " << firstNumber + secondNumber << "\n";
	cout << firstNumber << " - " << secondNumber << " is " << firstNumber - secondNumber << "\n";
	*
	/*
	int number{ getValueFromUser() }; // Asking user for input and  saving the return value as an integer called number.

	cout << number << " doubled is: " << number * 2 << "\n";
	*/
	
	// Lets use the getValueFromUser function to do some basic math.
	
	/*int x{ getValueFromUser() }; //Lets get the first value of our math problem
	int y{ getValueFromUser() }; //Now we get the second value of the problem

	sum(x, y);
	*/
	// /\ optimized is:

	//sum(getValueFromUser(), getValueFromUser());
	//Now, we’re using the return value of function getValueFromUser
	//directly as an argument to function sum.

	/* In the following piece of code:
	someFunction(a(), b());
	a() or b() may be called first
	If the architectures evaluates left to right, a() will be called before b().
	If the architecture evaluates right to left, b() will be called before a().
	This may or not be of consequence, depending on what a() and b() do.
	If it is important that one argument evaluate first,
	you should explicitly define the order of execution, like so:
	int a{ a() }; // a() will always be called first
	int b{ b() }; // b() will always be called second
	someFunction(a, b); // it doesn't matter whether a or b are copied first because they are just values
	*/

	/*int num = getValueFromUser();
	int doubled = doubleNumber(num);

	cout << num << " doubled is: " << doubled << "\n";
     
     */
	
    //Ask user for a single digit integer and based on it, pring wether said integer is a prime number or not.
    
    /*cout << "Enter a single digit integer. \n" ;
    
   int primenum = getValueFromUser() ;
    
    bool prime = isPrime(primenum);
    
    //Note that you dont need to write if (prime == true)... you can just use if (prime)...
    if (prime){
        cout << "The digit is prime \n";
    }
    else {
        cout << "The digit is not prime \n";
    } */
    
    /*Printing chars:
     basically 100% of times when you print a char variable, it prints out the ascii character of the char's value
     for example: char character { 97 };
                  std::cout << character;
     prints out the letter a instead of printing the number 97.
     
     if you want to initialixze your char to for example containt the code point for the number '5', do this:
     char ch { '5' }; //this initializes the variable with code point for '5'.
     char ch { 5 }; //This initializes the variable with the integer 5.
    */
    
    /*A type cast creates a value of one type from a value of another type.
     To convert between fundamental data types (for example, from a char to an int, or vice versa),
     we use a type cast called a static cast.
     
     The syntax for the static cast looks a little funny:
     static_cast<new_type>(expression)
     
     static_cast takes the value from an expression as input,
     and converts it into whatever fundamental type new_type represents (e.g. int, boolean, char, double).
     */
    
    //Here we use static cast to create an integer value from our char value:
    
   /* char ch{ 97 };
    cout << ch << "\n" ;
    cout << static_cast<int>(ch) << "\n";
    cout << ch << "\n";
    */
    
    /* This piece of code prints out the following:
     a
     97
     a
     */
    
    // Lets play with this information:
    
   /* cout << "Input a keyboard character: ";
    
    char character { 0 };
    cin >> character;
    cout << character << " has ASCII code " << static_cast<int>(character) << "\n";
    */
    
    /*Note that even though cin will let you enter multiple characters, ch will only hold 1 character.
     Consequently, only the first input character is placed in ch.
     The rest of the user input is left in the input buffer that cin uses,
     and can be accessed with subsequent calls to cin.
     
     You can see this behavior in the following example:
     */
    
    /*cout << "Input a keyboard character: "; //Assuming the user inputs "abcd"
    
    char input { 0 };
    cin >> input; //input = 'a', "bcd" is left queued.
    
    cout << input << " has an ASCII code " << static_cast<int>(input) << "\n";
    
    // Note: the following cin doesn't ask the user for input, it grabs queued input!
    cin >> input; // input = 'b', "cd" is left queued.
    
    cout << input << " has an ASCII code " << static_cast<int>(input) << "\n";
    */
     
    /*Escape sequences
     
     C++ has some characters that have special meaning. These characters are called escape sequences. An escape sequence starts with a Ô\Õ (backslash) , and then a following letter or number.
     
     The most common escape sequence is Ô\nÕ, which can be used to embed a newline in a string of text.
     
     Another commonly used escape sequence is Ô\tÕ, which embeds a tab
     
     Three other notable escape sequences are:
     \Õ prints a single quote
     \Ó prints a double quote
     \\ prints a backslash
     
     table of escape sequences can be found on the learncpp.com site or just simply by googling them!
     */
    
    /*So when should you use Ô\nÕ vs std::endl? The short answer is:
     
        -   Use std::endl when you need to ensure your output is output immediately (e.g. when writing a record to a file, or
            when updating a progress bar). Note that this may have a performance cost, particularly if writing to the
            output
            device is slow (e.g. when writing a file to a disk).
     
        -   Use Ô\nÕ in other cases.
     */
    
    // Literal constants.
    
    /* Literal constants (usually just called ÒliteralsÓ) are values inserted directly into the code.
     They are constants because you canÕt change their values. For example:
     */
    
   // int example = 5; // 5 is an integer literal
   // bool myNameIsJuho = true; // true is a boolean literal
   // cout << 3.4; // 3.4 is a double literal
    
    //just like variables, literals have a type. the type is assumed from the value and format of the literal istelf.
    
    /* By default:
     5, 0, -3 have a type of int
     true, false have a type of bool
     3.4, -2.2 have a type of double (not float)!
     'a' has a value of char
     "Hello world!" has a type of vonst char[14]
     */
    
    // Literal suffixes can be used if the default type of a literal is not desired.
    // literal suffixes:
    
    /* data type    suffix      meaning
       int          u or U      unsigned int
       int          l or L      long
       int          ul, UL      unsigned int (can be UL, Ul, uL, Lu, LU, lU etc)
       int          ll or LL    long long
       int          ull, uLL... unsigned long long
       double       f or F      float
       double       l or L      long double
     */
    
    // suffixes for int's aren't generally used but here are examples:
    //unsigned int value1 = 5u; // 5 has type unsigned int
    //long value2 = 6L; // 6 has type long
    
    /* By default, floating point literal constants have a type of double.
     To convert them into a float value, the f (or F) suffix should be used:
     */
    //float f = 5.0f; //5.0 has type float
    
    /* NOTE!
     while C++ supports string literals. for example:
     cout << "Hello world!"; // "Hello world!" is a C-style string literal
     
     String literals are handled very strangely in C++.
     For now, itÕs fine to use string literals to print text with std::cout,
     but donÕt try and assign them to variables or pass them to functions -- it either wonÕt work,
     or wonÕt work like youÕd expect.
     */
    
    // To use a hexadecimal literal, prefix your literal with 0x:
    int hexadecimal = 0xF; // 0x before the number means this is hexadecimal
    cout << hexadecimal << "\n";
    
    /* Because there are 16 different values for a hexadecimal digit, we can say that a single hexadecimal digit encompasses 4 bits. Consequently, a pair of hexadecimal digits can be used to exactly represent a full byte.
     
     Consider a 32-bit integer with value 0011 1010 0111 1111 1001 1000 0010 0110.
     Because of the length and repetition of digits, thatÕs not easy to read. In hexadecimal,
     this same value would be: 3A7F 9826.
     This makes hexadecimal values useful as a concise way to represent a value in memory.
     For this reason, hexadecimal values are often used to represent memory addresses or raw values in memory.
     */
    
    /* Prior to C++14, there is no way to assign a binary literal.
     However, hexadecimal pairs provides us with an useful workaround:
     */
    int bin { 0 };
    bin = 0x01; //assign binary 0000 0001 t0 the variable
    bin = 0x02; // assign binary 0000 0010 to the variable
    bin = 0x04; // assign binary 0000 0100 to the variable
    bin = 0x08; // assign binary 0000 1000 to the variable
    bin = 0x10; // assign binary 0001 0000 to the variable
    bin = 0x20; // assign binary 0010 0000 to the variable
    bin = 0x40; // assign binary 0100 0000 to the variable
    bin = 0x80; // assign binary 1000 0000 to the variable
    bin = 0xFF; // assign binary 1111 1111 to the variable
    bin = 0xB3; // assign binary 1011 0011 to the variable
    bin = 0xF770; // assign binary 1111 0111 0111 0000 to the variable
    
    // In c++ 14, we can assign binary literals by using the 0b prefix:
    
    bin = 0b1; // assign binary 0000 0001 to the variable
    bin = 0b11; // assign binary 0000 0011 to the variable
    bin = 0b1010; // assign binary 0000 1010 to the variable
    bin = 0b11110000; // assign binary 1111 0000 to the variable
    
    // Because long literals can be hard to read, C++ 14 also adds the ability to use a quatation mark (') as a digit separator.
    
    bin = 0b1011'0010; // Assign binary 1011 0010 to the variable
    long value = 2'132'673'462; //much easier to read than 2132673462
    cout << value << "\n";
    
    /* Consider the following snippet:
     
     int maxStudents = numClassrooms * 30;
     
     A number such as the 30 in the snippet above is called a magic number.
     A magic number is a hard-coded literal (usually a number)
     in the middle of the code that does not have any context.
     What does 30 mean? Although you can probably guess that in this case
     itÕs the maximum number of students per class, itÕs not absolutely clear.
     In more complex programs, it can be very difficult to infer what a hard-coded number represents,
     unless thereÕs a comment to explain it.
     
     Using magic numbers is generally considered bad practice because,
     in addition to not providing context as to what they are being used for,
     they pose problems if the value needs to change.
     LetÕs assume that the school buys new desks that allow them to raise the class size from 30 to 35,
     and our program needs to reflect that.
     Consider the following program:
     
     int maxStudents = numClassrooms * 30;
     setMax(30);
     
     To update our program to use the new classroom size, weÕd have to update the constant 30 to 35.
     But what about the call to setMax()? Does that 30 have the same meaning as the other 30? If so,
     it should be updated. If not, it should be left alone, or we might break our program somewhere else.
     If you do a global search-and-replace, you might inadvertently update the argument of setMax() when it wasnÕt
     supposed to change. So you have to look through all the code for every instance of the literal 30,
     and then determine whether it needs to change or not. That can be seriously time consuming (and error prone)
     
     Fortunately, better options (symbolic constants) exist.
     
     RULE: Don't use magic numbers in your code!!
     */
    
    /* Conts variables:
     sometimes its useful to define variables with values that can not be changed. For example, consider the value
     of gravity on earth : 9.81 m/s^2. This isn't likely to change any time soon. Defining this value as a constant
     helps ensure that this value isnt accodentally changed.
     
     To make a const variable, simply put the const keyword either before or after the variable type:
     */
    
    const int constant { 15 };
    const double gravity { 9.81 };
    cout << constant << gravity << "\n";
    
    // Const values have to be initialized when defining them and they cannot be changed via assigment.
    
    //Constant values can be initialized with non constant values like so:
    
    cout << "Enter your age: ";
    int age = getValueFromUser();
    
    const int userAge { age }; //UserAge can't be changed
    cout << userAge << "\n";
    
    //const is used most often with function parameters. (see top of program for the function called "printInteger".
    
    /* C++ actually has two different kinds of constants.
     Runtime constants are those whose initialization values can only be resolved at runtime
     (when your program is running). Variables such as usersAge and myValue above are runtime constants,
     because the compiler canÕt determine their values at compile time.
     usersAge relies on user input (which can only be given at runtime)
     and myValue depends on the value passed into the function (which is only known at runtime).
     
     Compile-time constants are those whose initialization values can be resolved at compile-time
     (when your program is compiling). Variable gravity above is an example of a compile-time constant.
     Whenever gravity is used, the compiler can simply substitute the identifier gravity for the literal double 9.8
     */
    
    /* In most cases, it doesnÕt matter whether a constant value is runtime or compile-time.
     However, there are a few odd cases where C++ requires a compile-time constant
     instead of a run-time constant (such as when defining the length of a fixed-size array
     -- weÕll cover this later). Because a const value could be either runtime or compile-time,
     the compiler has to keep track of which kind of constant it is.
     
     To help provide more specificity, C++11 introduced new keyword constexpr,
     which ensures that the constant must be a compile-time constant:
     */
    
    constexpr double gravitation { 9.81 }; // ok, the value of 9.81 can be resolved at compile-time
    constexpr int sum = 4 + 5; // ok, the value of 4 + 5 can be resolved at compile-time
    
    //cout << "Enter your age: ";
    int ageOfUser{ 0 };
    ageOfUser = getValueFromUser();
    //constexpr int myAge = ageOfUser; // not ok, ageOfUser can not be resolved at compile-time
    
    cout << gravitation << " " << sum << "\n";
    
    /* Rule: Any variable that should not change values after initialization
     and whose initializer is known at compile-time should be declared as constexpr.
     Rule: Any variable that should not change values after initialization
     and whose initializer is not known at compile-time should be declared as const.
     */
    
    /* Symbolic constants:
     
     we discussed Òmagic numbersÓ, which are literals used in a program to represent a constant value.
     Since magic numbers are bad, what should you do instead? The answer is: use symbolic constants!
     A symbolic constant is a name given to a constant literal value.
     There are two ways to declare symbolic constants in C++. One of them is good,
     and one of them is not. WeÕll show you both.
     
     Bad: Using object-like acros with a substitution parameter as symbolic constants.
     This method was commonly used in a lot of older code, so you may still see it.
     
     object like macros have two forms -- one that doesn't take a substitution parameter
     (generally used for conditional compilation), and one that does have a substitution parameter.
     We'll talk about the case with the substitution parameter here. that takes the form:
     #define IDENTIFIER substitution_text
     Whenever the preprocessor encounters this directive,
     any further occurrence of ÔidentifierÕ is replaced by Ôsubstitution_textÕ.
     The identifier is traditionally typed in all capital letters, using underscores to represent spaces.
     
     Consider the following snippet:
     
     #define MAX_STUDENTS_PER_CLASS 30
     int max_students = numClassrooms * MAX_STUDENTS_PER_CLASS;
     
     When you compile your code, the preprocessor replaces all instances of MAX_STUDENTS_PER_CLASS with the literal value 30, which is then compiled into your executable.
     
     YouÕll likely agree that this is much more intuitive than using a magic number for a couple of reasons.
     MAX_STUDENTS_PER_CLASS provides context for what the program is trying to do,
     even without a comment. Second, if the number of max students per classroom changes,
     we only need to change the value of MAX_STUDENTS_PER_CLASS in one place,
     and all instances of MAX_STUDENTS_PER_CLASS will be replaced by the new literal value at the next compilation.
     
     So why not use #define to make symbolic constants? There are (at least) two major problems.
     
     First, because macros are resolved by the preprocessor, which replaces the symbolic name with the defined value,
     #defined symbolic constants do not show up in the debugger (which shows you your actual code).
     So although the compiler would compile int max_students = numClassrooms * 30;,
     in the debugger youÕd see int max_students = numClassrooms * MAX_STUDENTS_PER_CLASS;.
     YouÕd have to go find the definition of MAX_STUDENTS_PER_CLASS in order to know what the actual value was.
     This can make your programs harder to debug.
     
     Second, #defined values always have file scope (which weÕll talk more about in the section on local and global
     variables). This means a value #defined in one piece of code may have a naming conflict
     with a value #defined within the same file later.
     
     For Example:
     
     void a()
     {
     // This define value is now available for the rest of this file
     #define x 5
     std::cout << x;
     }
     
     void b()
     {
     // Even though we're intending this x to be local to function b()
     // it conflicts with the x we defined inside function a()
     #define x 6
     std::cout << x;
     }
     
     int main() {
     
     a();
     b();
     
     return 0;
     }
     
     In the above code, we #define x in function a(), intending it to be used inside function a().
     However, #define value x can actually be used anywhere beyond that point in the same file.
     So when function b() #defines its own x, we get a naming conflict.
     Even if function b() used a variable named x instead of a #define value named x,
     we would still have issues, as the preprocessor would try to replace variable name x with the value 5.
     
     Rule: Avoid using #define to create symbolic constants
     
     A better solution: Use const variables
     
     A better way to create symbolic constants is through use of const (or better, constexpr) variables:
     
     1
     2
     constexpr int maxStudentsPerClass { 30 };
     constexpr int maxNameLength { 30 };
     These will show up in the debugger, and follow all of the normal variable rules around scope.
     
     Rule: use const variables to provide a name and context for your magic numbers.
     
     A great way to use const variables throughout a programs is to create them in a centralized location,
     so that you will only need to change them in one place regardless what file you're using. also it makes
     finding said variables easier.
     
     There are multiple ways to facilitate this within C++, but the following is probably easiest:
     
     1) Create a header file to hold these constants
     2) Inside this header file, declare a namespace (weÕll talk more about this in lesson 4.3b -- Namespaces)
     3) Add all your constants inside the namespace (make sure theyÕre const)
     4) #include the header file wherever you need it
     
     e.g. constants.h:
     
     
     #ifndef CONSTANTS_H
     #define CONSTANTS_H
     
     // define your own namespace to hold constants
     namespace constants
     {
     constexpr double pi(3.14159);
     constexpr double avogadro(6.0221413e23);
     constexpr double my_gravity(9.2); // m/s^2 -- gravity is light on this planet
     // ... other related constants
     }
     #endif
     
     Use the scope resolution operator (::) to access your constants in .cpp files:
    
     #include "constants.h"
     double circumference = 2 * radius * constants::pi; (same as std::cout << ;
     
     */
    
    
    cout << "Juho on kakkapaa. \n";

	return 0;
}
