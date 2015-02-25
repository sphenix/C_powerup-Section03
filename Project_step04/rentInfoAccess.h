/* Name : rentInfoAccess.h	ver 1.0
 * Content : 대여정보 접근을 위한 함수들의 선언
 * Implementation : YSW
 *
 * Last modified 2015/02/25
 */

#ifndef __RENTINFOACCESS_H__
#define __RENTINFOACCESS_H__

#include "rentInfoAccess.h"

void AddRentList(char *ISBN, char *cusID, int rentDay);
void PrintOutRentAllCusInfo(char *ISBN);
void PrintOutCusAllRentInfo(char *ID, unsigned int start, unsigned int end);

#endif
/* end of file */
