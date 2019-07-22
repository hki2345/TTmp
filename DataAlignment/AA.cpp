#include <iostream>



struct MixedData  /* After compilation in 32-bit x86 machine */
{
	char Data1; /* 1 byte */
	char Padding1[1]; /* 1 byte for the following 'short' to be aligned on a 2 byte boundary
assuming that the address where structure begins is an even number */
	short Data2; /* 2 bytes */
	int Data3;  /* 4 bytes - largest structure member */
	char Data4; /* 1 byte */
	char Padding2[3]; /* 3 bytes to make total size of the structure 12 bytes */
};
struct ex1
{
	int score;
	char ch3;
};
struct student
{
	char ch1;
	short num;
	char ch2;
	int score;
	double grade;
	char ch3;
};
struct FinalPadShort {
	short s;
	char n[3];
};

struct Date0 {
	unsigned nWeekDay;  
	unsigned nMonthDay; 
	// unsigned short : 0;
	unsigned nMonth;  
	unsigned nYear;   
};
struct Date1 {
	unsigned nWeekDay : 3;    // 0..7   (3 bits)
	unsigned nMonthDay : 6;    // 0..31  (6 bits)
	// unsigned  : 0;		// Force alignment to next boundary.
	unsigned nMonth : 5;    // 0..12  (5 bits)
	unsigned nYear : 8;    // 0..100 (8 bits)
};
struct Date {
	unsigned nWeekDay : 3;    // 0..7   (3 bits)
	unsigned nMonthDay : 6;    // 0..31  (6 bits)
	unsigned  : 0;		// Force alignment to next boundary.
	unsigned nMonth : 5;    // 0..12  (5 bits)
	unsigned nYear : 8;    // 0..100 (8 bits)
};
int main()
{
	// std::cout << sizeof(FinalPadShort) << std::endl;
	// std::cout << sizeof(MixedData) << std::endl;
	// std::cout << sizeof(student) << std::endl;
	// std::cout << sizeof(ex1) << std::endl;


	std::cout << "Byte Padding Size: " << sizeof(Date0) << std::endl;
	std::cout << "Bit Field Size: " << sizeof(Date1) << std::endl;
	std::cout << "Zero Length Bit Field Size: " << sizeof(Date) << std::endl;
}