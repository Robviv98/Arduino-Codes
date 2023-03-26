mkdir "D:\Github\Arduino"
cd "D:\Github\Arduino"
git init
git add .
git commit -m "Mi primer commit"
git remote add origin https://github.com/Robviv98/Arduino-Codes.git
git pull origin master
git push -u origin master
git commit -m "Actualizacion"
git push
pause
