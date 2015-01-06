/* Name : dvdInfo.h	ver 1.1
 * Content : 영화 DVD 관리 구조체
 * Implementation : YSW
 * 
 * Last modified 2015/01/05
 */

#ifndef __DVDINFO_H__
#define __DVDINFO_H__

#include "cusInfo.h"

#define ISBN_LEN	30
#define TITLE_LEN	30
#define RENT_LEN	100

enum {ACTION = 1, COMIC, SF, ROMANTIC};
enum {RENTED, RETURNED};

tyepdef struct __dvdRentInfo
{
	char cusID[ID_LEN];
	unsigned int rentDay;
} dvdRentInfo;

typedef	struct __dvdInfo
{
	char ISBN[ISBN_LEN];
	char title[TITLE_LEN];
	int genre;
	
	int rentState;
	int numOfRentCus;
	dvdRentInfo rentList[RENT_LEN];
} dvdInfo;

#endif
/* end of file */

