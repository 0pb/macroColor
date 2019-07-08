# macroColor
Short header for colored output in c and c++

## How it works ## 
Small header which include macro.
It use :
* `#include <windows.h>` for `SetConsoleTextAttribute` on Windows.
* `#include <iostream>` for `std::cout` on Linux (c++).
* `#include <stdio.h>` for `printf()` on Linux (c).

### Features
* 7 colors possibles : blu, green, cyan, red, magenta, yellow, white
* It work with both C and C++ (with the same header)
* Multi-line color (see "How to use" below or an [exemple](https://github.com/0pb/macroColor/blob/master/exemple/exemple.cpp))
* Nested color
* It work with both std::cout and printf
* Tested and working : Windows Seven mingw, Linux Mint, Windows Seven Msys2 with both mingw32 and 64 (if you use the MSYS_COMP define)
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

The 7 color are : `GREEN BLU CYAN RED MAGENTA YELLOW WHITE`

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
* Maybe background
* Implementing a macro that resolve the issue mentionned above

If by miracle someone use this, please don't hesitate to send me your opinion on macroColor !