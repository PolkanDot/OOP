SET program="%~1"

REM Defending from starting without arguments
IF program == "" (
	ECHO Please specify path to program
	EXIT /B 1
)

REM При запуске без параметров ожидается ненулевой код возврата
%program% >nul
IF NOT ERRORLEVEL 1 GOTO error
ECHO Test 1 successful

REM Work with empty file
%program% test_input_output\empty.txt "%TEMP%\empty_output.txt" a b
if ERRORLEVEL 1 GOTO error
FC.exe test_input_output\empty.txt "%TEMP%\empty_output.txt" > nul 
if ERRORLEVEL 1 GOTO error
ECHO Test 2 successful

REM Work with mormal args
%program% test_input_output\g_input.txt "%TEMP%\output.txt" g u
if ERRORLEVEL 1 GOTO error
FC.exe test_input_output\g_output.txt "%TEMP%\output.txt" > nul 
if ERRORLEVEL 1 GOTO error
ECHO Test 3 successful

REM Work with wrong substrings
%program% test_input_output\g_input.txt "%TEMP%\output.txt" a b
if ERRORLEVEL 1 GOTO error
FC.exe test_input_output\g_input.txt "%TEMP%\output.txt" > nul 
if ERRORLEVEL 1 GOTO error
ECHO Test 4 successful



REM Tests were successful
ECHO All tests were successful
EXIT /B 0

REM Some test failed
: error
ECHO Test faild
EXIT /B 1