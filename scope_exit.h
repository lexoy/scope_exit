#pragma once

namespace __scope_exit_handler {
	template< typename T >
	class scope_exit
	{
		public:
			explicit scope_exit( T&& callable_exit ) : callable_exit( std::forward< T >( callable_exit ) ) { }
			~scope_exit() { try{ callable_exit(); }catch( ... ){ } }

		private:
			T callable_exit;

			// Disable operator assignment
			const scope_exit& operator= ( const scope_exit& );
			
	};

	template< typename T >
	auto create_scope_exit( T&& callable_exit )->scope_exit< T >
	{
		return scope_exit< T >( std::forward< T >( callable_exit ) );
	}
}

#ifdef UTILITY_SCOPE_EXIT
#undef UTILITY_SCOPE_EXIT
#endif
#ifdef _UTILITY_EXIT_SCOPE_LINENAME
#undef _UTILITY_EXIT_SCOPE_LINENAME
#endif
#ifdef _UTILITY_EXIT_SCOPE_LINENAME_CAT
#undef _UTILITY_EXIT_SCOPE_LINENAME_CAT
#endif

#define _UTILITY_EXIT_SCOPE_LINENAME_CAT(name, line) name##line
#define _UTILITY_EXIT_SCOPE_LINENAME(name, line) _UTILITY_EXIT_SCOPE_LINENAME_CAT(name, line)
#define UTILITY_SCOPE_EXIT(f) const auto& _UTILITY_EXIT_SCOPE_LINENAME(exit_handler, __LINE__) = __scope_exit_handler::create_scope_exit(f)
