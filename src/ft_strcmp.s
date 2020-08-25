; vi:syntax=nasm

				global		ft_strcmp

				section 	.text
ft_strcmp:
				mov 		rax, 0; initialize return value
				mov 		rcx, 0; initialize register for byte comparison
				call 		_compare

_compare:
				mov byte 	al, [rdi]; move byte of 1st arg (char *s1)
				mov byte 	cl, [rsi]; move byte of 2nd arg (char *s2)
				cmp 		al, cl; compare bytes
				jne 		_return; return if !=
				cmp 		al, 0
				jz 			_return; return if *s1 == '\0'

				inc 		rdi; increment pointer to next byte (s1++)
				inc 		rsi; increment pointer to next byte (s2++)
				jmp 		_compare; do loop

_return:
				sub 		rax, rcx; do a substraction from return value
				ret
