Write-Output("#### On Windows System!");

$client = "TestClientFactory"


if ($args[0] -eq "clean") {
    Write-Output("Make clean");
    Remove-Item *.class
} else {
    Write-Output("Compiling...");
    javac $($client + $(".java"))

    Write-Output("Executing...");
    java $client
}

