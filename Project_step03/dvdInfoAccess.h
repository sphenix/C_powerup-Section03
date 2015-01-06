/* Name : dvdInfoAccess.h	ver 1.0
 * Content : DVD 정보 저장/참조 함수들의 선언
 * Implementation : YSW
 *
 * Last modified 2015/01/02
 */

#ifndef __DVDCONTROL_H_
#define __DVDCONTROL_H_

#include "dvdInfo.h"

int AddDVDInfo(char *ISBN, char *title, int genre);
dvdInfo *GetDVDPtrByISBN(char *ISBN);
int IsRegistISBN(char *ISBN);

#endif
/* end of file */
