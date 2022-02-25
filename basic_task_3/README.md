## Basics - Task 3

>Run the compile_c.sh script from basic task 1, passing as command-line arguments, two file paths. This script checks for the existence of the first first file, if it does not exist, an error message is displayed. If it exists, the existence of the second file is then checked. If it does not exist, it is created. The contents of the first file are then written to the second, and the operation is completed.

>In this case, write_file.c is our c file.

eg: `./compile_c.sh write_file.c` outputs, if the file doesn't exist:

```
write_file.c does not exist.
```

if the file exists, and without errors or warnings in it: 
```
write_file.c exists.
write_file.c is a c file
Compiling ...
Done ...
```

>To run the executable file generated, run `./write_file file1.txt file2.txt` where file1.txt and file2.txt are the paths to the files we are working with.

>Hint: Use `sudo chmod u+x write_file` to make generated file executable if you encounter a permission error

>If file 1 does not exist, you see:
```
-- file 1: file1.txt - could not be opened -- 
open: No such file or directory
```

<!-- >If it cannot be read, you see:
```
-- file1.txt could not be read -- 
read: No such file or directory
``` -->

>If file 1 exists and file 2 does not, you see:
```
-- file 1: file1.txt - opened successfully -- 
-- file 2: file2.txt - could not be opened -- 
open: No such file or directory
-- file 2: file2.txt - creating file -- 
-- file 2: file2.txt - created file successfully -- 
-- file 2: writing to file2.txt --
-- file 2: file2.txt - wrote to file sucessfully  -- 

-- Operation complete: copied file1.txt contents to file2.txt --
```

>If file 1 exists and file 2 exists, you see:
```
-- file 1: file1.txt - opened successfully -- 
-- file 2: file2.txt - opened successfully -- 
-- file 2: writing to file2.txt --
-- file 2: file2.txt - wrote to file sucessfully  -- 

-- Operation complete: copied file1.txt contents to file2.txt --
```

>You may comment out the logging feature, I included it for readability and easy debugging of the operation.