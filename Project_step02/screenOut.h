/* Name : screenOut.h	ver 1.1
 * Content : 콘솔 출력을 위한 함수들의 선언
 * Implementation : YSW
 *
 * Last modified 2015/01/02
 */

#ifndef __SCREENOUT_H__
#define __SCREENOUT_H__

#include "cusInfo.h"
#include "dvdInfo.h"

void ShowMenu(void);
void ShowCustomerInfo(cusInfo *pCus);
void ShowDVDInfo(dvdInfo *pDVD);

#endif
/* end of file */
