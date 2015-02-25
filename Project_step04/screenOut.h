/* Name : screenOut.h	ver 1.2
 * Content : 콘솔 출력을 위한 함수들의 선언
 * Implementation : YSW
 *
 * Last modified 2015/01/09
 */

#ifndef __SCREENOUT_H__
#define __SCREENOUT_H__

#include "cusInfo.h"
#include "dvdInfo.h"

void ShowMenu(void);
void ShowCustomerInfo(cusInfo *pCus);
void ShowCustomerInfoContinue(cusInfo *pCus);
void ShowDVDInfo(dvdInfo *pDVD);
void ShowGenre(int genre);
void ShowCusAllRentInfo(void);
#endif
/* end of file */
