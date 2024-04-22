#include <unity.h>

#include <utils_misc/cstring_utils.h>

void tst_csuEndsWith() {
  TEST_ASSERT_TRUE(csu_endsWith("net?","?"));
}

