# Enprint

Auto-generates `std::string_view`s for c++ scoped enums elements provided some conditions are met:

- `__PRETTY_FUNCTION__` is available.
- The enum's underlying type can be converted to the index of an array.

## Usage

If you include an element `ENUM::_SIZE` at the end you may simply call the function `enprint::enum_as_string_view(ENUM::Element)` to get your string view:

```cpp 
#include <iostream>

enum class MyEnum{First, Second, Third, _SIZE};

inline std::ostream& operator<<(std::ostream& out, const MyEnum& value){
	return out << enprint::enum_as_string_view(value);
}

int main(){
	std::cout << MyEnum::First << '\n';
	std::cout << MyEnum::Third << '\n';
	return 0;
}
```

Alternatively, you may instead pass the size of the enum, writing instead `enprint::enum_as_string_view<SIZE>(ENUM::Element)`.

```cpp 
#include <iostream>

enum class MyEnum{First, Second, Third};

inline std::ostream& operator<<(std::ostream& out, const MyEnum& value){
	return out << enprint::enum_as_string_view<3>(value);
}

int main(){
	std::cout << MyEnum::First << '\n';
	std::cout << MyEnum::Third << '\n';
	return 0;
}
```

## Example

[Example](examples/example_01.cpp)

## License

Copyright (c) 2022 Rui Pedro Costa (SmoothProcess)

Released under 
[the MIT license](https://github.com/SmoothProcess/enprint/blob/main/LICENSE)
