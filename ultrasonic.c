#include"ultrasonic.h"

u32 duration1 = 0;
u32 distance1 = 0;
u32 duration2 = 0;
u32 distance2 = 0;


/* Function Name: Ultrasonic_1
 * Inputs:        Nothing
 * Returns:       u32 distance1
 * Pins :         Pins used for ultrasonic sensor1 using timer3 as counter PA3 (Trigger) - PB2 (Echo)
 * Description:   It used to measure distance using HC SR04 Ultrasonic sensor module
 * */
u32 ultrasonic_1 (void){
    GPIO_Write_Pin(PA, PIN3, LOWV);         //Trigger LOW
    Timer0_Delay(10);                       //10 micro-seconds delay
    GPIO_Write_Pin(PA, PIN3, HIGHV);        //Trigger High
    Timer0_Delay(10);                       //10 micro-seconds delay
    GPIO_Write_Pin(PA, PIN3, LOWV);         //Trigger-Low
    // Clearing Trigger finished

    duration1 = Timer3_Count_Ret();         //Return counts of trigger detected by timer3
    distance1 = (((float)duration1*(float)0.00340000))/2;   //calculate the distance with the constant speed of sound

    return  distance1;
}



/* Function Name: Ultrasonic_2
 * Inputs:        Nothing
 * Returns:       u32 distance2
 * Pins :         Pins used for ultrasonic sensor1 using timer2 as counter PA2 (Trigger)  -   PB0  (Echo)
 * Description:   It used to measure distance using HC SR04 Ultrasonic sensor module
 * */
u32 ultrasonic_2 (void){
    GPIO_Write_Pin(PA, PIN2, LOWV);             //Trigger LOW
    Timer0_Delay(10);                           //10 micro-seconds delay
    GPIO_Write_Pin(PA, PIN2, HIGHV);            //Trigger High
    Timer0_Delay(10);                           //10 micro-seconds delay
    GPIO_Write_Pin(PA, PIN2, LOWV);             //Trigger-Low
    // Clearing Trigger finished

    duration2 = Timer2_Count_Ret();                          //Return counts of trigger detected by timer2
    distance2 = (((float)duration2*(float)0.00340000))/2;   //calculate the distance with the constant speed of sound

    return  distance2;
}

