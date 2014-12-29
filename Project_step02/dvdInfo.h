/* Name : dvdInfo.h	ver 1.0
 * Content : 영화 DVD 관리 구조체
 * Implementation : YSW
 * 
 * Last modified 2014/12/29
 */

#ifndef __DVDINFO_H__
#define __DVDINFO_H__

#define ISBN_LEN	30
#define TITLE_LEN	30

enum {ACTION = 1, COMIC, SF, ROMANTIC};

typedef	struct __dvdInfo
{
	char ISBN[ISBN_LEN];
	char title[TITLE_LEN];
	int genre;
} dvdInfo;

#endif
/* end of file */

