#include "Scripting.h"

Scripting::script::script()
{
	// Empty constructor
}

Scripting::script::script(const std::string st)
	: contents(st)
{
}

Scripting::script::script(const std::string st, const LANG la)
	: contents(st), lang(la)
{
}