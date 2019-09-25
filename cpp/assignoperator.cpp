#include <iostream>
using namespace std;

class Demo {
private:
	int i;
public:
	Demo(Demo &d) {
		cout << "In " << __func__ << endl;
	}
};

int main() {

	return 0;
}
