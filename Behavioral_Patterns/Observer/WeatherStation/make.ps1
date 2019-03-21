Write-Output "On WINDOWS System!"

if ($args[0] -eq "world")
{
    Write-Output "Compiling...."
    g++ -c Client.cpp WeatherData.cpp 

    g++ -o main main.cpp Client.o WeatherData.o
}

if ($args[0] -eq "launch")
{
    if (Test-Path main.exe)
    {
        Write-Output "Launching...."
        .\main.exe
    }
    else {
        Write-Output "File has not found! ---> Compile first, please...";
    }
    
}
if ($args[0] -eq "clean")
{
    Write-Output "Cleaning...."
    Remove-Item *.o
    Remove-Item *.exe 
}
