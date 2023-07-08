
compile: redis.cpp _tor.cpp _tor.h /usr/local/lib/libredis++.a /usr/local/lib/libhiredis.a
	g++ -std=c++17 -o fill redis.cpp _tor.cpp /usr/local/lib/libredis++.a /usr/local/lib/libhiredis.a -pthread
run: fill
	./fill $(VERT) $(EDGE)
clean:
	rm fill
