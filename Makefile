all: 20.valid-parentheses 28.implement-str-str

20.valid-parentheses: 20.valid-parentheses.cpp
	g++ -g -Og -W -Wall -o $@ $^

28.implement-str-str: 28.implement-str-str.cpp
	g++ -g -Og -W -Wall -o $@ $^
