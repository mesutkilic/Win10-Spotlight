# Win10-Spotlight
Win10 Spotlight Wallpaper Copy Program

# Usage 
Just double click `wall_v1.exe` or `run.bat`

# About
This program Copies Win10 Spotlight Wallpapers 

This program creates 3 folder to current directory : `Assets, Scripts, Temp`

If want to use spesific directory Use `run. bat` file. 

`.\wall_v1.exe 1920 C:\Wallpaper` 

Program takes 2 parameter

|Paramater         | Example       | Description    |
| :---             |     :---      |          :---  |
| Screen Size      | 1920          | Max Screen Size|
| Spesific Folder  | `C:\Wallpaper`  | Spesified Folder|

# Program Steps
- First cleans `Temp` folder
- Then copies files from `%localappdata%\Packages\Microsoft.Windows.ContentDeliveryManager_cw5n1h2txyewy\LocalState\Assets` to `Temp` folder
- Deletes unnecessary files from `Temp` folder
- Copies wallpapers to `Assets` folder end cleans `Temp` folder

`Scripts` folder contains copy and paste scripts.

## Mesut KILIÇ
