# Project: C - Simple Shell
##### This project consists in replicate how a the Linux Shell works.
## Description
The project is a very simple shell developed in C language. A shell is a program that takes commands inputs written from the user's keyboard and passes them to the machine to execute them through the kernel. 
## Prototype
```
int main(int ac, char **av, char **env);
```
## Compilation with gcc
```
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
```
## Compilation with valgrind
```
valgrind --tool=memcheck --leak-check=yes --track-origins=yes --show-leak-kinds=all -s ./hsh
```
## Examples of some commands
- `ls` --> This command lists all files in the current directory.
```
#cisfun$ ls
AUTHORS  facu  _getenv.c  hsh  main.h  man_1_simple_shell  _puts.c  README.md  shell.c  _strcat.c  _strcmp.c  _strdup.c  _which.c
```
- `env` --> Command used to print environment variables.
```
root@8536ce3238f7:/holbertonschool-simple_shell# env
HOSTNAME=8536ce3238f7
LANGUAGE=en_US:en
PWD=/holbertonschool-simple_shell
TZ=America/Los_Angeles
HOME=/root
LANG=en_US.UTF-8
LS_COLORS=rs=0:di=01;34:ln=01;36:mh=00:pi=40;33:so=01;35:do=01;35:bd=40;33;01:cd=40;33;01:or=40;31;01:mi=00:su=37;41:sg=30;43:ca=30;41:tw=30;42:ow=34;42:st=37;44:ex=01;32:*.tar=01;31:*.tgz=01;31:*.arc=01;31:*.arj=01;31:*.taz=01;31:*.lha=01;31:*.lz4=01;31:*.lzh=01;31:*.lzma=01;31:*.tlz=01;31:*.txz=01;31:*.tzo=01;31:*.t7z=01;31:*.zip=01;31:*.z=01;31:*.dz=01;31:*.gz=01;31:*.lrz=01;31:*.lz=01;31:*.lzo=01;31:*.xz=01;31:*.zst=01;31:*.tzst=01;31:*.bz2=01;31:*.bz=01;31:*.tbz=01;31:*.tbz2=01;31:*.tz=01;31:*.deb=01;31:*.rpm=01;31:*.jar=01;31:*.war=01;31:*.ear=01;31:*.sar=01;31:*.rar=01;31:*.alz=01;31:*.ace=01;31:*.zoo=01;31:*.cpio=01;31:*.7z=01;31:*.rz=01;31:*.cab=01;31:*.wim=01;31:*.swm=01;31:*.dwm=01;31:*.esd=01;31:*.jpg=01;35:*.jpeg=01;35:*.mjpg=01;35:*.mjpeg=01;35:*.gif=01;35:*.bmp=01;35:*.pbm=01;35:*.pgm=01;35:*.ppm=01;35:*.tga=01;35:*.xbm=01;35:*.xpm=01;35:*.tif=01;35:*.tiff=01;35:*.png=01;35:*.svg=01;35:*.svgz=01;35:*.mng=01;35:*.pcx=01;35:*.mov=01;35:*.mpg=01;35:*.mpeg=01;35:*.m2v=01;35:*.mkv=01;35:*.webm=01;35:*.ogm=01;35:*.mp4=01;35:*.m4v=01;35:*.mp4v=01;35:*.vob=01;35:*.qt=01;35:*.nuv=01;35:*.wmv=01;35:*.asf=01;35:*.rm=01;35:*.rmvb=01;35:*.flc=01;35:*.avi=01;35:*.fli=01;35:*.flv=01;35:*.gl=01;35:*.dl=01;35:*.xcf=01;35:*.xwd=01;35:*.yuv=01;35:*.cgm=01;35:*.emf=01;35:*.ogv=01;35:*.ogx=01;35:*.aac=00;36:*.au=00;36:*.flac=00;36:*.m4a=00;36:*.mid=00;36:*.midi=00;36:*.mka=00;36:*.mp3=00;36:*.mpc=00;36:*.ogg=00;36:*.ra=00;36:*.wav=00;36:*.oga=00;36:*.opus=00;36:*.spx=00;36:*.xspf=00;36:
LESSCLOSE=/usr/bin/lesspipe %s %s
TERM=xterm
LESSOPEN=| /usr/bin/lesspipe %s
SHLVL=1
LC_ALL=en_US.UTF-8
PATH=/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin
OLDPWD=/holbertonschool-simple_shell/facu
_=./hsh
```
- `exit` --> The exit command is responsible for the controlled termination of a program.
```
#cisfun$ exit
root@8536ce3238f7:/holbertonschool-simple_shell# _
```
# Others functions
- _getenv.c - Dynamically searches for the environment variable.
- _which.c - Search a path.
- _strdup.c - Duplicate a string.
- _strcmp.c - Compare two strings.
- _strcpy.c - Copies one string to another.

# Function flowcharts
![Flowchart drawio](https://user-images.githubusercontent.com/88350478/183078031-9dd1a202-eadb-4d2a-a59b-1672edda7b55.png)

# Authors
_By [Lautaro Illa](https://github.com/Lautaro1387) and [Facundo Blanco](https://github.com/Facundoblanco10)_
