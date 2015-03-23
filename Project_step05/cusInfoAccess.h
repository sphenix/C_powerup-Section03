/* Name : cusInfoAccess.h	ver 1.0
 * Content : 고객 정보 저장 및 참조 함수들의 선언
 * Implementation : YSW
 *
 * Last modified 2014/12/17
 */

#ifndef __CUSACCESS_H__
#define __CUSACCESS_H__

#include "cusInfo.h"

int AddCusInfo(char *ID, char *name, char *num);
cusInfo *GetCusPtrByID(char *ID);
int IsRegistID(char *ID);

#endif
/* end of file */
