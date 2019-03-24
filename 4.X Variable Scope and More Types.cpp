#include "pch.h"
#include <string>
#include <iostream>

int main()
{
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

	// Local variables, scope, and duration

	/* When discussing variables, its useful to separate out the concepts of scope and duration. A  variables scope determines where a variables is accessible.
	A varaibles duration determines where it is created and destroyed. the two concepts are often linked.
	
	Variables defined inside a function are called local variables. Local variables have automatic duration, which means they are created (and initialized,
	if relevant) at the point of definition, and destroyed when the block they are defined in is exited. local variables have block scope (also called
	local scope), which means that they enter scope at the point of declaration and go out of scope at the end of the block that they are defined in.

	example:

	int main(){
	int i { 5 }; // i created and intialized here
	double d { 4.0 }; // d created and initialized here

	return 0;

	} // i and d go out of scope and are destroyed here

	because i and d were defined inside the block that defines the main function, they are both destroyed when main() is finished executing.

	Variables defined inside nested blocks are destroyed as soon as the nested block ends:

	int main() // outer block{
	int n(5); // n created and initialized here

	{ // begin nested block
		double d(4.0); // d created and initialized here
	} // d goes out of scope and is destroyed here

	// d can not be used here because it was already destroyed!

	return 0;
	
	} // n goes out of scope and is destroyed here

	Variables defined inside a block can only be seen  within that block. Because each function has its own block, variables in one function can not be seen
	from another function:

	void someFunction(){
	int value(4); // value defined here

	// value can be seen and used here

	} // value goes out of scope and is destroyed here

	int main(){
	// value can not be seen or used inside this function.

	someFunction();

	// value still can not be seen or used inside this function.

	return 0;
	}
	
	This means functions can have variables or parameters with the same names as other functions. This is a good thing, bevause it measns we dont have to worry
	about naming collisions between two independent functions. In the following example, both functions have variables named x and y. These variables
	in each function are unaware of the exsistence of other variables with the same name in other functions.

	#include <iostream>

	// add's x and y can only be seen/used within function add()
	int add(int x, int y){ // add's x and y are created here and can only be seen/used within add() after this point
	
	return x + y;
	} // add's x and y are destroyed here

	// main's x and y can only be seen/used within function main()
	int main()	{
	int x = 5; // main's x is created here, and can be seen/used only within main() after this point
	int y = 6; // main's y is created here, and can be seen/used only within main() after this point

	std::cout << add(x, y) << std::endl; // the value from main's x and y are copied into add's x and y

	// We can still use main's x and y here

	return 0;
	} // main's x and y are destroyed here

	Nested blocks are considered part of the outer block in which they are defined. Consequently, variables defined in the outer block can be seen inside a
	nested block:

	#include <iostream>

int main(){ // start outer block

	int x(5);{ // start nested block
		int y(7);
		// we can see both x and y from here
		std::cout << x << " + " << y << " = " << x + y;
	} // y destroyed here

	// y can not be used here because it was already destroyed!

	return 0;
	} // x is destroyed here

	Shadowing:

	Note that a variable inside a nested block can have the same name as a variable inside an outer block. When this happens, the nested variable "hides"
	the outer variable. This is called name hiding or shadowing

	#include <iostream>

int main(){ // outer block
	int apples(5); // here's the outer block apples

	if (apples >= 5) // refers to outer block apples
	{ // nested block
		int apples; // hides previous variable named apples

		// apples now refers to the nested block apples
		// the outer block apples is temporarily hidden

		apples = 10; // this assigns value 10 to nested block apples, not outer block apples

		std::cout << apples << '\n'; // print value of nested block apples
	} // nested block apples destroyed

	// apples now refers to the outer block apples again

	std::cout << apples << '\n'; // prints value of outer block apples

	return 0;
	} // outer block apples destroyed

	If you run this program, it prints:

	10
	5

	in the above program, we first declare a variable named apples in the outer block. then we declare a different variable (also named apples) inside
	the nested block. When we assign value 10 to apples, we're assigning it to the nested block apples. After printing its value, nested block apples is
	destroyed, leaving outer block apples with its original value (5), which is then  printed. This program exectues the exact same as it would have if
	we'd named nested block apples something else (e.g. nbaApples) and kept the names discinct (because outer block apples and nested block apples are 
	distinct variables, they just share the same name)

	Note that if the nested block apples had not been defined, the name apples in the nested block would still refer to the outer apples, so the 
	assignment of value 10 to apples would have applied to the outer block apples: 

	#include <iostream>

	int main(){ // outer block
	int apples(5); // here's the outer block apples

	if (apples >= 5) // refers to outer block apples
	{ // nested block
		// no inner block apples defined

		apples = 10; // this now applies to outer block apples, even though we're in an inner block

		std::cout << apples << '\n'; // print value of outer block apples
	} // outer block apples retains its value even after we leave the nested block

	std::cout << apples << '\n'; // prints value of outer block apples

	return 0;
	} // outer block apples destroyed

	The above program prints:
	10
	10

	In both examples, outer block apples is not impacted by what happens to nested block apples. the only difference between the two programs is which apples
	the expression apples = 10 applies to.

	Shadowing is something that should generally be avoided, as it is quite confusing!

	Rule: Avoid using nested variables with the same names as variables in an outer block.

	Variables should be defined in the most limited scope possible:

	For example, if a variable is only used within a nested block, it should be defined inside that nested block:

	#include <iostream>

	int main(){
	// do not define y here

	{
		// y is only used inside this block, so define it here
		int y(5);
		std::cout << y;
	}

	// otherwise y could still be used here

	return 0;
	}

	By limiting the scope of a variable, you reduce the complexity  of the program because the number of active variables is reduced. Further,
	it makes it easier to see where variables are used. A variable defined inside a block can only be used within that block (or nested sub-blocks).
	This can make the program easier to understand.

	If a variable is needed in an outer block, it needs to be declared in the outer block:

	#include <iostream>

int main(){
	int y(5); // we're declaring y here because we need it in this outer block later

	{
		int x;
		std::cin >> x;
		// if we declared y here, immediately before its actual first use...
		if (x == 4)
			y = 4;
	} // ... it would be destroyed here

	std::cout << y; // and we need y to exist here

	return 0;
	}

	This is one of the rare cases where you may need to declare a variable well before its first use.

	Rule: Define variables in the smallest scope and as close to the first use as possible.. 

	Function parameters:

	Although function parameters are not defined inside the block belonging to the function, in most cases, they can be considered to have block scope.

	int max(int x, int y){ // x and y defined here
	
	// assign the greater of x or y to max
	int max = (x > y) ? x : y; // max defined here
	return max;
	} // x, y, and max all die here

	The exception case is for function-level exceptionsm which we'll cover in a future section.

	Summary:

	Variables defined inside functions are called local variables. these variables can only be accessed inside the block in which they are defined 
	(including nested blocks), and they are destroyed as soon as the block ends.

	Define variables in the smallest scope that they are used. if a variable is only used within a nested block, define it within the nested block.
	*/

	//quiz:
	
	/* 1) Write a program that asks the user to enter two integersm the second larger than the first. if the user entered a smaller integer for the second 
	integer, use a block and a temporary variable to swap the samller and larger values. Then print the value of the smaller and larger variables.
	Add comments to your code indicating where each variables dies.

	The output of the program should match the following:

	Enter an integer: 4
	Enter a larger integer: 2
	Swapping the values
	The smaller value is 2
	The larger value is 4
	*/

	// 1)
	//Asking the user for the first value
	std::cout << "Enter an integer: ";	
	int firstValue{ 0 };
	std::cin >> firstValue;

	//asking the user for the second value
	std::cout << "Enter a larger integer: ";
	int secondValue{ 0 };
	std::cin >> secondValue;

	std::cin.ignore(32767, '\n'); // you'll know what this means when you read down (:

	//Flipping the values if second value is smaller than first.
	if (firstValue > secondValue) {
		int temp = firstValue;
		firstValue = secondValue;
		secondValue = temp;
		std::cout << "Swapping the values \n";
	} //temp integer dies here

	std::cout << "the smaller value is " << firstValue << "\n";
	std::cout << "The larger value is " << secondValue << "\n";


	// 4.2 - Global variables and linkage:

	/* Variables declared outside of a function are called global variables. Global variables have static duration,
	which means they are created when the program starts and are destroyed when it ends. Global variables have file scope (also informally called
	"Global scope" or "global namespave scope"), which means they are visible until the end of the file in which they are declared. 

	Defining global variables:

	By convention, global variables are declared at the top of a file, below the includes but ab ove any code. Here's an example if a couple of global
	variables being defined:

	#include <iostream>

	// Variables declared outside of a function are global variables
	int g_x; // global variable g_x
	const int g_y(2); // global variable g_y

	void doSomething(){	
	// global variables can be seen and used everywhere in program
	g_x = 3;
	std::cout << g_y << "\n";
	}

	int main(	{
	doSomething();

	// global variables can be seen and used everywhere in program
	g_x = 5;
	std::cout << g_y << "\n";

	return 0;
	}

	Similar to how variables in an inner block with the same name as a variable in an outer block hides the variable in the outer block,
	local variables with the same name as a global variable hide the global variable inside the block that the local variable is declared in.
	However, the global scope operator (::) can be used to tell the compiler you mean the global version instead of the local version.

	#include <iostream>
	int value(5); // global variable

	int main()	{
	int value = 7; // hides the global variable value
	++value; // increments local value, not global value

	--(::value); // decrements global value, not local value (parenthesis added for readability)

	std::cout << "local value: " << value << "\n";
	std::cout << "global value: " << ::value << "\n";

	return 0;
	} // local value is destroyed

	This code prints:

	local value: 8
	global value: 4

	However, having local variables with the same name as global variables is usually a recipe for trouble, and should be avoided whenever possible.
	By convention, many developers prefix global variable names with "g_" to indicate that they are global. This both helps identify global variables
	as well as avoids naming conflicts with local variables.

	Internal and external linkage via the static and extern keywords:

	In addition to scope and duration, variables have a third property: linkage. A variables linkage determines whether multiple instances of an identifier
	refer to the same variable or not.

	A variable with no linkage can only be referred to from the limited scope it exists in. Normal local variables are an example of variables with no
	linkage. Two local variables with the same name but defined in different functions have no linkage -- each will be considered an independent variable.

	A variable with internal linkage is called an internal variable (or static variable). Variables with internal linkage can be used anywhere 
	within the file they are defined in, but can't be referenced outside the file they exist in.

	A variable with external linkage is called an external variable. Variables with external linkage can be used both in the file they are defined in,
	as well as in other files.

	If we want to make a global variable internal (able to be used only within a single file), we can use the static keyword to do so:

	static int g_x; // g_x is static, and can only be used within this file

	int main(){
	return 0;
	}

	Similarly if we want to make a global variable external (able to be used anyhwere in our program), we use the extern keyword to do so:

	extern double g_y(9.8); // g_y is external, and can be used by other files

	// Note: those other files will need to use a forward declaration to access this external variable
	// We'll discuss this in the next section
	
	int main(){
	return 0;
	}	

	By default, non-const variables declared outside of a function are assumed to be external. However, const variables declared outside of a function 
	are assumed to be internal.

	Variable forward declarations via the extern keyword:

	In the section on programs with multiple files, you learned that in order to use a function declared in another file,
	you have to use a function forward declaration.

	Similarly, in order to use an external global variable that has been declared in another file,
	you must use a variable forward declaration. For variables, creating a forward declaration is done via the extern keyword
	(with no initialization value).

	Note that this means the “extern” keyword has different meanings in different contexts. In some contexts,
	extern means “give this variable external linkage”. In other contexts, extern means
	“this is a forward declaration for an external variable that is defined somewhere else”.
	We’ll summarize these usages in lesson 4.3a -- Scope, duration, and linkage summary.

	Here is an example of using a variable forward declaration:

	global.cpp:

	// define two global variables
	// non-const globals have external linkage by default
	int g_x; // external linkage by default
	extern int g_y(2); // external linkage by default, so this extern is redundant and ignored

	// in this file, g_x and g_y can be used anywhere beyond this point

	main.cpp:

	extern int g_x; // forward declaration for g_x (defined in global.cpp) -- g_x can now be used beyond this point in this file

	int main()
	{
	extern int g_y; // forward declaration for g_y (defined in global.cpp) -- g_y can be used beyond this point in main() only

	g_x = 5;
	std::cout << g_y; // should print 2

	return 0;
	}

	If the variable forward declaration is declared outside of a function, it applies for the whole file.
	If the variable forward declaration is declared inside a function, it applies within that block only.

	Function linkage:

	Functions have the same linkage property that variables do. Functions always default to external linkage,
	but can be set to internal linkage via the static keyword:

	// This function is declared as static, and can now be used only within this file
	// Attempts to access it via a function prototype will fail
	static int add(int x, int y)
	{
	return x + y;
	}

	Function forward declarations don't need the extern keyword. the compiler is able to tell whether you're defining a function or a function prototype
	by wheter you supply a function body or not.

	it’s worth noting that non-extern objects and functions in different files are considered to be different entities,
	even if their names and types are identical. This makes sense, since they can’t be seen outside of their respective files anyway.

	File scope vs global scope:

	The terms "file scope" and "global scope" tend to cause confusion, and this is partly due to the way they are informally used. Technically, in C++, all
	global variables in C++ have "file scope". However, informally, the term "file scope" is more often applied to file scope variables
	with internal linkage only, and "global scope" to file scope variables with external linkage.

	Global symbolic constants:

	Earlier we introduced the consept of symbolic constants, and defined them like this:

	constants.h:
	#ifned CONSTANTS_H
	#define CONSTANTS_H

	// define your own namespace to hold constants
	namespace Constants{
	const double pi(3.14159);
    const double avogadro(6.0221413e23);
    const double my_gravity(9.2); // m/s^2 -- gravity is light on this planet
    // ... other related constants
	}
	#endif

	While this is simple (and fine for smaller programs), every time constants.h gets #included into a different code file,
	each of these variables is copied into the including code file. Therefore, if constants.h gets included into 20 different code files,
	each of these variables is duplicated 20 times. Header guards won’t stop this from happening,
	as they only prevent a header from being included more than once into a single including file,
	not from being included one time into multiple different code files
	. This duplication of variables isn’t really that much of a problem (since constants aren’t likely to be huge),
	but changing a single constant value would require recompiling every file that includes the constants header,
	which can lead to lengthy rebuild times for larger projects.

	We can avoid this problem by turning these constants into const global variables, and changing the header file to hold only the variable forward declarations:

	constants.cpp:

	namespace Constants{
	// actual global variables
	extern const double pi(3.14159);
	extern const double avogadro(6.0221413e23);
	extern const double my_gravity(9.2); // m/s^2 -- gravity is light on this planet
	}

	constants.h:

	#ifndef CONSTANTS_H
	#define CONSTANTS_H

	namespace Constants{
	// forward declarations only
	extern const double pi;
	extern const double avogadro;
	extern const double my_gravity;
	}

	#endif

	Use in the code file stays the same:

	#include "Constants.h"
	double circumference = 2 * radius * Constants::pi;

	Because global symbolic constants should be namespaced (to avoid naming conflicts with other identifiers in the global namespace) and are read-only,
	the use of the g_ prefix is not necessary.

	Now the symbolic constants will get instantiated only once (in constants.cpp), instead of once every time constants.h is #included,
	and the other uses will simply refer to the version in constants.cpp. Any changes made to constants.cpp will require recompiling only constants.cpp.

	However, there are a couple of downsides to doing this. First, these constants are now considered compile-time constants only within the file they are
	actually defined in (constants.cpp), not anywhere else they are used. This means that outside of constants.cpp,
	they can’t be used anywhere that requires a compile-time constant (such as for the length of a fixed array,
	something we talk about in chapter 6). Second, the compiler may not be able to optimize these as much.

	Given the above downsides, we recommend defining your constants in the header file. If you find that for some reason those constants are causing
	trouble, you can move them into a .cpp file as per the above as needed.

	A word of caution about (non-const) global variables:

	New programmers are often tempted to use lots of global variables, because they are easy to work with, especially when many functions a re involved.
	However, use of non-const global variables should generally be avoided altogether! we'll discuss why in the next section.

	Summary:

	Global vairables have global scope, and can be used anywhere in the program. Like functions, you must use a forward declaration (via keyword extern)
	to use a global variable defined in another file.

	By default , non-const global variables have external linkage. you can use static keyword to explicitly make them internal if desired.
	By default, const global variables have internal linkage. you can use the extern keyword to explicitly make them external if desired.

	use a g_ prefix to help you identify your non- const global variables.

	Here’s a summary chart of the use of the extern and static keywords for non-const and const variable use cases:

	// Uninitialized definition:
	int g_x;        // defines uninitialized global variable (external linkage)
	static int g_x; // defines uninitialized static variable (internal linkage)
	const int g_x;  // not allowed: const variables must be initialized

	// Forward declaration via extern keyword:
	extern int g_z;       // forward declaration for global variable defined elsewhere
	extern const int g_z; // forward declaration for const global variable defined elsewhere

	// Initialized definition:
	int g_y(1);        // defines initialized global variable (external linkage)
	static int g_y(1); // defines initialized static variable (internal linkage)
	const int g_y(1);  // defines initialized const variable (internal linkage)

	// Initialized definition w/extern keyword:
	extern int g_w(1);       // defines initialized global variable (external linkage, extern keyword is redundant in this case)
	extern const int g_w(1); // defines initialized const global variable (external linkage)

	4.2a - Why global vairables are evil:

	Before we go into why, we should make a clarification. When developers say that global variables are evil, theyre not talking about all global 
	variables. They're mostly talking about non-const global variables.

	Why (non-const) global variables are evil:

	By far the biggest reason non-const variables are dangerous is because their values can be changed by any function that is called,
	and there is no easy way for the programmer to know that this will happen.

	consider the following program:

	// declare global variable
	int g_mode;

	void doSomething(){
	g_mode = 2; // set the global g_mode variable to 2
	}

	int main(){
	g_mode = 1; // note: this sets the global g_mode variable to 1.  It does not declare a local g_mode variable!

	doSomething();

	// Programmer still expects g_mode to be 1
	// But doSomething changed it to 2!

	if (g_mode == 1)
		std::cout << "No threat detected.\n";
	else
		std::cout << "Launching nuclear missiles...\n";

	return 0;
	}

	Note that the programmer set g_mode to 1, and then called doSomething(). Unless the programmer had explicit knowledge that doSomething()
	was going to change the value of g_mode, he or she was probably not expecting doSomething() to change the value! Consequently, the rest of main()
	doesn’t work like the programmer expects (and the world is obliterated).

	Non-const global variables make every function call potentially dangerous, and the programmer has no easy way of knowing which ones are dangerous
	and which ones aren’t! Local variables are much safer because other functions can not affect them directly.

	There are plenty of other good reasons not to use non-const globals.

	With global variables, it’s not uncommon to find a piece of code that looks like this:
	
	void foo(){
	// useful code

	if (g_mode == 4) // do something good
	}

	Your program is broken because g_mode is set to 3, not 4. How do you fix it? Now you need to find all of the places g_mode could possibly get set to 3,
	and trace through how it got set in the first place. It’s possible this may be in a totally unrelated piece of code!

	One of the reasons to declare local variables as close to where they are used as possible is because doing so minimizes the amount of code
	you need to look through to understand what the variable does. Global variables are at the opposite end of the spectrum --
	because they can be used anywhere, you might have to look through a significant amount of code to understand their usage.

	For example, you might find g_mode is referenced 442 times in your program. Unless g_mode is well documented, you’ll potentially have to look through
	every use of g_mode to understand how it’s being used in different cases, what its valid values are, and what its overall function is.

	Global variables also make your program less modular and less flexible. A function that utilizes nothing but its parameters and has no side effects
	is perfectly modular. Modularity helps both in understanding what a program does, as well as with reusability.
	Global variables reduce modularity significantly.

	In particular, avoid using global variables for important “decision-point” variables (e.g. variables you’d use in a conditional statement,
	like variable g_mode in the example above). Your program isn’t likely to break if a global variable holding an informational value changes
	(e.g. like the user’s name). It is much more likely to break if you change a global variable that impacts how your program operates.

	Rule: Use local variables instead of global variables whenever reasonable, and pass them to the functions that need them.

	So what are very good reasons to use non-const global variables?

	There aren’t many. In many cases, there are other ways to solve the problem that avoids the use of non-const global variables.
	But in some cases, judicious use of non-const global variables can actually reduce program complexity, and in these rare cases,
	their use may be better than the alternatives.

	For example, if your program uses a database to read and write data, it may make sense to define the database globally,
	because it could be needed from anywhere. Similarly, if your program has an error log (or debug log) where you can dump error (or debug) information,
	it probably makes sense to define that globally, because you’re mostly likely to only have one log and it could be used anywhere.
	A sound library would be another good example: you probably don’t want to pass this to every function that needs it.
	Since you’ll probably only have one sound library managing all of your sounds, it may be better to declare it globally,
	initialize it at program launch, and then treat it as read-only thereafter.

	Protecting yourself from global destruction:

	If you do find a good use for a non-const global variable, a few useful bits of advice will minimize the amount of trouble you can get into.

	First, prefix all your global variables with “g_”, and/or put them in a namespace, both to reduce the chance of naming collisions and raise awareness
	that a variable is global.

	For example:

	double g_gravity {9.81} // this is better than the latter because this makes it clear that this is a global variable.
	double gravity {9.81}


	Second, instead of allowing direct access to the global variable, it’s a better practice to “encapsulate” the variable. First,
	make the variable static, so it can only be accessed directly in the file it’s declared. Second, provide external global “access functions”
	to work with the variable. These functions can ensure proper usage is maintained (e.g. do input validation, range checking, etc…). Also,
	if you ever decide to change the underlying implementation (e.g. move from one database to another), you only have to update the access functions
	instead of every piece of code that uses the global variable directly.

	For example, instead of:

	double g_gravity (9.8); // can be exported and used directly in any file

	do this:

	static double g_gravity (9.8); // restrict direct access to this file only
	double getGravity() // this function can be exported to other files to access the global outside of this file
	{
	// We could add logic here if needed later
	return g_gravity;
	}

	Third, when writing a standalone function that uses the global variable, don’t use the variable directly in your function body.
	Pass it in as a parameter, and use the parameter. That way, if your function ever needs to use a different value for some circumstance,
	you can simply vary the parameter. This helps maintain modularity.

	Instead of:

	// This function is only useful for calculating your instant velocity based on the global gravity
	double instantVelocity(int time){
	return g_gravity * time;
	}

	Do this:

	// This function can calculate the instant velocity for any gravity value (more useful)
	// pass in the return value from getGravity() for parameter gravity if you want to use the global gravity
	double instantVelocity(int time, double gravity){
	return gravity * time;
	}

	Finally, changing the value of a global variable is the thing that is most likely to cause problems.
	Structure your code to assume a global variable’s value may change. Try to minimize the number of places where you change your global’s value
	-- treat the global as read-only as much as possible. If you can set your global’s value at program startup and then not change it afterward,
	you’ll minimize the chance of unexpected issues occurring.

	Summary:

	Avoid use of non-const global variables if at all possible! If you do have to use them, use them sensibly and cautiously.

	Const global variables (symbolic constants) are fine to use, so long as you use proper naming conventions.

	in other cases, favor local variables. pass those local variables to the functions that need them.

	4.3 - Static duration variables

	The static keyword is one of the most confusing keywords in the C++ language (maybe with the exception of the keyword "class"). This is because it has
	different meanings depending on where it is used.

	In section 4.2 -- Global variables, you learned that when applied to a variable declared outside of a block,
	it defines a global variable with internal linkage, meaning the variable could only be used in the file in which it was defined.

	The static keyword can also be applied to variables declared inside a block, where it has a different meaning entirely.
	In section 4.1a -- Local variables and local scope, you learned that local variables have automatic duration, which means they are created
	at the point of definition, and destroyed when the block is exited. 

	Using the static keyword on local variables changes them from automatic duration to static duration (also called fixed duration).
	A static duration variable (also called a “static variable”) is one that retains its value even after the scope in which it has been created
	has been exited! Static duration variables are only created (and initialized) once, and then they are persisted throughout the life of the program.

	The easiest way to show the difference between automatic and static duration variables is by example.

	Automatic duration (default):

	#include <iostream>

	void incrementAndPrint()
	{
	int value = 1; // automatic duration by default
	++value;
	std::cout << value << '\n';
	} // value is destroyed here

	int main(){
	incrementAndPrint();
	incrementAndPrint();
	incrementAndPrint();

	return 0;
	}

	Each time incrementAndPrint is called, a variable named value is created and assigned the value of 1. incrementAndPrint increments value to 2,
	and then prints the value of 2. When incrementAndPrint is finished running, the variable goes out of scope and is destroyed. Consequently,
	this program outputs:

	2
	2
	2

	Now consider the static scope version of this program. The only difference between this and the above program is that we’ve changed the local
	variable value from automatic to static duration by using the static keyword.

	Static duration (using static keyword):

	#include <iostream>

	void incrementAndPrint(){
	static int s_value = 1; // static duration via static keyword.  This line is only executed once.
	++s_value;
	std::cout << s_value << '\n';
	} // s_value is not destroyed here, but becomes inaccessible

	int main(){
	incrementAndPrint();
	incrementAndPrint();
	incrementAndPrint();

	return 0;
	}

	In this program, because s_value has been declared as static, s_value is only created and initialized (to 1) once.
	When it goes out of scope, it is not destroyed. Each time the function incrementAndPrint() is called, the value of s_value is whatever we left it at
	previously. Consequently, this program outputs:

	2
	3
	4

	Just like we use “g_” to prefix global variables, it’s common to use “s_” to prefix static (static duration) variables.
	Note that internal linkage global variables (also declared using the static keyword) get a “g_”, not a “s_”.

One of the most common uses for static duration local variables is for unique identifier generators
. When dealing with a large number of similar objects within a program, it is often useful to assign each one a unique ID number so they can be identified.
This is very easy to do with a static duration local variable:

	int generateID(){
	static int s_itemID = 0;
	return s_itemID++; // makes copy of s_itemID, increments the real s_itemID, then returns the value in the copy
	}

	The first time this function is called, it returns 0. The second time, it returns 1. Each time it is called, it returns a number one higher
	than the previous time it was called. You can assign these numbers as unique IDs for your objects. Because s_itemID is a local variable, it
	can not be “tampered with” by other functions.

	Static variables offer some of the benefit of global variables (they don’t get destroyed until the end of the program) while limiting their
	visibility to block scope. This makes them much safer for use than global variables.

	4.3.a - Scope, duration, and linkage summary

	The consepts of scope, duration, and linkage cause a lot of confusion, so we're gpong to take an extra lessong to summarize everything.

	Scope summary:

	An identifier's scope determines where it is accessible. an identifier that is out of scope can not be accessed.

	- Variables with vlock scope / local scope can only be accessed within the block in which they are declared (including nested blocks). this includes:
		- Local variables
		- function parameters
		- locally-defined types
	- Variables and functions with global scope/ file scope can be accessed anywhere in the file. this includes:
		- Gloval variables
		- normal functions
		- globally-defined types

	Duration summary:

	A variables duration determines when it is created and destroyed

	- variables with automatic duration are created at the point of definition, and  destroyed when the block they are part of is exited. this includes:
		- normal local variables
	- variables with static duration are created when the program begins and destroyed when the program ends. this includes:
		- global variables
		- static local variables
	- variables with dynamic duration are created and destroyed by the programmer request this includes
		- dynamically allocated variables (we'll talk about these when we cover dynamic allocation in chapter 6)

	Linkage summary:

	An identifiers linkage determines wheter multiple instances of an identifier refer to the same identifier or not.

	- identifiers with no linkage mean the identifier only refers to itself. this includes:
		- normal local variables 
		- user-defined types, such as enums, typedefs, and calsses declared inside a block (we'll cover these in later lessons)
	- identifiers with internal linkage can be accessed anywhere within the file it is declared this includes:
		- static global variables (initialized or uninitialized)
		- const global variables
		- static functiosn (we'll cover these in chapter 7)
	- identifiers with external linkage can be accessed anywhere within the file it is declared, or other files (via forward declaration). this includes:
		- normal functions
		- non-const global variables (initialized or uninitialized)
		- user- defined types such as enumus, typedefs, and classes declared in the global scope (we'll cover these in later lessons)

	Identifiers with external linkage will cause a duplicate definition linker error if the definitions are compiled into more than one .cpp file

	there are a few things worth explicitly nothing here. First, functions are extrern by default, and can be made internal by using the static keyword

	second, astute readers may note that global types have external linkage, but their definitions dont cause a linker error when included in multiple files.
	this is because types, templates, and extern inline functions have an exemption that allows them to be defined in more than one file, so long as the
	definitions are identical. otherwise they wouldnt be of much use


	4.3b - namespaces

	In lesson 2.9 -- Naming conflicts and the std namespace, we introduced the concept of naming conflicts and namespaces.
	This lesson builds upon those topics.

	A naming conflict occurs when two identifiers are introduced into the same scope, and the compiler cant disambiguate which one to use. when this happens,
	compiler or linker will produce an error because it does not have enough information to resolve the ambiguity. as programs get larger and larger
	the number of identifiers increase lineraly, which in turn causes the probability of naming collisions to increase exponentially.

	Lets take a look at an example of a naming collision. In the following example foo.h and goo.h are the header files that contain functions that do different things
	but have the same name and parameters.

	foo.h:

	// This doSomething() adds the value of its parameters
	int doSomething(int x, int y){
		return x + y;
	}

	goo.h:

	// This doSomething() subtracts the value of its parameters
int doSomething(int x, int y){
	return x - y;
	}

	main.cpp:

	#include "foo.h"
	#include "goo.h"
	#include <iostream>

	int main(){
	
	std::cout << doSomething(4, 3); // which doSomething will we get?
	return 0;
	}

	If foo.h and goo.h are compiled separately, they will each compile without incident. However, by including them in the same program,
	we have now introduced two different functions with the same name and parameters into the same scope (the global scope),
	which causes a naming collision. As a result, the compiler will issue an error.

	in order to help address this type of problem, the consept of namespaces was introduced.

	what is a namespace?

	a namespace defines an area of code in which all identifiers are guaranteed to be unique. by default, global variables and normal
	functions are defined in the global namespace.
	For example lets take a look at the following snippet:

	int g_x = 5;

	int foo(int x){
	
	return -x;
	}

	both global variable g_x and function foo() are defined in the global namespace.

	in the example program above that had the naming collision, when main.cpp #included both foo.h and goo.h, both versions of doSomething() were 
	included into the global namespace, which is why the naming collsion resulted.

	in order to help avoid issues where two independent pieces of code have naming collisions with each other when used together, C++ allows us to declare
	our own namespaces via the namespace keyword. Anything declared inside a user-defined namespace belongs to that namespace, not the global namespace.

	Here's an example of the headers in the first examples rewritten using namespaces:

	foo.h

	namespace Foo{
	// This doSomething() belongs to namespace Foo
		int doSomething(int x, int y){
			return x + y;
		}
	}

	goo.h

	namespace Goo{
	// This doSomething() belongs to namespace Goo
		int doSomething(int x, int y){
		return x - y;
		}
	}

	Now the doSomething() inside of foo.h is inside Foo namespace, and the doSomething() inside of goo.h is inside the Goo namespace. Lets see what happens
	when we recompile main.cpp

	main.cpp:

	int main(){
		std::cout << doSomething(4, 3); // which doSomething will we get?
		return 0;
	}

	The answer is that now we get another error!

	C:\VCProjects\Test.cpp(15) : error C2065: 'doSomething' : undeclared identifier

	What happened is that when we tried to call the doSomething() function. the compiler looked in the global namespace
	to see if it could find a definition of doSomething(). However because neither if our doSomething() functions live inside the global namespace, it failed
	to find a definition at all!

	There are two different ways to tell the compiler which version of doSomething to use, via the scope resolution operator (::)
	or via using statements (which well discuss in the next lesson).

	Accessing a namespace with the scope resolution operator (::):

	The first way to tell the compiler to look in a particular namespace for an identifier is to use the scope resolution operator (::). this operator allows
	you to prefix an identifier name with the namespace you wish to use.

	for example:

	int main(){
	std::cout << Foo::doSomething(4, 3);
	return 0;
	}

	This produces the result:

	7

	IF we wanted to use the version of doSomething() that lives in Goo instead:

	int main(){
	std::cout << Goo::doSomething(4, 3);
	return 0;
	}

	this produces the result:

	1

	The scope resolution operator is v ery nice because it allows us to specifically pick which namespave we want to look in.
	it even allows us to do the following:

	int main(){
	std::cout << Foo::doSomething(4 , 3);
	std::cout << Goo::doSomething(4 , 3);
	return 0;
	}

	this produces the result:

	7
	1

	It is also possible to use the scope resolution operator without any namespace (eg. ::doSomething). In that case, it refers to the global namespace.

	Multiple namespace blocks with the same name allowed:

	It's legal to declare namespace blocks in multiple locations (either accross multiple filesm or multiple places within the same file). All declarations
	within the namespace block are considered part of the namepsace.
	
	add.h

	namespace BasicMath{	
		// function add() is part of namespace BasicMath
		int add(int x, int y){
	
		return x + y;
		}
	}

	subtract.h:

	namespace BasicMath{
		// function subtract() is also part of namespace BasicMath
			int subtract(int x, int y){
			return x - y;
			}
	}

	main.cpp:
	#include "add.h" // import BasicMath::add()
	#include "subtract.h" // import BasicMath::subtract()
	#include <iostream>

	int main(){
		std::cout << BasicMath::add(4, 3) << '\n';
		std::cout << BasicMath::subtract(4, 3) << '\n';

		return 0;
	}

	This works exactly as you would expect.

	The standard library makes extensive use of this feature, as all of the different header files included with the standard library have their
	functionality inside namespace std.

	Nested namespaces and namespace aliases:

	Namespaces can be nested inside other namespace. for example:

	#include <iostream>

	namespace Foo{
		namespace Goo{ // Goo is a namespace inside the Foo namespace
			const int g_x = 5;
		}
	}

	int main(){
		std::cout << Foo::Goo::g_x;
		return 0;
	}

	Note that because namespace Goo is inside of namespace Foo, we access g_x as Foo::Goo::g_x.

	In C++17, nested namespaces can also be declared this way:

	namespace Foo::Goo //Goo is a namespace inside the Foo namespace (C++17 style).

	Becuse typing the fully qualified name of a variable or function inside a nested namespace can be painful, C++ allows you to create namespace aliases:

	namespace Boo = Foo::Goo; // Boo now refers to Foo::Goo

	It’s worth noting that namespaces in C++ were not designed as a way to implement an information hierarchy
	-- they were designed primarily as a mechanism for preventing naming collisions. As evidence of this, note that the entirety
	of the standard template library lives under the singular namespace std::. Some newer languages (such as C#) differ from C++ in this regard.

	In general, you should avoid nesting namespaces if possible, and there are few good reasons to nest them more than 2 levels deep.
	However, in later lessons, we will see other related cases where the scope resolution operator needs to be used more than once.

	4.3c - Using statements

	if you use functions from a certain namespace a lot in a function, you can use a using declaration to make things a little bit easier for yourself:

	int main(){
	using std::cout; // from now on you can just type cout when you want to use the std::cout function.

	theres also the using directive statement:

	using namespace std; //now every function (for example, cout, cin, endl) can be used without the std:: prefix (this is generally not a good idea)

	Limiting the scope of using declarations and directives:

	Limiting the scope of using declarations and directives

	If a using declaration or using directive is used within a block, the using statement applies only within that block (it follows normal scoping rules).
	This is a good thing, as it reduces the chances for naming collisions to occur just within that block. However,
	many new programmers put using directives into the global scope. This pulls all of the names from the namespace directly into the global scope,
	greatly increasing the chance for naming collisions to occur. This is considered bad practice.

	Rule: Avoid “using” statements outside of a function (in the global scope).

	There’s some debate about whether using directives are okay to use within functions, where their impact is limited. However,
	our take is that using declarations are the better choice if using statements are desired, and that using directives should be avoided entirely.

	Suggestion: We recommend you avoid “using directives” entirely.

	4.4 - Implicit type conversion (coercion)

	So since the value of a variable is stored as a sequence of bits, and the data type tells the compiler how to interpret those bits into meaningful values.
	Different data types may represent the "same" number differently. for example, the integer value 3 and the float value 3.0 are stored as completely different
	binary patterns.

	So when we do something like this:

	float f = 3; // initializing floating point f with integer 3.

	in this case, the compiler can't just assign the value straight away. it has to first convert the integer 3 to a floating point number and only after that
	can the compiler assign it to our variable f.

	This process of converting a value from one data type to another is called a type conversion. Type conversions can happen in many different cases:

	- Assigning or initializing a variable with a value of a different data type:

	double d { 3 }; / initializing double variable with integer value 3
	d = 6; // assigning an integer value to our double variable.

	- passing a value to a function where the function parameter is of a different data type:

	void doSomething(long l){
	}

	doSomething(3); // pass an integer value 3 to a function expecting a long parameter.

	- Returning a value from a function where the function return type is of a different data type:

	float doSomething(){
	return 3.0; // return double value 3.0 back to caller through float  return type.
	}

	- Using a binary operator with operands of different types:

	double division = 4.0 / 3; // division wiht a double and an integer.

	in all of these cases (and quite a few others) C++ will use type conversion to convert data from one type to another.

	there are two basic types of data conversion: implicit type conversion, where the compiler automatically transforms one fundamental data type into another,
	and explicit type conversions, where the developer uses a casting operator  to direct the conversion.

	We'll go into implicit type conversion in this lesson and explicit in the next..

	Implicit type conversion:

	Implicit type conversion (also called automatic type conversion or coercion) is performed whenever one fundanmental data type is expected, but a different fundamental
	data type is supplied, and the user does not explicitly tell the compiler how to perform this conversion (via a cast).

	all of the above examples have used this method.

	there are two basic types of implicit type conversion: promotions  and conversions.

	Numeric promotion:

	Whenever a value from one type is converted into a value of a larger similar data type, this is called a numeric promotion (or widening, though this term 
	is usually reserved for integers). For example, an int can be widened into a long, or a float be promoted into a double:

	long l { 64 }; // widen the integer 64 into a long
	double d { 0.12f }; // promote the float 0.12 into a double.

	while the term "numeric promotion" covers any type of promotion, there are two other terms with specific meanings in C++:
		- integral promotion involves the conversion of integer types narrower than int (which includes bool, char, unsigned char, unsigned shortm signed short)
		to an int (if possible) or an unsigned int (otherwise)
		- Floating point promotion involves the conversion of a float to a double.

	integral promotion and floating point promotion are used in specific cases to convert smaller data types to int/unsigned int or double,
	because int and double are generally the most performant types to perform operations on.

	It's important to know that promotions are always safe and no data loss will result. Under the hood,
	promotions generally involve extending the binary representation of a number (e.g. for integers, adding leading 0s).

	Numeric conversions:

	When we convert a value from a larager type to a similar smaller type or between different types, this is called a numeric conversion. For example:

	double d { 3 }; // convert integer 3 into a double (between different types).
	short s { 2 }; // convert integer 2 to a short (from larger to smaller type).

	Unlike promotions, which are always safe, conversions may or may not result in a loss of data.
	Because of this, any code that does an implicit conversion will often cause the compiler to issue a warning (on the other hand
	, if you do an explicit conversion using a cast, the compiler will assume you know what you’re doing and not issue a warning).
	Under the hood, conversions typically require converting the underlying binary representation to a different format.

	The rules for conversions are complicated and numerous, so we’ll just cover the common cases here.

	In all cases, converting a value into a type that doesn’t have a large enough range to support the value will lead to unexpected results.
	This should be avoided. For example:

	int i { 30000 };
	char c { i };

	std::cout << static_cast<int>(c);

	in this example, we've assigned a large integer to a char (that has range -128 to 127) Which causes it to overflow and provide an undefined result:

	48

	However, converting from a larger integral or floating point type to a smaller similar type will generally work so long as the value fits in the range
	of the samller type, for example:

	int i { 2 };
	short s { i }; // convert from int to short.

	std::cout << s;

	double d { 0.1234};
	float f { d };
	std::cout << f;

	this produces the expected result:

	2
	0.1234

	In the case of floating point values, some rounding errors are bound to happen when converting from a larger type to a smaller one.

	converting from a floating point to an integer generally works as long as the value can fit into the integer, but any fractual values are lost

	int i { 3.5 };
	std::cout << i ;

	Produces the value: 
	
	3

	Evaluating arithmetic expressions:

	when evaluating expressions, the compiler breaks each expression down into individual subexpressions.
	the arithmetic operators require their operands to be of the same type. To ensure this, the compiler uses the following rules:

	- if an operand is an integer that is narrower that an int, it undergoes integral promotion (as described above) to int or unsigned int.
	- if the operands still do not match, the compiler finds the highes priority operand and implicitly converts the other operand to match.

	The priority of operands is as follows:

	- long double (highest)
	- double
	- float
	- unsigned long long
	- long long
	- unsigned long
	- long
	- unsigned int
	- int (lowest)

	we can see the usual arithmetic conversion take place via use of the typeid() operator (included in the typeinfo header),
	which can be used to show the resulting type of an expression.

	This hierarchy can cause some rather interesting errors. For example, take a look at this code:

	std::cout << 5u - 10; // 5u means treat 5 as unsigned integer

	you might expect the expression 5u - 10 to evaluate to -5 since 5 - 10 = -5. but heres what actually happends:

	4294967291

	in this case, the signed integer (10) is promoted to an unsigned integer (which has higher priority), and the expression is evaluated as an unsigned int.
	since -5 cant be stored in an unsigned int, overflow results and we get unexpected results.
	this is one of many good reasons to avoid unsgned integers in general.

	4.4a - explict type conversion (casting)

	many new programmers try something like this: float f = 10 / 4;. however, because 10 and 4 are both integers, no promotion takes place. integer division
	is performed on 10 / 4, resulting in the value  of 2, which is then implicitly converted to 2.0 and assigned to f!

	in this case where you are using literal values ( 10 and 4) replacing one or  both of the integer literal value with a floating point literal value (10.0.
	4.0) will cause both operands to be converted to floating point values, and the division will be done using floating point math.

	but what if you're using variables? consider this case:

	int i1 = 10;
	int i2 = 4;
	float f = i1 / i2;

	variable f will end up with value of 2. to tell the compiler we want to use floating point division instead, we use a type casting operator (commonly known
	as a cast) to tell the compiler to do explicit type conversion. A cast represents an explicit request by the programmer to do a type conversion.

	Type casting:

	in C++ there are 5 different types of casts: C-style casts, statics casts, const casts, dynamic casts, and reinterpret casts.

	We'll cover C-style casts and static casts in this lesson. Dynamic casts we'll save until after we cover pointers and inheritance.

	Const casts and reinterpret casts should generally be avoided because they are only useful in rare cases and can be harmful if used incorrectly.

	Rule: Avoid const casts and reinterpret casts unless you have a very good reason to use them.


	C-style casts:

	in standard C programming, casts are done via the ()-operator, with the name of the type to cast inside. For example:
	int i1 = 20;
	itn i2 = 5;
	float f = (float)i1 / i2;

	in the above program we use float cast to tell the compiler to convert i1 to a floating point value. because i1 is a floating point value,
	i2 will be converted to a floating point value as well.

	C++ will also let you use a C-style cast with a more function-call like syntax:
	int i1 = 10;
	int i2 = 4;
	float f = float(i1)  / i2;

	Because C-style casts arent checked by the compiler at compile time, C-style  casts can be ingerently misused, because they will let you do things that
	may not make sense, such as getting rid of a const or changing a data type without changing the underlying representation (leading to garbage result).

	Consequently, C-style casts should generally be avoided

	Rule: Avoid C-style casts.

	static_cast:

	C++ introduces a casting operator called static_cast. You've previously seen static_cast used to convert a char into an int so that std::cout
	prints it as an integer instead of a char:

	char c = 'a';
	std::cout << static_cast<int>(c) << std::endl; //prints 97, not 'a'.

	Static_cast is best used to convert one fundamental type into another:

	int i1 = 10;
	int i2 = 4;
	float f = static_cast<float>(i1) / i2;
	the main adventage of static_cast is that it provieds compile-time type checking, making it harder to make an inadvertent error. Static_cast is also
	(intentionally) less powerful than C-style casts, so you can't inadvertently remove const or do other things you may not have intended to do.

	Usings casts to make implicit type conversions clear:

	Compilers will often complain when an unsafe implicit type conversion is performed. For example, consider the following program:

	int i = 48;
	char ch = i;

	casting an int (4 bytes) to a char (1 byte) is potentilly unsafem and the compiler will typically complain. In order to announce to the compiler that you
	are explicitly doing something you recognize is potentially unsafe (but want to do anyways) you can use a cast:

	int i = 48;
	char ch = static_cast<char>(i);

	in the following program the compiler will typically complain that converting a double to an int may result in loss of data:
	int i = 100;
	i = i / 2.5;
	
	To tell the compiler that we explicitly mean to do this:

	int i = 100;
	i = static_cast<int>(i / 2.5);

	Summary:

	casting should be avoided if atr all possible, because any time a cast is useed, there is potential for trouble.
	but there are emany times when it  can not be avoided. In most of these cases, the C++ static_cast should be used instead of the C-style cast.




	in the following program, the compiler will typically complain that converting a double to an int may result in loss of data:

	4.4b - An introcution to std::string:

	What is a string?

	The very first program we wrote:

	#include <iostream>

	int main(){
		std::cout << "Hello World! << std::end;
		return 0;
	}

	so what exactly is "Hello world!"? "Hello world!" is a collection of sequential characters called a string. In C++ we use strings to represent text such
	names, addresses, words, and sentences. String literals (such as "Hello world!") are placed between double quotes to identify them as a string.

	Because strings are commonly used in programs, most modern languages include a buil-in string data type. C++ includes one, not as part of the core language
	but as part of the standard library.

	std::string:

	To use strings in C++ we first need to #include the <string> header to bring in the declarations for std::string. Once that is done, we can define 
	variables of type std::string.

	#include <string>

	std::string myName;

	just like normal variables, you can initialize or assign values to strings as you would expect:

	std::string myName { "Juho" }; // initialize myName with string literal "Juho".
	myName = "Sharon"; // Assign variable myName the string literal "Sharon".

	Note that strings can hold numbers aswell:
	std::string myID { "45" }; // "45" is not the same as integer 45!

	In string form, numbers are treated as text, not numbers, and thus they cant be manipulated as numbers (e.g. you cant multiply them) C++ will not
	automatically convert string numbers to integer or floating point values.

	String input and output:

	Strings can be output as expected using std::cout:

	#include <string>
	#include <iostream>

	int main(){
		std::string myName { "Juho" };
		std::cout << "My name is: " << myName << "\n";

		return 0;
	}

	This prints:

	My name is: Juho

	However, using strings with std::cin may yield some surprises! Consider the following example:

	#include <string>
	#include <iostream>

	int main(){
		std::cout << "Enter your full name: ";
		std::string name;
		std::cin >> name; // This wont work as expected since std::cin breaks on whitespace

		std::cout << "Enter your age: ";
		std::string age;
		std::cin >> age;

		std::cout << "Your name is " << name << " and your age is " << age << "\n";

		return 0;

	}

	Here's the results from a sample run of this program:

	Enter your full name: John Doe
	Enter your age: Your name os John and your age is Doe

	Hmmmm..... That isn't right :thinking: WTF!? It turns out when using operator>> to extract string from cin, operator>> only returns charactes up to the
	first whitespace it encounters. Any other characters are left inside cin, waiting for the next extraction.

	So when we used operator>> to extract string into variable name, only "John" was extrated leaving "Doe" inside std::cin, waiting for the next extraction. 
	
	Kakka.

	When we then used operator>> to get variable age, it extracted "Doe" intstead of waiting for us to input an age. We are never given a chance to enter an age.

	Use std::getline() to input text:

	To read a full line of input into a string, you're better off using the std::getline() function instead. std::getline takes two parameters: the first is 
	std::cin, and the second is your string variable.

	Heres the same program as above using std::getline:

	#include <string>
	#include <iostream>

	int main(){
		std::cout << "Enter your full name: ";
		std::string name;
		std::getline(std::cin, name); // Read a full line of text into name

		std::cout << "Enter your age: ";
		std::string age;
		std::getline(std::cin, age); // read full line of text into age

		std::cout << "Your name is " << name << " and your age is " << age << "\n";

		return 0;

	}

	Now the program works:

	Enter your full name: John Doe
	Enter your age: 23
	Your name is John Doe and your age is 23

	mixing std::cin and std::getline():

	Reading inputs with both std::cin and std::getline may cause some unexpected behaviour. Consider the following:

	#include <string>
	#include <iostream>

	int main(){
		std::cout << "Pick 1 or 2: ";
		int choice { 0 };
		std::cin << choice;

		std::cout << "Now enter your name: ";
		std::string name;
		std::getline(std::cin, name);
		
		std::cout << "Hello, " << name << ", you picked " << choice << "\n";

		return 0;

	}

	This program first asks you to enter 1 or 2, and waits for you to do so. all good so far. then it will ask you to enter your name. however,
	it wont actually wait for you to do so! Instead, it prints the "Hello" line, and then exits. What the hell happened?

	It turns out, when you enter a value using std::cin, cin not only captures the value, it also captures the newline. So when we enter 2, cin actually gets
	the string "2\n". It then extracts the 2 to variable choice, leaving the newline stuck in the input stream. Then when std::getline() gies ti read the name
	it sees "\n" is already in the stream,, and figures we must have entered an empty string! 

	kakka

	A good rule of thumb is that after reading a value with std::cin, remove the newline from the stream. This can be done using the following:

	std::cin.ignore(32767, '\n'); // ignore up to 32767 characters until a \n is removed.

	If we instert this line directly after reading variable choice, the extraneous newline will be removed from the stream, and the program will work as
	expected:

	int main(){
		std::cout << "Pick 1 or 2: ";
		int choice { 0 };
		std::cin >> choice;

		std::cin.ignore(32767, '\n');

		std::cout << "Now enter your name: ";
		std::string name;
		std::getline(std::cin, name);

		std::cout << "Hello, " << name << ", you picked " << choice << '\n';

		return 0;

	}

	Rule: If reading values with std::cin, its a good idea to remove the extraneous newline using std::cin.ignore().

	what's that 32767 magic number in this code?

	that thells std::cin.ignore() how many characters to ignore up to. we picked that number because its the largest signed value guaranteed to fit in a
	(2-byte) integer on all platforms.
	
	technically the correct way to ignore an unlimited amount of input is as follows:

	#include <limits>

	...

	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	// ignore unlimited characters until a \n is removed

	but this requires remembering (or looking up) that horrendous line of code, as well as remembering what header to include. Most of the time you wont need 
	to ignore more that a line or two of buffered input, so for practical purposes, 32767 works about as well, and has the benefit of being something you can
	actually remember in your head.

	throughout these tutorials we use 32767 for this reason. However its your choice weheter you want to do it the "obscure, complex, and correct" way or the
	"easy, practical, but not ideal" way.

	Appending strings:

	You can use operator+ to concatenate two strings together, or operator+= to append one sting to append one string to another. 

	Here's an example of both, also showing what happens if you try to use operator+ to add two numeric strings together:

	#include <string>
	#include <iostream>

	int main(){
		std::string a { "45" };
		std::string b { "11" };

		std::cout << a + b << "\n"; // a and b will be appended, not added

		a+= " volts";
		std::cout << 2;

		return 0;

	}

	This prints:

	4511
	45 volts

	Note that operator+ concatenated the strings "45" and "11" into "4511". It did not add them as numbers.

	String length:

	If we want to know how long a string is, we can ask the string for its length. the syntax for doing this is different than you've seen beforem but its
	pretty straightforward:

	#include <string>
	#include <iostream>

	int main(){
		std::string myName { "Juho" };
		std::cout << myName << " has " << myName.length() << " characters \n";

		return 0;

	}

	This prints:

	Juho has 4 characters

	Note that instead of asking for the string length as length(myName), we say myName.length().

	The length function isn't a normal standalone function like we've used up to this point -- its a special type of function that belongs to std::string called
	a member function. We'll cover member functions, including how to write your own, in more detail later.

	Conclusion:

	std::string is complex, leveraging many language features that we haven't covered yet. It also has a lot of other capabilities that we haven't touched
	on here. Fortunately, you dont need to understand these complexities to use std::string for simple tasks, like basic string input and output. We encourage
	to experiment with strings now, and we'll cover additional string capabilities later.

	Quiz:

	1)Write a program that asks the user to enter their full name and their age. As output, tell the user how many years they've lived
	for each letter in their name (for simplicity count spaces as a letter).

	Sample output:

	Enter your full name: John Doe
	Enter your age: 46
	You've lived 5.75 years for each letter in your name.
	*/

	// 1)
	std::cout << "Enter your full name: ";
	std::string name;
	std::getline(std::cin, name);

	std::cout << "enter your age: ";
	double age;
	std::cin >> age;

	std::cin.ignore(32767, '\n');
	
	std::cout << "You've lived " << age / name.length() << " years for each letter in your name. \n";

	/* 4.5 - Enumerated types:

	C++ contains quite a few built in data types. But these types arent always sufficient for the kinds of things we want to do. so C++ contains capabilities
	that allow programmers to create their own data types. These data types are called user-defined data types.

	Perhaps the simplest user-defined data type is the enumerated type. an enumerated type (also called an enumeration) is a data type where every possible
	value is defined as a symbolic constant(called enumerator). Enumerations are defined via the enum keyword. Let's take a look at an example:

	// define a new enumeration named Color.
	enum Color{
		// here are the enumerators
		// These define all the possible values this type can hold
		// each enumerator is seperatyed by a comma not a semicolon
		COLOR_BLACK,
		COLOR_RED,
		COLOR_BLUE,
		COLOR_GREEN,
		COLOR_WHITE,
		COLOR_CYAN,
		COLOR_YELLOW,
		COLOR_MAGENTA, // see note about trailing comma on the last enumator below
	}; //However the enum itself must end with a semicolon 

	// define a few variables of enumerated type color
	Color paint = COLOR_WHITE;
	Color house = (COLOR_BLUE);
	Color apple { COLOR_RED };

	Defining an enumeration (or any user-defined data type) does not allocate any memory. When a variable of the enumerated type is defined (such as
	variable paint in the example above), memory is allocated for that variable at that time.

	Note that each enumerator is separated by a comma, and the entire enumeration is ended with a semicolon.

	Prior to C++11 a trailing comma after the last enumerator (e.g. after COLOR_MAGENTA) is not allowed (though many compilers accepted it anyway).
	However, starting with C++11, a trailing comma is allowed. Now that C++11 compilers are more prevalent, use of a trailing comma after the last 
	element is generally considered acceptable.

	Naming enums:

	Enum identifiers are often named starting with a capital letter, and the enumerators are often named using all caps. because enumerators are placed 
	into the same namespace as the enumeration, an enumerator name can't be used in multiple enumerations within the same namespace:

	enum Color{
		RED,
		BLUE, // BLUE is put into the global namespace
		GREEN
	};

	enum Feeling{
		HAPPY,
		TIRED,
		BLUE // error, BLUE was already used in enum Color in the global namespace
	};

	Consequently, it’s common to prefix enumerators with a standard prefix like ANIMAL_ or COLOR_, both to prevent naming conflicts
	and for code documentation purposes.

	Enumerator values:

	Each enumerator is automatically assigned an integer value based on its position in the enumeration list. By default,
	the first enumerator is assigned the integer value 0, and each subsequent enumerator has a value one greater than the previous enumerator:

	enum Color{
		COLOR_BLACK, // assigned 0
		COLOR_RED, // assigned 1
		COLOR_BLUE, // assigned 2
		COLOR_GREEN, // assigned 3
		COLOR_WHITE, // assigned 4
		COLOR_CYAN, // assigned 5
		COLOR_YELLOW, // assigned 6
		COLOR_MAGENTA // assigned 7
	};

	Color paint(COLOR_WHITE);
	std::cout << paint;

	The cout statement prints the value 4.

	It is possible to explicitly define the value of enumerator. these integer  values can be positive or negative and can share the same value as other
	enumerators. Any non-defined enumerators are given a value on greater than the previous enumerator.

	// define a new enum named Animal

	enum Animal{
		ANIMAL_CAT = -3,
		ANIMAL_DOG, // assigned -2
		ANIMAL_PIG, // assigned -1
		ANIMAL_HORSE = 5,
		ANIMAL_GIRAFFE = 5, // shares same value as ANIMAL_HORSE
		ANIMAL_CHICKEN // assigned 6
	};

	Note in this case, ANIMAL_HORSE and ANIMAL_GIRAFFE have been given the same value. When this happens, the enumerations become non-distinct
	-- essentially, ANIMAL_HORSE and ANIMAL_GIRAFFE are interchangeable. Although C++ allows it, assigning the same value to two enumerators
	in the same enumeration should generally be avoided.

	Best practice: Don’t assign specific values to your enumerators.
	Rule: Don’t assign the same value to two enumerators in the same enumeration unless there’s a very good reason.

	Enum type evaluation and input/output

	Because enumerated values evaluate to integers, they can be assigned to integer variables. This means they cacn also be output (as integers), since 
	std::cout knows how to output integers.

	int mypet = ANIMAL_PIG
	std::cout << ANIMAL_HORSE; // evaluates to integer before being passed to std::cout

	This produces the result:

	5

	The compiler will not implicitly convert an integer to an enumerated value. The following will produce a compiler error:

	Animal animal = 5; // will cause compiler error

	However you can force it to do so via a static cast:

	Color color = static.cast<Color>(5);

	The compiler also will not let you input an enum using std::cin:

	enum Color{
		COLOR_BLACK, // assigned 0
		COLOR_RED, // assigned 1
		COLOR_BLUE, // assigned 2
		COLOR_GREEN, // assigned 3
		COLOR_WHITE, // assigned 4
		COLOR_CYAN, // assigned 5
		COLOR_YELLOW, // assigned 6
		COLOR_MAGENTA // assigned 7
	};

	Color color;
	std::cin >> color; // will cause compiler error

	One workaround is to read in an integer, and use static cast to force the compiler to put an integer value into an enumerated type:

	int inputColor;
	std::cin >> inputColor;

	Color color = static.cast<Color>(inputColor);

	 Each enumerated type is considered a distinct type. Consequently, trying to assign enumerators from one enum type to another enum type 
	 will cause a compile error:

	 Animal animal = COLOR_BLUE; // Will cuase compiler error

	 As with constant variables, enumerated types show up in the debugger, making them more useful that #defined values in this regard.

	 Printing enumerators:

	 As you saw above, trying to print an enumerated value using std::cout results in the integer value of the enumerator being printed. So how can you print
	 the enumerator itself as text? One way to do so is to write a function and use an if statement:

	enum Color{
		COLOR_BLACK, // assigned 0
		COLOR_RED, // assigned 1
		COLOR_BLUE, // assigned 2
		COLOR_GREEN, // assigned 3
		COLOR_WHITE, // assigned 4
		COLOR_CYAN, // assigned 5
		COLOR_YELLOW, // assigned 6
		COLOR_MAGENTA // assigned 7
	};

	void printColor(Color color){
		if (color == COLOR_BLACK)
			std::cout << "Black";
		else if (color == COLOR_RED)
			std::cout << "Red";
		else if (color == COLOR_BLUE)
			std::cout << "Blue";
		else if (color == COLOR_GREEN)
			std::cout << "Green";
		else if (color == COLOR_WHITE)
			std::cout << "White";
		else if (color == COLOR_CYAN)
			std::cout << "Cyan";
		else if (color == COLOR_YELLOW)
			std::cout << "Yellow";
		else if (color == COLOR_MAGENTA)
			std::cout << "Magenta";
		else
			std::cout << "Who knows!";
	}

	Once you've learned to use switch statements you'll probably want to use thse instead of a bunc of if/else statements, as it's a little more readable.

	Enum allocation and forward declaration:

	Enum types are considered a part of the integer family of types, and its up to the compiler to determine how much memory to allocate for an enum variable.
	The C++ standard says the enum size needs to be large enough to represent all of the enumerator values. most often it will make enum variables the same
	size as a standard int.

	Because the compiler needs to know how much memory to allocate for an enumeration, you cannot forward declare enum types. However, there is an easy
	workaround. Because defining an enumeration does not allocate any memory, if an enumeration is needed in multiple files, it is fine to define the 
	enumeration in a header, and #include that header wherever needed.

	What are enumerators useful for?

	Enumerated types are incredibly useful for code documentation and readability purposes when you need to represent a specific, predefined set of states.

	For example, functions often return integers to the caller to represent error codes when something went wrong inside the function. Typically, small
	negative numbers are used to represent different possible error codes. For example:

	int readFileContents(){
		if (!openFile())
			return -1;
		if (!readFile())
			return -2;
		if (!parseFile())
			return -3;

		return 0; // success!

	}

	However, using magic numbers like this isn't very descriptive. An alternative method would be through use of an enumerated type:

	enum ParseResult{
		SUCCESS = 0,
		ERROR_OPENING_FILE = -1,
		ERROR_READING_FILE = -2,
		ERROR_PARSING_FILE = -3
	};

	ParseResult readFileContents(){
		if (!openFile())
			return ERROR_OPENING_FILE;
		if (!readFile())
			return ERROR_READING_FILE;
		if (!parsefile())
			return ERROR_PARSING_FILE;

		return SUCCESS;
	}

	This is much  easier to read and understand than using magic number return values. Furthermorem the caller can test the functions return value
	against the appropriate enumerator, which is easier to understand  that testing the retrn result for a specific integer value.

	if (readFileContents() == SUCCESS){
		// do something
	}
	else{
		// print error message
	}

	Enumerated types are best used when defining a set of related identifiers. For example, let's say you were writing a game where the player can carry
	one item, but that item can be several different types. you could do this:

	#include <iostream>
	#include <string>

	enum ItemType{
		ITEMTYPE_SWORD,
		ITEMTYPE_TORCH,
		ITEMTYPE_POTION
	};

	std::string getItemName(ItemType itemType){
		if (itemType == ITEMTYPE_SWORD)
			return std::string("Sword");
		if (itemType == ITEMTYPE_TORCH)
			return std::string("Torch");
		if (itemType == ITEMTYPE_POTION)
			return std::string("Potion");

	// Just in case we add a new item in the future and forget to update this function
	return std::string("???");
	}

	int main(){
		// ItemType is the enumerated type we've defined above.
		// itemType (lower case i) is the name of the variable we're defining (of type ItemType).
		// ITEMTYPE_TORCH is the enumerated value we're initializing variable itemType with.
		ItemType itemType = ITEMTYPE_TORCH;

		std::cout << "You are carrying a " << getItemName(itemType) << "\n";

		return 0;
	}

	Or alternatively, if you were writing a function to sort a bunch of values:

	enum SortType{
		SORTTYPE_FORWARD,
		SORTTYPE_BACKWARDS
	};

	void sortData(SortType type){
		if (type == SORTTYPE_FORWARD)
			// sort data in forward order
		else if (type == SORTTYPE_BACKWARDS)
			// sort data in backwards order
	}

	Many languages use Enumerations to define booleans. A boolean is essentially just an enumeration with 2 enumerators: false and true! However, in C++
	true and false are defined as keywords instead of enumerators.

	Quiz:

	1) Define an enumerated type to choose between the following monster races: orcs, goblins, trolls, ogres, and skeletons.

	enum MonsterType(){
		MONSTERTYPE_ORCS,
		MONSTERTYPE_GOBLINS,
		MONSTERTYPE_TROLLS,
		MONSTERTYPE_OGRES,
		MONSTERTYPE_SKELETONS
	};

	int main(){

		MonsterType monster = MONSTERTYPE_TROLLS;


	4.5a - Enum classes

	Although enumerated types are distinct types in C++, they are not type safe, and in some caes will allow you to do things that dont make sense.
	Consider the following case:

	#include <iostream>

	int main (){
		enum Color{
			RED, // RED is placed in the same scope as Color
			BLUE
		};

		enum Fruit{
			BANANA, // BANANA is placed in the same scope as Fruit
			APPLE
		};

		Color color = RED; // Color and RED can be accessed in the same scope (no prefix needed)
		Fruit fruit = BANANA; // Fruit and BANANA can be accessed in the same scope (no prefix needed)

		if (color == fruit) // the compiler will compare a and b as integers
			std::cout << "color and fruit are equal\n"; // and find they are equal
		else
			std::cout << "color and fruit are not equal \n";
		return 0;
	}

	When C++ compares color and fruit, it implicitly converts color and fruit to integers, and compares the integers. Since color and fruit have both been
	set to enumators that evaluate to value 0, this means that in the above example, color will equal to fruit. this definitely not as desired since color
	and fruit are from different enumerations and are not intended to be comparable! With standard enumerators, there is no way to prevent comparing 
	enumerators from different enumerations

	C++11 defines a new concept, the enum class (also called a scpoped enumeration), which makes enumerations both strongly typed and strongly scoped. 
	To make an enum class, we use the keyword calss after the enum keyword. heres an example:

	#include <iostream>

	int main (){
		enum class Color{ // "enum class" defines this as a scoped enumeration instead of a standard enumeration
			RED, // RED is inside the scope of Color
			BLUE
		};

		enum calss Fruit{
			BANANA, // BANANA is inside the scope of Fruit
			APPLE
		};

		Color color == Color::RED; // note: RED is not directly accessible any more, we have to use Color::RED
		Fruit fruit == Fruit::BANANA // Note: BANANA is not directly accessible any more, we have to use Fruit::BANANA

		if (color == fruit) // Compile error here, as the compiler doesnt know how to compare different types Color and Fruit
			std::cout << "color and fruit are equal \n";
		else
			std::cout << "color and fruit are not equal \n";

		return 0;

	}

	With normal enumerations, enumerators are placed in the same  scope as the enumeration itself, so you can typically access enumerators directly (e.g.
	RED). However with enum calsses, the strong scoping rules mean that all enumerators are cosnidered part of the enumeration, so you have to use a scope 
	qualifier to access the enumerator (e.g. Color::RED). This helps keep name pollution and the potential for name conficts down.

	Because the enumerators are part of the enum class, there's no need to prefix the enumerator names (e.g. its okay to use RED instead of COLOR_RED, since
	Color::COLOR_RED is redundant).

	The strong typing rules means that each enum class is considered a unique type. this means that the compiler will not implicitly compare enumerators
	from different enumerations. if you try to do som the compiler will throw an error, as shown in the example above.

	However, nhote that you can still compare enumerators from within the same enum class (since they are of the same type):

	#include <iostream>

	int main (){
		enum class Color{
			RED,
			BLUE
		};

		Color color = Color::RED

		if (color = Color::RED) // this is ok
			std::cout << "The color is red! \n";
		else if (color = Color::BLUE)
			std::cout << "The color is blue! \n";

		return 0;

	}

	With enum classes, the compiler will no longer implicitly convert enumerator values to integers. this is mostly a good thing. however there are 
	occasionally cases where it is useful to be aboke to do so. in these cases you can explicitly convert an enum class enumerator to an integer by using
	a static_cast t int:

	#include <iostream>

	int main(){
		enum class Color{
			RED,
			BLUE
		};

		Color color = Color::BLUE;

		std::cout << color; // wont work, because there's no implicit conversion to int
		std::cout << static_cast<int>(color); // will print 1
		
		return 0;

	}

	If you're using a C++11 compiler, there's little reason to use normal enumerated types instead of enum classes.

	Note that the class keyword along wiht the static keyword is one of the most overloaded keywords in the C++ language, and can have different meanings
	depending on context. Although enum classes use the class keyword, they aren't considered "classes" in the traditional C++ sense. We'll civer actual
	classes later.

	Also, just in case you ever run into it, "enum struct" is equivalent to "enum class". But this usage is not recommended and is not commonly used.
	

	4.6 - typedefs and type aliases

	Typedefs allow tje programmer to create an alias for a data type, and use the aliased name instead of the actual type name. To declare a typedef
	simply use the typedef keyword, followed by the type to alias, followed by the alias name:

	typedef double distnace_t; // define distance_t as an alias for type double

	// The following two statements are equivalent:
	double d HowFar;
	distance_t HowFar;

	By convention typedef names are declared using a "_t" suffix. this helps indicate that they are types and not variables. this also helps to prevent
	naming collision.

	Typedef doesnt define a new type, its just an alias for an existing type. A typedef can be used interchangeably anywhere a regular type can.

	Typedefs are useful in a number of situations.

	Using typedefs for legibility

	one use for typedefs is to help with documentation and legibility. Data type names such as char, int, long, double, and bool are good for describing
	what type a function returns, but  more often we want to know what purpose a return value serves.

	For example, consider the following function.

	int GradesTest();

	We can see that the return value is an iteger, but what does the integer mean? A letter grade? The number of questions missed? The students ID number?
	An error code? who knows! Int does not tell us anything.

	typedef int testScore_t;
	testScore_t GradeTest();

	However, using a return type of testScore_t makes it obvious that the function is returing a type that represents a test score.

	Using typedefs for easier code maintenance:










	
	*/





	
	const char *lause = { "Juho on kakka." };
	printf("%s", lause);

	return 0;
} //firstValue and secondValue dies here
