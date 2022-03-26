rem ������������� � ���������� ���� � exe-����� ��������� 
set PROGRAM="%~1"
set OUT="%TEMP%\output.txt"
set OUT1="%TEMP%\output1.txt"
set OUT2="%TEMP%\aboba.jpg"
rem ������ ��� ���������� 
%PROGRAM% >nul
if NOT ERRORLEVEL 1 goto err
echo test without parameters passed

rem �� ���� �������������� ����
%PROGRAM% crypt CryptFiles\test.txt OUT 4 >nul
if NOT ERRORLEVEL 1 goto err
echo test with a non-existent input file passed

rem �� ���� ����� ������ ����
%PROGRAM% crypt CryptFiles\test3.txt OUT 4 >nul
if ERRORLEVEL 1 goto err
echo test with empty input file passed

rem �� ���� ����� ���� �������� ������� 
%PROGRAM% translate CryptFiles\test4.txt OUT 4 >nul
if NOT ERRORLEVEL 1 goto err
echo test with the wrong approach name passed

rem ������ ����� ����� ������ ������
%PROGRAM% crypt CryptFiles\test2.txt OUT "" >nul
if NOT ERRORLEVEL 1 goto err
echo test with empty string key 

rem ������ ����� ����� ������������ ������
%PROGRAM% crypt CryptFiles\test2.txt OUT dsjo35 >nul
if NOT ERRORLEVEL 1 goto err
echo test with a string key 

rem �� ���� ��������� ���������� ��������� ������
%PROGRAM% crypt CryptFiles\test2.txt OUT 4
if ERRORLEVEL 1 goto err
%PROGRAM% encrypt OUT OUT1 4
fc.exe OUT1 CryptFiles\test2.txt >nul 
if ERRORLEVEL 1 goto err
echo test with correct parameters passed

rem �� ���� ��������� �����������
%PROGRAM% crypt CryptFiles\aboba.jpg OUT 255
if ERRORLEVEL 1 goto err
%PROGRAM% encrypt OUT OUT2 255
fc.exe OUT2 CryptFiles\aboba.jpg >nul 
if ERRORLEVEL 1 goto err
echo test with image passed

exit /B 0

rem � ������ ������ ������� ��������������� ���������
:err
echo Program testing failed
exit /B 1