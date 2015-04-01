/* Name : dvdInfoAccess.h	ver 1.2
 * Content : DVD 정보 저장/참조 함수들의 선언
 * Implementation : YSW
 *
 * Last modified 2015/02/25
 */

#ifndef __DVDACCESS_H__
#define __DVDACCESS_H__

#include "dvdInfo.h"

int AddDVDInfo(char *ISBN, char *title, int genre);
dvdInfo *GetDVDPtrByISBN(char *ISBN);
int IsRegistISBN(char *ISBN);

int SetDVDRented(char *ISBN);
int SetDVDReturned(char *ISBN);
int GetDVDRentState(char *ISBN);
int dvdLoadFromFile(void);
int dvdStoreToFile(void);

#endif
/* end of file */
