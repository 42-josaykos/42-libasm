; vi:syntax=nasm

				global		ft_strcmp

				section 	.text
ft_strcmp:
				mov 		rax, 0
				mov 		rcx, 0
				call 		_compare

_compare:
				mov byte 	al, [rdi]; *s1
				mov byte 	cl, [rsi]; *s2
				cmp 		al, cl
				jne 		_return
				cmp 		al, 0
				jz 			_return

				inc 		rdi
				inc 		rsi
				jmp 		_compare

_return:
				sub 		eax, ecx
				ret
