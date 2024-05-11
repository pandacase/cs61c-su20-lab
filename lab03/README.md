
## What Have I Learned

### In `ex1.s`:

```s
.data
.word 2, 4, 6, 8
n: .word 9

.text
main:
    add t0, x0, x0
    addi t1, x0, 1
    la t3, n
    lw t3, 0(t3)
fib:    
    beq t3, x0, finish
    add t2, t1, t0
    mv t0, t1
    mv t1, t2
    addi t3, t3, -1  
    j fib
finish: 
    addi a0, x0, 1
    addi a1, t0, 0
    ecall # print integer ecall
    addi a0, x0, 10
    ecall # terminate ecall
```

- RISC-V directive:
  - `.data`: used to define and allocate storage for initialized data
  - `.word`: used to initialize memory locations with specific values(can be array), such as integers.
  - `.text`: it's where the actual executable instructions of the program are placed.
- The output is `34` show by ecall (though system call), which is the 9th number of Fibonacci number.
- The address of n is `0x10000010`.

### RISC-V green card

See [RISC-V](https://inst.eecs.berkeley.edu/~cs61c/sp21/resources-pdfs/riscvcard.pdf).

### Function call

- Callee: save `s` & `sp`
- Caller: save `t` & `a` & `ra`

> DONT forget `ra` when call a function!!