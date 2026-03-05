.global getSystemTime

.section .data
    tv_sec: .quad 0 
    tv_usec: .quad 0

.section .text
    getSystemTime:
        mov $96, %rax
        lea tv_sec(%rip), %rdi
        xor %rsi, %rsi
        syscall

        mov tv_sec(%rip), %rax
        mov tv_usec(%rip), %rdx
        imul $1000000, %rax
        add %rdx, %rax
        ret
