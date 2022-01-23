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
#include <sci.h>
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
	�N���b�N�ݒ�
		
	*****************************************************************************************/
	SYSTEM.PRCR.WORD = 0xa50b;		//�N���b�N�\�[�X�I���̕ی�̉���

	SYSTEM.PLLCR.WORD = 0x0F00;		/* PLL ���{�~16 ����1���� (12.000MHz * 16 = 192MHz)*/
	SYSTEM.PLLCR2.BYTE = 0x00;		/* PLL ENABLE */
	
	SYSTEM.PLLWTCR.BYTE     = 0x0F;		/* 4194304cycle(Default) */
	
	
	// ICK   : 192/2 = 96MHz 		// �V�X�e���N���b�N CPU DMAC DTC ROM RAM
	// PCLKA : 192/2 = 96MHz 		// ���Ӄ��W���[���N���b�NA ETHERC�AEDMAC�ADEU
	// PCLKB : 192/4 = 48MHz 		// ���Ӄ��W���[���N���b�NB ��L�ȊO PCLKB=PCLK
/*	
	SYSTEM.SCKCR.BIT.FCK=0x02;		//FCLK MAX 50MHz  192/4
	SYSTEM.SCKCR.BIT.ICK=0x01;		//ICLK MAX 100MHz 192/2
	SYSTEM.SCKCR.BIT.PSTOP1=0x01;		//BCLK �o�͒�~
	SYSTEM.SCKCR.BIT.PSTOP0=0x01;		//SDCLK �o�͒�~
	SYSTEM.SCKCR.BIT.BCK=0x02;		//BCLK MAX 100MHz ICLK�ȉ��ɂ���K�v������192/4
	SYSTEM.SCKCR.BIT.PCKA=0x01;		//PCLKA MAX 100MHz 192/2
	SYSTEM.SCKCR.BIT.PCKB=0x02;		//PCLKB MAX 50MHz 192/4
	//��L�̐ݒ�ł͐�����clock�ݒ肪�ł��Ȃ����߉��L�̂悤�Ɉꊇ�Őݒ肷�邱��
*/
	SYSTEM.SCKCR.LONG = 0x21C21211;		//FCK1/4 ICK1/2 BCLK��~ SDCLK��~ BCK1/4 PCLKA1/2 PCLKB1/4
/*
	SYSTEM.SCKCR2.BIT.UCK=0x03;		//UCLK MAX 48MHz 192/4
	SYSTEM.SCKCR2.BIT.IEBCK=0x02;		//IECLK MAX 50MHz 192/4
*/
	SYSTEM.SCKCR2.WORD = 0x0032;		/* UCLK1/4 IEBCK1/4 */
	SYSTEM.BCKCR.BYTE = 0x01;		/* BCLK = 1/2 */
	
	SYSTEM.SCKCR3.WORD = 0x0400;		//PLL��H�I��
	
	/*****************************************************************************************
	I/O�ݒ�
		LED�̐ݒ�	
	*****************************************************************************************/
	
	//�ԊOLED�̃s���ݒ�
	PORTA.PDR.BIT.B3 = 1;	//PA3���o�͗p�ɐݒ�
	PORT1.PDR.BIT.B5 = 1;	//P15���o�͗p�ɐݒ�
	PORT1.PDR.BIT.B4 = 1;	//P14���o�͗p�ɐݒ�
	PORT3.PDR.BIT.B1 = 1;	//P31���o�͗p�ɐݒ�
	/*****************************************************************************************
	���̑��C�j�V�����C�Y
		SCI�Ƃ�
	*****************************************************************************************/	
	//sci�̃C�j�V�����C�Y
	init_sci();
	
	/*****************************************************************************************
	A/DC�̐ݒ�
		���Z���T
	*****************************************************************************************/
	//A/D�ϊ��p�̃s���ݒ�
	SYSTEM.PRCR.WORD = 0xA502;
	MSTP_S12AD = 0;
	SYSTEM.PRCR.WORD = 0xA500;
	//PE1�p�ݒ�
	PORTE.PDR.BIT.B7 = 0;
	
	//A/D�|�[�g��PMR�ݒ�
	PORT4.PMR.BIT.B6=1;	//P46�����Ӌ@��Ƃ��Ďg�p
	PORT4.PMR.BIT.B2=1;	//P42�����Ӌ@��Ƃ��Ďg�p
	PORT4.PMR.BIT.B1=1;	//P41�����Ӌ@��Ƃ��Ďg�p
	PORT4.PMR.BIT.B0=1;	//P40�����Ӌ@��Ƃ��Ďg�p
	PORTE.PMR.BIT.B1=0;	//PE1�����Ӌ@��Ƃ��Ďg�p �d�� PE1
	//A/D�|�[�g��PFS�ݒ�
	MPC.PWPR.BYTE=0x00;	//�v���e�N�g����
	MPC.PWPR.BYTE=0x40;	//�v���e�N�g����
	MPC.P46PFS.BIT.ASEL=1;	//A/D SEN_FR	AN006���g�p
	MPC.P42PFS.BIT.ASEL=1;	//A/D SEN_R 	AN002���g�p
	MPC.P41PFS.BIT.ASEL=1;	//A/D SEN_FR	AN001���g�p
	MPC.P40PFS.BIT.ASEL=1;	//A/D SEN_R 	AN000���g�p
	MPC.PE1PFS.BIT.ASEL=1;	//A/D V_BAT	AN009���g�p
	MPC.PWPR.BYTE=0x80;	//�v���e�N�g�쓮
	
	//A/D�ϊ�(�f�t�H���g�ŃV���O�����[�h)
	//S12AD.ADCSR.BYTE = 0x0c;	//A/D�ϊ��N���b�N��PCLKB(48M[ha])
	S12AD.ADCSR.BIT.CKS = 3;	//A/D�ϊ��̃N���b�N��PCLK��1����(48M[Hz])�ɐݒ�
	S12AD.ADCSR.BIT.ADCS = 0;	//�V���O���X�L�������[�h�ɐݒ�
	
	unsigned long i = 0;
	while(1){
		S12AD.ADANS0.WORD = 0x0047;	//A/D�ϊ���AN000,1,2,6�̂݋�����
		//�Z���T����
		PORTA.PODR.BIT.B3 = 1;	//PA3��High�ɐݒ�
		PORT1.PODR.BIT.B5 = 1;	//P15��High�ɐݒ�
		PORT1.PODR.BIT.B4 = 1;	//P14��High�ɐݒ�
		PORT3.PODR.BIT.B1 = 1;	//P31��High�ɐݒ�
		for(i = 0; i < 100*1000/40; i++); //40��100usec 
		S12AD.ADCSR.BIT.ADST = 1;	//A/D�ϊ����J�n
		while(S12AD.ADCSR.BIT.ADST);	//A/D�ϊ����I���܂ő҂�
		PORTA.PODR.BIT.B3 = 0;	//PA3��Low�ɐݒ�
		PORT1.PODR.BIT.B5 = 0;	//P15��Low�ɐݒ�
		PORT1.PODR.BIT.B4 = 0;	//P14��Low�ɐݒ�
		PORT3.PODR.BIT.B1 = 0;	//P31��Low�ɐݒ�
		//�Z���T�̒l��\��
		SCI_printf("sensor_fr = %d\n\r",S12AD.ADDR6);
		SCI_printf("sensor_r = %d\n\r",S12AD.ADDR2);
		SCI_printf("sensor_l = %d\n\r",S12AD.ADDR1);
		SCI_printf("sensor_fl = %d\n\r",S12AD.ADDR0);
		//�o�b�e���[�d����A/D�ϊ�
		S12AD.ADANS0.WORD = 0x0200;	//A/D�ϊ���AN006�̂݋�����
		S12AD.ADCSR.BIT.ADST = 1;	//A/D�ϊ����J�n
		while(S12AD.ADCSR.BIT.ADST);	//A/D�ϊ����I���܂ő҂�
		
		SCI_printf("V_BAT = %d\n\r",S12AD.ADDR9);
		for(i = 0; i < 100*1000*100; i++);
		
		//��ʃN���A�V�[�P���X
		SCI_printf("\x1b[2J");			//�N���A�X�N���[��[CLS]
		SCI_printf("\x1b[0;0H");		//�J�[�\����0,0�Ɉړ�
		
	}
	

}



#ifdef __cplusplus
void abort(void)
{

}
#endif
