#ifndef PATTERNS_H_INCLUDED
#define PATTERNS_H_INCLUDED

// Redeclare pattern constants to work around variable redeclaration when including pattern.h multiple times.
enum Patterns
{
	IDP_CROSS = 1,
	IDP_CIRCLE = 2,
	IDP_TOWER = 3,
	IDP_TRIANGLE = 4
};

#endif // PATTERNS_H_INCLUDED