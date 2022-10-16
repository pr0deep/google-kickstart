#!/bin/bash

echo "Enter file to be tested : "
read "file" 

mkdir "test_$file"
cp "$file".cpp ./"test_$file"/fast.cpp
cp ./util/gen.cpp ./"test_$file"/gen.cpp 
cp ./util/brute.cpp ./"test_$file"/brute.cpp 
cp ./util/test.sh ./"test_$file"/test.sh 
cp stdc++.h.gch ./"test_$file"/stdc++.h.gch
cp dbg_src.h ./"test_$file"/dbg.h


cd "test_$file"
chmod +x test.sh
