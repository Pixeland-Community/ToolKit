#include "PixeHandler.h"



PixeHandler::PixeHandler()
{
}


PixeHandler::~PixeHandler()
{
}

// Exerpt from an article 
//
/*
template <typename Container = std::string,
		typename CharT = char,
		typename Traits = std::char_traits<char>>
auto read_file_into_memory(
		std::basic_ifstream<CharT, Traits>& in,
		typename Container::allocator_type alloc = {})
{
	// With an is_contiguous traits type, this can be
	// generalized to *any* container, and much easier.
	// You could do this with enable-if, too, to
	// to completely remove this function from the
	// overload set if the container type is wrong...
	// but i think static assert is more appropriate in
	// this context, and it will give more readable
	// errors.
	static_assert(
		// Allow only strings...
		std::is_same<Container, std::basic_string<CharT,
		Traits,
		typename Container::allocator_type>>::value ||
		// ... and vectors of the plain, signed, and
		// unsigned flavours of CharT.
		std::is_same<Container, std::vector<CharT,
		typename Container::allocator_type>>::value ||
		std::is_same<Container, std::vector<
		std::make_unsigned_t<CharT>,
		typename Container::allocator_type>>::value ||
		std::is_same<Container, std::vector<
		std::make_signed_t<CharT>,
		typename Container::allocator_type>>::value,
		"only strings and vectors of ((un)signed) CharT allowed");
	// You could also add other static assertions, like
	// confirming that the char type is trivially
	// copyable.

	auto const start_pos = in.tellg();

	in.ignore(
		std::numeric_limits<std::streamsize>::max());
	auto const char_count = in.gcount();

	in.seekg(start_pos);

	auto container = Container(std::move(alloc));
	container.resize(char_count);

	if (0 != container.size())
	{
		// reinterpret_cast is necessary if we want to
		// allow vector<char>, vector<unsigned char> (and
		// vector<signed char>, i guess). It's safe because
		// the enable-if guarantees that we're just dealing
		// with signed/unsigned variants.
		// Though if you're paranoid, you can put some
		// static asserts in to confirm this.
		in.read(reinterpret_cast<CharT*>(&container[0]),
			container.size());
	}

	return container;
}
*/