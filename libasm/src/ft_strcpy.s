; vi:syntax=nasm

				global		ft_strcpy

				section 	.text
ft_strcpy:
				mov			rax, rdi; return value is 1st argument (destination)

_copy:
				mov byte 	dl, [rsi]; copy byte at rsi address in a byte size register
				mov byte	[rdi], dl; then copy it to the memory address of rdi
				cmp byte 	[rdi], 0; check for '\0'
				je 			_return; return if '\0'
				inc 		rdi; dst++
				inc 		rsi; src++
				jmp 		_copy; copy next byte

_return:
				ret
