double gss(double a, double b) {
    double c = b - ((b-a) / gr);
    double d = a + ((b-a) / gr);
    while(abs(c-d) > eps) {
	if(f(c) < f(d)) b = d;
	else a = c;
	c = b - ((b - a) / gr);
	d = a + ((b - a) / gr);
    }
    return (b + a) / 2;
}
