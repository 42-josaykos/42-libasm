; vi:syntax=nasm

			extern 		ft_error
			global		ft_read

			section 	.text
ft_read:
			mov 		rax, 0; SYS_READ
			syscall

			cmp 		rax, 0; compare rax with 0
			jl 			ft_error; jump to ft_error if rax less than 0
			ret
