# Quantum Planning

A project to help with planning things and the controlled execution of plans.

## Building

The project currently uses eclipse for test driven development
with code coverage analysis.  This may change in future.

It uses CDT's internal builder. Googletest (with googlemock) is included 
as a git submodule. That subdirectory is excluded from being built by the
internal builder, instead, some include paths point here, and some source
files are included directly by the project's test runner, 
test/test_runner.cpp.

To execute the unit tests, the eclipse plugin "C/C++ Unit Testing Support"
should be installed, and a run configuration unter "C/C++ Unit" should be
generated.

Coverage analysis has been enabled in the debug setings of the C and C++ 
compilers.  After building and executing, the coverage analysis has to
be run by double-clicking on one of the coverage analysis output files
(ending in .gcda or .gcno). The coverage analysis will then open a
dedicated view with coverage percentages, and will also add red/green
background highlighting to the C/C++ source files in the editor.
