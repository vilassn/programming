//http://www.codeproject.com/Articles/541067/Cplusplus11-Smart-Pointers
class Test {
public:
	Test(int a = 0) :
			m_a(a) {
	}
	~Test() {
		cout << "Calling destructor" << endl;
	}
public:
	int m_a;
};

void main() {
	std::auto_ptr<Test> p(new Test(5));
	cout << p->m_a << endl;

	int *p_scalar = new int(5); //allocates an integer, set to 5. (same syntax as constructors)
	int *p_array = new int[5]; //allocates an array of 5 adjacent integers. (undefined values)
}
