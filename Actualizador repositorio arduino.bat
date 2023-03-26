@echo off

:menu
cls
echo Selecciona una opcion:
echo.
echo 1. Subir archivos de la carpeta al repositorio de GitHub.
echo 2. Descargar archivos faltantes del repositorio de GitHub a la carpeta.
echo 3. Eliminar archivos locales que no estan en el repositorio de GitHub.
echo 4. Eliminar archivos en el repositorio de GitHub que no estan en la carpeta local.
echo 5. Salir del programa.
echo.

set /p option=Ingrese una opcion: 

if %option% equ 1 (
    echo Subiendo archivos de la carpeta al repositorio de GitHub...
    cd "D:\Github\Arduino"
    git init
    git add .
    git commit -m "subida de archivos"
    git remote add origin https://github.com/Robviv98/Arduino-Codes.git
    git pull origin master
    git push -u origin master
    echo Los archivos se han subido exitosamente al repositorio de GitHub.
    pause
    goto menu
) else if %option% equ 2 (
    echo Descargando archivos faltantes del repositorio de GitHub a la carpeta...
    cd "D:\Github\Unity"
    git init
    git pull origin master
    echo Los archivos se han descargado exitosamente a la carpeta.
    pause
    goto menu
) else if %option% equ 3 (
    echo Eliminando archivos locales que no estan en el repositorio de GitHub...
    cd "D:\Github\Unity"
    forfiles /P "D:\Github\Unity" /S /M * /C "cmd /c if not @isdir==TRUE git ls-files --error-unmatch @relpath && del /Q @relpath"
    echo Los archivos locales que no estaban en el repositorio han sido eliminados exitosamente.
    pause
    goto menu
) else if %option% equ 4 (
    echo Eliminando archivos en el repositorio de GitHub que no estan en la carpeta local...
    cd "D:\Github\Unity"
    git init
    git add .
    git clean -f
    git commit -m "Eliminando archivos no encontrados en la carpeta local"
    git push -u origin master
    echo Los archivos en el repositorio de GitHub que no estaban en la carpeta local han sido eliminados exitosamente.
    pause
    goto menu
) else if %option% equ 5 (
    echo Saliendo del programa...
    exit
) else (
    echo Seleccione una opcion valida.
    pause
    goto menu
)
