; vi:syntax=nasm

			extern 		ft_error
			global		ft_write

			section		.text
ft_write:
			mov 		rax, 1; SYS_WRITE
			syscall

			cmp 		rax, 0; compare rax with 0
			jl 			ft_error; jump to ft_error if less than 0
			ret
