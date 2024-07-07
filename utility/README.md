# How to use
basci command to use the lib.

## Compile program with lib
1. static
` gcc -I./mylib/include -L./mylib/lib ./test/main.c -lmylib -o main `
2. dynamic
`   gcc -I./mylib/include -L./mylib/lib ./test/main.c -lmylib -o main
    export LD_LIBRARY_PATH=./mylib/lib
    ./main
`