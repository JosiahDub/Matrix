#include "Matrix.h"
#include <iostream>

int main()
{
	uint rows = 2;
	uint columns = 2;
	Matrix m(rows, columns);
	m.at(0, 0) = 14.0;
	std::cout << "normal m(0, 0): " << m.at(0, 0) << std::endl;

	//19
	m.add(5);
	std::cout << "added m(0, 0): " << m.at(0, 0) << std::endl;

	Matrix m_list({ {1, 2},
					{3, 4}});
	// 1
	std::cout << "list m(0, 0): " << m_list.at(0, 0) << std::endl;

	m.add(m_list);
	//20
	std::cout << "added list m(0, 0): " << m_list.at(0, 0) << std::endl;
	return 0;
}