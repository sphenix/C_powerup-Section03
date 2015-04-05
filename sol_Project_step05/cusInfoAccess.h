/* Name : cusInfoAccess.h	ver 1.1
 * Content : 고객 정보 저장 및 참조 함수들의 선언
 * Implementation : YSW
 *
 * Last modified 2015/04/06
 */

#ifndef __CUSACCESS_H__
#define __CUSACCESS_H__

#include "cusInfo.h"

int AddCusInfo(char *ID, char *name, char *num);
cusInfo *GetCusPtrByID(char *ID);
int IsRegistID(char *ID);

void StoreCusListToFile(void);
void LoadCusListFromFile(void);
#endif
/* end of file */
