Write-Output("On Windows System!!!");

$client = ComputerClient

if ($args[0] -eq "clean") {
    Remove-Item *.class 
    Write-Output("Clean successful");
} else {
    javac $($client + $(".java"))

    java $client 
}