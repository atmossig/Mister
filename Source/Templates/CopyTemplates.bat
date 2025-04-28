@echo off

SET SCRIPT_DIR=%~dp0

SET PS_SCRIPT_PATH="%SCRIPT_DIR%CopyTemplates.ps1"

IF NOT EXIST %PS_SCRIPT_PATH% (
    echo ERROR: PowerShell script not found at %PS_SCRIPT_PATH%
    pause
    exit /b 1
)

echo Executing PowerShell script: %PS_SCRIPT_PATH%
echo ==================================================

powershell.exe -ExecutionPolicy Bypass -File %PS_SCRIPT_PATH%

echo ==================================================
echo PowerShell script execution finished.

pause