#!/bin/bash
green=$(tput setaf 71);
red=$(tput setaf 1);
blue=$(tput setaf 32);
orange=$(tput setaf 178);
bold=$(tput bold);
reset=$(tput sgr0);

compile () {
g++ -Wall -Wextra -pedantic -std=c++2a -O2 -Wshadow -Wformat=2 -Wshift-overflow=2 -D_GLIBCXX_DEBUG -D_GLIBCXX_DEBUG_PEDANTIC -D_FORTIFY_SOURCE=2 -fsanitize=address -fsanitize=undefined -fno-sanitize-recover -fstack-protector "$1".cpp -o "$1";
}

compile "gen"
compile "fast"
compile "brute"

test=0;
mxtest=10;

while [ "$test" -le "$mxtest" ]; do 
  ./gen > in 
  ./brute < in > out1
  ./fast < in > out2
  if cmp -s "out1" "out2"; then 
    echo -ne "Case #$test : ${green}Passed ${reset} \r"
  else 
    echo "Case #$test : ${red}Failed ${reset}"
    echo "Input:"
    cat in 
    echo ""
    
    echo "${orange}Output: ${reset}"
    cat out2
    echo ""

    echo "${orange}Expected output: ${reset}"
    cat out1 
    echo ""
    break
  fi
  test=$(( test + 1 ))
done 
echo -e "\n${green}GG...! ${reset} \r"
