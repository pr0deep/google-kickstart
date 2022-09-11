#!/bin/sh

echo "Enter file to be tested : "
read "file" 

mkdir "test_$file"
cp "$file".cpp ./"test_$file"/fast.cpp
cp ./util/gen.cpp ./"test_$file"/fast.cpp 
cp ./util/brute.cpp ./"test_$file"/brute.cpp 
cp ./util/test.sh ./"test_$file"/test.sh 



