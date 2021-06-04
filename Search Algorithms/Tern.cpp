double solve(double x, double y, double z)
{
        double ret = 0;
        double l = z, r = min(z + k, x + y);
        for (int i = 0; i < 100; ++i)
        {
                double per = (r - l) / 3.0;
                if (f(x, y, l + per) > f(x, y, r - per))
                        r -= per;
                else
                        l += per;
        }
        return f(x, y, l);
}
