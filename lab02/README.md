
## What Have I Learned

### Linear Feedback Shift Register

See [https://en.wikipedia.org/wiki/Linear-feedback_shift_register](https://en.wikipedia.org/wiki/Linear-feedback_shift_register).

### Makefile

See [make.txt](./make.txt)

### C Memory Management

#### #1 🐦: Why is this incorrect:

```c
/* Bad example of how to create a new vector */
vector_t *bad_vector_new() {
    /* Create the vector and a pointer to it */
    vector_t *retval, v;
    retval = &v;

    /* Initialize attributes */
    retval->size = 1;
    retval->data = malloc(sizeof(int));
    if (retval->data == NULL) {
        allocation_failed();
    }

    retval->data[0] = 0;
    return retval;
}
```

A: v(*retval) is local var, will be clear when out of scope.

#### #2 🦆: Why is this incorrect:

```c
vector_t also_bad_vector_new() {
    /* Create the vector */
    vector_t v;

    /* Initialize attributes */
    v.size = 1;
    v.data = malloc(sizeof(int));
    if (v.data == NULL) {
        allocation_failed();
    }
    v.data[0] = 0;
    return v;
}
```

A: v is on stack. After return the function there might take a copy from v to var of caller, which cost a lot of performance.

#### #3 🦉: The truely correct 

```c
vector_t *vector_new() {
    vector_t *retval;

    retval = (vector_t *)malloc(sizeof(vector_t));

    if (!retval) {
        allocation_failed();
    }

    retval->size = 1;
    retval->data = (int *)malloc(sizeof(int));

    if (!(retval->data)) {
        free(retval);
        allocation_failed();
    }

    retval->data[0] = 0;

    return retval;
}
```

### Valgrind's flags

```sh
$ valgrind --tool=memcheck --leak-check=full --track-origins=yes [OS SPECIFIC ARGS] ./<executable>
```

- `--tool=memcheck`: The tool memcheck is used to detect memory error & leak.
- `--leak-check=full`: Report full detailed info about memory leak.
- `--track-origins=yes`: When reporting memory leak, show the locations.

