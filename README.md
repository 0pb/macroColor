# macroColor
simple header for colored output in c++

## How it works ## 
Small header which include macro.
Use `#include <windows.h>` for `SetConsoleTextAttribute` on Windows.
Use `#include <stdio.h> #include <iostream>` for `std::cout` on Linux.


### Features
* 6 colors possibles : blu, green, cyan, red, yellow, white
* Multi-line color (see "How to use" below or an [exemple](https://github.com/0pb/macroColor/blob/master/exemple/exemple.cpp))
* Nested color
* Work with std::cout
* Tested and working on : Windows Seven, Linux Mint, Msys2 with both mingw32 and 64
* You can easily remove the color in compilation with `#define REMOVE_COLOR`

## How to use ##
Simply drop the header file "macroColor" in your directory, then insert `#include "macroColor.h"` in your .cpp file.

How to use the basic macro : 
```bash
GREEN
(
	std::cout << "show up as green" ; 
)
```
Will show up in green.

The 6 color are : `GREEN BLU CYAN RED YELLOW WHITE`

To use nested color : 
```bash
GREEN
(
	std::cout << "1 - show up as green\n" ;
	RED
	(
		std::cout << "2 - show up as red\n" ;	
	) 
	std::cout << "3 - show up as green\n" ;
)
```


You can also use directly the color macro with `C_GREEN C_BLU etc.` however it won't revert back to white automatically.
```bash
C_YELLOW
std::cout << "Yellow without white afterward\n" ; 
int abc = 0 ; 
std::cout << abc << "\n" ; 
std::cout << "Still yellow\n" ; 
C_WHITE
```

The result of the exemple given in `exemple/` should show something like this : 

![exemple](result.png)


## Issues ##

Because the macro uses a `do { } while(0) ;`, it mean any variable, function, etc. declared in the macro will create an error if you try to use it outside of its scope.

### Forcing AINSI color (for msys2 on windows)

Simply put a `#define MSYS_COMP` right before the `#include "macroColor.h"` in your .cpp file.
Like so : 
```bash
#define MSYS_COMP
#include "macroColor.h"
```
If you wish to get your color back, simply delete the `#define MSYS_COMP` or comment it out with //

## Future ##
### What I plan to do in order
* More color and background
* Implementing a macro that resolve the issue mentionned above

If by miracle someone use this, please don't hesitate to send me your opinion on macroColor !