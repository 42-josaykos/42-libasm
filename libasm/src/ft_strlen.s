; vi:syntax=nasm

				global		ft_strlen

				section		.text
ft_strlen:
				mov 		rax, 0; initialize return value to 0
				; mov 		rdi, rdi ; str
				call 		_count

_count:
				cmp 		byte [rdi], 0; compare the byte rdi is pointing to with '\0'
				je 			_return; return if equals
				inc 		rax; increment the counter
				inc 		rdi; increment the pointer
				jmp 		_count; loop again

_return:
				ret
