/*
 * debug.c
 *
 *  Created on: 12.09.2017
 *      Author: bertw
 */

#include "debug/dbg.h"
#include "debug/log.h"

#include <ctime>

const char *db_log_tm() {
 static char buf[16];
 time_t t = time(0);
 struct tm *ltm = localtime(&t);
 if (!ltm)
   return "";
 strftime(buf, sizeof buf - 1, " (%H:%M:%S)", ltm);
 return buf;
}
