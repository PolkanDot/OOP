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

REM Work with empty findingString
%program% test_input_output\g_input.txt "%TEMP%\output.txt" "" b
if ERRORLEVEL 1 GOTO error
FC.exe test_input_output\g_input.txt "%TEMP%\output.txt" > nul 
if ERRORLEVEL 1 GOTO error
ECHO Test 5 successful

REM Work with same substrings ("ma" "mama")
%program% test_input_output\ma_input.txt "%TEMP%\output.txt" ma mama 
if ERRORLEVEL 1 GOTO error
FC.exe test_input_output\ma_output.txt "%TEMP%\output.txt" > nul 
if ERRORLEVEL 1 GOTO error
ECHO Test 6 successful

REM Work with same substrings and text
%program% test_input_output\123_input.txt "%TEMP%\output.txt" 1231234 w 
if ERRORLEVEL 1 GOTO error
FC.exe test_input_output\123_output.txt "%TEMP%\output.txt" > nul 
if ERRORLEVEL 1 GOTO error
ECHO Test 7 successful

REM Tests were successful
ECHO All tests were successful
EXIT /B 0

REM Some test failed
: error
ECHO Test faild
EXIT /B 1