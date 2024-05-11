.globl factorial

.data
n: .word 8

.text
main:
    la t0, n
    lw a0, 0(t0)
    jal ra, factorial

    addi a1, a0, 0
    addi a0, x0, 1
    ecall # Print Result

    addi a1, x0, '\n'
    addi a0, x0, 11
    ecall # Print newline

    addi a0, x0, 10
    ecall # Exit

factorial:
    # YOUR CODE HERE
    addi t0, x0, 1  # i = 1;
    addi t1, x0, 1  # res = 1;

factorial_loop:
    bgt t0, a0, factorial_exit # if t0(i) > a0(n) then factorial_exit
    mul t1, t1, t0  # res = res * i
    addi t0, t0, 1  # i = i + 1
    j factorial_loop

factorial_exit:
    mv  a0, t1 # a0 = t1(res)
    jr ra
