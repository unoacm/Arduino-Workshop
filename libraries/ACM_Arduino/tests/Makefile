arduino_installation=C:\Program Files (x86)\Arduino

compiler=g++
compiler-flags = -Wall -pedantic -I "$(arduino_installation)\libraries\ACM_Arduino\src"

vector:	vector.cpp
	$(compiler) $(compiler-flags) $< -o $@

array:	array.cpp
	$(compiler) $(compiler-flags) $< -o $@

tuple:	tuple.cpp
	$(compiler) $(compiler-flags) $< -o $@

memory:	memory.cpp
	$(compiler) $(compiler-flags) $< -o $@

utility:	utility.cpp
	$(compiler) $(compiler-flags) $< -o $@

type_traits:	type_traits.cpp
	$(compiler) $(compiler-flags) $< -o $@

forward_list:	forward_list.cpp
	$(compiler) $(compiler-flags) $< -o $@

list:	list.cpp
	$(compiler) $(compiler-flags) $< -o $@