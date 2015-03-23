/* Name : cusInfo.h	ver 1.0
 * Content : 고객 관리 구조체
 * Implementation : YSW
 *
 * Last modified 2014/12/17
 */

#ifndef __CUSINFO_H__
#define __CUSINFO_H__

#define ID_LEN		10
#define NAME_LEN	30
#define PHONE_LEN	30

typedef	struct	__cusInfo
{
	char ID[ID_LEN];
	char name[NAME_LEN];
	char phoneNum[PHONE_LEN];
} cusInfo;

#endif
/* end of file */
