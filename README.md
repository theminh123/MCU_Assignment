# MCU_Assignment

HCMUT Microprocessor Semester 221 
Group 5
Phan Thế Minh - 1852580 (CC02)
Phạm Lê Thế Anh - 1652026 (CC02)
Nguyễn Hữu Anh Đức - 1752176 (CCO2)
Nguyễn Quốc Anh - 1852238 (CC01 - later adopted since the original group disbanded)

Assignment submission
Topic: TRAFFIC LIGHT USING STM32F103RB
4 main modes:
Automatic: run as "normal". Timer ticks every 1 second. Has 4 states (of the lights): RED-GREEN -> RED-YELLOW -> GREEN-RED -> YELLOW-RED -> (RESET TO STATE 1)
Manual (input): used to hot switch the lights state. When in this mode, press the 2nd button to advance the light states (1st to 2nd, 2nd to 3rd state, ...)
Tunning (from input): used to alter the light duration on the fly. With the constraint of timer: Red = Green + Yellow. Use button to increase the value of the timer. Maximum = 99 (to utilize the counter is 2 digits).
Button 1 is used to switch the modes. Modes go in sequence: 1->2->3->1->...

Pedestrian scramble
This feature is activated using button 0. The pedestrian light will display (which in reversed order to the traffic light) to indicate the pedestrian traffic. There is also a "bell" (or buzzer) that rings when the timer is close to 0.
