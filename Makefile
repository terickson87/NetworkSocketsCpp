# https://linux.die.net/man/1/g++

# Find what to put for the recipe by running the command:
# g++ -MM filename.c

# To generate object files (no linker) run something like (using -c flag):
# g++ -o filename.o -c 

# Automatic variables
# https://www.gnu.org/software/make/manual/html_node/Automatic-Variables.html
# $@ == target name, ie "<target>: prerequisites \n \t recipe"
# $< == first prerequisite name
# $^ == The names of all the prerequisites, with spaces between them

# https://www.gnu.org/software/make/manual/html_node/Setting.html
# Variables defined with ‘=’ are recursively expanded variables. Variables defined with ‘:=’ or ‘::=’ are simply expanded variables

SRCDIR := src
BUILDDIR := build
BINDIR := bin

CFLAGS := -Wall
GDBFLAG := -ggdb
CPPFLAGS := -Wall -pedantic-errors -Weffc++ -Wextra -Wsign-conversion -Werror -std=c++14
# "-pedantic-errors",// Treat as errors the warnings demmanded by strict ISO C and ISO C++
# "-Wall",// All Compiler warnings
# "-Weffc++",// Effective C++ warnings
# "-Wextra",// Extra Compiler warnings
# "-Wsign-conversion",// Warn for implicit conversions that may change the sign of an integer value
# "-Werror",// Treat warnings as errors
# For GCC/G++, you can pass compiler flags -std=c++11, -std=c++14, -std=c++17, or -std=c++2a to enable C++11/14/17/2a support respectively.

# EXAMPLE 1:
# test: test.cpp test.h test2.h
#	g++ -o $@ $(GDBFLAG) $(CPPFLAGS) $<
#
# this is effectively the same as:
# g++ -o test -ggdb -Wall -pedantic-errors -Weffc++ -Wextra -Wsign-conversion -Werror test.cpp

# EXAMPLE 2:
# Ch9/Date.o: Ch9/Date.cpp Ch9/Date.h
#  	g++ -c -o $@ $(GDBFLAG) $(CPPFLAGS) $<
#
# Ch9/testDate.o: Ch9/testDate.cpp Ch9/Date.o Ch9/Date.h
#  	g++ -c -o $@ $(GDBFLAG) $(CPPFLAGS) $<
#
# Ch9/testDate: Ch9/testDate.o Ch9/Date.o
#  	g++ -o $@ $(GDBFLAG) $(CPPFLAGS) $^

# EXAMPLE 3:
# $(BUILDDIR)/Date.o: $(SRCDIR)/Date.cpp $(SRCDIR)/Date.h
#  	g++ -c -o $@ $(GDBFLAG) $(CPPFLAGS) $<
#
# $(BUILDDIR)/testDate.o: $(SRCDIR)/testDate.cpp $(SRCDIR)/Date.o $(SRCDIR)/Date.h
#  	g++ -c -o $@ $(GDBFLAG) $(CPPFLAGS) $<
#
# $(BINDIR)/testDate: $(SRCDIR)/testDate.o $(SRCDIR)/Date.o
#  	g++ -o $@ $(GDBFLAG) $(CPPFLAGS) $^

$(BUILDDIR)/RunInNewWsl.o: $(SRCDIR)/RunInNewWsl.cpp $(SRCDIR)/RunInNewWsl.h
 	g++ -c -o $@ $(GDBFLAG) $(CPPFLAGS) $<

$(BUILDDIR)/testRunInNewWsl.o: $(SRCDIR)/testRunInNewWsl.cpp $(SRCDIR)/RunInNewWsl.o
  	g++ -c -o $@ $(GDBFLAG) $(CPPFLAGS) $<

$(BINDIR)/testRunInNewWsl: $(SRCDIR)/testRunInNewWsl.o $(SRCDIR)/RunInNewWsl.o
  	g++ -o $@ $(GDBFLAG) $(CPPFLAGS) $^