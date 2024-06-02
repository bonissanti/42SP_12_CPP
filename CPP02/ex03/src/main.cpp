/*************************************************************************************/
/*   ⠀⠀  ⠀⠀⠀⠀ ⣴⣿⣦ ⠀⠀⠀⠀⠀⠀⠀⠀                                                       */
/* ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢻⣿⣿⠂⠀⠀⠀⠀⠀⠀⠀⠀                                                       */
/* ⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣴⣿⣿⣀⠀⠀⠀⠀⠀⠀⠀⠀                                                       */
/* ⠀⠀⠀⠀⠀⠀⠀⢠⣾⣿⣿⣿⣿⣿⣿⣦          ⠀                                                   */
/* ⠀⠀⠀⠀⠀⠀⣴⣿⢿⣷⠒⠲⣾⣾⣿⣿⠂         Created by: brunrodr - 05/31/2024                   */
/* ⠀⠀⠀⠀⣴⣿⠟⠁⠀⢿⣿⠁⣿⣿⣿⠻⣿⣄⠀⠀⠀⠀   Updated by: brunrodr - 05/31/2024                   */
/* ⠀⠀⣠⡾⠟⠁⠀⠀⠀⢸⣿⣸⣿⣿⣿⣆⠙⢿⣷⡀⠀⠀                                                       */
/* ⣰⡿⠋⠀⠀⠀⠀⠀⠀⢸⣿⣿⣿⣿⣿⣿⠀⠀⠉⠻⣿⡀                                                       */
/* ⠀⠀⠀⠀⠀⠀⠀⠀⠀⣾⣿⣿⣿⣿⣿⣿⣆ ⠀       Email: brunrodr@student.42sp.org.br                 */
/* ⠀⠀⠀⠀⠀⠀⠀⠀⣼⣿⣿⣿⡿⣿⣿⣿⣿⡄⠀⠀⠀⠀                                                       */
/* ⠀⠀⠀⠀⠀⠀⠀⢠⣿⣿⠿⠟⠀⠀⠻⣿⣿⡇⠀⠀⠀⠀                                                       */
/* ⠀⠀⠀⠀⠀⠀⢀⣾⡿⠃⠀⠀⠀⠀⠀⠘⢿⣿⡀⠀⠀⠀                                                       */
/* ⠀⠀⠀⠀⠀⣰⣿⡟⠀⠀⠀⠀⠀⠀⠀⠀⢸⣿⣷⡀⠀⠀   ⢽⣿⣿⠛⢻⣿⣿⣿⣿⠛⠛⠛⠛⢻⣿⣿⠿⠛⠛⠿⣿⡟⠛⠛⠛⠛⣿⡟⢿⣿⣿⣿⠛⢻⡟⠛⠛⠛⠻⣿⣿⣿ */
/* ⠀⠀⠀⠀⢠⣿⠟⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠻⣿⣧⠀⠀   ⢸⣿⣿⠀⢸⣿⣿⣿⣿⠀⢿⣿⣿⣿⡿⠁⣴⣶⣶⣾⣿⡇⠀⣿⣿⣿⣿⡏⢀⠙⢿⣿⠀⢸⡇⠀⣷⣷⣆⠈⢿⣿ */
/* ⠀⠀⠀⢀⣿⠃⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠘⣿⣆⠀   ⢸⣿⣿⠀⢸⣿⣿⣿⣿⠀⢤⣤⣴⣿⣧⠀⢿⣿⣤⠀⣿⡇⠀⣤⣤⣼⣿⡇⠀⣷⣄⠙⠀⢸⡇⠀⣿⣿⡟⠀⣸⣿ */
/*  ⠀⠠⢾⠇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⣿⣷⡤  ⢸⣿⣿⣀⣈⣉⣉⣉⣿⣀⣈⣉⣉⣹⣿⣷⣄⣈⣁⣤⣿⣇⣀⣉⣉⣉⣿⣇⣀⣿⣿⣷⣄⣸⣧⣀⣉⣉⣀⣴⣿⣿ */
/*************************************************************************************/

#include "../include/Fixed.hpp"
#include "../include/Point.hpp"

static void test(Point a, Point b, Point c, Point point, std::string description)
{
	std::cout << description << ": ";
	if (bsp(a, b, c, point) == true)
		std::cout << "Inside" << std::endl;
	else
		std::cout << "Outside" << std::endl;
}

int	main(void)
{
	//Equilateral triangle ///////////////////////
	Point a1(0, 0);
	Point b1(4, 0);
	Point c1(2.0f, 3.464f);
	Point point1(2, 1);
	Point point2(2.0f, 3.464f);
	Point point3(4, 4);
	test(a1, b1, c1, point1, "Equilateral (inside)");
	test(a1, b1, c1, point2, "Equilateral (on the edge)");
	test(a1, b1, c1, point3, "Equilateral (outside)");
	std::cout << "\n\n";

	//Right-angle triangle ///////////////////////
	Point a2(0, 0);
	Point b2(4, 0);
	Point c2(0, 3);
	Point point4(1, 1);
	Point point5(2, 0);
	Point point6(5, 5);
	test(a2, b2, c2, point4, "Retangle (inside)");
	test(a2, b2, c2, point5, "Retangle (on the edge)");
	test(a2, b2, c2, point6, "Retangle (outside)");
	std::cout << "\n\n";

	//Isosceles triangle ///////////////////////
	Point a3(0, 0);
	Point b3(4, 0);
	Point c3(2, 4);
	Point point7(2, 2);
	Point point8(2, 0);
	Point point9(5, 5);
	test(a3, b3, c3, point7, "Isosceles (inside)");
	test(a3, b3, c3, point8, "Isosceles (on the edge)");
	test(a3, b3, c3, point9, "Isosceles (outside)");
	std::cout << "\n\n";

	//Vertex ///////////////////////////////////
	Point point10(0, 0);
	test(a1, b1, c1, point10, "Equilateral (vertex)");
	test(a2, b2, c2, point10, "Retangle (vertex)");
	test(a3, b3, c3, point10, "Isosceles (vertex)");
	return (0);
}