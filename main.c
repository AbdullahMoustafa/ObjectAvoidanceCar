#include"stdtypes.h"
#include"util.h"
#include"Timer0.h"
#include"GPIO.h"
#include"UART .h"
#include"ultrasonic.h"
#include"PWM.h"


u8 res1 = 0 ;

u32 dist1 = 0;
u32 dist2 = 0;

/*  Speed changes from change duty 0 to 1  */

/*Connect Enable of motor driver to 5V
 *control motor direction using HIGH and LOW of PD0
 *control motor speed using PWM from 0.9 to 0.1 for foward direction and vice-versa
 * */
int main(void)
{
    PWM_Init();

    GPIO_Initialize_Port(PD);
    GPIO_Set_Pin_Direction(PD, PIN0, OUT);          //backMotorA1
    GPIO_Set_Pin_Direction(PD, PIN1, OUT);          //backMotorA2

    GPIO_Set_Pin_Direction(PD, PIN2, OUT);          //streeingMotor1
    GPIO_Set_Pin_Direction(PD, PIN3, OUT);          //streeingMotor2


    GPIO_Initialize_Port(PA);
    GPIO_Set_Pin_Direction(PA, PIN2, OUT);
    GPIO_Set_Pin_Direction(PA, PIN3, OUT);

    UART_Initialization();

    Timer2_Count_Init();
    Timer3_Count_Init();

    while(1){

        dist1 = ultrasonic_1();
        Timer0_Delay(100);
        dist2 = ultrasonic_2();
        Timer0_Delay(100);

        /*Forward Motion
          MA1 HIGH  "PB6"  (changeable)
          MA2 LOW   "PD1"
         */

        if (dist1 > 100 && dist2 > 100){

            change_duty(0.9);                   //MA1  change duty from 0.9 to 0.1 to control speed
            GPIO_Write_Pin(PD, PIN1, LOWV);     //MA2  set LOW to move forward
        }

        /*Backward Motion
           MA1 HIGH  "PB6"  (changeable)
           MA2 LOW   "PD1"
         */

        else //dist1 < 100 && dist2<100
        {
            change_duty(0.1);                    //MA1  change duty from 0.1 to 0.9 to control speed
            GPIO_Write_Pin(PD, PIN1, HIGHV);     //MA2  set LOW to move forward
        }



    }

    return 0;
}



void UART3_Handler()
{

    if(GET_BIT(UARTMIS,4)==1) //checking if an receive interrupt has occurred
    {
        res1=read();
        SET_BIT(UARTICR,4); // clearing the receive flag bit by setting corresponding bit in this register
    }
    if(GET_BIT(UARTMIS,5)==1) //checking if an transmit interrupt has occurred
    {

        SET_BIT(UARTICR,5); // clearing the transmit flag bit by setting corresponding bit in this register
    }
}


