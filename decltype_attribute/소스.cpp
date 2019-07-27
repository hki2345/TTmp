#include <utility>
template <class T, class ReturnT, class... ArgsT>
class IsCallable
{
public:
	struct BadType {};
	template <class U>
	static decltype(std::declval<T>()(std::declval<ArgsT>()...)) Test(int); //C2064. Should be declval<U>
	template <class U>
	static BadType Test(...);
	static constexpr bool value = std::is_convertible<decltype(Test<T>(0)), ReturnT>::value;
};

constexpr bool test1 = IsCallable<int(), int>::value;
static_assert(test1, "PASS1");
constexpr bool test2 = !IsCallable<int*, int>::value;
static_assert(test2, "PASS2");

int main()
{

}


[[deprecated]]
void Foo(int);