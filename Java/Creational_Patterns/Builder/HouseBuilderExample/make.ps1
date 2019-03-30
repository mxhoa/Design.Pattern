Write-Output("-- On Windows System --");

$OUTPUT = "output"
$EXEC = "HouseClient"

$DIR1 = "./house/*.java"
$DIR2 = "./brick/*.java"
$DIR3 = "./wood/*.java"
$DIR4 = "./*.java"


function compileModule {
    param (
        [string]$OUT,
        [string]$DEP,
        [string]$DIR
    )
    Write-Output("Compiling " + $DIR)
    javac.exe -cp $DEP -d $OUT $DIR -verbose
    Write-Output("Completed " + $DIR + "`n")
}

if ($args[0] -eq "clean") {
    if (Test-Path $OUTPUT) {
        Write-Output("Cleaning...");
        Remove-Item -path $OUTPUT -Recurse
        Write-Output("Clean Completed!");
    } else {
        Write-Output("Output directory hasn't existed");
    }
} elseif ($args[0] -eq "launch") {
    if (Test-Path $OUTPUT) {
        Write-Output("Launching...");
        Set-Location .\output
        java.exe $EXEC -verbose
        Set-Location ..
    } else {
        Write-Output("Need to compile first.");
    }
} elseif ($args[0] -eq "world") {
    Write-Output("Compiling...");
    compileModule -OUT $OUTPUT -DEP $OUTPUT -DIR  $DIR1

    compileModule -OUT $OUTPUT -DEP $OUTPUT -DIR  $DIR2

    compileModule -OUT $OUTPUT -DEP $OUTPUT -DIR  $DIR3

    compileModule -OUT $OUTPUT -DEP $OUTPUT -DIR  $DIR4

    Write-Output("Compiling Successfully");

} else {
    Write-Output("Choose options:");
    Write-Output("1. clean");
    Write-Output("2. world");
    Write-Output("3. launch");
}