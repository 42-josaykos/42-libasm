; vi:syntax=nasm

				extern 		malloc
				extern 		ft_strlen
				extern 		ft_strcpy
				global 		ft_strdup

				section 	.text
ft_strdup:
				mov 		rbx, rdi; save 1st arg in another register
				call 		ft_strlen; get the length of the arg in rdi
				inc 		rax; length is returned in rax, so increase it by 1 for '\0'
				call 		malloc; malloc with the size in rax
				jz 			_return; return if malloc fails (check if CF flag is 0)

				mov 		rdi, rax; malloc return in rax is the dst
				mov 		rsi, rbx; 1st arg saved in rbx is the src
				call 		ft_strcpy

_return:
				ret
