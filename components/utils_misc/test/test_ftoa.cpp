#include <unity.h>

#include <utils_misc/ftoa.h>

void tst_ftoa() {
  char buf[32];
  const char *s = ftoa(53.12, buf, 2);
  TEST_ASSERT_EQUAL_STRING("53.12", s);
}

int main() {
  UNITY_BEGIN();

  RUN_TEST(tst_ftoa);

  return UNITY_END();
}
