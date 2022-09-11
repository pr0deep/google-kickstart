read file
g++ -Wall -Wextra -pedantic -std=c++2a -O2 -Wshadow -Wformat=2  -Wshift-overflow=2  -D_GLIBCXX_DEBUG -D_GLIBCXX_DEBUG_PEDANTIC -D_FORTIFY_SOURCE=2 -fsanitize=address -fsanitize=undefined -fno-sanitize-recover -fstack-protector  "$file.cpp" -o a;
a < in
