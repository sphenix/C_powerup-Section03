/* Name : dvdInfo.h	ver 1.2
 * Content : 영화 DVD 관리 구조체
 * Implementation : YSW
 * 
 * Last modified 2015/02/25
 */

#ifndef __DVDINFO_H__
#define __DVDINFO_H__

#include "cusInfo.h"

#define ISBN_LEN	30
#define TITLE_LEN	30

enum {ACTION = 1, COMIC, SF, ROMANTIC};
enum {RENTED, RETURNED};

typedef	struct __dvdInfo
{
	char ISBN[ISBN_LEN];
	char title[TITLE_LEN];
	int genre;
	int rentState;
} dvdInfo;

#endif
/* end of file */

