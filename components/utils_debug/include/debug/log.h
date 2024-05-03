#ifdef MCU_ESP32

#include <esp_log.h>
#define db_loge  ESP_LOGE
#define db_logi  ESP_LOGI
#define db_logw  ESP_LOGW
#define db_logd  ESP_LOGD
#define db_printf(format, ... ) ESP_LOGD("debug", format __VA_OPT__(,)  __VA_ARGS__)

#else

#ifdef __cplusplus
extern "C++" {
#endif
const char *db_log_tm();
#ifdef __cplusplus
}
#endif

#include <stdio.h>
#define db_loge( tag, format, ... ) fprintf(stderr,  "E%s %s: " format "\n", db_log_tm(), tag __VA_OPT__(,) __VA_ARGS__)
#define db_logi( tag, format, ... ) fprintf(stderr,  "I%s %s: " format "\n", db_log_tm(), tag __VA_OPT__(,) __VA_ARGS__)
#define db_logw( tag, format, ... ) fprintf(stderr,  "W%s %s: " format "\n", db_log_tm(), tag __VA_OPT__(,) __VA_ARGS__)
#define db_printf(format, ... ) fprintf(stderr,  format  __VA_OPT__(,) __VA_ARGS__)

#endif
