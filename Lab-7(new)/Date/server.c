//server program

long *bin_date_1_svc(NULL)
{
	static long timeval;
	long time();
	timeval=time((long *)0);
	return &timeval;
}

char **str_date_1_svc(long *lresult)
{
	static char* time;
	char* ctime();
	time=ctime(lresult);
	return &time;
}
