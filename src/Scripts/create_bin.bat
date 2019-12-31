echo %cd%
set ROOT_PATH=.\..\..
set SRC=%ROOT_PATH%\..\Project\STM32F10x_StdPeriph_Template\MDK-ARM\STM3210B-EVAL\*.hex
set TOOL=%ROOT_PATH%\..\Bin\hex2bin.exe

if exist %SRC% (%TOOL% %SRC%)
exit