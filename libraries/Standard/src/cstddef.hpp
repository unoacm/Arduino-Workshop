#ifndef UNO_ACM_CSTDDEF
#define UNO_ACM_CSTDDEF

namespace std
{
	using ptrdiff_t = long;
	using size_t = unsigned int;
	using nullptr_t = decltype(nullptr);
}

#endif