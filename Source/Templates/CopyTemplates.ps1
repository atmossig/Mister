$SourcePath = $PSScriptRoot
$TemplateFiles = @(
    "Mister DLL.zip",
    "Mister Executable.zip",
	"Mister Console Executable.zip",
    "Mister LIB.zip"
)
$DocumentsPath = [Environment]::GetFolderPath("MyDocuments")
$TargetBaseDir = Join-Path -Path $DocumentsPath -ChildPath "Visual Studio 2022"
$TargetDir = Join-Path -Path $TargetBaseDir -ChildPath "My Exported Templates"
if (-not (Test-Path -Path $TargetBaseDir -PathType Container)) {
    Write-Warning "Visual Studio 2022 directory not found at '$TargetBaseDir'. Cannot copy templates."
} else {
    if (-not (Test-Path -Path $TargetDir -PathType Container)) {
        Write-Host "Target directory '$TargetDir' not found. Creating it..."
        try {
            New-Item -ItemType Directory -Path $TargetDir -Force -ErrorAction Stop | Out-Null
            Write-Host "Successfully created directory '$TargetDir'."
        } catch {
            Write-Error "Failed to create directory '$TargetDir'. Please check permissions. Error: $($_.Exception.Message)"
            exit 1
        }
    } else {
        Write-Host "Target directory '$TargetDir' already exists."
    }
    foreach ($File in $TemplateFiles) {
        $SourceFile = Join-Path -Path $SourcePath -ChildPath $File
        $DestinationFile = Join-Path -Path $TargetDir -ChildPath $File

        Write-Host "Attempting to copy '$SourceFile' to '$TargetDir'..."

        if (Test-Path -Path $SourceFile -PathType Leaf) {
            try {
                Copy-Item -Path $SourceFile -Destination $DestinationFile -Force -ErrorAction Stop
                Write-Host "Successfully copied '$File'."
            } catch {
                Write-Error "Failed to copy '$File'. Error: $($_.Exception.Message)"
            }
        } else {
            Write-Warning "Source file '$SourceFile' not found. Skipping."
        }
    }
    Write-Host "Template copy process finished."
}