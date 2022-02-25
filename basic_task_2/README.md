## Basics - Task 2

>Run the compile_c.sh script from basic task 1, passing as command-line argument, a file paths. This script checks for the existence of the file, if it does not exist, an error message is displayed. If it exists, the contents of the first file are then written to two newly created files, and the operation is completed.

>In this case, split_file.c is our c file.

eg: `./compile_c.sh split_file.c` outputs, if the file doesn't exist:

```
split_file.c does not exist.
```

if the file exists, and without errors or warnings in it: 
```
split_file.c exists.
split_file.c is a c file
Compiling ...
Done ...
```

>To run the executable file generated, run `./split_file file.txt` where file.txt is the path to the file we are working with.

>Hint: Use `sudo chmod u+x split_file` to make generated file executable if you encounter a permission error

>If file.txt does not exist, you see:
```
-- file.txt could not be opened -- 
open: No such file or directory
```
>Otherwise, you see:
```
-- file : file.txt - splitting file done -- 
-- file 1: file1.txt - created file successfully -- 
-- file 2: file2.txt - created file successfully -- 
-- file 1: writing to file1.txt --
-- file 1: file1.txt - wrote to file sucessfully  -- 
-- file 2: writing to file2.txt --
-- file 2: file2.txt - wrote to file sucessfully  -- 

-- Operation complete: copied file.txt contents to file1.txt and file2.txt --
```

>You may comment out the logging feature, I included it for readability and easy debugging of the operation.