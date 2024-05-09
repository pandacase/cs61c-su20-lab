
## What Have I Learned

### gcc agrs

- `-o` output file
- `-g` grnerate gdb info
- `-c` only compiler, not link. generate `.o` file


### cgdb vs gdb 

cgdb is a lightweight curses (terminal-based) interface to the GNU Debugger (GDB). In addition to the standard gdb console, cgdb provides a split screen view that displays the source code as it executes. The keyboard interface is modeled after vim, so vim users should feel at home using cgdb.

### gdb usage

see [gdb.txt](./gdb.txt)

### fgets < stdin

run:

```sh
./int_hello < stdin.txt
```

gdb:

```sh
gdb ./int_hello
```

```gdb
run < stdin.txt
```

### valgrind

```sh
panda@panda ~/c/c/lab01 (master)> valgrind ./segfault_ex
```
```
==37508== Memcheck, a memory error detector
==37508== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==37508== Using Valgrind-3.18.1 and LibVEX; rerun with -h for copyright info
==37508== Command: ./segfault_ex
==37508== 
==37508== Invalid write of size 4
==37508==    at 0x10914F: main (in /home/panda/cs61c/cs61c-su20-lab/lab01/segfault_ex)
==37508==  Address 0x1fff001000 is not stack'd, malloc'd or (recently) free'd
==37508== 
==37508== 
==37508== Process terminating with default action of signal 11 (SIGSEGV)
==37508==  Access not within mapped region at address 0x1FFF001000
==37508==    at 0x10914F: main (in /home/panda/cs61c/cs61c-su20-lab/lab01/segfault_ex)
==37508==  If you believe this happened as a result of a stack
==37508==  overflow in your program's main thread (unlikely but
==37508==  possible), you can try to increase the size of the
==37508==  main thread stack using the --main-stacksize= flag.
==37508==  The main thread stack size used in this run was 8388608.
==37508== 
==37508== HEAP SUMMARY:
==37508==     in use at exit: 0 bytes in 0 blocks
==37508==   total heap usage: 0 allocs, 0 frees, 0 bytes allocated
==37508== 
==37508== All heap blocks were freed -- no leaks are possible
==37508== 
==37508== For lists of detected and suppressed errors, rerun with: -s
==37508== ERROR SUMMARY: 1 errors from 1 contexts (suppressed: 0 from 0)
fish: Job 1, 'valgrind ./segfault_ex' terminated by signal SIGSEGV (Address boundary error)
```

`Address 0x1fff001000 is not stack'd, malloc'd or (recently) free'd` means that some the program try to r/w to unallocated memory.

- Why didn’t the no_segfault_ex program segfault?

> 5 ~ 19 is undefinded, but still in stack(not unalloced memory).

- Why does the no_segfault_ex produce inconsistent outputs?

> 5 ~ 19 is undefinded, the value is unknown

- Why is sizeof incorrect? How could you still use sizeof but make the code correct?

> use `sizeof(a) / sizeof(int)`

