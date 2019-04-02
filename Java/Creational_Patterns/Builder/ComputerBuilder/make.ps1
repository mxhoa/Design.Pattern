Write-Output("On Windows System!");

$main = "ComputerClient"

if ($args[0] -eq "clean") {
    Remove-Item *.class 
    Write-Output("Clean Successfully");
} else {
    javac $($main + $(".java"))

    java $main 
}