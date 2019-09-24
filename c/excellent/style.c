/* printing the string into style format*/
#include<stdio.h>
void exit(int);
char str[20];
int meet[15]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
int i=0;
main()
{
	printf("Enter the string\n\t\t\t\t");
	gets(str);
        printf("\n\n\n");
	start();
}

start()
{
  char ch;
  ch = str[i];
 switch(ch)
    {
  	case 'A': case 'a':fa();break;
	case 'B': case 'b':fb();break;
	case 'C': case 'c':fc();break;
	case 'D': case 'd':fd();break;
	case 'E': case 'e':fe();break;
	case 'F': case 'f':ff();break;
	case 'G': case 'g':fg();break;
	case 'H': case 'h':fh();break;
	case 'I': case 'i':fi();break;
	case 'J': case 'j':fj();break;
	case 'K': case 'k':fk();break;
	case 'L': case 'l':fl();break;
	case 'M': case 'm':fm();break;
	case 'N': case 'n':fn();break;
	case 'O': case 'o':fo();break;
	case 'P': case 'p':fp();break;
	case 'Q': case 'q':fq();break;
	case 'R': case 'r':fr();break;
	case 'S': case 's':fs();break;
	case 'T': case 't':ft();break;
	case 'U': case 'u':fu();break;
	case 'V': case 'v':fv();break;
	case 'W': case 'w':fw();break;
	case 'X': case 'x':fx();break;
	case 'Y': case 'y':fy();break;
	case 'Z': case 'z':fz();break;
        case ' ':      fspace();break;
        case '\0':   fnewline();break;
    }
     start();
}

fa()
{
  i++;
  int b;
  b=meet[i];
  b++;
  meet[i]=b;
  switch(b)
     {
       	case 1:printf("  ####### ");break;
       	case 2:printf(" #       #");break;
       	case 3:printf(" #       #");break;
       	case 4:printf(" #########");break;
       	case 5:printf(" #       #");break;
       	case 6:printf(" #       #");break;
       	case 7:printf(" #       #");break;
	default:printf("\n\n\n\n\n");exit(0);
     }
}


fb()
{
 i++;
 int b;
 b=meet[i];
 b++;
 meet[i]=b;
 switch(b)
    {
       	case 1:printf(" ######## ");break;
       	case 2:printf(" #       #");break;
       	case 3:printf(" #       #");break;
       	case 4:printf(" ######## ");break;
       	case 5:printf(" #       #");break;
       	case 6:printf(" #       #");break;
       	case 7:printf(" ######## ");break;
        default:printf("\n\n\n\n\n");exit(0);
    }
}

fc()
{
 i++;
 int b;
 b=meet[i];
 b++;
 meet[i]=b;
 switch(b)
    {
       	case 1:printf("   ###### ");break;
       	case 2:printf("  #       ");break;
       	case 3:printf(" #        ");break;
       	case 4:printf(" #        ");break;
       	case 5:printf(" #        ");break;
       	case 6:printf("  #       ");break;
       	case 7:printf("   ###### ");break;
 	default:printf("\n\n\n\n\n");exit(0);
    }
}
fd()
{
 i++;
 int b;
 b=meet[i];
 b++;
 meet[i]=b;
 switch(b)
    {
       	case 1:printf(" ######   ");break;
       	case 2:printf(" #      # ");break;
       	case 3:printf(" #       #");break;
       	case 4:printf(" #       #");break;
       	case 5:printf(" #       #");break;
       	case 6:printf(" #      # ");break;
       	case 7:printf(" ######   ");break;
 	default:printf("\n\n\n\n\n");exit(0);
    }
}
fe()
{
 i++;
 int b;
 b=meet[i];
 b++;
 meet[i]=b;
 switch(b)
    {
       	case 1:printf(" #########");break;
       	case 2:printf(" #        ");break;
       	case 3:printf(" #        ");break;
       	case 4:printf(" #####    ");break;
       	case 5:printf(" #        ");break;
       	case 6:printf(" #        ");break;
       	case 7:printf(" #########");break;
 	default:printf("\n\n\n\n\n");exit(0);
    }
}
ff()
{
 i++;
 int b;
 b=meet[i];
 b++;
 meet[i]=b;
 switch(b)
    {
       	case 1:printf(" #########");break;
       	case 2:printf(" #        ");break;
       	case 3:printf(" #        ");break;
       	case 4:printf(" ####     ");break;
       	case 5:printf(" #        ");break;
       	case 6:printf(" #        ");break;
       	case 7:printf(" #        ");break;
 	default:printf("\n\n\n\n\n");exit(0);
    }
}
fg()
{
 i++;
 int b;
 b=meet[i];
 b++;
 meet[i]=b;
 switch(b)
    {
       	case 1:printf("  ####### ");break;
       	case 2:printf(" #        ");break;
       	case 3:printf(" #        ");break;
       	case 4:printf(" #    ####");break;
       	case 5:printf(" #       #");break;
       	case 6:printf(" #       #");break;
       	case 7:printf("  ####### ");break;
 	default:printf("\n\n\n\n\n");exit(0);
    }
}
fh()
{
 i++;
 int b;
 b=meet[i];
 b++;
 meet[i]=b;
 switch(b)
    {
       	case 1:printf(" #       #");break;
       	case 2:printf(" #       #");break;
       	case 3:printf(" #       #");break;
       	case 4:printf(" #########");break;
       	case 5:printf(" #       #");break;
       	case 6:printf(" #       #");break;
       	case 7:printf(" #       #");break;
 	default:printf("\n\n\n\n\n");exit(0);
    }
}
fi()
{
 i++;
 int b;
 b=meet[i];
 b++;
 meet[i]=b;
 switch(b)
    {
       	case 1:printf("  ####### ");break;
       	case 2:printf("     #    ");break;
       	case 3:printf("     #    ");break;
       	case 4:printf("     #    ");break;
       	case 5:printf("     #    ");break;
       	case 6:printf("     #    ");break;
       	case 7:printf("  ####### ");break;
 	default:printf("\n\n\n\n\n");exit(0);
    }
}
fj()
{
 i++;
 int b;
 b=meet[i];
 b++;
 meet[i]=b;
 switch(b)
    {
       	case 1:printf("         #");break;
       	case 2:printf("         #");break;
       	case 3:printf("         #");break;
       	case 4:printf("         #");break;
       	case 5:printf("         #");break;
       	case 6:printf("  #      #");break;
       	case 7:printf("   #####  ");break;
 	default:printf("\n\n\n\n\n");exit(0);
    }
}
fk()
{
 i++;
 int b;
 b=meet[i];
 b++;
 meet[i]=b;
 switch(b)
    {
       	case 1:printf(" #    # # ");break;
       	case 2:printf(" #   #    ");break;
       	case 3:printf(" #  #     ");break;
       	case 4:printf(" ###      ");break;
       	case 5:printf(" #  #     ");break;
       	case 6:printf(" #   #    ");break;
       	case 7:printf(" #    # # ");break;
 	default:printf("\n\n\n\n\n");exit(0);
    }
}
fl()
{
 i++;
 int b;
 b=meet[i];
 b++;
 meet[i]=b;
 switch(b)
    {
       	case 1:printf(" #        ");break;
       	case 2:printf(" #        ");break;
       	case 3:printf(" #        ");break;
       	case 4:printf(" #        ");break;
       	case 5:printf(" #        ");break;
       	case 6:printf(" #       #");break;
       	case 7:printf(" #########");break;
 	default:printf("\n\n\n\n\n");exit(0);
    }
}
fm()
{
 i++;
 int b;
 b=meet[i];
 b++;
 meet[i]=b;
 switch(b)
    {
       	case 1:printf(" #        #");break;
       	case 2:printf(" # #    # #");break;
       	case 3:printf(" #   ##   #");break;
       	case 4:printf(" #        #");break;
       	case 5:printf(" #        #");break;
       	case 6:printf(" #        #");break;
       	case 7:printf(" #        #");break;
 	default:printf("\n\n\n\n\n");exit(0);
    }
}
fn()
{
 i++;
 int b;
 b=meet[i];
 b++;
 meet[i]=b;
 switch(b)
    {
       	case 1:printf(" #       #");break;
       	case 2:printf(" # #     #");break;
       	case 3:printf(" #  #    #");break;
       	case 4:printf(" #   #   #");break;
       	case 5:printf(" #    #  #");break;
       	case 6:printf(" #     # #");break;
       	case 7:printf(" #       #");break;
 	default:printf("\n\n\n\n\n");exit(0);
    }
}
fo()
{
 i++;
 int b;
 b=meet[i];
 b++;
 meet[i]=b;
 switch(b)
    {
       	case 1:printf("  ####### ");break;
       	case 2:printf(" #       #");break;
       	case 3:printf(" #       #");break;
       	case 4:printf(" #       #");break;
       	case 5:printf(" #       #");break;
       	case 6:printf(" #       #");break;
       	case 7:printf("  ####### ");break;
 	default:printf("\n\n\n\n\n");exit(0);
    }
}
fp()
{
 i++;
 int b;
 b=meet[i];
 b++;
 meet[i]=b;
 switch(b)
    {
       	case 1:printf(" ######## ");break;
       	case 2:printf(" #       #");break;
       	case 3:printf(" #       #");break;
       	case 4:printf(" ######## ");break;
       	case 5:printf(" #        ");break;
       	case 6:printf(" #        ");break;
       	case 7:printf(" #        ");break;
 	default:printf("\n\n\n\n\n");exit(0);
    }
}
fq()
{
 i++;
 int b;
 b=meet[i];
 b++;
 meet[i]=b;
 switch(b)
    {
       	case 1:printf("  ####### ");break;
       	case 2:printf(" #       #");break;
       	case 3:printf(" #       #");break;
       	case 4:printf(" #       #");break;
       	case 5:printf(" #    #  #");break;
       	case 6:printf(" #     # #");break;
       	case 7:printf("  ###### #");break;
 	default:printf("\n\n\n\n\n");exit(0);
    }
}
fr()
{
 i++;
 int b;
 b=meet[i];
 b++;
 meet[i]=b;
 switch(b)
    {
       	case 1:printf(" ######## ");break;
       	case 2:printf(" #       #");break;
       	case 3:printf(" #       #");break;
       	case 4:printf(" ######## ");break;
       	case 5:printf(" #  #     ");break;
       	case 6:printf(" #   #    ");break;
       	case 7:printf(" #    ### ");break;
 	default:printf("\n\n\n\n\n");exit(0);
    }
}
fs()
{
 i++;
 int b;
 b=meet[i];
 b++;
 meet[i]=b;
 switch(b)
    {
       	case 1:printf("  ####### ");break;
       	case 2:printf(" #        ");break;
       	case 3:printf(" #        ");break;
       	case 4:printf("  ####### ");break;
       	case 5:printf("         #");break;
       	case 6:printf("         #");break;
       	case 7:printf("  ####### ");break;
 	default:printf("\n\n\n\n\n");exit(0);
    }
}
ft()
{
 i++;
 int b;
 b=meet[i];
 b++;
 meet[i]=b;
 switch(b)
    {
       	case 1:printf(" #########");break;
       	case 2:printf("     #    ");break;
       	case 3:printf("     #    ");break;
       	case 4:printf("     #    ");break;
       	case 5:printf("     #    ");break;
       	case 6:printf("     #    ");break;
       	case 7:printf("     #    ");break;
 	default:printf("\n\n\n\n\n");exit(0);
    }
}
fu()
{
 i++;
 int b;
 b=meet[i];
 b++;
 meet[i]=b;
 switch(b)
    {
       	case 1:printf(" #       #");break;
       	case 2:printf(" #       #");break;
       	case 3:printf(" #       #");break;
       	case 4:printf(" #       #");break;
       	case 5:printf(" #       #");break;
       	case 6:printf(" #       #");break;
       	case 7:printf("  ####### ");break;
 	default:printf("\n\n\n\n\n");exit(0);
    }
}
fv()
{
 i++;
 int b;
 b=meet[i];
 b++;
 meet[i]=b;
 switch(b)
    {
       	case 1:printf(" #       #");break;
       	case 2:printf(" #       #");break;
       	case 3:printf(" #       #");break;
       	case 4:printf(" #       #");break;
       	case 5:printf("  #     # ");break;
       	case 6:printf("   #   #  ");break;
       	case 7:printf("     #    ");break;
 	default:printf("\n\n\n\n\n");exit(0);
    }
}
fw()
{
 i++;
 int b;
 b=meet[i];
 b++;
 meet[i]=b;
 switch(b)
    {
       	case 1:printf(" #       #");break;
       	case 2:printf(" #       #");break;
       	case 3:printf(" #       #");break;
       	case 4:printf(" #   #   #");break;
       	case 5:printf(" #  # #  #");break;
       	case 6:printf(" # #   # #");break;
       	case 7:printf(" #       #");break;
 	default:printf("\n\n\n\n\n");exit(0);
    }
}
fx()
{
 i++;
 int b;
 b=meet[i];
 b++;
 meet[i]=b;
 switch(b)
    {
       	case 1:printf(" #       #");break;
       	case 2:printf("  #     # ");break;
       	case 3:printf("   #   #  ");break;
       	case 4:printf("    ###   ");break;
       	case 5:printf("   #   #  ");break;
       	case 6:printf("  #     # ");break;
       	case 7:printf(" #       #");break;
 	default:printf("\n\n\n\n\n");exit(0);
    }
}
fy()
{
 i++;
 int b;
 b=meet[i];
 b++;
 meet[i]=b;
 switch(b)
    {
       	case 1:printf(" #       #");break;
       	case 2:printf("  #     # ");break;
       	case 3:printf("   #   #  ");break;
       	case 4:printf("     #    ");break;
       	case 5:printf("     #    ");break;
       	case 6:printf("     #    ");break;
       	case 7:printf("     #    ");break;
 	default:printf("\n\n\n\n\n");exit(0);
    }
}
fz()
{
 i++;
 int b;
 b=meet[i];
 b++;
 meet[i]=b;
 switch(b)
    {
       	case 1:printf(" #########");break;
       	case 2:printf("       #  ");break;
       	case 3:printf("      #   ");break;
       	case 4:printf("     #    ");break;
       	case 5:printf("    #     ");break;
       	case 6:printf("   #      ");break;
       	case 7:printf(" #########");break;
 	default:printf("\n\n\n\n\n");exit(0);
    }
}

fnewline()
{
 i=0;
 printf("\n");
}

fspace()
{
 i++;
 printf("   ");
}
