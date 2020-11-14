all: 20.valid-parentheses 28.implement-str-str 35.search-insert-position

20.valid-parentheses: 20.valid-parentheses.cpp
	g++ -g -Og -W -Wall -o $@ $^

28.implement-str-str: 28.implement-str-str.cpp
	g++ -g -Og -W -Wall -o $@ $^

35.search-insert-position: 35.search-insert-position.cpp
	g++ -g -Og -W -Wall -o $@ $^
