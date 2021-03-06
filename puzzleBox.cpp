#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;

enum BoxVar {
	a, b, c
};

class Box {
private:
	int a;
	int b;
	int c;
	int get_a() {
		b = (b + get_c()) % 7;
		return a;
	}
	int get_b() {
		c = (c + 5) % 11;
		return b;
	}
	int get_c() {
		a = (a + get_b()) % 5;
		return c;
	}
public:
	Box() {
		a = 1;
		b = 1;
		c = 1;
	}
	int get(BoxVar var) {
		switch (var) {
		case BoxVar::a:
			return get_a();
			break;
		case BoxVar::b:
			return get_b();
			break;
		case BoxVar::c:
			return get_c();
			break;
		}
		return 0;
	}
	bool get_success() {
		if (a == 1 && b == 2 && c == 3) {
			return true;
		}
		return false;
	}
};

void pattern(Box* box) {
	box->get(a);
	box->get(b);
	box->get(c);
}

void loop(Box* b) {
	int count = 0;
	int maxLoops = 100000;
	while (!b->get_success() && count < maxLoops) {
		count++;
		pattern(b);
	}
	if (b->get_success()) {
		cout << "Success! took " << count << " loops.\n";
	}
	else {

		cout << "Timed out (success not achieved within " << maxLoops << " iterations).\n";
	}
	
	char x = getchar();
}

int main()
{
	Box b;
	loop(&b);
    return 0;
}

