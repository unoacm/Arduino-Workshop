#ifndef UNO_ACM_MEMORY
#define UNO_ACM_MEMORY

#include <type_traits.h>
#include <cstddef.h>
#include <climits.h>
#include <utility.h>

namespace uno_acm
{
	template<class Alloc>
	struct allocator_traits
	{
		using allocator_type = Alloc;
		using value_type = typename allocator_type::value_type;
		using pointer = typename allocator_type::pointer;
		using const_pointer = typename allocator_type::const_pointer;
		using void_pointer = typename allocator_type::void_pointer;
		using const_void_pointer = typename allocator_type::const_void_pointer;
		using difference_type = typename allocator_type::difference_type;
		using size_type = typename allocator_type::size_type;
		using propagate_on_container_copy_assignment = typename allocator_type::propagate_on_container_copy_assignment;
		using propagate_on_container_move_assignment = typename allocator_type::propagate_on_container_move_assignment;
		using propagate_on_container_swap = typename allocator_type::propagate_on_container_swap;
		template<class T> struct rebind_alloc { using other = typename Alloc::rebind::other; };
		template<class T> using rebind_traits = allocator_traits<rebind_alloc<T>>;

		static pointer allocate(allocator_type& alloc, size_type n)
		{
			return alloc.allocate(n);
		}

		static pointer allocate(allocator_type& alloc, size_type n, const_void_pointer hint)
		{
			return alloc.allocate(n, hint);
		}

		static void deallocate(allocator_type& alloc, pointer p, size_type n)
		{
			alloc.deallocate(p);
		}

		template<class T>
		static void destroy(allocator_type& alloc, T* p)
		{
			alloc.destroy(p);
		}

		static size_type max_size(const allocator_type& alloc)
		{
			return alloc.max_size();
		}

		static allocator_type select_on_container_copy_construction(const allocator_type& alloc)
		{
			return alloc.select_on_container_copy_construction();
		}
	};

	template<class T>
	struct allocator
	{
		using value_type = T;
		using pointer = value_type*;
		using const_pointer = const pointer;
		using void_pointer = void*;
		using const_void_pointer = const void_pointer;
		using reference = value_type&;
		using const_reference = const reference;
		using size_type = size_t;
		using difference_type = ptrdiff_t;
		using propagate_on_container_move_assignment = true_type;
		using propagate_on_container_copy_assignment = false_type;
		using propagate_on_container_swap = false_type;
		template<class U> struct rebind { using other = allocator<U>; };
		using is_always_equal = true_type;

		allocator()
		{
		}

		~allocator()
		{
		}

		pointer address(reference x)
		{
			return &x;
		}

		const_pointer address(const_reference x) const
		{
			return &x;
		}

		pointer allocate(size_type n, const_void_pointer hint = 0)
		{
			return ::operator new(n);
		}

		void deallocate(pointer p, size_type n)
		{
			::operator delete(p);
		}

		size_type max_size() const
		{
			return numeric_limits<size_type>::max_() / sizeof(value_type);
		}

		void construct(pointer p, const_reference val)
		{
			new(p) T(val);
		}

		template<class U, class... Args>
		void construct(U* p, Args&&... args)
		{
			::new(p) U(forward<Args>(args)...);
		}

		void destroy(pointer p)
		{
			p->~T();
		}

		template<class U>
		void destroy(U* p)
		{
			p->~U();
		}
	};
}

#endif