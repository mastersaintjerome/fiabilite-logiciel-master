#include "triangle.h"
#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>

void test_lecture_null(void)
/*
 * Test la lecture d'un fichier null.
 */
{
	Triangle *triangle = readData(NULL);

	CU_ASSERT_EQUAL(-1, triangle->a);
	CU_ASSERT_EQUAL(-1, triangle->b);
	CU_ASSERT_EQUAL(-1, triangle->c);

	free(triangle);
}

void test_mauvaise_lecture(void)
/*
 * Test la lecture d'un fichier inexistant.
 */
{
	Triangle *triangle = readData("test.txt");
	
	CU_ASSERT_EQUAL(-1, triangle->a);
	CU_ASSERT_EQUAL(-1, triangle->b);
	CU_ASSERT_EQUAL(-1, triangle->c);

	free(triangle);
}

void test_lecture_triangle_equilateral(void)
/*
 * Test la lecture d'un fichier inexistant.
 */
{
	Triangle *triangle = readData("triangleEquilateral.csv");
	
	CU_ASSERT_EQUAL(2.0, triangle->a);
	CU_ASSERT_EQUAL(2.0, triangle->b);
	CU_ASSERT_EQUAL(2.0, triangle->c);

	free(triangle);
}

void test_lecture_mauvais_csv(void)
/*
 * Test la lecture d'un fichier avec un mauvais format.
 */
{
	Triangle *triangle = readData("mauvaisTriangle.csv");
	
	CU_ASSERT_EQUAL(-1, triangle->a);
	CU_ASSERT_EQUAL(-1, triangle->b);
	CU_ASSERT_EQUAL(-1, triangle->c);

	free(triangle);
}

int main(){
	
	test_lecture_null();
	test_mauvaise_lecture();
	test_lecture_triangle_equilateral();
	test_lecture_mauvais_csv();
	
	return 0;
}