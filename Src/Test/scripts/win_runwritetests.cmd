@ECHO OFF
SET EXECUTABLE=../../Build/VS/x64/Debug/CZIcmd.exe
SET TEMPFOLDER=%TEMP%


REM https://superuser.com/questions/245775/is-there-a-built-in-checksum-utility-on-windows-7
REM https://weblogs.asp.net/lorenh/silly-batch-file-tricks-redirecting-stdout-into-an-evironment-variable-and-dp0

"%EXECUTABLE%" --command CreateCZI -o "%TEMP%\test" --createsubblocksize 1024x1024 --guidofczi {22D355B7-A051-4F2E-8686-B50F2A3B154D} --bitmapgenerator gdi --createczisbblkmetadata {\"StageXPosition\":-8906.346,\"StageYPosition\":-648.51} > nul
@certutil -hashfile "%TEMP%\test.czi" MD5|find /v "hash of "|find /v "CertUtil" > "%TEMP%\test.czi.txt"
set /p CHKSUM= < "%TEMP%\test.czi.txt"
del "%TEMP%\test.czi"
del "%TEMP%\test.czi.txt"
if /I "%CHKSUM%" EQU "a0de6ca0207fdaad73180fe23779dcb5" (echo TEST #1: OK) else (echo TEST #1: FAILURE)

