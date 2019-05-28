#include "triangle.h"
#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>

void test_equilateral(void)
/*
 * Test si un triangle est équilatéral.
 */
{
	CU_ASSERT_EQUAL(3, typeTriangle(2.0, 2.0, 2.0));
	CU_ASSERT_EQUAL(3, typeTriangle(10.0, 10.0, 10.0));
}

void test_isocele(void)
/*
 * Test si un triangle est isocèle.
 */
{
	CU_ASSERT_EQUAL(2, typeTriangle(2.0, 2.0, 1.0));
	CU_ASSERT_EQUAL(2, typeTriangle(5.0, 10.0, 10.0));
	CU_ASSERT_EQUAL(2, typeTriangle(5.0, 3.0, 5.0));
}

void test_quelconque(void)
/*
 * Test si un triangle est quelconque.
 */
{
	CU_ASSERT_EQUAL(1, typeTriangle(2.0, 3.0, 4.0));
	CU_ASSERT_EQUAL(1, typeTriangle(2.0, 4.0, 3.0));
	CU_ASSERT_EQUAL(1, typeTriangle(3.0, 2.0, 4.0));
}

void test_non_triangle(void)
/*
 * Test si les valeurs ne représentent pas un triangle.
 */
{
	CU_ASSERT_EQUAL(-1, typeTriangle(2.0, 3.0, 0.0));
	CU_ASSERT_EQUAL(-1, typeTriangle(-2.0, 4.0, 3.0));
	CU_ASSERT_EQUAL(-1, typeTriangle(3.0, 22.0, 4.0));
}
int main(){

	test_equilateral();
	test_isocele();
	test_quelconque();
	test_non_triangle();

	return 0;
}