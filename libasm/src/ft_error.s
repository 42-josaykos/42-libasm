; vi:syntax=nasm

			extern 		__errno_location
			global 		ft_error

			section 	.text
ft_error:
			neg 		rax; set rax (error code) to positive
			mov 		rdx, rax; move error code away from return value
			call 		__errno_location; put errno location in rax
			mov 		[rax], rdx; set errcode to errno location
			mov 		rax, -1; return value is -1
			ret
