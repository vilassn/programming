int i;
main()
{
 *(int *)0 = 0;
 func();
}

func()
{
 int j;
 i++;
 printf("%d at %p, &j=%p\n", i, &i, &j);
 func();
}

//stack size is 8MB in linux
