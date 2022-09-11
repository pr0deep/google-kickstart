#!/bin/sh

# Author : pradeep S 

# setting up folder 
echo "Enter contest name : "
read FOLDER
rm -rf "$FOLDER"

echo "preparing folder ...!"
mkdir "$FOLDER"/
cp ./source/base.cpp ./"$FOLDER"/a.cpp;
cp ./source/base.cpp ./"$FOLDER"/b.cpp;
cp ./source/base.cpp ./"$FOLDER"/c.cpp;
cp ./source/base.cpp ./"$FOLDER"/d.cpp;
cp ./source/base.cpp ./"$FOLDER"/e.cpp;
cp ./source/dbg.h ./"$FOLDER";
cp ./source/run.sh ./"$FOLDER";
touch in 

cd "$FOLDER"

# precompile headers
echo "compiling headers ...!"
g++ -Wall -Wextra -pedantic -std=c++2a -O2 -Wshadow -Wformat=2  -Wshift-overflow=2  -D_GLIBCXX_DEBUG -D_GLIBCXX_DEBUG_PEDANTIC -D_FORTIFY_SOURCE=2 -fsanitize=address -fsanitize=undefined -fno-sanitize-recover -fstack-protector  /usr/include/x86_64-linux-gnu/c++/9/bits/stdc++.h -o stdc++.h.gch;

# utils 
echo "preparing utils ...!"
mkdir "util"

cp ../source/gen.cpp ./util/gen.cpp
cp ../source/brute.cpp ./util/brute.cpp
cp ../source/test.sh ./util/test.sh
cp ../source/setup_test.sh ./

# perms
echo "fixing permissions ...!"
chmod +x ./setup_test.sh
chmod +x ./run.sh
