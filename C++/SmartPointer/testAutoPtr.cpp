#include<iostream>
#include<string>
#include<memory>

/*

�ο����ϣ�[C++����ָ���ܽ�](https://www.cnblogs.com/wuyepeng/p/9741241.html)
*/
class Test
{
public:
	Test(std::string s);
	std::string& getStr()
	{
		return str;
	}

	void setStr(std::string s)
	{
		str = s;
	}

	void print()
	{
		std::cout << str << std::endl;
	}
	~Test();

private:
	std::string str;
};

Test::Test(std::string s)
{
	str = s;
	std::cout << "Test create" << std::endl;
}

Test::~Test()
{
	std::cout << "Test delete:" << str << std::endl;
}

std::unique_ptr<Test> fun()
{
	return std::unique_ptr<Test>(new Test("789"));	// �����˹��캯�������Test creat
}

// std::auto_ptr()�����Ļ���ʹ��
void autoPtrTest1()
{
	std::auto_ptr<Test> ptest(new Test("123"));	// ���ù��캯�����Test create
	ptest->setStr("hello "); // �޸ĳ�Ա������ֵ
	ptest->print();	// ���hello
	ptest.get()->print();	// ���hello
	ptest->getStr() += "world !";
	(*ptest).print();	// ���hello world
	ptest.reset(new Test("123"));	// ��Ա����reset()���°�ָ��Ķ��󣬶�ԭ���Ķ�����ᱻ�ͷţ�������������һ�ι��캯�������е���һ�����������ͷŵ�֮ǰ�Ķ���
	ptest->print();		// ���123
}

// std::auto_ptr()ָ��ĸ�ֵ����
void autoPtrTest2()
{
	std::auto_ptr<Test> ptest(new Test("123"));
	std::auto_ptr<Test> ptest2(new Test("456"));

	ptest->print();
	ptest2->print();
	ptest2 = ptest;
	ptest2->print();

	ptest2.release();
	ptest2.reset();

	if (ptest.get() == NULL)
		std::cout << "ptest = NULL" << std::endl;
}

void uniquePtrTest()
{
	std::unique_ptr<Test> ptest(new Test("123"));	// �����˹��캯�������Test create
	std::unique_ptr<Test> ptest2(new Test("456"));	// �����˹��캯�������Test create
	ptest->print();									// ���123
	//ptest2 = ptest;								// ����ֱ�Ӹ�ֵ����Ȼ�ᱬ��
	ptest2 = std::move(ptest);						// ������move��ptest2ԭ���Ķ���ᱻ�ͷţ�ptest2����ָ��ԭ��ptest����
	ptest2->print();
	if (ptest == NULL)std::cout << "ptest = NULL\n" << std::endl;	// ��Ϊ����unique_ptr����ָ��ͬһ�ڴ��ַ�����Ծ���ǰ��move��ptest�ᱻ��ֵNULL�����ptest = NULL
	Test* p = ptest2.release();						// release��Ա������ptest2ָ�븳ֵΪ�գ����ǲ�û���ͷ�ָ��ָ����ڴ棬���Դ�ʱpָ��ԭ��ptest2ָ����ڴ�
	p->print();										// ���123
	ptest.reset(p);									// ���°󶨶���ԭ���Ķ���ᱻ�ͷŵ�������ptest���������ͷ��ˣ���������Ͳ����ٵ�������������
	ptest->print();									// ���123
	ptest2 = fun();									// ���������=����Ϊʹ�����ƶ����캯������������һ��unique_ptr���Զ������ƶ����캯��
	ptest2->print();								// ���789
}

void sharedPtrTest()
{
	std::shared_ptr<Test> ptest(new Test("123"));	// ���ù��캯�����Test create
	std::shared_ptr<Test> ptest2(new Test("456"));	// ���ù��캯�����Test create
	std::cout << ptest2->getStr() << std::endl;		// ���456
	std::cout << ptest2.use_count() << std::endl;	// ��ʾ��ʱ��Դ������ָ�빲�����1
	ptest = ptest2;									// "456"���ô�����1����123�����٣����Test create
	ptest->print();									// ���456
	std::cout << ptest.use_count() << std::endl;	// ��ָ��ָ�����Դ������ָ�빲�����2
	std::cout << ptest2.use_count() << std::endl;	// 2
	ptest.reset();									// ���°󶨶��󣬰�һ���ն��󣬵�ʱ��ʱָ��ָ��Ķ���������ָ��ָ��Ͳ����ͷŸö�����ڴ�ռ�
	ptest2.reset();									// ��ʱ��456�����٣���ʱָ��ָ����ڴ�ռ��ϵ�ָ��Ϊ0�����ͷ��˸��ڴ棬���Test delete
	std::cout << "Done!" << std::endl;
}

void makeSharedTest()
{
	std::shared_ptr<int> foo = std::make_shared<int>(10);
	// same as:
	std::shared_ptr<int> foo2(new int(10));

	auto bar = std::make_shared<int>(20);

	auto baz = std::make_shared<std::pair<int, int>>(30, 40);

	std::cout << "*foo: " << *foo << std::endl;
	std::cout << "*bar: " << *bar << std::endl;
	std::cout << "*baz: " << baz->first << ' ' << baz->second << std::endl;
}

int main()
{
	//autoPtrTest1();
	//autoPtrTest2();
	//uniquePtrTest();
	//sharedPtrTest();
	makeSharedTest();
	return 0;
}