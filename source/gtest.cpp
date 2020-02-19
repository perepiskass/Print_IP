#include <gtest/gtest.h>
#include "version_lib.h"
#include "print.h"
#include <map>
#include <set>


// Тест кейсы на проверку версий
TEST(version_test_case, version_test_patch)
{
    ASSERT_GE(version_patch(), 1);
}
TEST(version_test_case, version_test_minor)
{
    EXPECT_EQ(version_minor(), 1);
}
TEST(version_test_case, version_test_major)
{
    EXPECT_EQ(version_major(), 1);
}

// Тест кейсы класса has_Begin_End
TEST(has_Begin_End_test_case, True_test) 
{
  EXPECT_TRUE(has_Begin_End<std::vector<int>>::value);
  EXPECT_TRUE(has_Begin_End<std::list<int>>::value);

  using m = std::map<int,int>;
  EXPECT_TRUE(has_Begin_End<m>::value);
  EXPECT_TRUE(has_Begin_End<std::set<int>>::value);
}


// Тест кейсы шаблонной функции для контейнеров
TEST(conteiner_print_test_case, vector_print_test)
{
  bool value = std::is_same<void, decltype(printIP(std::declval<std::vector<int>>()))>::value;
  
  EXPECT_TRUE(value);
}

TEST(conteiner_print_test_case, list_print_test)
{
  bool value = std::is_same<void, decltype(printIP(std::declval<std::list<int>>()))>::value;
  
  EXPECT_TRUE(value);
}


// Тест кейсы шаблоной функции для интегральных типов
TEST(integral_print_test_case, int_print_test)
{
  int a = 0;
  bool value = std::is_same<void, decltype(printIP(a))>::value;
  
  EXPECT_TRUE(value);
}

TEST(integral_print_test_case, char_print_test)
{
  bool value = std::is_same<void, decltype(printIP(char()))>::value;
  
  EXPECT_TRUE(value);
}


// Тест кейсы шаблоной функции для строки
TEST(string__print_test_case, string_test)
{
  bool value = std::is_same<void, decltype(printIP(std::string()))>::value;
  EXPECT_TRUE(value);
}


int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}