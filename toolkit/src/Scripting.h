#pragma once

#include <chaiscript\chaiscript.hpp>

// A lot of this is getting created quickly and will most likely be messy.
// I dislike writing just to refactor later but want to make something usable soon.
// Matt

// I should note that while I would like to allow multiple scripting languages it is
// just not in my capabilities to make that right now.

namespace Scripting
{
	enum LANG
	{
		chai
	};

	// A multilang script primitive. Could be completely useless
	// Will only support Chai right now.
	class script
	{
		// This should only ever need to be evaluated once for chaiscript.
		// Should I have it delete itself or make the evaluator delete it
		// when it is no longer needed? Going with the latter for now. 
	public:
		std::string contents;
		// Should go unused but I suppose for safety it is not bad to have
		LANG lang;

		script();
		script(const std::string);
		script(const std::string, const LANG);
		// ~script();

		script operator=(const std::string& st)
		{
			contents = st;
		}
	};

	std::unique_ptr<chaiscript::ChaiScript> create_chaiscript()
	{
		auto chai = std::unique_ptr<chaiscript::ChaiScript>(new chaiscript::ChaiScript());
		chai->add(create_chaiscript_main_bindings());
		return chai;
	}

	std::shared_ptr<chaiscript::Module> create_chaiscript_main_bindings()
	{
		return std::shared_ptr<chaiscript::Module>();
	}
};
