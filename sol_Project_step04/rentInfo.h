/* Name : rentInfo.h ver 1.0
 * Content : 영화 DVD 대여 정보 구조체
 * Implementation : YSW
 *
 * Last modified 2015/02/25
 */

#ifndef __RENTINFO_H__
#define __RENTINFO_H__

#include "dvdInfo.h"
#include "cusInfo.h"

typedef struct __dvdRentInfo
{
    char cusID[ID_LEN];
    char ISBN[ISBN_LEN];
    unsigned int rentDay;
} dvdRentInfo;

#endif
/* end of file */
