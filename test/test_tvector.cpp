#include "utmatrix.h"

#include <gtest.h>

TEST(TVector, can_create_vector_with_positive_length)
{
  ASSERT_NO_THROW(TVector<int> v(5));
}

TEST(TVector, cant_create_too_large_vector)
{
  ASSERT_ANY_THROW(TVector<int> v(MAX_VECTOR_SIZE + 1));
}

TEST(TVector, throws_when_create_vector_with_negative_length)
{
  ASSERT_ANY_THROW(TVector<int> v(-5));
}

TEST(TVector, throws_when_create_vector_with_negative_startindex)
{
  ASSERT_ANY_THROW(TVector<int> v(5, -2));
}

TEST(TVector, can_create_copied_vector)
{
  TVector<int> v(10);

  ASSERT_NO_THROW(TVector<int> v1(v));
}

TEST(TVector, copied_vector_is_equal_to_source_one)
{
  TVector<int> v(4);
  v[0]=10;
  v[2]=3;
  // 10 0 3 0
  
  TVector<int> t(v);

  EXPECT_EQ(v, t);
}

TEST(TVector, copied_vector_has_its_own_memory)
{
  TVector<int> v(4);
  v[0] = 10;
  v[2] = 3;
  // 10 0 3 0
  
  TVector<int> t(v);
  t[1] = 7;
  // 10 7 3 0

  EXPECT_NE(v, t);
}

TEST(TVector, can_get_size)
{
  TVector<int> v(4);

  int k = 0;

  ASSERT_NO_THROW(k = v.GetSize()); 

  EXPECT_EQ(k, 4);
}

TEST(TVector, can_get_start_index)
{
  TVector<int> v(4, 2);

  int k = 0;

  ASSERT_NO_THROW(k = v.GetStartIndex()); 

  EXPECT_EQ(k, 2);
}

TEST(TVector, can_set_and_get_element)
{
  TVector<int> v(4);

  ASSERT_NO_THROW(v[0] = 4);

  EXPECT_EQ(4, v[0]);
}

TEST(TVector, throws_when_set_element_with_negative_index)
{
  TVector<int> v(4);

  ASSERT_ANY_THROW(v[-3]);
}

TEST(TVector, throws_when_set_element_with_too_large_index)
{
  TVector<int> v(4);

  ASSERT_ANY_THROW(v[7]);
}

TEST(TVector, can_assign_vector_to_itself)
{
  TVector<int> v(4);
  v[0] = 10;
  v[2] = 3;
  // 10 0 3 0
  
  TVector<int> t(4);
  t[0] = 10;
  t[2] = 3;
  // 10 0 3 0

  ASSERT_NO_THROW(v = v);

  EXPECT_EQ(v, t);
}

TEST(TVector, can_assign_vectors_of_equal_size)
{
  TVector<int> v(4);
  v[0] = 10;
  v[2] = 3;
  // 10 0 3 0

  TVector<int> r(4);
  r[1] = 1;
  r[3] = 4;
  // 0 1 0 4
  
  TVector<int> t(r);
  // 0 1 0 4

  ASSERT_NO_THROW(v = r);

  EXPECT_EQ(v, t);
}

TEST(TVector, assign_operator_change_vector_size)
{
  TVector<int> v(4);
  TVector<int> t(5); 

  ASSERT_NO_THROW(v = t);

  EXPECT_NE(v.GetSize(), 4);
}

TEST(TVector, can_assign_vectors_of_different_size)
{
  TVector<int> v(4);
  v[0] = 10;
  v[2] = 3;
  // 10 0 3 0

  TVector<int> r(5);
  r[1] = 1;
  r[3] = 4;
  r[4] = 11;
  // 0 1 0 4 11
  
  TVector<int> t(r);
  // 0 1 0 4 11

  ASSERT_NO_THROW(v = r); 

  EXPECT_EQ(v, t);
}

TEST(TVector, compare_equal_vectors_return_true)
{
  TVector<int> v(4);
  v[0] = 10;
  v[2] = 3;
  // 10 0 3 0
  
  TVector<int> t(4);
  t[0] = 10;
  t[2] = 3;
  // 10 0 3 0

  EXPECT_EQ(v == t, true);
}

TEST(TVector, compare_vector_with_itself_return_true)
{
  TVector<int> v(4);
  v[0] = 10;
  v[2] = 3;
  // 10 0 3 0

  EXPECT_EQ(v == v, true);
}

TEST(TVector, vectors_with_different_size_are_not_equal)
{
  TVector<int> v(4);
  v[0] = 10;
  v[2] = 3;
  // 10 0 3 0
  
  TVector<int> t(5);
  t[0] = 10;
  t[2] = 3;
  // 10 0 3 0 0

  EXPECT_EQ(v == t, false);
}

TEST(TVector, can_add_scalar_to_vector)
{
  TVector<int> v(4);
  v[0] = 10;
  v[2] = 3;
  // 10 0 3 0
  
  TVector<int> t(4);
  t[0] = 12;
  t[1] = 2;
  t[2] = 5;
  t[3] = 2;

  // 12 2 5 2

  ASSERT_NO_THROW(v = v + 2); 

  EXPECT_EQ(v, t);
}

TEST(TVector, can_subtract_scalar_from_vector)
{
  TVector<int> v(4);
  v[0] = 10;
  v[2] = 3;
  // 10 0 3 0
  
  TVector<int> t(4);
  t[0] = 8;
  t[1] = -2;
  t[2] = 1;
  t[3] = -2;

  // 8 -2 1 -2

  ASSERT_NO_THROW(v = v - 2);
 
  EXPECT_EQ(v, t);
}

TEST(TVector, can_multiply_scalar_by_vector)
{
  TVector<int> v(4);
  v[0] = 10;
  v[2] = 3;
  // 10 0 3 0
  
  TVector<int> t(4);
  t[0] = 20;
  t[2] = 6;

  // 20 0 6 0

  ASSERT_NO_THROW(v = v * 2);
 
  EXPECT_EQ(v, t);
}

TEST(TVector, can_add_vectors_with_equal_size)
{
  TVector<int> v(4);
  v[0] = 10;
  v[2] = 3;
  // 10 0 3 0
  
  TVector<int> t(4);
  t[0] = 20;
  t[2] = 6;
  // 20 0 6 0

  ASSERT_NO_THROW(v = v + v);

  EXPECT_EQ(v, t);
}

TEST(TVector, cant_add_vectors_with_not_equal_size)
{
  TVector<int> v(4), r(5);

  ASSERT_ANY_THROW(v + r);
}

TEST(TVector, can_subtract_vectors_with_equal_size)
{
  TVector<int> v(4);
  v[0] = 10;
  v[2] = 3;
  // 10 0 3 0
  
  TVector<int> t(4);
  t[0] = 10;
  t[1] = 1;
  t[2] = 3;
  t[3] = 4;
  // 10 1 3 4

  TVector<int> r(4);
  r[1] = -1;
  r[3] = -4;
  // 0 -1 0 -4

  ASSERT_NO_THROW(v = v - t);

  EXPECT_EQ(v, r);
}

TEST(TVector, cant_subtract_vectors_with_not_equal_size)
{
  TVector<int> v(4), r(5);

  ASSERT_ANY_THROW(v - r);
}

TEST(TVector, can_multiply_vectors_with_equal_size)
{
  TVector<int> v(4);
  v[0] = 10;
  v[2] = 3;
  // 10 0 3 0
  
  TVector<int> t(4);
  t[0] = 10;
  t[1] = 1;
  t[2] = 3;
  t[3] = 4;
  // 10 1 3 4
  
  int k = 0;

  ASSERT_NO_THROW(k = v * t);
 
  EXPECT_EQ(k, 109);
}

TEST(TVector, cant_multiply_vectors_with_not_equal_size)
{
  TVector<int> v(4), r(5);

  ASSERT_ANY_THROW(v * r);
}

