#ifndef ENPRINT_HPP
#define ENPRINT_HPP

#include <string_view>
#include <array>
#include <type_traits>

namespace enprint{

template<typename Enum, Enum v>
[[nodiscard]] constexpr auto strip_enum_element_str() noexcept{
	std::string_view pretty_function{__PRETTY_FUNCTION__};
	auto first = pretty_function.find_last_of("::")+1;
	auto last = pretty_function.length()-1-first;
	return pretty_function.substr(first, last);
}

template<typename ENUM, typename T, T... ints>
[[nodiscard]] std::string_view enum_as_string_view(std::integer_sequence<T, ints...> int_seq, const size_t i){
	using Array = std::array<std::string_view, int_seq.size()>;
	constexpr Array arr{{strip_enum_element_str<ENUM, ENUM(ints)>()...}};
	return arr.at(i);
}

template<size_t sz, typename ENUM>
[[nodiscard]] inline std::string_view enum_as_string_view(const ENUM i){
	return enum_as_string_view<ENUM>(
			std::make_index_sequence<sz>(), 
			static_cast<size_t>(i)
	);
}

template<typename ENUM>
[[nodiscard]] inline std::string_view enum_as_string_view(const ENUM i){
	return enum_as_string_view<static_cast<size_t>(ENUM::_Size), ENUM>(i);
}

} // enprint

#endif