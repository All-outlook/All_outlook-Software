/***********************************************************************/
/*                                                                     */
/*  FILE        :Main.c or Main.cpp                                    */
/*  DATE        :Tue, Oct 31, 2006                                     */
/*  DESCRIPTION :Main Program                                          */
/*  CPU TYPE    :                                                      */
/*                                                                     */
/*  NOTE:THIS IS A TYPICAL EXAMPLE.                                    */
/*                                                                     */
/***********************************************************************/
//#include "typedefine.h"
#include "iodefine.h"
#ifdef __cplusplus
//#include <ios>                        // Remove the comment when you use ios
//_SINT ios_base::Init::init_cnt;       // Remove the comment when you use ios
#endif

void main(void);
#ifdef __cplusplus
extern "C" {
void abort(void);
}
#endif


void main(void)
{
	/*****************************************************************************************
	I/O�s���̐ݒ�
		�u�U�[�pIO�|�[�g�̐ݒ�
	*****************************************************************************************/
	//�u�U�[�֘A
	PORTB.PDR.BIT.B5 = 1;
	
	/*****************************************************************************************
	���C���v���O����
		�u�U�[ON
	*****************************************************************************************/
	int i = 0;
	while(1){
		PORTB.PODR.BIT.B5 = 1;
		for(i = 0; i < 100; i++);
		PORTB.PODR.BIT.B5 = 0;
		for(i = 0; i < 100; i++);
	}
}

#ifdef __cplusplus
void abort(void)
{

}
#endif
