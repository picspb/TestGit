// ���� ���������� PIC24FJ256GA702
// ���� ������������
// �������� �����������
#define FCY 8000000UL/2                  //������� ������������ ����
#include <xc.h>
#include <libpic30.h>

//------ ���� ������������ PIC24FJ64GA102 -------------
//���� ��������� � c:\Program Files (x86)\Microchip\xc16\v1.33\docs\/config_index.html ��� ���.245
#pragma config ALTI2C1 = ALTI2CDIS	//����� �������������� ����� ��� ���� I2C (ALTI2CDIS, ALTI2CEN)
#pragma config SOSCHP   =   ON      //SOSC ��������� � ������ High Power (��������� ������ ��� SOSCSEL = 1)
#pragma config TMPRPIN  =   OFF     //��������� ���������������� ����� TMPRN (��.RTCC ������)
#pragma config ALTCMPI  =   DISABLE //���. �������������� ����� ������������ C1INC, C2INC, C3INC 
#pragma config JTAGEN   =   OFF     //���-���� JTAG �����
#pragma config ICS      =   PGD1    //����� ����� ������� (PGD1,PGD2,PGD3)
#pragma config DNVPEN   =   DISABLE //���������� ������ �� �������� ���������� BOR (ENABLE,DISABLE)
#pragma config LPCFG    =   ON      //���������� ��� ������� ���������� ���� � SLEEP (�������� RCONbits.RETEN=1;)
#pragma config BOREN    =   OFF     //Brown Out Enable bit (OFF,SBOREN,NO_SLEEP,ON)
#pragma config WDTCLK   =   SYSCLK  //�������� ������������ WDT (SYSCLK,SOSC,FRC,LPRC)
#pragma config WDTCMX   =   WDTCLK  //��� ������������ �������� ������������ WDT (LPRC-������ LPRC, WDTCLK - ������ ������������ WDTCLK)
#pragma config WDTWIN   =   WIN75   //����� ������ ���� WDT � ��������� (WIN25,WIN37,WIN50,WIN75)
#pragma config WINDIS   =   OFF     //��������� �������� ������ WDT (ON, OFF)
#pragma config FWDTEN   =   OFF     //��������� WDT (�������������) (OFF,ON_DIS_SLEEP,ON_SWDTEN,ON)
#pragma config FWPSA    =   PR32   //������������ WDT(1:128-32)
#pragma config WDTPS    =   PS2048 //������������ WDT(1:32768-16384-8192-4096-2048-1024-512-256-128-64-32-16-8-4-2)
#pragma config FCKSM    =   CSDCMD  //���������� ������ ��������� ����������
#pragma config IOL1WAY  =   OFF     //���������� ����������� ������ � �������� RPxx (OFF - ������������ ������ RPxx)
#pragma config PLLSS    =   PLL_FRC //�������� ������������ PLL (PLL_FRC,PLL_PRI)
#pragma config SOSCSEL  =   OFF     //����������� ���������� ���������� ������ SOSCI/SOSCO (ON,OFF)
#pragma config OSCIOFCN =   OFF      //���������� ����� OSCO RA3 (ON-������� ��/��� OFF-����� �������� �������/2)
#pragma config POSCMD   =   NONE    //����� ������ ��������� ���������� (EC,XT,HS,NONE)
#pragma config IESO     =   OFF     //����� �� ���� ����������� ON-������� �������� FRC, ����� ��������� ������������ ��������� OFF- ����� ����������������
#pragma config PLLMODE  =   DISABLED//����� PLL (DISABLED,PLL8X,PLL6X,PLL4X,PLL96DIV12,PLL96DIV8,PLL96DIV6,PLL96DIV5,PLL96DIV4,PLL96DIV3,PLL96DIV2,PLL96DIV1)
#pragma config FNOSC    =   OSCFDIV   //����� ���������� (FRC-����������) FRCPLL,PRI,PRIPLL,SOSC,LPRC,DCO,OSCFDIV
#pragma config BSLIM    =   0x1FFF   //������ ����������� ������� (�������� ������������� ������� �.�. 0 - ��� ������ �������)
#pragma config AIVTDIS  =   OFF     //�������������� ������� �������� ���������� (ON,OFF)
#pragma config CSS      =   DISABLED//������� ������ ������� ������������(HIGH,ENHNCD,STNDRD,DISABLED)
#pragma config CWRP     =   OFF     ////������ ������� ������������
#pragma config GSS      =   DISABLED//������� ������ ��������� �������� ������ (HIGH,ENHNCD,STNDRD,DISABLED)	
#pragma config GWRP     =   OFF     //������ ��������� �������� ������ ��������
#pragma config BSEN     =   OFF     //���������� ��������� ����������� ������� - ������ ��������� FBSLIM (ON,OFF)
#pragma config BSS      =   DISABLED//������� ������ ����������� ������� (HIGH,STNDRD,DISABLED)	
#pragma config BWRP     =   OFF     //������ �� ������ ����������� ������� Boot Segment(ON,OFF)




#define	LED_B           _LATA0          //����� ���������
#define	LED_R           _LATB8          //������� ���������
#define	LED_G           _LATB9          //������ ���������


//----------- �������� ���� ��������� --------------
int main(void) {
//AD1PCFG =   0b1111111111111111;   //��� ����� ���������
TRISA   =   0b00000;
LATA    =   0b00000;
TRISB   =   0b0000000000000000;       //0-����� 1-����
LATB    =   0b0000000000000000;   

//CLKDIVbits.CPDIV =   3;					//���������� ��������� ����������� ���������� 0x0700-31��� 0x0500-250��� 0x0200-2���  0x0100-4��� 0x0000-8���
OSCDIVbits.DIV = 0;     //������������� ������� ������� ���������� 1-(1*2)=2,2-(2*2)=4,3-(3*2)=6..... 32767-(32767*2)=65534
OSCFDIVbits.TRIM = 0;   //������� �������� ������� ���������� 1-1/512,2-2/512 ...510-510/512,511-511/512
while(1)
{
LED_G=1;
__delay_ms(100);
LED_G=0;    
__delay_ms(500);
//RCONbits.RETEN=1;
//Sleep(); 
}//����� while(1)
    return 0;   //��� �����������
}//����� int main(void)

