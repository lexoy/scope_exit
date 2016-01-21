#pragma once

namespace _scope_exit_handler {
	template< typename T >
	class scope_exit
	{
		public:
			explicit scope_exit( T callable_exit ) : callable_exit( callable_exit ){}
			~scope_exit(){try{callable_exit();}catch( ... ){}}

		private:
			T callable_exit;
	};

	template< typename T >
	auto create_scope_exit( T callable_exit )
	{
		return scope_exit< T >( callable_exit );
	}
}