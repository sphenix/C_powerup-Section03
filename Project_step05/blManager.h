/* Name : cusManager.h	ver 1.0
 * Content : 고객 및 DVD 관련 업무 처리 함수들의 선언
 * Implementation : YSW
 * 
 * Last modified 2015/03/23
 */

#ifndef	__BLMGR_H__
#define __BLMGR_H__

void RegistCustomer(void);
void SearchCusInfo(void);

void RegistDVD(void);
void SearchDVDInfo(void);

void RentDVD(void);
void ReturnDVD(void);
void ShowDVDRentAllCusInfo(void);
void ShowDVDCusAllRentInfo(void);


#endif
/* end of file */

