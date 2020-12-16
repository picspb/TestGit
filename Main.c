// Тест процессора PIC24FJ256GA702
// Биты конфигурации
// Моргание светодиодом
#define FCY 8000000UL/2                  //частота тактирования ядра
#include <xc.h>
#include <libpic30.h>

//------ Биты конфигурации PIC24FJ64GA102 -------------
//Биты расписаны в c:\Program Files (x86)\Microchip\xc16\v1.33\docs\/config_index.html или стр.245
#pragma config ALTI2C1 = ALTI2CDIS	//Выбор альтернативных ножек для шины I2C (ALTI2CDIS, ALTI2CEN)
#pragma config SOSCHP   =   ON      //SOSC генератор в рнжиме High Power (актуально только при SOSCSEL = 1)
#pragma config TMPRPIN  =   OFF     //Включение функционирования ножки TMPRN (см.RTCC таймер)
#pragma config ALTCMPI  =   DISABLE //Вкл. альтернативных ножек компараторов C1INC, C2INC, C3INC 
#pragma config JTAGEN   =   OFF     //Вкл-выкл JTAG порта
#pragma config ICS      =   PGD1    //Выбор порта отладки (PGD1,PGD2,PGD3)
#pragma config DNVPEN   =   DISABLE //Разрешение защиты от снижения напряжения BOR (ENABLE,DISABLE)
#pragma config LPCFG    =   ON      //Разрешение вкл низкого напряжения ядра в SLEEP (включать RCONbits.RETEN=1;)
#pragma config BOREN    =   OFF     //Brown Out Enable bit (OFF,SBOREN,NO_SLEEP,ON)
#pragma config WDTCLK   =   SYSCLK  //Источник тактирования WDT (SYSCLK,SOSC,FRC,LPRC)
#pragma config WDTCMX   =   WDTCLK  //Чем определяется источник тактирования WDT (LPRC-всегда LPRC, WDTCLK - битами конфигурации WDTCLK)
#pragma config WDTWIN   =   WIN75   //Выбор ширины окна WDT в процентах (WIN25,WIN37,WIN50,WIN75)
#pragma config WINDIS   =   OFF     //Включение оконного режима WDT (ON, OFF)
#pragma config FWDTEN   =   OFF     //Включение WDT (классического) (OFF,ON_DIS_SLEEP,ON_SWDTEN,ON)
#pragma config FWPSA    =   PR32   //Предделитель WDT(1:128-32)
#pragma config WDTPS    =   PS2048 //Постделитель WDT(1:32768-16384-8192-4096-2048-1024-512-256-128-64-32-16-8-4-2)
#pragma config FCKSM    =   CSDCMD  //Мониторинг отказа тактового генератора
#pragma config IOL1WAY  =   OFF     //Разрешение однократной записи в регистры RPxx (OFF - многократная запись RPxx)
#pragma config PLLSS    =   PLL_FRC //Источник тактирования PLL (PLL_FRC,PLL_PRI)
#pragma config SOSCSEL  =   OFF     //Подключение вторичного генератора ножкам SOSCI/SOSCO (ON,OFF)
#pragma config OSCIOFCN =   OFF      //Назначение ножки OSCO RA3 (ON-обычный вх/ывх OFF-выход тактовой частоты/2)
#pragma config POSCMD   =   NONE    //Выбор режима основного генератора (EC,XT,HS,NONE)
#pragma config IESO     =   OFF     //Старт от двух генераторов ON-сначала стартует FRC, потом выбранный ползователем генератор OFF- сразу пользовательский
#pragma config PLLMODE  =   DISABLED//Режим PLL (DISABLED,PLL8X,PLL6X,PLL4X,PLL96DIV12,PLL96DIV8,PLL96DIV6,PLL96DIV5,PLL96DIV4,PLL96DIV3,PLL96DIV2,PLL96DIV1)
#pragma config FNOSC    =   OSCFDIV   //Выбор генератора (FRC-внутренний) FRCPLL,PRI,PRIPLL,SOSC,LPRC,DCO,OSCFDIV
#pragma config BSLIM    =   0x1FFF   //Размер загрузочной области (значение инвертировано побитно т.е. 0 - это полная область)
#pragma config AIVTDIS  =   OFF     //Альтернативная таблица векторов прерывания (ON,OFF)
#pragma config CSS      =   DISABLED//Уровень защиты области конфигурации(HIGH,ENHNCD,STNDRD,DISABLED)
#pragma config CWRP     =   OFF     ////Защита области конфигурации
#pragma config GSS      =   DISABLED//Уровень защиты основного сегмента памяти (HIGH,ENHNCD,STNDRD,DISABLED)	
#pragma config GWRP     =   OFF     //Защита основного сегмента памяти программ
#pragma config BSEN     =   OFF     //Разрешение выделения загрузочной области - размер регистром FBSLIM (ON,OFF)
#pragma config BSS      =   DISABLED//Уровень защиты загрузочной области (HIGH,STNDRD,DISABLED)	
#pragma config BWRP     =   OFF     //Защита от записи загрузочной области Boot Segment(ON,OFF)




#define	LED_B           _LATA0          //синий светодиод
#define	LED_R           _LATB8          //красный светодиод
#define	LED_G           _LATB9          //зелёный светодиод


//----------- ОСНОВНОЕ ТЕЛО ПРОГРАММЫ --------------
int main(void) {
//AD1PCFG =   0b1111111111111111;   //АЦП входы отключены
TRISA   =   0b00000;
LATA    =   0b00000;
TRISB   =   0b0000000000000000;       //0-выход 1-вход
LATB    =   0b0000000000000000;   

//CLKDIVbits.CPDIV =   3;					//управление делителем внутреннего генератора 0x0700-31КГц 0x0500-250КГц 0x0200-2МГц  0x0100-4МГц 0x0000-8МГц
OSCDIVbits.DIV = 0;     //целочисленное деление частоты генератора 1-(1*2)=2,2-(2*2)=4,3-(3*2)=6..... 32767-(32767*2)=65534
OSCFDIVbits.TRIM = 0;   //дробный делитель частоты генератора 1-1/512,2-2/512 ...510-510/512,511-511/512
while(1)
{
LED_G=1;
__delay_ms(100);
LED_G=0;    
__delay_ms(500);
//RCONbits.RETEN=1;
//Sleep(); 
}//конец while(1)
    return 0;   //это обязательно
}//конец int main(void)

