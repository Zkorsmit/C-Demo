// C code to demontrate LOOPING code "while" and "for".
// C code to demonstrate decision making code "if".
#include <p18cxxx.h> 
#pragma config XINST = OFF   // Extended Instruction Set ON, to optimise code specifically for C 

//Delay function waste time counting. 32767 is largest positive 16 bit 2CN number
void delay() {      
    int delaycount = 0;   
    for (delaycount = 0; delaycount<32767; delaycount++);  //works with "RUN"  
    //for (delaycount = 0; delaycount<2; delaycount++);  	   //works with "STEP INTO"  
 }   

//main program
void main(void) {      
    int counter = 0;   
    TRISJ = 0xff;	// all bits of portJ are set 1 as input      
    TRISE = 0; 		// all bits of portE are set 0 as output      
    PORTE = 0; 		// turn off all led's   

//while PORTJ switch #7 = 1 you execute the "if/else" code that uses 
//  switch #0 to control count direction
    while (PORTJbits.RJ7) {          
       if (PORTJbits.RJ0 == 0) { 				//if switch =0 count forward                          
            for (counter = 0; counter<=15; counter++)
			{
				PORTE = counter; 
			 	delay();
			} 
	   } else {              					//else count backwards
            for (counter = 15; counter>-1; counter--)
			{
				PORTE = counter; 
			 	delay();
			} 
       }   
     
    }       
 }   
 
