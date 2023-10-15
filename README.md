# Attiny85_NeoPixel_Button
 Attiny85 NeoPixel 


Created By MacaDaca88

Small form light show.

LDR sensor for automatic brightness adjustment 
push button to change modes
Reset button
varible input voltage


////////////////////////////////////////////////////////////////////////////////////
/////////////////////////    DISCLAIMER    /////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////

Im not responsible for you.

When Refering to Pin(x)  this is the physical pin (1-8)
When Refering to PB(x)  this is Digital pin (x)
When Refeing to A(x)  this is Analog pin (x)



////////////////////////////////////////////////////////////////////////////////////
/////////////////////////  Concept/Idea    /////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////

Input voltage from 3v to 14v (idealy keep it as close as possible to 5v)
Optional REG or UNREG input voltage (Be careful not to put more then 5v into VCC (pin8) )
LDR responds to the light for the tme of day when bright leds dim when dark leds bright
2Way Switch gives you options for upto 16v input reg to 5v or direct to VCC
Capacitor on input and as close as posible to VCC to smooth everything out
Small led threw 2.2k resistor represents POWER ON no mater the input voltage state


////////////////////////////////////////////////////////////////////////////////////
///////////////////////// Bill Of Materials:  //////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////


1x Attiny85 IC
2x Momontary Buttons
1x 3Pin Male Header
1x 2Pin JST Female
1x LM7805 Voltage Reg
1x Heat Sink
1x 100k Resistor
1x 2.2k Resistor (2.2k Resistor Optional Power Led)
1x 220uf 10v Capacitor
1x 100uf 16v Capacitor (16v Can Be Exchanged For 25v If Input Exceds 16v)
1x LDR Resistor
1x Pizo Buzzer
1x 2Way Switch 
1x Led (Power Led Optional)
1x NeoPixel Strip (Optional Led Strip Size)
1x 350mAh (run time depending on brightness and colors will run for few hours no worries)

////////////////////////////////////////////////////////////////////////////////////
/////////////////////////   WIRING/PINOUT  /////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////


im getting there............