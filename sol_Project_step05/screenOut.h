/* Name : screenOut.h	ver 1.3
 * Content : 콘솔 출력을 위한 함수들의 선언
 * Implementation : YSW
 *
 * Last modified 2015/02/25
 */

#ifndef __SCREENOUT_H__
#define __SCREENOUT_H__

#include "cusInfo.h"
#include "dvdInfo.h"
#include "rentInfo.h"

void ShowMenu(void);
void ShowCustomerInfo(cusInfo *pCus);
void ShowCustomerInfoContinue(cusInfo *pCus);
void ShowDVDInfo(dvdInfo *pDVD);
void ShowDVDRentInfo(dvdRentInfo dvd);
void ShowGenre(int genre);

#endif
/* end of file */
