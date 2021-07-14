//Modify this file to change what commands output to your statusbar, and recompile using the make command.
//nvidia-smi -q | grep "Used" | awk 'NR==1 {print $3}'
static const Block blocks[] = {
	/*Icon*/	/*Command*/		/*Update Interval*/	/*Update Signal*/
  {"Mem:", "free -h | awk '/^Память/ { print $3\"/\"$2 }' | sed s/i//g", 2, 0},
  {"GPUMem:", "nvidia-smi -q | grep \"Used\\|Total\" | awk 'NR==1{l = $3}NR==2{l=l\" \"$3}END{print l}' | awk '{print $2\"M/\"$1\"M\"}'", 2, 0},
  {"Battery:",     "sb-battery",                                         5,  3},
  {"",     "setxkbmap -query | grep -q 'us' && echo US || echo RU",      0,  2},
  {"",     "sb-internet"   ,                                             5,  4},
	{"",     "sb-clock",                                                   60, 1},
};

//sets delimeter between status commands. NULL character ('\0') means no delimeter.
static char delim[] = " | ";
static unsigned int delimLen = 5;
