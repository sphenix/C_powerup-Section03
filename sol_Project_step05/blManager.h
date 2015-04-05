/* Name : blManager.h   ver 1.0
 * Content : 비즈니스 로직 처리 함수들의 선언
 * Implementation : YSW
 *
 * Last modified 2015/04/06
 */
#ifndef __BL_MGR_H__
#define __BL_MGR_H__

void RegistCustomer(void);
void SearchCusInfo(void);
void RegistDVD(void);
void SearchDVDInfo(void);
void RentDVD(void);
void ReturnDVD(void);
void ShowDVDRentAllCusInfo(void);
void ShowDVDCusAllRentInfo(void);
void InitData(void);

#endif
