@echo off
echo =======================================
echo     DAILY DSA PROGRESS SYNCING...
echo =======================================

:: Staging all changes
echo 1. Staging files...
git add .

:: Committing changes with date and time
echo 2. Committing changes...
git commit -m "Daily DSA Practice Update - %date% %time%"

:: Pushing to GitHub
echo 3. Pushing to GitHub...
git push -u origin main

echo =======================================
echo     SYNC COMPLETE! KEEP GRINDING!
echo =======================================
pause
