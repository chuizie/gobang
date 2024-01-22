@echo off
cd gamereplay
dir /b > datalist1.txt
findstr /v "datalist" datalist1.txt > datalist.txt
del datalist1.txt
cd..
