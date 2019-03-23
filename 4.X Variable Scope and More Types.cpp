#include "pch.h"
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







	*/

	
	const char *lause = { "Juho on kakka." };
	printf("%s", lause);

	return 0;
} //firstValue and secondValue dies here
