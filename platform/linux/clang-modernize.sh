#!/bin/sh

find src \( -name "*.cpp" -o -name "*.cu" \) | xargs -I file --verbose clang-modernize \
	-risk=risky -summary -add-override -loop-convert -pass-by-value -replace-auto_ptr -use-auto -use-nullptr \
	file -- -isystem include -Isrc -std=c++14 -Wpedantic -Wall -Wextra -Werror -Ofast -x c++
