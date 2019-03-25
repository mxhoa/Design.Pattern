Write-Output("On Windows System!");

if ($args[0] -eq "clean") {
    Write-Output ("Cleaning....");
    rm *.class 
} else {
    Write-Output("Compiling...");
    javac DirectoryCompositeApp.java 

    Write-Output("Executing...");
    java DirectoryCompositeApp 
}