echo %cd%

set ROOT_PATH=.\..\..
set HEX_FILE=%ROOT_PATH%\..\Project\STM32F10x_StdPeriph_Template\MDK-ARM\STM3210B-EVAL\*.hex
set BIN_FILE=%ROOT_PATH%\..\Project\STM32F10x_StdPeriph_Template\MDK-ARM\STM3210B-EVAL\*.bin
set DST_DIR=%ROOT_PATH%\..\Firmware\
if exist %HEX_FILE% (XCOPY /Y /S /F %HEX_FILE% %DST_DIR%)
if exist %BIN_FILE% (XCOPY /Y /S /F %BIN_FILE% %DST_DIR%)
exit