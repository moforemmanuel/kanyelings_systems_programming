#!/bin/bash

file="$1"

# echo $file

fileName=$(echo $file | cut -d '.' -f 1)

# echo $fileName

fileExt=$(echo $file | cut -d '.' -f 2)

# echo $fileExt

if [ -f "$file" ]   #test file existence
then 
    echo "$file exists."
    if [ $fileExt == "c" ]   #test file extension
    then 
        echo "$file is a c file"
        echo "Compiling ..."
        # gcc $file -o $fileName
        gcc -Wall -Wextra -O2 -g -o $fileName $file
        echo "Done ..."
    else 
        echo "$file is not a c file"
    fi

else
    echo "$file does not exist."
fi




