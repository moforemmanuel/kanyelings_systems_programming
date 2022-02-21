## Basics - Task 1

>Run the compile_c.sh script, passing a file path as command-line argument. This script checks for the existence of the file, if its a c file, and then compiles it, to an executable file with same name as the c file passed as argument.

eg: `./compile_c.sh c_file_name.c` outputs, if the file doesn't exist:

```
c_file_name.c does not exist.
```

if the file exists: 
```
c_file.c exists.
c_file.c is a c file
Compiling ...
Done ...
```

if the file exists but is not a c file:
```
file_name.ext exists.
file_name.ext is not a c file
```

>To run the executable file generated, run `./c_file_name`

>Use `sudo chmod u+x c_file_name` to make generated file executable if you encounter a permission error